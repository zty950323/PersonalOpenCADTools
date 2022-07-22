///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(BASICQTPATTERNS_LIB)
#  define BASICQTPATTERNS_EXPORT Q_DECL_EXPORT
# else
#  define BASICQTPATTERNS_EXPORT Q_DECL_IMPORT
# endif
#else
# define BASICQTPATTERNS_EXPORT
#endif
