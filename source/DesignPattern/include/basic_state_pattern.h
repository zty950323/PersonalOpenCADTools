///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_STATE_PATTERN_H_H_
#define _BASIC_STATE_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TzState;

class TzStateContext
{
public:
	TzStateContext(TzState* pState);
	~TzStateContext();
	void request();
	void changeState(TzState* pState);

private:
	TzState* m_pState;
};

class TzState
{
public:
	virtual ~TzState()
	{

	}

	virtual void handle(TzStateContext* pContext) = 0;
};

class TzConcreateStateA : public TzState
{
public:
	void handle(TzStateContext* pContext) override;
};

class TzConcreateStateB : public TzState
{
public:
	void handle(TzStateContext* pContext) override;
};

TZ_NAMESPACE_END(TzSoft)

#endif