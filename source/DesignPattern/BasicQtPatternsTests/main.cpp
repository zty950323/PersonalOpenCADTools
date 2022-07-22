///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_factory_pattern_ctests.h"
#include "basic_abstract_factory_pattern_ctests.h"
#include "basic_builder_pattern_ctests.h"
#include "basic_prototype_pattern_ctests.h"
#include "basic_singleton_pattern_ctests.h"
#include "basic_adapter_pattern_ctests.h"
#include "basic_bridge_pattern_ctests.h"
#include "basic_composite_pattern_ctests.h"
#include "basic_decorator_pattern_ctests.h"
#include "basic_proxy_pattern_ctests.h"
#include "basic_template_method_pattern_ctests.h"
#include "basic_chain_of_responsibility_pattern_ctests.h"
#include "basic_flyweight_pattern_ctests.h"
#include "basic_command_pattern_ctests.h"
#include "basic_observer_pattern_ctests.h"
#include "basic_strategy_pattern_ctests.h"
#include "basic_state_pattern_ctests.h"
#include "basic_iterator_pattern_ctests.h"
#include "basic_memento_pattern_ctests.h"
#include "basic_visitor_pattern_ctests.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

void testQStringTr()
{
	QString str("Hello , this is a test.");
	qDebug() << QObject::tr(str.toStdString().c_str());
}

void testPFunc(int* p)
{
	delete p;
	p = nullptr;
}

void testDeleteOut()
{
	int* p = new int;
	*p = 10;
	qDebug() << p << "\t" << *p;
	testPFunc(p);
	// delete p;
	qDebug() << p << "\t" << *p;
	*p = 20;
	qDebug() << p << "\t" << *p;
}

typedef struct TestUsing
{
	int m_a = { 0 };
	int m_b = { 1 };

	float m_f = { 0.0f };
} UTest, UTT;

using UsingTT = struct TestU
{
	int m_a = { 0 };
	int m_b = { 1 };

	float m_f = { 0.0f };
};

void testUsingPrint(void)
{
	UsingTT tt;
	UTest ut;
	qDebug() << tt.m_a << '\t' << tt.m_b << '\t' << tt.m_f;

	qDebug() << ut.m_a << '\t' << ut.m_b << '\t' << ut.m_f;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#if 1
    qDebug() << "This is the Factory Pattern Tests:";
    TzSoftTest::TzFactoryTest::testCase_01();

    qDebug() << "This is the Abstract Factory Pattern Tests:";
    TzSoftTest::TzAbstractFactoryTest::testCase_01();

    qDebug() << "This is the Builder Pattern Tests:";
    TzSoftTest::TzBuilderTest::testCase_01();

    qDebug() << "This is the Prototype Pattern Tests:";
    TzSoftTest::TzPrototypeTest::testCase_01();

	qDebug() << "This is the Singleton Pattern Tests:";
	TzSoftTest::TzSingletonTest::testCase_01();

    qDebug() << "This is the Adapter01 Pattern Tests:";
    TzSoftTest::TzAdapter01Test::testCase_01();

	qDebug() << "This is the Bridge Pattern Tests:";
	TzSoftTest::TzBridgeTest::testCase_01();

	qDebug() << "This is the Composite Pattern Tests:";
	TzSoftTest::TzCompositeTest::testCase_01();

	qDebug() << "This is the Decorator Pattern Tests:";
	TzSoftTest::TzDecoratorTest::testCase_01();

	qDebug() << "This is the Proxy Pattern Tests:";
	TzSoftTest::TzProxyTest::testCase_01();

	qDebug() << "This is the Template Method Pattern Tests:";
	TzSoftTest::TzTemplateMethodTest::testCase_01();

	qDebug() << "This is the Chain of Responsibility Pattern Tests:";
	TzSoftTest::TzChainOfResponsibilityTest::testCase_01();

	qDebug() << "This is the Flyweight Pattern Tests:";
	TzSoftTest::TzFlyweightTest::testCase_01();

	qDebug() << "This is the Command Pattern Tests:";
	TzSoftTest::TzCommandTest::testCase_01();

	qDebug() << "This is the Observer Pattern Tests:";
	TzSoftTest::TzObserverTest::testCase_01();

	qDebug() << "This is the Strategy Pattern Tests:";
	TzSoftTest::TzStrategyTest::testCase_01();

	qDebug() << "This is the State Pattern Tests:";
	TzSoftTest::TzStateTest::testCase_01();

	qDebug() << "This is the Iterator Pattern Tests:";
	TzSoftTest::TzIteratorTest::testCase_01();

	qDebug() << "This is the Memento Pattern Tests:";
	TzSoftTest::TzMementoTest::testCase_01();

	qDebug() << "This is the Visitor Pattern Tests:";
	TzSoftTest::TzVisitorTest::testCase_01();


	testDeleteOut();
	testUsingPrint();
#endif
	testQStringTr();
    return a.exec();
}