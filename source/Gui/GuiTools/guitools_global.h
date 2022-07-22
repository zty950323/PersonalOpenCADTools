///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(GUITOOLS_LIB)
#  define GUITOOLS_EXPORT Q_DECL_EXPORT
# else
#  define GUITOOLS_EXPORT Q_DECL_IMPORT
# endif
#else
# define GUITOOLS_EXPORT
#endif
