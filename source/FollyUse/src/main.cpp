///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "FollyArenaTest.h"

#include <folly/futures/Future.h>

#include <folly/AtomicLinkedList.h>

using namespace folly;
using namespace std;

void foo(int x) {
    // do something with x
    cout << "foo(" << x << ")" << endl;
}

void testFuture(void)
{
    cout << "making Promise" << endl;
    Promise<int> p;
    Future<int> f = p.getFuture();
    // f.then(foo);
    cout << "Future chain made" << endl;
    // ... now perhaps in another event callback

    cout << "fulfilling Promise" << endl;
    p.setValue(42);
    cout << "Promise fulfilled" << endl;
}

void useLinkedList()
{
    AtomicLinkedList<int> list;
    list.insertHead(200);
    for (int i = 0; i < 100; ++i)
    {
        list.insertHead(i);
    }
}

int main(int argc, char *argv[])
{
    /* code */
    testFuture();
    cout << "Hello Folly!" << endl;
    return TzFollyArenaTestCase::runAllCases(argc, argv);
}