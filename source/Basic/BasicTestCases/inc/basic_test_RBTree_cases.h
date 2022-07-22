///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_TEST_RBTREE_CASES_H_
#define _BASIC_TEST_RBTREE_CASES_H_

#include "DataStructure/basic_RBTree.h"
#include "DesignPatternTools/basic_open_singleTon.h"

namespace Basic {
class TzBasicRBTreeTestCases : public TzSingleTon<TzBasicRBTreeTestCases> {
  friend class TzSingleTon<TzBasicRBTreeTestCases>;

  TzBasicRBTreeTestCases() {}

  ~TzBasicRBTreeTestCases() {}

  bool runAllTestCases();
  bool runAllCommonTests();
  bool runSomeCertainTests();
  std::string printTrees(void) const;

 private:
  void initRandomData();
  void initCertainData();
  void clearData();

 private:
  TzRBTree<int> m_intTree;
  TzRBTree<float> m_floatTree;
  TzRBTree<double> m_doubleTree;
  TzRBTree<short> m_shortTree;
  TzRBTree<unsigned int> m_uintTree;
  TzRBTree<long> m_longTree;
};
}  // namespace Basic

#endif  // !_BASIC_TEST_RBTREE_CASES_H_