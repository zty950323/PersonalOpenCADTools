///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_builder_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

TzDirector::TzDirector(TzBuilder* pBuilder)
	: m_pBuilder(pBuilder)
{

}

TzDirector::~TzDirector()
{
	delete m_pBuilder;
	m_pBuilder = nullptr;
}

void TzDirector::Construct()
{
	m_pBuilder->builderPartA();
	m_pBuilder->builderPartB();
}

void TzConcreateBuilder1::builderPartA()
{
	qDebug() << "BuilderPartA by ConcreateBuilder1";
}

void TzConcreateBuilder1::builderPartB()
{
	qDebug() << "BuilderPartB by ConcreateBuilder1";
}

void TzConcreateBuilder2::builderPartA()
{
	qDebug() << "BuilderPartA by ConcreateBuilder2";
}

void TzConcreateBuilder2::builderPartB()
{
	qDebug() << "BuilderPartB by ConcreateBuilder2";
}

TZ_NAMESPACE_END(TzSoft)