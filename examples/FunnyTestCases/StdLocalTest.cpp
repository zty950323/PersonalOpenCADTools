///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "StdLocalTest.h"
#include <math.h>
#include <cmath>
#include "../Platform/inc/zsofts_types.h"
#include <QDebug>

void StdLocalTest::testSqrtDoubleMax(void)
{
    TZDOUBLE num = DBL_MAX;
    TZDOUBLE dx = std::sqrt(num);
    TZDOUBLE x = dx * dx;
    TZBOOL ret = x == num;
    qDebug() << num << "\t" << dx << "\t" << x << "\t" << ret;
}
