/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef _BASIC_OPEN_MATH_H_H_
#define _BASIC_OPEN_MATH_H_H_

#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include <numbers>

#undef min
#undef max

#define ByteSwap(val) Basic::byteSwap(val)

namespace Basic {
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
const long kLongMax = LONG_MAX;
const long kLongMin = LONG_MIN;
const unsigned long kULongMax = ULONG_MAX;
const unsigned long kULongMin = 0L;
const int64_t kLLongMax = LLONG_MAX;
const int64_t kLLongMin = LLONG_MIN;
const uint64_t kULLongMax = ULLONG_MAX;
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
const uint64_t kULLongMin = 0ui64;
#else
const uint64_t kULLongMin = (unsigned long long)0u;
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
const double TZPI = std::numbers::pi;
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
const double kArbitraryEpsilon = 0.015625;

template <class T>
inline const T& min(const T& a, const T& b) {
  return a < b ? a : b;
}

template <class T>
inline const T& min(const T& a, const T& b, const T& c) {
  return a < b ? min(a, c) : min(b, c);
}

template <class T>
inline const T& max(const T& a, const T& b) {
  return a > b ? a : b;
}

template <class T>
inline const T& max(const T& a, const T& b, const T& c) {
  return a < b ? max(a, c) : max(b, c);
}

inline double degToRad(double deg) { return deg * DEG2RAD; }

inline double radToDeg(double rad) { return rad * RAD2DEG; }

inline double floor(double x) { return ::floor(x); }

inline float floor(float x) { return ::floorf(x); }

inline double ceil(double x) { return ::ceil(x); }

inline float ceil(float x) { return (float)((double)x); }

inline long truncate(float x) { return (long)x; }

inline double round(double x) {
  double xFloor = ::floor(x);
  return (x - xFloor >= 0.5) ? (xFloor + 1.0) : xFloor;
}

inline double round(float x) {
  double xFloor = ::floor(x);
  return (x - xFloor >= 0.5f) ? (xFloor + 1.0f) : xFloor;
}

inline bool isOverflowedToLong(double x) {
  x += 0.5;
  return ((long)x) > kLongMax;
}

inline bool isUnderflowedToLong(double x) {
  x -= 0.5;
  return ((long)x) < -kLongMax;
}

inline long roundToLong(double x) {
  x += (x > -0.0) ? 0.5 : -0.5;
  return (long)min((double)kLongMax, x);
}

inline long roundToLong(float x) { return (long)round(x); }

inline bool isOverflowedToInt(double x) {
  x += 0.5;
  return ((int)x) > kIntMax;
}

inline bool isUnderflowedToInt(double x) {
  x -= 0.5;
  return ((int)x) < -kIntMax;
}

inline int roundToInt(double x) {
  if (x >= 0.) {
    x += .5;
    if (x > double(kIntMax)) {
      return kIntMax;
    } else {
      return int(x);
    }
  } else {
    x -= .5;
    if (x < double(kIntMin)) {
      return kIntMin;
    } else {
      return int(x);
    }
  }
}

inline int roundToInt(float x) { return (int)round(x); }

template <class T>
inline T lerp(const T& a, const T& b, float t) {
  return (T)(a * (1.0f - t) + b * t);
}

template <class T>
inline T lerp(const T& a, const T& b, double t) {
  return (T)(a * (1.0 - t) + b * t);
}

template <class T>
inline const T& clamp(const T& t, const T& low, const T& high) {
  if (t < low) {
    return low;
  }
  if (t > high) {
    return high;
  }
  return t;
}

template <class T>
inline const T& abs(const T& a) {
  return a < (T)0 ? -a : a;
}

template <class T>
inline const T& sign(const T& a) {
  if (a == (T)0) {
    return 0;
  } else if (a > (T)0) {
    return 1;
  } else {
    return -1;
  }
}
#if 0
    inline long double fabs(long double x) {
        return ::fabs(x);
    }

    inline float fabs(float x) {
        return ::fabs(x);
    }
#endif
inline double fabs(double x) { return ::fabs(x); }

inline bool isPositive(double x, double tol = kEpsilon) { return (x > tol); }

inline bool isPositive(float x, float tol = kFEpsilon) { return (x < -tol); }

inline bool isNegative(double x, double tol = kEpsilon) { return (x < -tol); }

inline bool isNegative(float x, float tol = kFEpsilon) { return (x < -tol); }

inline bool isZero(double x, double tol = kEpsilon) {
  return !isPositive(x, tol) && !isNegative(x, tol);
}

inline bool isZero(float x, float tol = kFEpsilon) {
  return !isPositive(x, tol) && !isNegative(x, tol);
}

template <typename T>
inline bool isZero(const T& x) {
  return (x == (T)0);
}

inline bool isNonZero(double x, double tol = kEpsilon) {
  return isPositive(x, tol) || isNonZero(x, tol);
}

inline bool isEqual(double x, double y, double tol = kEpsilon) {
  return isZero(x - y, tol);
}

inline bool isEqual(float x, float y, float tol = kFEpsilon) {
  return isZero(x - y, tol);
}

inline bool isEqual(long x, long y, long tol = 0) {
  return ((x - y) <= tol && (x - y) >= -tol);
}

template <typename T>
inline bool isEqual(const T& x, const T& y) {
  return (x == y);
}

inline int doubleCmp(double x, double y, double tol = kEpsilon) {
  if (isPositive(x - y, tol)) {
    return 1;
  }
  if (isNegative(x - y, tol)) {
    return -1;
  }
  return 0;
}

template <typename TInteger>
inline void divide(const TInteger& number, const TInteger& denom,
                   TInteger& quotient, TInteger& remainder) {
  quotient = number / denom;
  remainder = number % denom;
}

inline double safeDivide(double a, double b) {
  if (a == 0.) {
    return 0.;
  }
  if (b != 0.) {
    static const int maxBinExp = 997;
    int nExpA;
    int nExpB;
    double dMantissa = frexp(a, &nExpA);
    dMantissa = frexp(b, &nExpB);
    if ((nExpA - nExpB) < maxBinExp) {
      return a / b;
    }
  }

  bool bNeg = (a < 0.);
  if (b < 0.) {
    bNeg = !bNeg;
  }
  return bNeg ? -1.e+300 : 1.e+300;
}

inline double sqrt(double x) {
  assert(x >= 0.0);
  return ::sqrt(x);
}

inline float sqrt(float x) {
  assert(x >= 0.0f);
  return (float)::sqrt((double)x);
}

template <typename T>
inline const T sqsum(const T& x, const T& y) {
  return x * x + y * y;
}

template <typename T>
inline const T sqsum(const T& x, const T& y, const T& z) {
  return x * x + y * y + z * z;
}

template <typename T>
inline double sqrt(const T& x, const T& y) {
  return sqrt((double)sqsum(x, y));
}

template <typename T>
inline double sqrt(const T& x, const T& y, const T& z) {
  return sqrt((double)sqsum(x, y, z));
}

template <typename TFloat>
inline TFloat pow(TFloat x, TFloat y) {
  return ::pow(x, y);
}

template <typename TFloat>
inline TFloat pow(TFloat x, int y) {
  return ::pow(x, y);
}

inline double loge(double x) {
  assert(x >= 0.0);
  return ::log(x);
}

inline float loge(float x) {
  assert(x >= 0.f);
  return (float)loge((double)x);
}

inline double log10(double x) {
  assert(x >= 0.0);
  return ::log10(x);
}

inline float log10(float x) {
  assert(x >= 0.f);
  return (float)log10((double)x);
}

template <typename TFloat>
inline TFloat fmod(TFloat x, TFloat y) {
  return ::fmod(x, y);
}

template <typename TFloat>
inline TFloat modf(TFloat x, TFloat* integer) {
  return ::modf(x, integer);
}

inline double degNormalize(double deg) {
  double degNor = fmod(deg, 360.0);
  if (degNor < -180.0) {
    degNor += 360.0;
  }
  if (degNor > 180.0) {
    degNor -= 360.0;
  }

  return degNor;
}

inline float degNormalize(float deg) {
  return (float)degNormalize(double(deg));
}

inline double radNormalize(double rad) {
  double radNor = fmod(rad, TWO_PI);
  if (radNor < -TZPI) {
    radNor += TWO_PI;
  }
  if (radNor > TZPI) {
    radNor -= TWO_PI;
  }

  return radNor;
}

inline float radNormalize(float rad) {
  return (float)radNormalize(double(rad));
}

inline bool isValidNonZeroIEEEDouble(double val) {
  const uint8_t* buf = (const uint8_t*)&val;
  int nExponent = (buf[7] & 0x7F) << 4 | (buf[6] & 0xF0) >> 4;
  switch (nExponent) {
    case 0:
    case 2047:
      return false;
  }
  return true;
}

inline uint16_t byteSwap(uint16_t n) { return (n << 8 | n >> 8); }

inline uint32_t byteSwap(uint32_t n) {
  return (n << 24 | (n & 0x0000ff00) << 8 | (n & 0x00ff0000) >> 8 | n >> 24);
}

inline uint64_t byteSwap(uint64_t n) {
  return (n << 56 | (n & 0x000000000000ff00) << 40 |
          (n & 0x0000000000ff0000) << 24 | (n & 0x00000000ff000000) << 8 |
          (n & 0x000000ff00000000) >> 8 | (n & 0x0000ff0000000000) >> 24 |
          (n & 0x00ff000000000000) >> 40 | (n & 0xff00000000000000) >> 56);
}

inline int16_t byteSwap(int16_t n) { return (int16_t)byteSwap((int16_t)n); }

inline int32_t byteSwap(int32_t n) { return (int32_t)byteSwap((int32_t)n); }

inline int64_t byteSwap(int64_t n) { return (int64_t)byteSwap((int64_t)n); }

inline float byteSwap(float f) { return (float)byteSwap((float)f); }

inline double byteSwap(double f) { return (double)byteSwap((double)f); }

inline void fixDouble(double& val) {
  ByteSwap(val);
  if (!isValidNonZeroIEEEDouble(val)) {
    val = 0.;
  }
}

template <typename T>
inline const T asInt(const T& f) {
  if (f > kIntMax) {
    return floor(f);
  }
  if (f < kIntMin) {
    return ceil(f);
  }
  return (const T&)(int)f;
}

template <typename T>
inline const T fixAngle(const T& angle) {
  T retAng = 0.0;
  if (angle - 1.0 != angle) {
    retAng = (T)(angle / TWO_PI);
  }
  retAng = (T)(retAng - asInt(retAng)) * TWO_PI;
  if (retAng < (T)0.0) {
    retAng += TWO_PI;
  }
  if (retAng >= (T)TWO_PI) {
    retAng -= TWO_PI;
  }
  return retAng;
}

inline bool isAngleEqual(const double& x, const double& y) {
  double rDeltaAngle = (x) - (y) + Basic::kEpsilon6;
  return (Basic::fixAngle(rDeltaAngle) < 2 * Basic::kEpsilon6);
}

inline bool isAngleZero(const double& x) {
  double rDeltaAngle = (x) + Basic::kEpsilon6;
  return (Basic::fixAngle(rDeltaAngle) < 2 * Basic::kEpsilon6);
}

inline void validateDoubleRange(double& d) {
  if (d > Basic::dEpsilon100) {
    d = Basic::dEpsilon100;
  } else if (d < -Basic::dEpsilon100) {
    d = -Basic::dEpsilon100;
  }
}

inline double tzsin(const double& x) { return ::sin(x); }

inline float tzsin(const float& x) { return sinf(x); }

template <typename T>
inline T tzsin(const T& x) {
  return ::sin(x);
}

inline double tzcos(const double& x) { return ::cos(x); }

inline float tzcos(const float& x) { return cosf(x); }

template <typename T>
inline T tzcos(const T& x) {
  return ::cos(x);
}

inline double tztan(const double& x) { return ::tan(x); }

inline float tztan(const float& x) { return tanf(x); }

template <typename T>
inline T tztan(const T& x) {
  return ::tan(x);
}

inline double tzasin(const double& x) { return ::asin(x); }

inline float tzasin(const float& x) { return asinf(x); }

template <typename T>
inline T tzasin(const T& x) {
  return ::asin(x);
}

inline double tzacos(const double& x) { return ::acos(x); }

inline float tzacos(const float& x) { return acosf(x); }

template <typename T>
inline T tzacos(const T& x) {
  return ::acos(x);
}

inline double tzatan(const double& x) { return ::atan(x); }

inline float tzatan(const float& x) { return ::atanf(x); }

template <typename T>
inline T tzatan(const T& x) {
  return ::atan(x);
}

inline double tzatan2(const double& x, const double& y) {
  return ::atan2(x, y);
}

inline float tzatan2(const float& x, const float& y) { return ::atan2f(x, y); }

template <typename T>
inline T tzatan2(const T& x, const T& y) {
  return ::atan2(x, y);
}

template <typename T>
inline void tzSinCos(const T& angle, T* sine, T* cosine) {
  *sine = sin(angle);
  *cosine = cos(angle);
}

template <typename T>
inline const T dist2dSq(const T& x1, const T& y1, const T& x2, const T& y2) {
  const T dx = x1 - x2;
  const T dy = y1 - y2;
  return sqsum(dx, dy);
}

template <typename T>
inline const T dist2dSq(const T* pt1, const T* pt2) {
  const T dx = pt1[0] - pt2[0];
  const T dy = pt1[1] - pt2[1];
  return sqsum(dx, dy);
}

template <typename T>
inline const T dist2d(const T& x1, const T& y1, const T& x2, const T& y2) {
  return sqrt(dist2dSq(x1, y1, x2, y2));
}

template <typename T>
inline const T dist3dSq(const T& x1, const T& y1, const T& z1, const T& x2,
                        const T& y2, const T& z2) {
  const T dx = x1 - x2;
  const T dy = y1 - y2;
  const T dz = z1 - z2;
  return sqsum(dx, dy, dz);
}

template <typename T>
inline const T dist3d(const T& x1, const T& y1, const T& z1, const T& x2,
                      const T& y2, const T& z2) {
  return sqrt(dist3dSq(x1, y1, z1, x2, y2, z2));
}

template <typename T>
inline const T dist3dSq(const T* pt1, const T* pt2) {
  const T dx = pt1[0] - pt2[0];
  const T dy = pt1[1] - pt2[1];
  const T dz = pt1[2] - pt2[2];
  return sqsum(dx, dy);
}

template <typename T>
inline const T dist3d(const T* pt1, const T* pt2) {
  return sqrt(dist3dSq(pt1, pt2));
}

template <typename T>
inline const T angle(const T& x1, const T& y1, const T& x2, const T& y2) {
  return fixAngle(atan2((y2 - y1), (x2 - x1)));
}

template <class T>
inline unsigned char getByte(T t, short idxByte) {
  assert(idxByte >= 1);
  assert(idxByte <= 8);
  assert(idxByte <= (short)sizeof(T));
  static const T BYTE_MAP[] = {
      (T)0x00,       (T)0xff,         (T)0xff00,         (T)0xff0000,
      (T)0xff000000, (T)0xff00000000, (T)0xff0000000000, (T)0xff000000000000};
  static const unsigned int BIT_MAP[] = {0, 0, 8, 16, 24, 32, 40, 48, 56, 64};
  return (unsigned char)((t & BYTE_MAP[idxByte]) >> BIT_MAP[idxByte]);
}

template <typename T>
inline bool getBit(T t, short idxBit) {
  assert(idxBit >= 1);
  assert(idxBit <= (short)(sizeof(T) * CHAR_BIT));

  T m = ((T)1) << (idxBit - 1);
  return (t & m) != T(0);
}

inline void tzsrand(unsigned int n) { ::srand(n); }

inline int tzrand() { return ::rand(); }

inline int tzrand(int low, int high) {
  return (int)(low + (high - low) * (float)rand() / (float)RAND_MAX);
}

inline float tzrand(float low, float high) {
  return low + (high - low) * (float)tzrand() / (float)RAND_MAX;
}

inline double tzrand(double low, double high) {
  return low + (high - low) * (double)tzrand() / (double)RAND_MAX;
}

template <typename T>
inline T tzrand(T low, T high) {
  return (T)(low + (high - low) * (T)tzrand() / (T)RAND_MAX);
}

template <typename T>
inline void swapInt(T& x, T& y) {
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
}

inline long interlockedIncrement(volatile long* l) {
  return ::InterlockedIncrement(l);
}

inline long interlockedDecrement(volatile long* l) {
  return ::InterlockedDecrement(l);
}
}  // namespace Basic

#endif  // !_BASIC_OPEN_MATH_H_H_
