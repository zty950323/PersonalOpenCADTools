///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_COMMAND_PATTERN_H_H_
#define _BASIC_COMMAND_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TzCommand 
{
public:
	virtual ~TzCommand()
	{

	}

	virtual void execute() = 0;
};

class TzReceiver
{
public:
	void action();
};

class TzInvoker
{
public:
	TzInvoker(TzCommand* pCommand);
	~TzInvoker();

	void invoke();

private:
	TzCommand* m_pCommand = { nullptr };
};

class TzConcreateCommand : public TzCommand
{
public:
	TzConcreateCommand(TzReceiver* pReceiver);
	virtual ~TzConcreateCommand();

	virtual void execute();

private:
	TzReceiver* m_pReceiver = { nullptr };
};

TZ_NAMESPACE_END(TzSoft)

#endif