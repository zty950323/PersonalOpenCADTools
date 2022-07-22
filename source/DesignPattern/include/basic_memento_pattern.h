///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_MEMENTO_PATTERN_H_H_
#define _BASIC_MEMENTO_PATTERN_H_H_

#include "zsofts_compiler_specific.h"

#include <string>

TZ_NAMESPACE_BEGIN(TzSoft)

using State = std::string;

class TzMemento;

class TzOriginator
{
public:
	TzOriginator(const State& rState);
	TzOriginator();
	~TzOriginator();

	TzMemento* createMemento();
	void setMemento(TzMemento* pMemento);
	State getState() const;
	void setState(const State& rState);
	void restoreState(TzMemento* pMemento);
	void printState() const;

private:
	State m_state;
};

// �� Memento �Ľӿں���������Ϊ˽�е�,�� Originator ��������Ԫ, 
// ������֤��ֻ�� Originator ���Զ������
class TzMemento
{
private:
	friend class TzOriginator;
	TzMemento(const State& rState);
	void setState(const State& rState);
	State getState() const;

	State m_state;
};

TZ_NAMESPACE_END(TzSoft)

#endif