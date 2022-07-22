///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
// This file is used to define the reference count pointer class
// used by a graphics engine.
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MIDR_GL_REF_PRT_H_H_
#define _MIDR_GL_REF_PRT_H_H_

#include "zsofts_compiler_specific.h"
#include "zsofts_types.h"

#if (TZ_COMPIER == TZ_COMPILER_MSVC)
#pragma warning ( disable : 4251 )
#endif // if (TZ_COMPIER == TZ_COMPILER_MSVC)

TZ_NAMESPACE_BEGIN(TzSoft)

template<class T>
class TzMidrglRefPtr
{
public:
	using element_type = T;

	TzMidrglRefPtr() : m_ptr(nullptr)
	{

	}

	TzMidrglRefPtr(T* ptr) 
		: m_ptr(ptr)
	{
		if (m_ptr)
		{
			m_ptr->ref();
		}
	}

	TzMidrglRefPtr(const TzMidrglRefPtr& rp)
		: m_ptr(rp.m_ptr)
	{
		if (m_ptr)
		{
			m_ptr->ref();
		}
	}

	template<class Other> TzMidrglRefPtr(const TzMidrglRefPtr<Other>& rp)
		: m_ptr(rp.m_ptr)
	{
		if (m_ptr)
		{
			m_ptr->ref();
		}
	}

	~TzMidrglRefPtr()
	{
		if (m_ptr)
		{
			m_ptr->unref();
			m_ptr = nullptr;
		}
	}

	TzMidrglRefPtr& operator= (const TzMidrglRefPtr& rp) 
	{
		assign(rp);
		return *this;
	}

	template<class Other> TzMidrglRefPtr& operator= (const TzMidrglRefPtr& rp)
	{
		assign(rp);
		return *this;
	}

	inline TzMidrglRefPtr& operator= (T* ptr)
	{
		if (m_ptr == ptr)
		{
			return *this;
		}

		T* tmp_ptr = m_ptr;
		m_ptr = ptr;
		if (m_ptr)
		{
			m_ptr->ref();
		}
		if (tmp_ptr)
		{
			tmp_ptr->unref();
		}
		return *this;
	}

	TZBOOL operator== (const TzMidrglRefPtr& rp) const 
	{
		return (m_ptr == rp.m_ptr);
	}

	TZBOOL operator== (const T* ptr) const
	{
		return (m_ptr == ptr);
	}

	friend TZBOOL operator== (const T* ptr, const TzMidrglRefPtr& rp)
	{
		return (ptr == rp.m_ptr);
	}

	TZBOOL operator != (const TzMidrglRefPtr& rp) const
	{
		return (m_ptr != rp.m_ptr);
	}

	TZBOOL operator != (const T* ptr) const
	{
		return (m_ptr != ptr);
	}

	friend TZBOOL operator != (const T* ptr, const TzMidrglRefPtr& rp)
	{
		return (ptr != rp.m_ptr);
	}

	TZBOOL operator < (const TzMidrglRefPtr& rp) const
	{
		return (m_ptr < rp.m_ptr);
	}

private:
	typedef T* TzMidrglRefPtr::*unspecified_bool_type;

public:
	// safe bool conversion
	operator unspecified_bool_type() const { return valid() ? &TzMidrglRefPtr::m_ptr : nullptr; }

	T& operator*() const
	{
		return *m_ptr;
	}

	T* operator->() const
	{
		return m_ptr;
	}

	T* get() const 
	{
		return m_ptr;
	}
	
	// this is not required.
	TZBOOL operator! () const
	{
		return m_ptr == nullptr;
	}

	TZBOOL valid() const
	{
		return m_ptr != nullptr;
	}

	T* release()
	{
		T* tmp = m_ptr;
		if (m_ptr)
		{
			m_ptr->unref_nodelete();
			m_ptr = nullptr;
		}
		return tmp;
	}

	void swap(TzMidrglRefPtr& rp)
	{
		T* tmp = m_ptr;
		m_ptr = rp.m_ptr;
		rp.m_ptr = tmp;
	}

private:

	template<class Other> void assign(const TzMidrglRefPtr<Other>& rp)
	{
		if (m_ptr == rp.m_ptr)
		{
			return;
		}

		T* tmp_ptr = m_ptr;
		m_ptr = rp.m_ptr;
		if (m_ptr)
		{
			m_ptr->ref();
		}

		// unref second to prevent any deletion of any object which might
		// be referenced by the other object. i.e rp is child of the original m_ptr.
		if (tmp_ptr)
		{
			tmp_ptr->unref();
		}
	}

	template<class Other> friend class TzMidrglRefPtr;

	T* m_ptr;
};

TZ_NAMESPACE_END(TzSoft)

#endif // !_MIDR_GL_REF_PRT_H_H_