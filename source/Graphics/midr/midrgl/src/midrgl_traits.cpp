///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "midrgl_traits.h"

#include <GL/GL.h>

TZ_NAMESPACE_BEGIN(TzSoft)

namespace 
{
	// TODO : [Note] may need some detect mechanism to get the follow vars, here just hard code the values.
	class DummyGLDetect 
	{
	public:
		DummyGLDetect()
		{
			MidrglApiTraitsBase::GL1_AVAILABLE = TRUE;
			MidrglApiTraitsBase::GL2_AVAILABLE = TRUE;

			MidrglApiTraitsBase::GL_DISPLAYLISTS_AVAILABLE = TRUE;
			MidrglApiTraitsBase::GL_MATRICES_AVAILABLE = TRUE;
			MidrglApiTraitsBase::GL_VERTEX_FUNCS_AVAILABLE = TRUE;
			MidrglApiTraitsBase::GL_VERTEX_ARRAY_FUNCS_AVAILABLE = TRUE;
			MidrglApiTraitsBase::GL_FIXED_FUNCTION_AVAILABLE = TRUE;

			MidrglApiTraitsBase::GL1_FEATURES = TRUE;
			MidrglApiTraitsBase::GL2_FEATURES = TRUE;
			MidrglApiTraitsBase::GL3_FEATURES = FALSE;
			MidrglApiTraitsBase::GLES1_FEATURES = FALSE;
			MidrglApiTraitsBase::GLES2_FEATURES = FALSE;
			MidrglApiTraitsBase::GLES3_FEATURES = FALSE;
			MidrglApiTraitsBase::GL_CONTEXT_VERSION = 1.0f;
		}
	};

	DummyGLDetect s_detect;
}

TZBOOL MidrglApiTraitsBase::GL1_AVAILABLE = FALSE;
TZBOOL MidrglApiTraitsBase::GL2_AVAILABLE = FALSE;

TZBOOL MidrglApiTraitsBase::GL_DISPLAYLISTS_AVAILABLE = FALSE;
TZBOOL MidrglApiTraitsBase::GL_MATRICES_AVAILABLE = FALSE;
TZBOOL MidrglApiTraitsBase::GL_VERTEX_ARRAY_FUNCS_AVAILABLE = FALSE;
TZBOOL MidrglApiTraitsBase::GL_VERTEX_FUNCS_AVAILABLE = FALSE;
TZBOOL MidrglApiTraitsBase::GL_FIXED_FUNCTION_AVAILABLE = FALSE;

TZBOOL MidrglApiTraitsBase::GL1_FEATURES = FALSE;
TZBOOL MidrglApiTraitsBase::GL2_FEATURES = FALSE;
TZBOOL MidrglApiTraitsBase::GL3_FEATURES = FALSE;
TZBOOL MidrglApiTraitsBase::GLES1_FEATURES = FALSE;
TZBOOL MidrglApiTraitsBase::GLES2_FEATURES = FALSE;
TZBOOL MidrglApiTraitsBase::GLES3_FEATURES = FALSE;
TZFLOAT MidrglApiTraitsBase::GL_CONTEXT_VERSION = 0.0f;

TZ_NAMESPACE_END(TzSoft)