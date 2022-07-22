///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MIDR_GL_REFENCE_H_H_
#define _MIDR_GL_REFENCE_H_H_

#include "midrgl_export.h"
#include "midrgl_common.h"
#include "zsofts_types.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class MidrglReferenceImpl;
class MidrglHardState;

class TZ_MIDR_GL_STATIC_EXPORT MidrglReference 
{
public:
	MidrglReference();
	virtual ~MidrglReference();

	void* operator new(size_t size, TZPCSTR file, TZINT line);
	void operator delete(void* p, TZPCSTR file, TZINT line);

	void* operator new(size_t size);
	void operator delete(void* p);

	void* operator new[](size_t size, TZPCSTR file, TZINT line);
	void operator delete[](void* p, TZPCSTR file, TZINT line);

	void* operator new[](size_t size);
	void operator delete[](void* p);

	void* operator new(size_t size, void* buf) 
	{
		// TODO
		return buf; 
	}

	void operator delete(void*, void*) 
	{
		// TODO
	}

	TZINT ref() const;
	TZINT unref() const;
	TZINT unref_nodelete() const;
	TZINT referenceCount() const;

	virtual void resizeGLObjectBuffers(TZUINT maxSize)
	{
		// TODO
	}

	virtual void releaseGLObjects(MidrglHardState* state = nullptr)
	{
		// TODO
	}

protected:
	// TODO : add some data.

private:
	TZ_MIDR_GL_DISABLE_COPY_MOVE(MidrglReference);
	TZ_MIDR_GL_DECLARE_IMP(MidrglReference) = { nullptr };
};

TZ_NAMESPACE_END(TzSoft)

#endif