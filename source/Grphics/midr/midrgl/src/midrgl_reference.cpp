///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "midrgl_reference.h"
#include "midrgl_util.h"

#include "tzsofts_debug_utils.h"

#include <atomic>

TZ_NAMESPACE_BEGIN(TzSoft)

class MidrglReferenceImpl 
{
public:
	MidrglReferenceImpl(MidrglReference* pFacade) 
		: m_pFacade(pFacade)
	{

	}

	~MidrglReferenceImpl()
	{

	}

	TZINT ref() const 
	{
		return ++m_refCount;
	}

	TZINT unref() const
	{
		return --m_refCount;
	}

	TZINT referenceCount() const
	{
		return m_refCount;
	}

private:
	mutable std::atomic<TZINT> m_refCount = { 0 };

	TZ_MIDR_GL_DECLARE_FACADE(MidrglReference) = { nullptr };
};


MidrglReference::MidrglReference()
	: m_pImpl(new MidrglReferenceImpl(this))
{

}

MidrglReference::~MidrglReference()
{
	TZ_MIDR_GL_D();

	// if this happen, may cause wild pointer issue.
	TZ_ASSERT(0 == d->referenceCount());

	if (m_pImpl)
	{
		delete m_pImpl;
		m_pImpl = nullptr;
	}
}

void * MidrglReference::operator new(size_t size, TZPCSTR file, TZINT line)
{
	return ::malloc(size);
}

void MidrglReference::operator delete(void * p, TZPCSTR file, TZINT line)
{
	return ::free(p);
}

void * MidrglReference::operator new(size_t size)
{
	return ::malloc(size);
}

void MidrglReference::operator delete(void * p)
{
	return ::free(p);
}

void * MidrglReference::operator new[](size_t size, TZPCSTR file, TZINT line)
{
	return ::malloc(size);
}

void MidrglReference::operator delete[](void * p, TZPCSTR file, TZINT line)
{
	return ::free(p);
}

void * MidrglReference::operator new[](size_t size)
{
	return ::malloc(size);
}

void MidrglReference::operator delete[](void * p)
{
	return ::free(p);
}

TZINT MidrglReference::ref() const
{
	TZ_MIDR_GL_D();
	return d->ref();
}
	
TZINT MidrglReference::unref() const
{
	TZ_MIDR_GL_D();

	TZINT newValue = d->unref();

	if (0 == newValue)
	{
		if (this)
		{
			delete this;
		}
	}

	return newValue;
}

TZINT MidrglReference::unref_nodelete() const
{
	TZ_MIDR_GL_D();
	return d->unref();
}

TZINT MidrglReference::referenceCount() const
{
	TZ_MIDR_GL_D();
	return d->referenceCount();
}

TZ_NAMESPACE_END(TzSoft)