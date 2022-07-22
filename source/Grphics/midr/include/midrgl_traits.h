///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MIDR_GL_TRATILS_H_H_
#define _MIDR_GL_TRATILS_H_H_

#include "zsofts_compiler_specific.h"
#include "midrgl_export.h"

#include "zsofts_types.h"

#define MIDRGL_APIENTRY APIENTRY

TZ_NAMESPACE_BEGIN(TzSoft)

enum MIDRGL_API  : TZUINT8
{
	MIDRGL_STANDARD
};

class MidrglApiTraitsBase 
{
public:
	using gl_enum = unsigned int;
	using gl_sizei = int;
	using gl_int = int;
	using gl_ubyte = unsigned char;
	using gl_ushort = unsigned short;
	using gl_uint = unsigned int;
	using gl_float = float;
	using gl_void = void;
	using gl_double = double;
	using gl_boolean = unsigned char;

	using gl_char = char;
	using gl_byte = signed char;
	using gl_short = short;
	using gl_int64 = TZINT64;
	using gl_uint64 = TZUINT64;

	using gl_intptr = ptrdiff_t;
	using gl_sizeiptr = ptrdiff_t;

	using gl_bitfield = unsigned int;
	using gl_sync = struct __gl_sync;

	/*
	* Note: different platform may have different value , have not check the detail yet.
	* TODO : in the future need to check the detail carefully.
	*/

	// PrimitiveType indicate pass mode to draw call.
	// TODO : put the right value to these const var.
	static const gl_enum gl_BYTE = 0x1400;
	static const gl_enum gl_SHORT = 0x1402;
	static const gl_enum gl_INT = 0x1404;
	static const gl_enum gl_INT64 = 0x140E;
	static const gl_enum gl_UINT64 = 0x140F;
	static const gl_enum gl_UNSIGNED_BYTE = 0x1401;
	static const gl_enum gl_UNEIGNED_SHORT = 0x1403;
	static const gl_enum gl_UNSIGNED_INT = 0x1405;
	static const gl_enum gl_FLOAT = 0x1406;
	static const gl_enum gl_DOUBLE = 0x140A;
	static const gl_enum gl_BOOL = 0x8B56;
	static const gl_enum gl_INT64_ARB = 0x140E;
	static const gl_enum gl_UNSIGNED_INT64_ARB = 0x140F;

	// gl mode use for glEnable and glDisable
	// TODO : put the right value to these const var.
	static const gl_enum gl_POINTS = 0x0000;
	static const gl_enum gl_LINES = 0x0001;
	static const gl_enum gl_LINE_LOOP = 0x0002;
	static const gl_enum gl_LINE_STRIP = 0x0003;
	static const gl_enum gl_TRIANGLES = 0x0004;
	static const gl_enum gl_TRIANGLE_STRIP = 0x0005;
	static const gl_enum gl_TRIANGLE_FAN = 0x0006;
	static const gl_enum gl_QUADS = 0x0007;
	static const gl_enum gl_QUAD_STRIP = 0x0008;
	static const gl_enum gl_POLYGON = 0x0009;

	// gl mode use for glEnable and glDisable
	// TODO : put the right value to these const var.
	static const gl_enum gl_DEPTH_TEST = 0x0B71;
	static const gl_enum gl_BLEND = 0x0BE2;
	static const gl_enum gl_SISSOR_TEST = 0x0C11;
	static const gl_enum gl_LIGHTING = 0x0B50;

	// GL blend function parameter.
	// TODO : put the right value to these const var.
	static const gl_enum gl_ZERO = 0;
	static const gl_enum gl_ONE = 1;
	static const gl_enum gl_SRC_COLOR = 0x0300;
	static const gl_enum gl_ONE_MINUS_SRC_COLOR = 0x0301;
	static const gl_enum gl_SRC_ALPHA = 0x0302;
	static const gl_enum gl_ONE_MINUS_SRC_ALPHA = 0x0303;
	static const gl_enum gl_DST_ALPHA = 0x0304;
	static const gl_enum gl_ONE_MINUS_DST_ALPHA = 0x0305;
	static const gl_enum gl_DST_COLOR = 0x0306;
	static const gl_enum gl_ONE_MINUS_DST_COLOR = 0x0307;
	static const gl_enum gl_SRC_ALPHA_SATURATE = 0x0308;

	// GL depth function.
	static const gl_enum gl_NEVER = 0x0200;
	static const gl_enum gl_LESS = 0x0201;
	static const gl_enum gl_EQUAl = 0x0202;
	static const gl_enum gl_LEQUAL = 0x0203;
	static const gl_enum gl_GREATER = 0x0204;
	static const gl_enum gl_NOTEQUAL = 0x0205;
	static const gl_enum gl_GEQUAL = 0x0206;
	static const gl_enum gl_ALWAYS = 0x0207;

	// GL clear buffer bit.
	static const gl_enum gl_COLOR_BUFFER_BIT = 0x00004000;
	static const gl_enum gl_DEPTH_BUFFER_BIT = 0x00000100;
	static const gl_enum gl_STENCIL_BUFFER_BIT = 0x00000400;

	// gl target
	// TODO : put the right value to these const var.
	static const gl_enum gl_MAX_TEXTURE_SIZE = 0x0D33;

	// TextureMagFilter
	static const gl_enum gl_NEAREST = 0x2600;
	static const gl_enum gl_LINEAR = 0x2601;

	// some boolean flags.
	static TZBOOL GL1_AVAILABLE;
	static TZBOOL GL2_AVAILABLE;

	static TZBOOL GL_DISPLAYLISTS_AVAILABLE;
	static TZBOOL GL_MATRICES_AVAILABLE;
	static TZBOOL GL_VERTEX_FUNCS_AVAILABLE;
	static TZBOOL GL_VERTEX_ARRAY_FUNCS_AVAILABLE;
	static TZBOOL GL_FIXED_FUNCTION_AVAILABLE;

	static TZBOOL GL1_FEATURES;
	static TZBOOL GL2_FEATURES;
	static TZBOOL GL3_FEATURES;
	static TZBOOL GLES1_FEATURES;
	static TZBOOL GLES2_FEATURES;
	static TZBOOL GLES3_FEATURES;
	static TZFLOAT GL_CONTEXT_VERSION;

};

template <MIDRGL_API  T, TZUINT8 MAJOR, TZUINT8 MINOR, TZUINT8 PATCH>
class MidrglApiTraits 
{
public:
	// define nothing.
};

template<>
class MidrglApiTraits<MIDRGL_STANDARD, 0, 0, 0> : public MidrglApiTraitsBase 
{
public:
	// MatrixType indicate how to use the matrix in different way.
	static const gl_enum gl_FLOAT_MAT2 = 0x8B5A;
	static const gl_enum gl_FLOAT_MAT3 = 0x8B5B;
	static const gl_enum gl_FLOAT_MAT4 = 0x8B5C;
	static const gl_enum gl_FLOAT_MAT2x3 = 0x8B65;
	static const gl_enum gl_FLOAT_MAT2x4 = 0x8B66;
	static const gl_enum gl_FLOAT_MAT3x2 = 0x8B67;
	static const gl_enum gl_FLAOT_MAT3x4 = 0x8B68;
	static const gl_enum gl_FLOAT_MAT4x2 = 0x8B69;
	static const gl_enum gl_FLOAT_MAT4x3 = 0x8B6A;
	static const gl_enum gl_DOUBLE_MAT2 = 0x8F46;
	static const gl_enum gl_DOUBLE_MAT3 = 0x8F47;
	static const gl_enum gl_DOUBLE_MAT4 = 0x8F48;
	static const gl_enum gl_DOUBLE_MAT2x3 = 0x8F49;
	static const gl_enum gl_DOUBLE_MAT2x4 = 0x8F4A;
	static const gl_enum gl_DOUBLE_MAT3x2 = 0x8F4B;
	static const gl_enum gl_DOUBLE_MAT3x4 = 0x8F4C;
	static const gl_enum gl_DOUBLE_MAT4x2 = 0x8F4D;
	static const gl_enum gl_DOUBLE_MAT4x3 = 0x8F4E;

	// VecType indicate how to use the vec in different way.
	static const gl_enum gl_FLOAT_VEC2 = 0x8B50;
	static const gl_enum gl_FLOAT_VEC3 = 0x8B51;
	static const gl_enum gl_FLOAT_VEC4 = 0x8B52;
	static const gl_enum gl_INT_VEC2 = 0x8B53;
	static const gl_enum gl_INT_VEC3 = 0x8B54;
	static const gl_enum gl_INT_VEC4 = 0x8B55;
	static const gl_enum gl_BOOL_VEC2 = 0x8B57;
	static const gl_enum gl_BOOL_VEC3 = 0x8B58;
	static const gl_enum gl_BOOL_VEC4 = 0x8B59;
	static const gl_enum gl_DOUBLE_VEC2 = 0x8FFC;
	static const gl_enum gl_DOUBLE_VEC3 = 0x8FFD;
	static const gl_enum gl_DOUBLE_VEC4 = 0x8FFE;
	static const gl_enum gl_UNSIGNED_INT_VEC2_EXT = 0x8DC6;
	static const gl_enum gl_UNSIGNED_INT_VEC3_EXT = 0x8DC7;
	static const gl_enum gl_UNSIGNED_INT_VEC4_EXT = 0x8DC8;

	// SampleType indicate how to use the sample in different way.
	static const gl_enum gl_SAMPLER_1D = 0x8B5D;
	static const gl_enum gl_SAMPLER_2D = 0x8B5E;
	static const gl_enum gl_SAMPLER_3D = 0x8B5F;
	static const gl_enum gl_SAMPLER_CUBE = 0x8B60;
	static const gl_enum gl_SAMPLER_1D_SHADOW = 0x8B61;
	static const gl_enum gl_SAMPLER_2D_SHADOW = 0x8B62;
	static const gl_enum gl_SAMPLER_1D_ARRAY_EXT = 0x8DC0;
	static const gl_enum gl_SAMPLER_2D_ARRAY_EXT = 0x8DC1;
	static const gl_enum gl_SAMPLER_CUBE_SHADOW_EXT = 0x8DC5;
	static const gl_enum gl_SAMPLER_CUBE_MAP_ARRAY = 0x900C;
	static const gl_enum gl_SAMPLER_2D_MULTISAMPLE = 0x9108;
	static const gl_enum gl_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x900D;
	static const gl_enum gl_SAMPLER_2D_RECT = 0x8D63;
	static const gl_enum gl_SAMPLER_2D_RECT_SHADOW = 0x08B64;
	static const gl_enum gl_SAMPLER_BUFFER = 0x8DC2;
	static const gl_enum gl_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E;
	static const gl_enum gl_INT_SAMPLER_2D_MULTISAMPLE = 0x9109;
	static const gl_enum gl_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;
	static const gl_enum gl_INT_SAMPLER_1D_EXT = 0x8DC9;
	static const gl_enum gl_INT_SAMPLER_2D_EXT = 0x8DCA;
	static const gl_enum gl_INT_SAMPLER_3D_EXT = 0x8DCB;
	static const gl_enum gl_INT_SAMPLER_CUBE_EXT = 0x8DCC;
	static const gl_enum gl_INT_SAMPLER_2D_RECT_EXT = 0x8DCD;
	static const gl_enum gl_INT_AMPLER_1D_ARRAY_EXT = 0x8DCE;
	static const gl_enum gl_INT_SAMPLER_2D_ARRAY_EXT = 0x8DD0;
	static const gl_enum gl_INT_SAMPLER_BUFFER_EXT = 0x8DD0;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_1D_EXT = 0x8DD1;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_2D_EXT = 0x8DD2;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_3D_EXT = 0x8DD3;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_CUBE_EXT = 0x8DD4;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_2D_RECT_EXT = 0x8DD5;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT = 0x8DD6;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT = 0x8DD7;
	static const gl_enum gl_UNSIGNED_INT_SAMPLER_BUFFER_EXT = 0x8DD8;

	// ImageType indicate pass mode to draw image call.
	static const gl_enum gl_IMAGE_1D = 0x904C;
	static const gl_enum gl_IMAGE_2D = 0x904D;
	static const gl_enum gl_IMAGE_3D = 0x904E;
	static const gl_enum gl_IMAGE_2D_RECT = 0x904F;
	static const gl_enum gl_IMAGE_CUBE = 0x9050;
	static const gl_enum gl_IMAGE_BUFFER = 0x9051;
	static const gl_enum gl_IMAGE_1D_ARRAY = 0x9052;
	static const gl_enum gl_IMAGE_2D_ARRAY = 0x9053;
	static const gl_enum gl_IMAGE_CUBE_MAP_ARRAY = 0x9054;
	static const gl_enum gl_IMAGE_2D_MULTISAMPLE = 0x9055;
	static const gl_enum gl_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9056;
	static const gl_enum gl_INT_IMAGE_1D = 0x9057;
	static const gl_enum gl_INT_IMAGE_2D = 0x9058;
	static const gl_enum gl_INT_IMAGE_3D = 0x9059;
	static const gl_enum gl_INT_IMAGE_2D_RECT = 0x905A;
	static const gl_enum gl_INT_IMAGE_CUBE = 0x905B;
	static const gl_enum gl_INT_IMAGE_BUFFER = 0x905C;
	static const gl_enum gl_INT_IMAGE_1D_ARRAY = 0x905D;
	static const gl_enum gl_INT_IMAGE_2D_ARRAY = 0x905E;
	static const gl_enum gl_INT_IMAGE_CUBE_MAP_ARRAY = 0x905F;
	static const gl_enum gl_INT_IMAGE_2D_MULTISAMPLE = 0x9060;
	static const gl_enum gl_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9061;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_1D = 0x9062;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_2D = 0x9063;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_3D = 0x9064;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_2D_RECT = 0x9065;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_CUBE = 0x9066;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_BUFFER = 0x9067;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_1D_ARRAY = 0x9068;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY = 0x906A;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE = 0x906B;
	static const gl_enum gl_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x906C;

	// GL shader type
	static const gl_enum gl_VERTEX_SHADER = 0x8B31;
	static const gl_enum gl_TESS_CONTROL_SHADER = 0x8E88;
	static const gl_enum gl_TESS_EVALUATION_SHADER = 0x8E87;
	static const gl_enum gl_GEOMETRY_SHADER = 0x8DD9;
	static const gl_enum gl_FRAGMENT_SHADER = 0x8B30;
	static const gl_enum gl_COMPUTE_SHADER = 0x91B9;

	// GL clip distance
	static const gl_enum gl_CLIP_DISTANCE0 = 0x3000;
	static const gl_enum gl_CLIP_DISTANCE1 = 0x3001;
	static const gl_enum gl_CLIP_DISTANCE2 = 0x3002;
	static const gl_enum gl_CLIP_DISTANCE3 = 0x3003;
	static const gl_enum gl_CLIP_DISTANCE4 = 0x3004;
	static const gl_enum gl_CLIP_DISTANCE5 = 0x3005;

	// GL target
	static const gl_enum gl_MAX_3D_TEXTURE_SIZE = 0x8073;
	static const gl_enum gl_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
	static const gl_enum gl_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
	static const gl_enum gl_MAX_TEXTURE_COORDS = 0x8871;

	// other numbers
	static const gl_enum gl_INVALID_INDEX = 0xFFFFFFFu;
	static const gl_enum gl_LINK_STATUS = 0x8B82;
	static const gl_enum gl_ACTIVE_UNIFORMS = 0x8B86;
	static const gl_enum gl_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
	static const gl_enum gl_UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB;

};

using MidrglTraits = MidrglApiTraits<MIDRGL_STANDARD, 0, 0, 0>;

TZ_NAMESPACE_END(TzSoft)

#endif // _MIDR_GL_TRATIS_H_H_