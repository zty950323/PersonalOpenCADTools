///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "gui_tools_drawhelpers.h"

#include <QtCore/QVector>

#ifndef _GUI_DRAWHELPERS_UNIT_TEST_H_
#define _GUI_DRAWHELPERS_UNIT_TEST__H_

TZ_NAMESPACE_BEGIN(TZSofts)

class TzDrawHelpersUnitTest 
{
public:
	TzDrawHelpersUnitTest(void);
	TzDrawHelpersUnitTest(QVector<QPair<qreal, qreal>> data);
	~TzDrawHelpersUnitTest();

	qreal addTestData(qreal data, qreal result);
	bool testWithCertainResult(qreal data, qreal result);

	QVector<qreal> initRandomTestData(int itemNumber);
	
private:
	void testAll(void);

private :
	QVector<QPair<qreal, qreal>> m_testData;
};

TZ_NAMESPACE_END(TZSofts)

#endif