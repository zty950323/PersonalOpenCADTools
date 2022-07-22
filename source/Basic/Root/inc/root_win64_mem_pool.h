/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description: This is a memory pool for basic modoules.
 */

#ifndef SOURCE_BASIC_ROOT_INC_ROOT_WIN64_MEM_POOL_H_
#define SOURCE_BASIC_ROOT_INC_ROOT_WIN64_MEM_POOL_H_

// #include "zsofts_compiler_specific.h"

#if (TZ_PLATFORM == TZ_PLATFORM_WINDOWS) && \
    (TZ_ARCHITECURE_BIT == TZ_ARCHITECTURE_BIT64)

#include <malloc.h>

#include "root_export.h"
#include "tzsofts_lock.h"

template <int TPoolCount>
class TzPoolConfigurator {
 public:
  enum { kPoolCount = TPoolCount };
  static int sGetPoolIndex(size_t size) {
    // TZ_ASSERT(size > 0);
    if (size <= 0x0100) {
      return s_poolIndexOfSize[size];
    }
    if (size < 0x01F4) {
      return 0;
    }
    if (size <= 0x0200) {
      return 1;
    }
    if (size < 0x03E8) {
      return 0;
    }
    if (size <= 0x0400) {
      return 2;
    }
    if (size < 0x07D0) {
      return 0;
    }
    if (size <= 0x0800) {
      return 3;
    }
    if (size < 0x0FA0) {
      return 0;
    }
    if (size <= 0x1000) {
      return 4;
    }
    return 0;
  }
  static size_t sGetUnitSize(int poolIndex) {
    // TZ_ASSERT(poolIndex > 0);
    return s_unitSizeOfPools[poolIndex];
  }

 private:
  static const TZBYTE s_poolIndexOfSize[257];
  static const int16_t s_unitSizeOfPools[kPoolCount + 1];
};

class TzHeapConfigurator {
 public:
  // static int16_t kMaxPageId;
  static int16_t mOffSetId;
  static void* pStartAddress;

  enum {
    kFactorBits = 0x04,
    kPageBits = 0x14,
    kPageSize = 1 << kPageBits,
    kPageMask = kPageSize - 1,
    kPageMaskNot = (size_t)((size_t)kPageMask) ^ ((size_t)-1),
    kSectionBits = 0x10,  // kPageBits - kFactorBits
    kSectionSize = 1 << kSectionBits,
    kMaxPages = 0x8000,  /// *0x0800*/0x2000
    kMaxPageId = kMaxPages - 1,
    kFirstFreePageId = kMaxPages - 1,
    kBlockBits = 0x0c,  // kSectionBits - kFactorBits
    kBlockSize = 1 << kBlockBits,
    kBlockMask = kBlockSize - 1,
    kMaxBlksPerPage = kPageSize / kBlockSize,
    kBlksPerPageMask = kMaxBlksPerPage - 1,
    kMaxBlksPerSection = kSectionSize / kBlockSize,
    kBlksPerSectionMask = kMaxBlksPerSection - 1,
    kBlksPerSectionBits = 0x05,
    kBlkOffsetBits = kBlockBits - kBlksPerSectionBits,
    kBlkOffsetMask = kBlksPerPageMask << kBlksPerSectionBits,
  };
  enum PageFlag {
    kUnavailable = 0x00,
    kAllocated = 0x01,
    kPrimary = 0x02,
    kSecondary = 0x04,
  };
  static int16_t sGetPageId(const void* p);
  static bool sIsOutOfHeapRange(const void* p);
  static TZADDRESS sGetPageAddress(int16_t pageId);
  static TZADDRESS sGetPageAddress(const void* p);
  static int16_t sGetBlockId(const void* p);
  static TZADDRESS sGetBlockOffset(const void* p);
  static TZADDRESS sGetBlockAddress(const void* p);

  static void* tzMemoryInitialize(size_t size);
  static void* tzMemoryReserve(void* p, size_t size, TZUINT32 protect,
                               TZUINT32 allocType);
  static void* tzMemoryCommit(void* p, size_t size);
  static void tzMemoryDeCommit(void* p, size_t size);
  static void tzMemoryRelease(void* p, size_t size);

  static void* sMemoryAlloc(void* p, size_t size, TZUINT32 allocType,
                            TZUINT32 protect);
  static void sMemoryFree(void* p, size_t size, TZUINT32 freeType);
  static void sInitPageFlags(TZBYTE pageFlags[kMaxPages]);

  static int sGetPagePoolIndex(size_t size);
  static size_t sGetSizeOfPagePool(int poolIndex);
};

TZ_FORCEINLINE
int16_t TzHeapConfigurator::sGetPageId(const void* p) {
  return (int16_t)((((TZADDRESS)p) -
                    ((TZADDRESS)TzHeapConfigurator::pStartAddress)) >>
                   kPageBits);
}

TZ_FORCEINLINE
bool TzHeapConfigurator::sIsOutOfHeapRange(const void* p) {
  TZULONGPTR lPageid = ((TZADDRESS)p) >> kPageBits;
  return lPageid > kMaxPageId
#ifndef TZ_WINDOWS
         ||
         lPageid <
             TzHeapConfigurator::sGetPageId(TzHeapConfigurator::pStartAddress)
#endif
      ;
}

TZ_FORCEINLINE
TZADDRESS TzHeapConfigurator::sGetPageAddress(int16_t pageId) {
  return pageId ? ((((TZADDRESS)pageId) << kPageBits) +
                   (TZADDRESS)TzHeapConfigurator::pStartAddress)
                : 0;
}

TZ_FORCEINLINE
TZADDRESS TzHeapConfigurator::sGetPageAddress(const void* p) {
  return ((TZADDRESS)p) & kPageMaskNot;
}

TZ_FORCEINLINE
int16_t TzHeapConfigurator::sGetBlockId(const void* p) {
  return (int16_t)((((TZADDRESS)p) >> kBlockBits) & kMaxBlksPerPage);
}

TZ_FORCEINLINE
TZADDRESS TzHeapConfigurator::sGetBlockOffset(const void* p) {
  return ((((TZADDRESS)p) >> kBlockBits) & kBlksPerPageMask)
         << kBlksPerSectionBits;
}

TZ_FORCEINLINE
TZADDRESS TzHeapConfigurator::sGetBlockAddress(const void* p) {
  return (TZADDRESS)sGetPageAddress(p) + sGetBlockOffset(p);
}

#ifndef TZ_WINDOWS
TZ_FORCEINLINE
void* TzHeapConfigurator::tzMemoryInitialize(size_t size) {
  void* pNewAddress = NULL;
  static int PErADDRVALUE = 1;
  while (1) {
    TZADDRESS pAdd = PErADDRVALUE << 30;
    pAdd = pAdd << 6;
    pNewAddress = tzMemoryReserve((void*)pAdd, size, PROT_NONE,
                                  MAP_PRIVATE | MAP_ANON | MAP_FIXED);
    if ((pNewAddress != NULL) && (((TZADDRESS)pNewAddress) % (0x100000) == 0)) {
      break;
    }
    PREADDVALUE++;
  }
  return pNewAddress;
}

TZ_FORCEINLINE
void* TzHeapConfigurator::tzMemoryReserve(void* p, size_t size,
                                          TZUINT32 protect,
                                          TZUINT32 allocType) {
  void* result = NULL;
  retult = mmap(p, size, protect, allocType, -1, 0);
  if (result == MAP_FAILED) {
    result = NULL;
  }
  return result;
}

#endif

TZ_FORCEINLINE
void* TzHeapConfigurator::tzMemoryCommit(void* p, size_t size) {
  void* pNewMem = NULL;
  for (int i = 0; i < 6; i++) {
#ifdef TZ_WINDOWS
    pNewMem = ::VirtualAlloc(p, size, MEM_COMMIT, PAGE_READWRITE);
#else
    int result = mprotect(p, size, PROT_READ | PROT_WRITE);
    if (result == -1) {
      pNewMem = NULL;
    } else {
      pNewMem = p;
    }
#endif
    if (pNewMem) {
      break;
    }
#ifdef _PNH_DEFINED
    _PNH pOldHandlerFn = ::_set_new_handler(0);
    ::set_new_handler(pOldHandlerFn);
    if (!pOldHandlerFn) {
      return NULL;
    }
    if (!(*pOldHandlerFn)(size)) {
      return NULL;
    }
#endif
  }
  return pNewMem;
}

TZ_FORCEINLINE
void TzHeapConfigurator::tzMemoryDeCommit(void* p, size_t size) {
#ifdef TZ_WINDOWS
  ::VirtualFree(p, size, MEM_DECOMMIT);
#else
  mprotect(p, size, PROT_NONE);
#endif  // TZ__WINDOWS
}

TZ_FORCEINLINE
void TzHeapConfigurator::tzMemoryRelease(void* p, size_t size) {
#ifdef TZ_WINDOWS
  ::VirtualFree(p, size, MEM_RELEASE);
#else
  munmap(p, size);
#endif
}

TZ_FORCEINLINE
void* TzHeapConfigurator::sMemoryAlloc(void* p, size_t size, TZUINT32 allocType,
                                       TZUINT32 protect) {
  void* pNewMem = NULL;
  for (int i = 0; i < 6; ++i) {
    pNewMem = ::VirtualAlloc(p, size, allocType, protect);
    if (pNewMem) {
      break;
    }
#ifdef _PNH_DEFINED
    _PNH pOldHandlerFn = ::_set_new_handler(0);
    ::set_new_handler(pOldHandlerFn);
    if (!pOldHandlerFn) {
      return NULL;
    }
    if (!(*pOldHandlerFn)(size)) {
      return NULL;
    }
#endif  // _PNH_DEFINED
  }
  return pNewMem;
}

TZ_FORCEINLINE
void TzHeapConfigurator::sMemoryFree(void* p, size_t size, TZUINT32 freeType) {
  ::VirtualFree(p, size, freeType);
}

TZ_FORCEINLINE
void TzHeapConfigurator::sInitPageFlags(TZBYTE pageFlags[kMaxPages]) {
#ifdef TZ_WINDOWS
  ::memset(pageFlags, kPrimary, kMaxPageId + 1);
  ::memset(pageFlags, kUnavailable, 0x0C);
  ::memset(pageFlags + 0x0330, kSecondary, 0x30);
  ::memset(pageFlags + 0x0600, kSecondary, 0x80);
  ::memset(pageFlags + 0x07F0, kSecondary, 0x10);
  ::memset(pageFlags + kMaxPageId, kUnavailable, kMaxPages - kMaxPageId);
#else
  memset(pageFlags, kPrimary, kMaxPageId + 1);
  memset(pageFlags, kUnavailable, 0x01);
#endif
}

TZ_FORCEINLINE
int TzHeapConfigurator::sGetPagePoolIndex(size_t size) {
  if (size & kBlockMask) {
    return 0;
  }
  return static_cast<int>((size >> kBlockBits));
}

TZ_FORCEINLINE
size_t TzHeapConfigurator::sGetSizeOfPagePool(int poolIndex) {
  return static_cast<size_t>((poolIndex << kBlockBits));
}

class TzHeapDbgDumper {
 public:
  static void init();
  static void uninit();
  static void dump(const void* p);
};

template <int TPoolCount, class TPoolConfigurator,
          class THeapConfigurator = TzHeapConfigurator,
          class TDbgDumper = TzHeapDbgDumper>
class TzHeap {
 public:
  enum {
    kPoolCount = TPoolCount,
  };

  using PoolCfg = TPoolConfigurator;
  using HeapCfg = THeapConfigurator;

  class Unit;
  class Block;
  class Page;
  class Pool;

  class Unit {
   public:
    Unit* nextUnit(size_t size) { return (Unit*)((TZADDRESS)this + size); }
    Unit* prevUnit(size_t size) { return (Unit*)((TZADDRESS)this - size); }
    Unit* next;
  };

  class Block {
   public:
    void pushBackTo(Block*& pTail) {
      prev = pTail;
      next = NULL;
      if (pTail != NULL) {
        pTail->next = this;
      }
      pTail = this;
    }

    void pushFrontTo(Block*& pHead) {
      next = pHead;
      prev = NULL;
      if (pHead != NULL) {
        pHead->prev = this;
      }
      pHead = this;
    }

    void popBackFrom(Block*& pTail) {
      if (next) {
        next->prev = prev;
      } else {
        pTail = prev;
      }

      if (prev) {
        prev->next = next;
      }
    }

    void popFrontFrom(Block*& pHead) {
      if (prev) {
        prev->next = next;
      } else {
        pHead = next;
      }

      if (next) {
        next->prev = prev;
      }
    }

    Block* nextBlock() const {
      return (Block*)((TZADDRESS)this + sizeof(Block));
    }

    int16_t blockId() const {
      TZADDRESS offset = (TZADDRESS)this;
      offset >>= HeapCfg::kBlksPerSectionBits;
      offset &= HeapCfg::kBlksPerPageMask;
      return (int16_t)offset;
    }

    int16_t parentPageId() const { return HeapCfg::sGetPageId(this); }

    Page* parentPage() const { return (Page*)(HeapCfg::sGetPageAddress(this)); }

    Unit* firstUnit() const {
      TZADDRESS offset = ((TZADDRESS)blockId()) << HeapCfg::kBlockBits;
      return (Unit*)((TZADDRESS)parentPage() + offset);
    }

    Unit* lastUnit(size_t size) const {
      TZADDRESS offset = ((TZADDRESS)blockId() + 1) << HeapCfg::kBlockBits;
      return (Unit*)((TZADDRESS)parentPage() + offset - size);
    }

    void* allocMem(size_t size) {
      void* pNew = static_cast<void*>(freeUnit);
      if (--freeCount == 0) {
        freeUnit = NULL;
      }
      if (freeUnit) {
        if (memoryFlag & HeapCfg::kAllocated) {
          freeUnit = freeUnit->next;
        } else {
          freeUnit = freeUnit->nextUnit(size);
        }
      }
      return pNew;
    }

    bool isFreeUnit(Unit* pUnit) const {
      for (Unit* pFreeUnit = freeUnit; pFreeUnit; pFreeUnit = pFreeUnit->next) {
        if (pUnit == pFreeUnit) {
          return true;
        }
        return false;
      }
    }

    void dump() const {
#ifdef TZ_MEM_DEBUG
      size_t unitSize = PoolCfg::sGetUnitSize(poolIndex);
      Unit* pUnit = firstUnit();
      Unit* pLastUnit = lastUnit(unitSize);
      for (; pUnit <= pLastUnit; pUnit = pUnit->nextUnit(unitSize)) {
        if (isFreeUnit(pUnit)) {
          continue;
        }
        TDbgDumper::dump(pUnit);
      }
#endif
    }

   public:
    Block* next = nullptr;
    Block* prev = nullptr;
    Unit* freeUnit = nullptr;
    int freeCount;
    TZUSHORT poolIndex;
    TZUSHORT memoryFlag;
  };

  class Page {
   public:
    Page* prevPage() const {
      return (
          Page*)(HeapCfg::sGetPageAddress(static_cast<int16_t>(prevPageId)));
    }
    Page* nextPage() const {
      return (
          Page*)(HeapCfg::sGetPageAddress(static_cast<int16_t>(nextPageId)));
    }

    void setPrevPage(Page* pPage) {
      prevPageId = HeapCfg::sGetPageId(pPage);
      if (pPage) {
        pPage->nextPageId = HeapCfg::sGetPageId(this);
      }
    }

    void setNextPage(Page* pPage) {
      nextPageId = HeapCfg::sGetPageId(pPage);
      if (pPage) {
        pPage->prevPageId = HeapCfg::sGetPageId(this);
      }
    }

    void pushBackTo(Page* pTail) {
      setPrevPage(pTail);
      setNextPage(NULL);
      pTail = this;
    }

    void pushFrontTo(Page*& pHead) {
      setNextPage(pHead);
      setPrevPage(NULL);
      pHead = this;
    }

    void popBackFrom(Page* pTail) {
      Page* pNextPage = nextPage();
      Page* pPrevPage = prevPage();
      if (pNextPage) {
        pTail = pPrevPage;
      } else {
        pTail = pPrevPage;
      }

      if (pNextPage) {
        pNextPage->setPrevPage(pPrevPage);
      }
    }

    void popFrontFrom(Page*& pHead) {
      Page* pPrevPage = prevPage();
      Page* pNextPage = nextPage();
      if (pPrevPage) {
        pPrevPage->setNextPage(pNextPage);
      } else {
        pHead = pNextPage;
      }
      if (pNextPage) {
        pNextPage->setPrevPage(pPrevPage);
      }
    }

    void initialize() {
      int offsetSize = sizeof(Page) / HeapCfg::kSectionBits;
      Block* pBlock = (Block*)((TZADDRESS)this + offsetSize * sizeof(Page));
      currBlock = pBlock;
      currBlockCount = HeapCfg::kBlksPerSectionMask - (offsetSize - 1);
      int i = currBlockCount - 1;
      do {
        i--;
        pBlock->next = pBlock->nextBlock();
        pBlock = pBlock->next;
      } while (i);
      pBlock->next = NULL;
      pBlock = pBlock->nextBlock();
      leftBlock = pBlock;
      leftBlockCount = HeapCfg::kBlksPerPageMask - HeapCfg::kBlksPerSectionMask;
      i = leftBlockCount - 1;
      do {
        i--;
        pBlock->next = pBlock->nextBlock();
        pBlock = pBlock->next;
      } while (i);
      pBlock->next = NULL;
    }

   public:
    Block* currBlock = nullptr;
    Block* leftBlock = nullptr;
    int nextPageId;
    int prevPageId;
    int currBlockCount;
    int leftBlockCount;
  };
  class Pool {
   public:
    explicit Pool(int nPoolIndex)
        : m_nUnitSize(0),
          m_nPoolIndex(nPoolIndex),
          m_nMaxUnitCount(0),
          m_pFreeBlock(NULL),
          m_pFullBlock(NULL) {
      if (nPoolIndex > 0) {
        m_nUnitSize = PoolCfg::sGetUnitSize(nPoolIndex);
      }
      if (m_nUnitSize > 0) {
        m_nMaxUnitCount = static_cast<int>(HeapCfg::kBlockSize / m_nUnitSize);
      }
    }

   public:
    TzSoft::Locker m_locker;
    size_t m_nUnitSize;
    int m_nPoolIndex;
    int m_nMaxUnitCount;
    Block* m_pFreeBlock = nullptr;
    Block* m_pFullBlock = nullptr;
  };

  class PageHeap {
   public:
    PageHeap()
        : poolIndex(0),
          memoryFlag(0),
          pageId(-1),
          freeCount(0),
          freeUnit(NULL),
          next(NULL),
          prev(NULL) {}

    void pushBackTo(PageHeap*& pTail) {
      prev = pTail;
      next = NULL;
      if (pTail != NULL) {
        pTail->next = this;
      }
    }

    void pushFronTo(PageHeap*& pHead) {
      next = pHead;
      prev = NULL;
      if (pHead != NULL) {
        pHead->prev = this;
      }
      pHead = this;
    }

    void popBackFrom(PageHeap*& pTail) {
      if (next) {
        next->prev = prev;
      } else {
        pTail = prev;
      }
      if (prev) {
        prev->next = next;
      }
    }

    void popFrontFrom(PageHeap*& pHead) {
      if (prev) {
        prev->next = next;
      } else {
        pHead = next;
      }
      if (next) {
        next->prev = prev;
      }
    }
    Unit* firstUnit() const {
      return static_cast<Unit*>((TZADDRESS)pageId << HeapCfg::kPageBits);
    }

    Unit* lastUnit(size_t size) const {
      return static_cast<Unit*>(
          ((TZADDRESS)(pageId + 1) << HeapCfg::kPageBits) - size);
    }

    void* allocMem(size_t size) {
      void* pNew = static_cast<void*>(freeUnit);
      if (--freeCount == 0) {
        freeUnit = NULL;
      }
      if (freeUnit) {
        if (memoryFlag & HeapCfg::kAllocated) {
          freeUnit = freeUnit->next;
        } else {
          freeUnit = freeUnit->nextUnit(size);
        }
      }
      return pNew;
    }

   public:
    int16_t poolIndex;
    int16_t memoryFlag;
    int16_t pageId;
    int16_t freeCount;
    Unit* freeUnit = nullptr;
    PageHeap* next = nullptr;
    PageHeap* prev = nullptr;
  };

  class PagePool {
   public:
    explicit PagePool(int nPoolIndex)
        : m_nUnitSize(0),
          m_nPoolIndex(nPoolIndex),
          m_nMaxUnitCount(0),
          m_pFreePageHeap(NULL),
          m_pFullPageHeap(NULL) {
      if (nPoolIndex > 0) {
        m_nUnitSize = HeapCfg::sGetSizeOfPagePool(nPoolIndex);
      }
      if (m_nUnitSize > 0) {
        m_nMaxUnitCount = static_cast<int>((HeapCfg::kPageSize / m_nUnitSize));
      }
    }

   public:
    TzSoft::Locker m_locker;
    size_t m_nUnitSize;
    int m_nPoolIndex;
    int m_nMaxUnitCount;
    PageHeap* m_pFreePageHeap = nullptr;
    PageHeap* m_pFullPageHeap = nullptr;
  };

 public:
  bool isPageAllocated(int16_t pageId) {
    return TZGETBIT(m_pageFlags[pageId - HeapCfg::mOffSetId],
                    HeapCfg::kAllocated);
  }

  void setPageAllocated(int16_t pageId, bool bAlloc = true) {
    TZSETBIT(m_pageFlags[pageId - HeapCfg::mOffSetId], HeapCfg::kAllocated,
             bAlloc);
  }

  bool isResident(void* p) {
    if (HeapCfg::sIsOutOfHeapRange(p)) {
      return false;
    }
    return isPageAllocated(HeapCfg::sGetPageId(p));
  }

  void* preallocPageHeap(int16_t fromPageId, int16_t toPageId,
                         TZBYTE pageFlag) {
    if (fromPageId <= toPageId || fromPageId > HeapCfg::kMaxPageId) {
      return NULL;
    }
    void* pNewPage = NULL;
    int16_t pageId = fromPageId;
    TZBYTE nPageFlag = HeapCfg::kPrimary;
    for (; pageId > toPageId; --pageId) {
      nPageFlag = m_pageFlags[pageId - HeapCfg::mOffSetId];
      if (nPageFlag == pageFlag) {
        LPVOID pAddress = (LPVOID)(HeapCfg::sGetPageAddress(pageId));
#ifdef TZ_WINDOWS
        pNewPage = VirtualAlloc(pAddress, HeapCfg::kPageSize, MEM_RESERVE,
                                PAGE_READWRITE);
#else
        pNewPage = pAddress;
#endif
        if (pNewPage) {
          break;
        }
      }
    }
    if (!pNewPage) {
      return NULL;
    }
    m_nFreePageId = (pageFlag == HeapCfg::kPrimary) ? (pageId - 1) : 0;
    setPageAllocated(pageId, true);
    return pNewPage;
  }

  void* preallocNewPage() {
    TZ_AUTOLOCK(&m_pageLocker);
    void* pNewPage = NULL;
    for (int i = 0; i < 6; ++i) {
      if (m_nFreePageId != 0) {
        pNewPage = preallocPageHeap(m_nFreePageId, 0, HeapCfg::kPrimary);
        if (pNewPage) {
          break;
        }
      }

      pNewPage = preallocPageHeap(HeapCfg::kMaxPageId, 0, HeapCfg::kPrimary);
      if (pNewPage) {
        break;
      }

      pNewPage = preallocPageHeap(HeapCfg::kMaxPageId, 0, HeapCfg::kSecondary);
      if (pNewPage) {
        break;
      }

#ifdef _PNH_DEFINED
      _PNH pOldHandlerFn = ::_set_new_handler(0);
      ::_set_new_handler(pOldHandlerFn);
      if (!pOldHandlerFn) {
        return NULL;
      }
      if (!(*pOldHandlerFn)(HeapCfg::kPageSize)) {
        return NULL;
      }
#endif
    }
    return pNewPage;
  }

  void* allocRawPage() {
    void* pNewPage = preallocNewPage();
    // TZ_ASSERT(pNewPage);
    if (!pNewPage) {
      return NULL;
    }
    void* pNewHeap = HeapCfg::tzMemoryCommit(pNewPage, HeapCfg::kPageSize);

    if (!pNewHeap) {
      return NULL;
    }

    // TZ_ASSERT(pNewHeap == pNewPage);
    return pNewHeap;
  }

  void freeRawPage(void* pPage) {
    TZ_AUTOLOCK(&m_pageLocker);
    int16_t pageId = HeapCfg::sGetPageId(pPage);
    setPageAllocated(pageId, false);
    if (pageId > m_nFreePageId) {
      m_nFreePageId = pageId;
    }
    HeapCfg::tzMemoryDeCommit(pPage, HeapCfg::kPageSize);
    HeapCfg::tzMemoryRelease(pPage, 0);
  }

  Page* allocPage() {
    Page* pNewPage = static_cast<Page*>(preallocNewPage());
    // TZ_ASSERT(pNewPage);
    if (!pNewPage) {
      return NULL;
    }
    void* pNewHeap = HeapCfg::tzMemoryCommit(pNewPage, HeapCfg::kSectionSize);
    if (!pNewHeap) {
      return NULL;
    }
    // TZ_ASSERT(pNewHeap == pNewPage);
    pNewPage->initialize();
    TZ_AUTOLOCK(&m_poolLocker);
    pNewPage->pushFrontTo(m_pFreePage);
    return pNewPage;
  }

  void freePage(Page* pPage) { freeRawPage(pPage); }

  Block* allocBlockFromPage(Page* pPage) {
    pPage->currBlockCount--;
    Block* pBlock = pPage->currBlock;
    pPage->currBlock = pBlock->next;
    if (pPage->currBlockCount == 0) {
      pPage->popFrontFrom(m_pFreePage);
      if (pPage->leftBlockCount > 0) {
        pPage->pushFrontTo(m_pFullPage);
      }
    }
    return pBlock;
  }

  void reallocBlockFromPage(Page* pPage) {
    int nTotalCount = TZMIN(pPage->leftBlockCount, HeapCfg::kMaxBlksPerSection);
    Block* pBlock = pPage->leftBlock;
    int nFreeCount = 1;
    for (; pBlock && (nFreeCount < nTotalCount); ++nFreeCount) {
      Block* pNext = pBlock->nextBlock();
      if (pBlock->next != pNext) {
        break;
      }
      pBlock = pNext;
    }
    void* pAddress = NULL;
    if (pPage->leftBlock) {
      pAddress = static_cast<void*>(pPage->leftBlock->firstUnit());
    }

    TZADDRESS nSize = ((TZADDRESS)nFreeCount) << HeapCfg::kBlockBits;
    void* pNewMem = NULL;
    if (pAddress) {
      pNewMem = HeapCfg::tzMemoryCommit(pAddress, nSize);
    }

    // TZ_ASSERT(pNewMem);
    if (pNewMem) {
      pPage->currBlock = pPage->leftBlock;
      pPage->currBlockCount = nFreeCount;
      pPage->leftBlock = pBlock->next;
      pBlock->next = NULL;
      pPage->leftBlockCount -= nFreeCount;
    }

    pPage->popBackFrom(m_pFullPage);
    pPage->pushFrontTo(m_pFreePage);
  }

  void deallocBlockFromPage(Block* pBlock, Page* pPage) {
    pBlock->next = pPage->currBlock;
    pBlock->poolIndex = 0;
    pPage->currBlockCount++;
    pPage->currBlock = pBlock;
    if (pPage->currBlockCount == 1) {
      if (pPage->leftBlockCount > 0) {
        pPage->popBackFrom(m_pFullPage);
      }
      pPage->pushFrontTo(m_pFreePage);
    }
  }

  void freeBlockFromPage(Block* pBlock, Page* pPage) {
    pBlock->next = pPage->leftBlock;
    pBlock->poolIndex = 0;
    pPage->leftBlockCount++;
    pPage->leftBlock = pBlock;
    HeapCfg::tzMemoryDeCommit(pBlock->firstUnit(), HeapCfg::kBlockSize);
  }

  Block* allocBlock() {
    TZ_AUTOLOCK(&m_poolLocker);
    Page* pPage = m_pFreePage;
    if (!pPage) {
      pPage = m_pFullPage;
      if (!pPage) {
        pPage = allocPage();
        if (!pPage) {
          return NULL;
        } else {
          reallocBlockFromPage(pPage);
        }
      }
    }
    return allocBlockFromPage(pPage);
  }

  void freeBlock(Block* pBlock) {
    TZ_AUTOLOCK(&m_poolLocker);
    Page* pPage = pBlock->parentPage();
    if (pPage->currBlockCount >= 0x10) {
      if ((pPage->currBlockCount + pPage->leftBlockCount !=
           (HeapCfg::kBlksPerPageMask - 1)) ||
          (m_pFullPage == NULL && m_pFreePage == pPage)) {
        freeBlockFromPage(pBlock, pPage);
      } else {
        pPage->popBackFrom(m_pFreePage);
        ;
        freePage(pPage);
      }
    } else {
      deallocBlockFromPage(pBlock, pPage);
    }
  }

  void* reallocFromPool(Pool* pPool) {
    Block* pBlock = pPool->m_pFreeBlock;
    if (pBlock == NULL) {
      pBlock = allocBlock();
      if (!pBlock) {
        return NULL;
      }
      pBlock->pushFrontTo(pPool->m_pFreeBlock);
      pBlock->poolIndex = (TZBYTE)pPool->m_nPoolIndex;
      pBlock->freeUnit = pBlock->firstUnit();
      pBlock->memoryFlag &= ~HeapCfg::kAllocated;
      pBlock->freeCount = (int16_t)pPool->m_nMaxUnitCount;
    }

    if (pBlock->freeCount == 1) {
      pBlock->popFrontFrom(pPool->m_pFreeBlock);
      pBlock->pushFrontTo(pPool->m_pFullBlock);
    }
    return pBlock->allocMem(pPool->m_nUnitSize);
  }

  void* allocFromPool(Pool* pPool) {
    TZ_AUTOLOCK(&pPool->m_locker);
    void* pNew = NULL;
    if (pPool->m_pFreeBlock == NULL ||
        pPool->m_pFreeBlock->memoryFlag & HeapCfg::kAllocated ||
        pPool->m_pFreeBlock->freeCount <= 1) {
      pNew = reallocFromPool(pPool);
    } else {
      pPool->m_pFreeBlock->freeCount--;
      pNew = pPool->m_pFreeBlock->freeUnit;
      pPool->m_pFreeBlock->freeUnit =
          pPool->m_pFreeBlock->freeUnit->nextUnit(pPool->m_nUnitSize);
    }
    return pNew;
  }

  void freeFromPool(void* p, Pool* pPool) {
    TZ_AUTOLOCK(&pPool->m_locker);
    Block* pBlock = (Block*)(HeapCfg::sGetBlockAddress(p));
    pBlock->freeCount++;
    if (pBlock->freeCount == pPool->m_nMaxUnitCount) {
      if (pBlock->freeCount == 1) {
        pBlock->popFrontFrom(pPool->m_pFullBlock);
      } else {
        pBlock->popFrontFrom(pPool->m_pFreeBlock);
      }
      freeBlock(pBlock);
    } else {
      TZADDRESS nAddress = (TZADDRESS)p;
      TZADDRESS nBase = (TZADDRESS)pBlock->firstUnit();
      if (pBlock->freeCount == 1) {
        pBlock->popFrontFrom(pPool->m_pFullBlock);
        pBlock->pushFrontTo(pPool->m_pFreeBlock);
        TZADDRESS nOffset =
            (TZADDRESS)((pPool->m_nMaxUnitCount - 1) * pPool->m_nUnitSize);
        if (nAddress == nBase + nOffset) {
          pBlock->memoryFlag &= ~HeapCfg::kAllocated;
        } else {
          pBlock->memoryFlag |= HeapCfg::kAllocated;
          ((Unit*)nAddress)->next = NULL;
        }
      } else {
        if (pBlock->memoryFlag & HeapCfg::kAllocated) {
          ((Unit*)nAddress)->next = pBlock->freeUnit;
        } else if (nAddress !=
                   (TZADDRESS)pBlock->freeUnit->prevUnit(pPool->m_nUnitSize)) {
          ((Unit*)nAddress)->next = pBlock->freeUnit;
          Unit* pLastUnit = pBlock->lastUnit(pPool->m_nUnitSize);
          Unit* pUnit = pBlock->freeUnit;
          for (; pUnit < pLastUnit; pUnit = pUnit->next) {
            pUnit->next = pUnit->nextUnit(pPool->m_nUnitSize);
          }
          pUnit->next = NULL;
          pBlock->memoryFlag |= HeapCfg::kAllocated;
        }
      }
      pBlock->freeUnit = (Unit*)p;
    }
  }

  void* allocHeap(size_t size) {
    if (size == 0) {
      size = 1;
    }
    Pool* pPool = m_pools[PoolCfg::sGetPoolIndex(size)];
    if (!pPool) {
      return ::malloc(size);
    }
    void* pNewMem = allocFromPool(pPool);
    if (!pNewMem) {
      return ::malloc(size);
    }
    return pNewMem;
  }

  void* reallocHeap(void* p, size_t newSize) {
    if (!isResident(p)) {
      return ::realloc(p, newSize);
    }
    if (newSize == 0) {
      newSize = 1;
    }
    void* pNewMem = allocHeap(newSize);
    if (!pNewMem) {
      return NULL;
    }
    Block* pBlock = (Block*)HeapCfg::sGetBlockAddress(p);
    // TZ_ASSERT(pBlock);
    ::memcpy(pNewMem, p,
             TZMIN(newSize, PoolCfg::sGetUnitSize(pBlock->poolIndex)));

    Pool* pPool = m_pools[pBlock->poolIndex];
    if (pPool) {
      freeFromPool(p, pPool);
    }

    return pNewMem;
  }

  void freeHeap(void* p) {
    if (!isResident(p)) {
      ::free(p);
      return;
    }
    if (m_bFreeDelay) {
      return;
    }
    Block* pBlock = (Block*)HeapCfg::sGetBlockAddress(p);
    // TZ_ASSERT(pBlock);
    Pool* pPool = m_pools[pBlock->poolIndex];
    if (pPool) {
      freeFromPool(p, pPool);
    }
  }

  size_t sizeOfHeap(void* p) {
    if (!isResident(p)) {
#ifdef TZ_WINDOWS
      return ::_msize(p);
#else
#warning "not implement yet!!!"
      MPD_FAIL_ONCE();
#endif
      Block* pBlock = (Block*)HeapCfg::sGetBlockAddress(p);
      // TZ_ASSERT(pBlock);
      return PoolCfg::sGetUnitSize(pBlock->poolIndex);
    }
  }

  void createPool(int poolIndex) {
    m_pools[poolIndex] = new Pool(poolIndex);
    // TZ_ASSERT(m_pools[poolIndex]);
  }

  void releasePool(int poolIndex) {
    Block* pBlock = m_pools[poolIndex]->m_pFreeBlock;
    Block* pBlkToFree = NULL;

    while (pBlock) {
      pBlock->dump();
      pBlkToFree = pBlock;
      pBlock = pBlock->next;
      freeBlock(pBlkToFree);
    }

    pBlock = m_pools[poolIndex]->m_pFullBlock;
    while (pBlock) {
      pBlock->dump();
      pBlkToFree = pBlock;
      pBlock = pBlock->next;
      freeBlock(pBlkToFree);
    }
    delete m_pools[poolIndex];
    m_pools[poolIndex] = NULL;
  }

  PageHeap* getPageHeap(void* p) {
    TZ_AUTOLOCK(&m_pagePoolLocker);
    int16_t nPageId = HeapCfg::sGetPageId(p);
    // TZ_ASSERT(nPageId >= 0 && nPageId < 2048);
    PageHeap* pPage = &m_pageHeaps[nPageId];
    // TZ_ASSERT(pPage->pageId == nPageId);
    return pPage;
  }

  PageHeap* allocPageHeap() {
    void* p = allocRawPage();
    // TZ_ASSERT(p);
    if (!p) {
      return NULL;
    }
    TZ_AUTOLOCK(&m_pagePoolLocker);
    int16_t nPageId = HeapCfg::sGetPageId(p);
    // TZ_ASSERT(nPageId >= 0 && nPageId < 2048);
    PageHeap* pPage = &m_pageHeaps[nPageId];
    // TZ_ASSERT(pPage->pageId == -1);
    pPage->pageId = nPageId;
    return pPage;
  }

  void freePageHeap(PageHeap* pPage) {
    TZ_AUTOLOCK(&m_pagePoolLocker);

    // TZ_ASSERT(pPage);
    // TZ_ASSERT(pPage->pageId >= 0 && pPage->pageId < 2043);
    freeRawPage((void*)HeapCfg::sGetPageAddress(pPage->pageId));
    pPage->pageId = -1;
  }

  void* reallocFromPagePool(PagePool* pPagePool) {
    PageHeap* pPage = pPagePool->m_pFreePageHeap;
    if (pPage == NULL) {
      pPage = allocPageHeap();
      if (!pPage) {
        return NULL;
      }
      pPage->pushFronTo(pPagePool->m_pFreePageHeap);
      pPage->poolIndex = (int16_t)pPagePool->m_nPoolIndex;
      pPage->memoryFlag &= ~HeapCfg::kAllocated;
      pPage->freeCount = (int16_t)pPagePool->m_nMaxUnitCount;
    }

    if (pPage->freeCount == 1) {
      pPage->popFrontFrom(pPagePool->m_pFreePageHeap);
      pPage->pushFronTo(pPagePool->m_pFullPageHeap);
    }
    return pPage->allocMem(pPagePool->m_nUnitSize);
  }

  void* allocFromPagePool(PagePool* pPagePool) {
    TZ_AUTOLOCK(&pPagePool->m_locker);
    void* pNew = NULL;
    if (pPagePool->m_pFreePageHeap == NULL ||
        pPagePool->m_pFreePageHeap->memoryFlag & HeapCfg::kAllocated ||
        pPagePool->m_pFreePageHeap->freeCount <= 1) {
      pNew = reallocFromPagePool(pPagePool);
    } else {
      pPagePool->m_pFreePageHeap->freeCount--;
      pNew = pPagePool->m_pFreePageHeap->freeUnit;
      pPagePool->m_pFreePageHeap->freeUnit =
          pPagePool->m_pFreePageHeap->freeUnit->nextUnit(
              pPagePool->m_nUnitSize);
    }
    return pNew;
  }

  void freeFromPagePool(void* p, PagePool* pPagePool) {
    TZ_AUTOLOCK(&pPagePool->m_locker);
    PageHeap* pPage = getPageHeap(p);
    pPage->freeCount++;
    if (pPage->freeCount == pPagePool->m_nMaxUnitCount) {
      if (pPage->freeCount == 1) {
        pPage->popFrontFrom(pPagePool->m_pFullPageHeap);
      } else {
        pPage->popFrontFrom(pPagePool->m_pFreePageHeap);
      }
      freePageHeap(pPage);
    } else {
      TZADDRESS nAddress = (TZADDRESS)p;
      TZADDRESS nBase = (TZADDRESS)pPage->firstUnit();
      if (pPage->freeCount == 1) {
        pPage->popFrontFrom(pPagePool->m_pFullPageHeap);
        pPage->pushFronTo(pPagePool->m_pFreePageHeap);
        TZADDRESS nOffset = (TZADDRESS)((pPagePool->m_nMaxUnitCount - 1) *
                                        pPagePool->m_nUnitSize);
        if (nAddress == nBase + nOffset) {
          pPage->memoryFlag &= ~HeapCfg::kAllocated;
        } else {
          pPage->memoryFlag |= HeapCfg::kAllocated;
          ((Unit*)nAddress)->next = NULL;
        }
      } else {
        if (pPage->memoryFlag & HeapCfg::kAllocated) {
          ((Unit*)nAddress)->next = pPage->freeUnit;
        } else if (nAddress != (TZADDRESS)pPage->freeUnit->prevUnit(
                                   pPagePool->m_nUnitSize)) {
          ((Unit*)nAddress)->next = pPage->freeUnit;
          Unit* pLastUnit = pPage->lastUnit(pPagePool->m_nUnitSize);
          Unit* pUnit = pPage->freeUnit;
          for (; pUnit < pLastUnit; pUnit = pUnit->next) {
            pUnit->next = pUnit->nextUnit(pPagePool->m_nUnitSize);
          }
          pUnit->next = NULL;
          pPage->memoryFlag |= HeapCfg::kAllocated;
        }
      }
      pPage->freeUnit = (Unit*)p;
    }
  }

  void* allocHeapPage(size_t size) {
    if (size == 0) {
      size = 1;
    }
    PagePool* pPagePool = m_pagePools[HeapCfg::sGetPagePoolIndex(size)];
    if (!pPagePool) {
      return ::malloc(size);
    }
    void* pNewMem = allocFromPagePool(pPagePool);
    if (!pNewMem) {
      return ::malloc(size);
    }
    return pNewMem;
  }

  void* reallocHeapPage(void* p, size_t newSize) {
    if (!HeapCfg::sIsResident(p)) {
      return ::realloc(p, newSize);
    }
    if (newSize == 0) {
      newSize = 1;
    }
    void* pNewMem = allocPageHeap(newSize);
    if (!pNewMem) {
      return NULL;
    }
    PageHeap* pPageHeap = getPageHeap(p);
    // TZ_ASSERT(pPageHeap);
    ::memcpy(pNewMem, p,
             TZMIN(newSize, HeapCfg::sGetSizeOfPagePool(pPageHeap->poolIndex)));
    PagePool* pPagePool = m_pagePools[pPageHeap->poolIndex];
    if (pPagePool) {
      freeFromPagePool(p, pPagePool);
    }
    return pNewMem;
  }

  void freeHeapPage(void* p) {
    if (!isResident(p)) {
      ::free(p);
      return;
    }
    if (m_bFreeDelay) {
      return;
    }
    PageHeap* pPageHeap = getPageHeap(p);
    // TZ_ASSERT(pPageHeap);
    PagePool* pPagePool = m_pagePools[pPageHeap->poolIndex];
    if (pPagePool) {
      freeFromPagePool(p, pPagePool);
    }
  }

  size_t sizeOfHeapPage(void* p) {
    if (!isResident(p)) {
#ifdef TZ_WINDOWS
      return ::_msize(p);
#else
#warning "not implement yet"
      MPD_FAIL_ONCE();
#endif
      PageHeap* pPageHeap = getPageHeap(p);
      // TZ_ASSERT(pPageHeap);
      return HeapCfg::sGetSizeOfPagePool(pPageHeap->poolIndex);
    }
  }

  void createPagePool(int poolIndex) {
    m_pagePools[poolIndex] = new PagePool(poolIndex);
    // TZ_ASSERT(m_pagePools[poolIndex]);
  }

  void releasePagePool(int poolIndex) {
    PageHeap* pPage = m_pagePools[poolIndex]->m_pFreePageHeap;
    PageHeap* pPageToFree = NULL;
    while (pPage) {
      pPageToFree = pPage;
      pPage = pPage->next;
      freePageHeap(pPageToFree);
    }
    delete m_pagePools[poolIndex];
    m_pagePools[poolIndex] = NULL;
  }

  bool isFreeDelayEnabled() const { return m_bFreeDelay; }

  void enableFreeDelay() { m_bFreeDelay = true; }

  void disableFreeDelay() { m_bFreeDelay = false; }

  void setFreeDelay(bool flag) { m_bFreeDelay = flag; }

  void initPageFlags() { HeapCfg::sInitPageFlags(m_pageFlags); }

  TzHeap()
      : m_pFreePage(NULL),
        m_pFullPage(NULL),
        m_nFreePageId(HeapCfg::kFirstFreePageId),
        m_bFreeDelay(false) {
    initPageFlags();
#ifndef TZ_WINDOWS
    size_t memSize = 0x200000000;
    HeapCfg::pStartAddress = HeapCfg::tzMemoryInitialize(memSize);
    HeapCfg::mOffSetId = HeapCfg::sGetPageId(HeapCfg::pStartAddress);
    m_nFreePageId = (HeapCfg::kMaxPageId + 1) / 2;
#endif
    m_pools[0] = NULL;
    for (int i = 1; i <= kPoolCount; ++i) {
      createPool(i);
    }
    m_pagePools[0] = NULL;
    for (int j = 1; j <= HeapCfg::kMaxBlksPerPage; ++j) {
      createPool(j);
    }
  }

  ~TzHeap() {
#if defined(TZ_MEM_DBG)
    TDbgDumper::init();
#endif
    for (int i = 1; i <= kPoolCount; ++i) {
      releasePool(i);
    }
    for (int j = 1; j <= HeapCfg::kMaxBlksPerPage; ++j) {
      releasePagePool(j);
    }
#if defined(TZ_MEM_DBG)
    TDbgDumper::uninit();
#endif
  }

 private:
  TzSoft::Locker m_pageLocker;
  TzSoft::Locker m_poolLocker;
  TzSoft::Locker m_pagePoolLocker;
  Pool* m_pools[kPoolCount + 1];
  Page* m_pFreePage;
  Page* m_pFullPage;
  PagePool* m_pagePools[HeapCfg::kMaxBlksPerPage + 1];
  PageHeap m_pageHeaps[HeapCfg::kMaxPages];
  volatile int16_t m_nFreePageId;
  TZBYTE m_pageFlags[HeapCfg::kMaxPages];
  bool m_bFreeDelay;
  bool m_bOutOfPage;
};

using TzGlobalHeap = TzHeap<34, TzPoolConfigurator<34> >;
extern TzGlobalHeap g_tzGlobalHeap;

#endif

#endif  // SOURCE_BASIC_ROOT_INC_ROOT_WIN64_MEM_POOL_H_
