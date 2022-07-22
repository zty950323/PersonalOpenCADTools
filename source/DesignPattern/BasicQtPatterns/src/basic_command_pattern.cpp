///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_command_pattern.h"

#include <QtCore/QDebug>

TZ_NAMESPACE_BEGIN(TzSoft)

void TzReceiver::action()
{
	qDebug() << "Receiver action";
}

TzInvoker::TzInvoker(TzCommand* pCommand)
	: m_pCommand(pCommand)
{

}

TzInvoker::~TzInvoker()
{
	delete m_pCommand;
	m_pCommand = nullptr;
}

void TzInvoker::invoke()
{
	if (nullptr != m_pCommand)
	{
		m_pCommand->execute();
	}
}

TzConcreateCommand::TzConcreateCommand(TzReceiver* pReceiver)
	: m_pReceiver(pReceiver)
{

}

TzConcreateCommand::~TzConcreateCommand()
{
	delete m_pReceiver;
	m_pReceiver = nullptr;
}

void TzConcreateCommand::execute()
{
	if (nullptr != m_pReceiver)
	{
		m_pReceiver->action();
	}

	qDebug() << "Execute by ConcreateComand";
}

TZ_NAMESPACE_END(TzSoft)