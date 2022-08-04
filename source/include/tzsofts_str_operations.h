/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _TZ_SOFT_STRING_OPERATIONS_H_H_
#define _TZ_SOFT_STRING_OPERATIONS_H_H_

#include <wchar.h>

#include <string>

#ifdef TZ_WINDOWS
#include <mbstring.h>
#endif // TZ_WINDOWS
#include "zsofts_types.h"

#define tz_stdstring_a std::string
#define tz_stdstring_w std::wstring

#ifdef _UNICODE
#define tz_stdstring tz_stdstring_w
#ifndef _ftprintf
#define _ftprintf fwprintf
#endif
#ifndef _ftscanf
#define _ftscanf fwscanf
#endif
#ifndef _tprintf
#define _tprintf wprintf
#endif
#else
#define tz_stdstring tz_stdstring_a
#ifndef _ftprintf
#define _ftprintf fprintf
#endif
#ifndef _ftscanf
#define _ftscanf fscanf
#endif
#ifndef _tprintf
#define _tprintf printf
#endif
#endif // _UNICODE

#define tz_vscprintf _vsctprintf
#define tz_vstprintf _vstprintf
#define tz_vstprintf_s _vstprintf_s
#define tz_stprintf _stprintf
#define tz_stprintf_s _stprintf_s
#define tz_ftprintf _ftprintf
#define tz_ftscanf _ftscanf
#define tz_printf _tprintf
#define tz_strlen _tcslen
#define tz_strcmp _tcscmp
#define tz_stricmp _tcsicmp
#define tz_strncmp _tcsncmp
#define tz_strnccmp _tcsnccmp
#define tz_strnicmp _tcsnicmp
#define tz_strcpy _tcscpy
#define tz_strcpy_s _tcscpy_s
#define tz_strncpy _tcsncpy
#define tz_strncpy_s _tcsncpy_s
#define tz_vtcprintf _vtcprintf
#define tz_strcat _tcscat
#define tz_strcat_s _tcscat_s
#define tz_fullpath _tfullpath
#define tz_strncat _tcsncat
#define tz_strstr _tcsstr
#define tz_strdup _tcsdup
#define tz_strdup_dbg _tcsdup_dbg
#define tz_splitpath _tsplitpath
#define tz_strcpy_s _tcscpy_s
#define tz_strchr _tcschr
#define tz_strrchr _tcsrchr

#define tz_access _taccess

#define tz_stoi _tstoi
#define tz_isdigit _istdigit
#define tz_stscanf _stscanf
#define tz_islower _istlower
#define tz_isupper _istupper
#define tz_toupper _totupper
#define tz_toupper_l _totupper_l
#define tz_tolower _totlower
#define tz_tolower_l _totlower_l
#define tz_strupr _tcsupr
#define tz_tcstol _tcstol
#define tz_tcslwr _tcslwr
#define tz_strlwr _strlwr
#define tz_isalpha _istalpha
#define tz_istspace _istspace
#define tz_istalnum _istalnum
#define tz_getenv _tgetenv

#define tz_mbsinc _mbsinc
#define tz_ttoi _tstoi
#define tz_atoi64 atoll
#define tz_mbsninc _mbsninc
#define tz_mbsdec _mbsdec
#define tz_ismbclower _ismbclower
#define tz_ismbcupper _ismbcupper
#define tz_mbslwr _mpslwr
#define tz_mbsupr _mpsupr
#define tz_ismbcspace _ismbcspace
#define tz_isspace _istspace
#define tz_ismbcdigit _ismbcdigit
#define tz_wcsupr _wcsupr
#define tz_wcslwr _wcslwr
#define tz_wtoi _wtoi
#define tz_wtol _wtol
#define tz_wroi64 _wroi64
#define tz_wtof _wtof
#define tz_itoa _itoa
#define tz_itow _itow
#define tz_itow_s _itow_s
#define tz_i64toa _i64toa
#define tz_ui64tow _ui64toa
#define tz_ltoa _ltoa
#define tz_ltow _ltow
#define tz_ltow_s _ltow_s
#define tz_fcvt _fcvt
#define tz_mbscmp _mbscmp
#define tz_mbsncmp _mbsncmp
#define tz_mbsnicmp _mbsnicmp
#define tz_mbscoll _mbscoll
#define tz_mbsncoll _mbsncoll
#define tz_mbsicoll _mbsicoll
#define tz_mbsnicoll _mbsnicoll
#define tz_wcsicoll _wcsicoll
#define tz_wcsncoll _wcsncoll
#define tz_wcsnicoll _wcsnicoll
#define tz_mbsstr _mbsstr
#define tz_mbsspn _mbsspn
#define tz_mbscspn _mbscspn
#define tz_wcscspn wcscspn
#define tz_mbsrev _mbsrev
#define tz_wcsrev _wcsrev
#define tz_mbslen _mbslen
#define tz_mbscpy _mbscpy
#define tz_mbscpy_s _mbscpy_s
#define tz_wcscpy_s wcscpy_s
#define tz_memcpy_s memcpy_s
#define tz_wmemcpy_s wmemcpy_s
#define tz_wmemcpy wmemcpy
#define tz_vsprintf_s vsprintf_s
#define tz_vswprintf vswprintf
#define tz_vswprintf_s vswprintf_s
#define tz_swprintf tz_swprintf
#define tz_tsplitpath _tsplitpath
#define tz_tmakepath _tmakepath

#endif // !_TZ_SOFT_STRING_OPERATIONS_H_H_
