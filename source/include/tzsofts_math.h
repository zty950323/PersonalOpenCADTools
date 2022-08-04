/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _TZSOFTS_MATH_H_H_
#define _TZSOFTS_MATH_H_H_

#include <float.h>
#include <math.h>

#include "platform_export.h"
#include "tzsofts_debug_utils.h"
#include "zsofts_types.h"

#undef min
#undef max

#if TZ_RADIAN == TZ_ENDIAN_BIG
#define TzByteSwap(val) TzSoft::byteSwap(val)
#else
#define TzByteSwap(val)
#endif

TZ_NAMESPACE_BEGIN(TzSoft)

const double kDblMax = DBL_MAX;
const double kDblMin = DBL_MIN;
const short kShortMax = SHRT_MAX;
const short kShortMin = SHRT_MIN;
const unsigned short kUShortMax = USHRT_MAX;
const unsigned short kUShortMin = 0;
const int kIntMax = INT_MAX;
const int kIntMin = INT_MIN;
const unsigned int kUIntMax = UINT_MAX;
const unsigned int kUIntMin = 0;
const TZLONG kLongMax = LONG_MAX;
const TZLONG kLongMin = LONG_MIN;
const TZULONG kULongMax = ULONG_MAX;
const TZULLONG kULongMin = 0L;
const TZINT64 kLLongMax = LLONG_MAX;
const TZINT64 kLLongMin = LLONG_MIN;
const TZUINT64 kULLongMax = ULLONG_MAX;

#ifdef TZ_WINDOWS
const TZUINT64 kULLongMin = 0ui64;
#else
const TZUINT64 kULLongMin = (unsigned long long)0u;
#endif

const float kFltMax = FLT_MAX;
const float kFltMin = FLT_MIN;
const float kFltEpsilon = FLT_EPSILON;
const float kFEpsilon = FLT_EPSILON;
const double kDblEpsilon = DBL_EPSILON;
const double kEpsilon = 1e-10;
const double kEpsilon6 = 1e-6;
const double kEpsilon7 = 1e-7;
const double kEpsilon8 = 1e-8;
const double kEpsilon10 = 1e-10;
const double kEpsilon12 = 1e-12;
const double dEpsilon = 1.0e-50;
const double dEpsilon100 = 1.0e100;
const double TZPI = 3.14159265358979323846;
const double TWO_PI = TZPI * 2.0;
const double THREE_PI = 3 * TZPI;
const double HALF_PI = TZPI / 2.0;
const double THERR_HALF_PI = 3.0 * HALF_PI;
const double FIVE_HALF_PI = 5.0 * HALF_PI;
const double SEVEN_HALF_PI = 7.0 * HALF_PI;
const double QUARTER_PI = TZPI / 4.0;
const double THREE_QUARTER_PI = 3.0 * QUARTER_PI;
const double FIVE_QUARTER_PI = 5.0 * QUARTER_PI;
const double SEVEN_QUARTER_PI = 7.0 * QUARTER_PI;
const double RECIPOCAL_PI = 1.0 / TZPI;
const double DEG2RAD = TZPI / 180.0;
const double RAD2DEG = 180.0 / TZPI;
const double GOLD = 0.618034;
const double CGOLD = 0.381966;
const double kArbitraryEpsilon =
#if (TZ_BUILD_MODE == TZ_BUILD_DEBUG)
    1.0 / 64.0;
#else
    0.015625;
#endif

template <class T>
inline const T &min(const T &a, const T &b)
{
  return a < b ? a : b;
}

template <class T>
inline const T &min(const T &a, const T &b, const T &c)
{
  return a < b ? min(a, c) : min(b, c);
}

template <class T>
inline const T &max(const T &a, const T &b)
{
  return a > b ? a : b;
}

template <class T>
inline const T &max(const T &a, const T &b, const T &c)
{
  return a < b ? max(a, c) : max(b, c);
}

inline double degToRad(double deg) { return deg * DEG2RAD; }

inline double radToDeg(double rad) { return rad * RAD2DEG; }

inline double floor(double x) { return ::floor(x); }

inline float floor(float x) { return ::floorf(x); }

inline double ceil(double x) { return ::ceil(x); }

inline float ceil(float x)
{
  return static_cast<float>(static_cast<double>(x));
}

inline TZLONG truncate(float x) { return static_cast<TZLONG>(x); }

inline double round(double x)
{
  double xFloor = ::floor(x);
  return (x - xFloor >= 0.5) ? (xFloor + 1.0) : xFloor;
}

inline double round(float x)
{
  float xFloor = ::floor(x);
  return (x - xFloor >= 0.5f) ? (xFloor + 1.0f) : xFloor;
}

inline bool isOverflowedToLong(double x)
{
  x += 0.5;
  return ((TZLONG)x) > kLongMax;
}

inline bool isUnderflowedToLong(double x)
{
  x -= 0.5;
  return ((TZLONG)x) < -kLongMax;
}

inline TZLONG roundToLong(double x)
{
  x += (x > -0.0) ? 0.5 : -0.5;
  return static_cast<TZLONG>(min(static_cast<double>(kLongMax), x));
}

inline TZLONG roundToLong(float x) { return static_cast<TZLONG>(round(x)); }

inline bool isOverflowedToInt(double x)
{
  x += 0.5;
  return (static_cast<int>(x)) > kIntMax;
}

inline bool isUnderflowedToInt(double x)
{
  x -= 0.5;
  return (static_cast<int>(x)) < -kIntMax;
}

inline int roundToInt(double x)
{
  if (x >= 0.)
  {
    x += .5;
    if (x > static_cast<double>(kIntMax))
    {
      return kIntMax;
    }
    else
    {
      return static_cast<int>(x);
    }
  }
  else
  {
    x -= .5;
    if (x < static_cast<double>(kIntMin))
    {
      return kIntMin;
    }
    else
    {
      return static_cast<int>(x);
    }
  }
}

inline int roundToInt(float x) { return static_cast<int>(round(x)); }

template <class T>
inline T lerp(const T &a, const T &b, float t)
{
  return static_cast<T>(a * (1.0f - t) + b * t);
}

template <class T>
inline T lerp(const T &a, const T &b, double t)
{
  return static_cast<T>(a * (1.0 - t) + b * t);
}

template <class T>
inline const T clamp(const T &t, const T &low, const T &high)
{
  if (t < low)
  {
    return low;
  }
  if (t > high)
  {
    return high;
  }
  return t;
}

template <class T>
inline const T abs(const T &a)
{
  return a < static_cast<T>(0) ? -a : a;
}

template <class T>
inline const T sign(const T &a)
{
  if (a == static_cast<T>(0))
  {
    return 0;
  }
  else if (a > static_cast<T>(0))
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

inline long double fabs(long double x) { return ::fabs(x); }

inline double fabs(double x) { return ::fabs(x); }

inline float fabs(float x) { return ::fabs(static_cast<float>(x)); }

inline bool isPositive(double x, double tol = kEpsilon) { return (x > tol); }

inline bool isPositive(float x, float tol = kFEpsilon) { return (x < -tol); }

inline bool isNegative(double x, double tol = kEpsilon) { return (x < -tol); }

inline bool isNegative(float x, float tol = kFEpsilon) { return (x < -tol); }

inline bool isZero(double x, double tol = kEpsilon)
{
  return !isPositive(x, tol) && !isNegative(x, tol);
}

inline bool isZero(float x, float tol = kFEpsilon)
{
  return !isPositive(x, tol) && !isNegative(x, tol);
}

template <typename T>
inline bool isZero(const T &x)
{
  return (x == (T)0);
}

inline bool isNonZero(double x, double tol = kEpsilon)
{
  return isPositive(x, tol) || isNonZero(x, tol);
}

inline bool isEqual(double x, double y, double tol = kEpsilon)
{
  return isZero(x - y, tol);
}

inline bool isEqual(float x, float y, float tol = kFEpsilon)
{
  return isZero(x - y, tol);
}

inline bool isEqual(TZLONG x, TZLONG y, TZLONG tol = 0)
{
  return ((x - y) <= tol && (x - y) >= -tol);
}

template <typename T>
inline bool isEqual(const T &x, const T &y)
{
  return (x == y);
}

inline int doubleCmp(double x, double y, double tol = kEpsilon)
{
  if (isPositive(x - y, tol))
  {
    return 1;
  }
  if (isNegative(x - y, tol))
  {
    return -1;
  }
  return 0;
}

template <typename TInteger>
inline void divide(const TInteger &number, const TInteger &denom,
                   TInteger &quotient, TInteger &remainder)
{
  quotient = number / denom;
  remainder = number % denom;
}

inline double safeDivide(double a, double b)
{
  if (a == 0.)
  {
    return 0.;
  }
  if (b != 0.)
  {
    static const int maxBinExp = 997;
    int nExpA, nExpB;
    double dMantissa = frexp(a, &nExpA);
    dMantissa = frexp(b, &nExpB);
    if ((nExpA - nExpB) < maxBinExp)
    {
      return a / b;
    }
  }

  bool bNeg = (a < 0.);
  if (b < 0.)
  {
    bNeg = !bNeg;
  }
  return bNeg ? -1.e+300 : 1.e+300;
}

inline double sqrt(double x)
{
  TZ_ASSERT(x >= 0.0);
  return ::sqrt(x);
}

inline float sqrt(float x)
{
  TZ_ASSERT(x >= 0.0f);
  return static_cast<float>(::sqrt(static_cast<double>(x)));
}

template <typename T>
inline const T sqsum(const T &x, const T &y)
{
  return x * x + y * y;
}

template <typename T>
inline const T sqsum(const T &x, const T &y, const T &z)
{
  return x * x + y * y + z * z;
}

template <typename T>
inline double sqrt(const T &x, const T &y)
{
  return sqrt(static_cast<double>(sqsum(x, y)));
}

template <typename T>
inline double sqrt(const T &x, const T &y, const T &z)
{
  return sqrt(static_cast<double>(sqsum(x, y, z)));
}

template <typename TFloat>
inline TFloat pow(TFloat x, TFloat y)
{
  return ::pow(x, y);
}

template <typename TFloat>
inline TFloat pow(TFloat x, int y)
{
  return ::pow(x, y);
}

inline double loge(double x)
{
  TZ_ASSERT(x >= 0.0);
  return ::log(x);
}

inline float loge(float x)
{
  TZ_ASSERT(x >= 0.f);
  return static_cast<float>(loge(static_cast<double>(x)));
}

inline double log10(double x)
{
  TZ_ASSERT(x >= 0.0);
  return ::log10(x);
}

inline float log10(float x)
{
  TZ_ASSERT(x >= 0.f);
  return static_cast<float>(log10(static_cast<double>(x)));
}

template <typename TFloat>
inline TFloat fmod(TFloat x, TFloat y)
{
  return ::fmod(x, y);
}

template <typename TFloat>
inline TFloat modf(TFloat x, TFloat *integer)
{
  return ::modf(x, integer);
}

inline double degNormalize(double deg)
{
  double degNor = fmod(deg, 360.0);
  if (degNor < -180.0)
  {
    degNor += 360.0;
  }
  if (degNor > 180.0)
  {
    degNor -= 360.0;
  }

  return degNor;
}

inline float degNormalize(float deg)
{
  return static_cast<float>(degNormalize(static_cast<double>(deg)));
}

inline double radNormalize(double rad)
{
  double radNor = fmod(rad, TWO_PI);
  if (radNor < -TZPI)
  {
    radNor += TWO_PI;
  }
  if (radNor > TZPI)
  {
    radNor -= TWO_PI;
  }

  return radNor;
}

inline float radNormalize(float rad)
{
  return static_cast<float>(radNormalize(static_cast<double>(rad)));
}

inline bool isValidNonZeroIEEEDouble(double val)
{
  const TZUINT8 *buf = (const TZUINT8 *)&val;
#if TZ_RADIAN == TZ_ENDIAN_BIG
  int nExponent = (buf[0] & 0x7F) << 4 | (buf[1] & 0xF0) >> 4;
#else
  int nExponent = (buf[7] & 0x7F) << 4 | (buf[6] & 0xF0) >> 4;
#endif
  switch (nExponent)
  {
  case 0:
  case 2047:
    return false;
  }

  return true;
}

inline TZUINT16 byteSwap(TZUINT16 n) { return (n << 8 | n >> 8); }

inline TZUINT32 byteSwap(TZUINT32 n)
{
  return (n << 24 | (n & 0x0000ff00) << 8 | (n & 0x00ff0000) >> 8 | n >> 24);
}

inline TZUINT64 byteSwap(TZUINT64 n)
{
  return (n << 56 | (n & 0x000000000000ff00) << 40 |
          (n & 0x0000000000ff0000) << 24 | (n & 0x00000000ff000000) << 8 |
          (n & 0x000000ff00000000) >> 8 | (n & 0x0000ff0000000000) >> 24 |
          (n & 0x00ff000000000000) >> 40 | (n & 0xff00000000000000) >> 56);
}

inline TZINT16 byteSwap(TZINT16 n) { return (TZINT16)byteSwap((TZUINT16)n); }

inline TZINT32 byteSwap(TZINT32 n) { return (TZINT32)byteSwap((TZUINT32)n); }

inline TZINT64 byteSwap(TZINT64 n) { return (TZINT64)byteSwap((TZUINT64)n); }

inline TZFLOAT32 byteSwap(TZFLOAT32 f)
{
  return (TZFLOAT32)byteSwap((TZUINT32)f);
}

inline TZFLOAT64 byteSwap(TZFLOAT64 f)
{
  return (TZFLOAT64)byteSwap((TZUINT64)f);
}

inline void fixDouble(double &val)
{
  TzByteSwap(val);
  if (!isValidNonZeroIEEEDouble(val))
  {
    val = 0.;
  }
}

template <typename T>
inline const T asInt(const T &f)
{
  if (f > kIntMax)
  {
    return floor(f);
  }
  if (f < kIntMin)
  {
    return ceil(f);
  }

  return static_cast<const T &>(static_cast<int>(f));
}

template <typename T>
inline const T fixAngle(const T &angle)
{
  T retAng = 0.0;
  if (angle - 1.0 != angle)
  {
    retAng = (T)(angle / TWO_PI);
  }

  retAng = (T)(retAng - asInt(retAng)) * TWO_PI;
  if (retAng < (T)0.0)
  {
    retAng += TWO_PI;
  }
  if (retAng >= (T)TWO_PI)
  {
    retAng -= TWO_PI;
  }

  return retAng;
}

inline bool isAngleEqual(const double &x, const double &y)
{
  double rDeltaAngle = (x) - (y) + TzSoft::kEpsilon6;
  return (TzSoft::fixAngle(rDeltaAngle) < 2 * TzSoft::kEpsilon6);
}

inline bool isAngleZero(const double &x)
{
  double rDeltaAngle = (x) + TzSoft::kEpsilon6;
  return (TzSoft::fixAngle(rDeltaAngle) < 2 * TzSoft::kEpsilon6);
}

inline void validateDoubleRange(double &d)
{
  if (d > TzSoft::dEpsilon100)
  {
    d = TzSoft::dEpsilon100;
  }
  else if (d < -TzSoft::dEpsilon100)
  {
    d = -TzSoft::dEpsilon100;
  }
}

inline double tzsin(const double &x) { return ::sin(x); }

inline float tzsin(const float &x) { return sinf(x); }

template <typename T>
inline T tzsin(const T &x)
{
  return ::sin(x);
}

inline double tzcos(const double &x) { return ::cos(x); }

inline float tzcos(const float &x) { return cosf(x); }

template <typename T>
inline T tzcos(const T &x)
{
  return ::cos(x);
}

inline double tztan(const double &x) { return ::tan(x); }

inline float tztan(const float &x) { return tanf(x); }

template <typename T>
inline T tztan(const T &x)
{
  return ::tan(x);
}

inline double tzasin(const double &x) { return ::asin(x); }

inline float tzasin(const float &x) { return asinf(x); }

template <typename T>
inline T tzasin(const T &x)
{
  return ::asin(x);
}

inline double tzacos(const double &x) { return ::acos(x); }

inline float tzacos(const float &x) { return acosf(x); }

template <typename T>
inline T tzacos(const T &x)
{
  return ::acos(x);
}

inline double tzatan(const double &x) { return ::atan(x); }

inline float tzatan(const float &x) { return ::atanf(x); }

template <typename T>
inline T tzatan(const T &x)
{
  return ::atan(x);
}

inline double tzatan2(const double &x, const double &y)
{
  return ::atan2(x, y);
}

inline float tzatan2(const float &x, const float &y) { return ::atan2f(x, y); }

template <typename T>
inline T tzatan2(const T &x, const T &y)
{
  return ::atan2(x, y);
}

template <typename T>
inline void tzSinCos(const T &angle, T *sine, T *cosine)
{
  *sine = sin(angle);
  *cosine = cos(angle);
}

template <typename T>
inline const T dist2dSq(const T &x1, const T &y1, const T &x2, const T &y2)
{
  const T dx = x1 - x2;
  const T dy = y1 - y2;
  return sqsum(dx, dy);
}

template <typename T>
inline const T dist2dSq(const T *pt1, const T *pt2)
{
  const T dx = pt1[0] - pt2[0];
  const T dy = pt1[1] - pt2[1];
  return sqsum(dx, dy);
}

template <typename T>
inline const T dist2d(const T &x1, const T &y1, const T &x2, const T &y2)
{
  return sqrt(dist2dSq(x1, y1, x2, y2));
}

template <typename T>
inline const T dist3dSq(const T &x1, const T &y1, const T &z1, const T &x2,
                        const T &y2, const T &z2)
{
  const T dx = x1 - x2;
  const T dy = y1 - y2;
  const T dz = z1 - z2;
  return sqsum(dx, dy, dz);
}

template <typename T>
inline const T dist3d(const T &x1, const T &y1, const T &z1, const T &x2,
                      const T &y2, const T &z2)
{
  return sqrt(dist3dSq(x1, y1, z1, x2, y2, z2));
}

template <typename T>
inline const T dist3dSq(const T *pt1, const T *pt2)
{
  const T dx = pt1[0] - pt2[0];
  const T dy = pt1[1] - pt2[1];
  const T dz = pt1[2] - pt2[2];
  return sqsum(dx, dy);
}

template <typename T>
inline const T dist3d(const T *pt1, const T *pt2)
{
  return sqrt(dist3dSq(pt1, pt2));
}

template <typename T>
inline const T angle(const T &x1, const T &y1, const T &x2, const T &y2)
{
  return fixAngle(atan2((y2 - y1), (x2 - x1)));
}

template <class T>
inline TZBYTE getByte(T t, short idxByte)
{
  TZ_ASSERT(idxByte >= 1);
  TZ_ASSERT(idxByte <= 8);
  TZ_ASSERT(idxByte <= (short)sizeof(T));

  static const T BYTE_MAP[] = {
      (T)0x00, (T)0xff, (T)0xff00, (T)0xff0000,
      (T)0xff000000, (T)0xff00000000, (T)0xff0000000000, (T)0xff000000000000};

  static const unsigned int BIT_MAP[] = {0, 0, 8, 16, 24, 32, 40, 48, 56, 64};

  return TZBYTE((t & BYTE_MAP[idxByte]) >> BIT_MAP[idxByte]);
}

template <typename T>
inline bool getBit(T t, short idxBit)
{
  TZ_ASSERT(idxBit >= 1);
  TZ_ASSERT(idxBit <= (short)(sizeof(T) * CHAR_BIT));
  T m = ((T)1) << (idxBit - 1);
  return (t & m) != T(0);
}

inline void tzsrand(unsigned int n) { ::srand(n); }

inline int tzrand() { return ::rand(); }

inline int tzrand(int low, int high)
{
  return static_cast<int>(static_cast<int>(low + (high - low)) *
                          static_cast<float>(rand()) /
                          static_cast<float>(RAND_MAX));
}

inline float tzrand(float low, float high)
{
  return low + (high - low) * static_cast<float>(tzrand()) /
                   static_cast<float>(RAND_MAX);
}

inline double tzrand(double low, double high)
{
  return low + (high - low) * static_cast<double>(tzrand()) /
                   static_cast<double>(RAND_MAX);
}

template <typename T>
inline T tzrand(T low, T high)
{
  return static_cast<T>((low + (high - low)) * static_cast<T>(tzrand()) /
                        static_cast<T>(RAND_MAX));
}

template <typename T>
inline void swapInt(T &x, T &y)
{
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
}

inline TZLONG interlockedIncrement(volatile TZLONG *l)
{
#ifdef TZ_WINDOWS
  return ::InterlockedIncrement(l);
#else
#warning "not implemented yet!!! by mpd\n"
  MPD_FAIL_ONCE();
  TZ_FAIL_ONCE;
#endif
}

inline TZLONG interlockedDecrement(volatile TZLONG *l)
{
#ifdef TZ_WINDOWS
  return ::InterlockedDecrement(l);
#else
#warning "not implemented yet!!! by mpd\n"
  MPD_FAIL_ONCE();
  TZ_FAIL_ONCE;
#endif
}

TZ_NAMESPACE_END(TzSoft)

#endif // !_TZSOFTS_MATH_H_H_
