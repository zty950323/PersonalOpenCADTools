/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#if (TZ_PLATFORM == TZ_PLATFORM_WINDOWS) && \
    (TZ_ARCHITECURE_BIT == TZ_ARCHITECTURE_BIT64)

#include "root_win64_mem_pool.h"

#include "zsofts_types.h"

#pragma init_seg(lib)

const TZBYTE TzPoolConfigurator<34>::s_poolIndexOfSize[257] = {
    0x00, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1d, 0x1d, 0x1d,
    0x1d, 0x1d, 0x1d, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c,
    0x1c, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1a, 0x1a, 0x1a,
    0x1a, 0x1a, 0x1a, 0x1a, 0x1a, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19, 0x19,
    0x19, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x17, 0x17, 0x17,
    0x17, 0x17, 0x17, 0x17, 0x17, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16, 0x16,
    0x16, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x14, 0x14, 0x14,
    0x14, 0x14, 0x14, 0x14, 0x14, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
    0x13, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x12, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0e, 0x0e,
    0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x0d,
    0x0d, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0b, 0x0b, 0x0b,
    0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a,
    0x0a, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x05,
};

const int16_t TzPoolConfigurator<34>::s_unitSizeOfPools[35] = {
    0x0000, 0x0200, 0x0400, 0x0800, 0x1000, 0x0100, 0x00f0, 0x00e0, 0x00d0,
    0x00c8, 0x00c0, 0x00b8, 0x00b0, 0x00a8, 0x00a0, 0x0098, 0x0090, 0x0088,
    0x0080, 0x0078, 0x0070, 0x0068, 0x0060, 0x0058, 0x0050, 0x0048, 0x0040,
    0x0038, 0x0030, 0x0028, 0x0020, 0x0018, 0x0010, 0x0008};

#if defined(TZ_MEM_DBG)

void TzHeapDbgDumper::init() {
  // Not implemented yet.
}

void TzHeapDbgDumper::uninit() {
  // Not implemented yet.
}

void TzHeapDbgDumper::dump(const void* p) {
  // Not implemented yet.
}

#endif  // #if defined(TZ_MEM_DBG)

int16_t TzHeapConfigurator::mOffSetId = 0;
void* TzHeapConfigurator::pStartAddress = 0;
TzGlobalHeap g_tzGlobalHeap;

#endif