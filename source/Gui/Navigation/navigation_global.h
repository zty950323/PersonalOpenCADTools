///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(NAVIGATION_LIB)
#  define NAVIGATION_EXPORT Q_DECL_EXPORT
# else
#  define NAVIGATION_EXPORT Q_DECL_IMPORT
# endif
#else
# define NAVIGATION_EXPORT
#endif
