///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <QtCore/QCoreApplication>
#include "StdLocalTest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    StdLocalTest::testSqrtDoubleMax();
    return a.exec();
}
