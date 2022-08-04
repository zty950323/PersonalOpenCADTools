/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_BASIC_OPEN_NO_COPYABLE_CLASS_H_
#define SOURCE_INCLUDE_BASIC_OPEN_NO_COPYABLE_CLASS_H_

namespace Basic
{
#define DISALLOW_COPY_AND_MOVE(className) \
  DISALLOW_COPY(className);               \
  DISALLOW_MOVE(className)

#define DISALLOW_COPY(className)         \
  className(const className &) = delete; \
  className &operator=(const className &) = delete

#define DISALLOW_MOVE(className)    \
  className(className &&) = delete; \
  className &operator=(className &&) = delete

    class TzNoCopyable
    {
    protected:
        TzNoCopyable() {}
        virtual ~TzNoCopyable() {}

    private:
        DISALLOW_COPY_AND_MOVE(TzNoCopyable);
    };
} // namespace Basic

#endif // SOURCE_INCLUDE_BASIC_OPEN_NO_COPYABLE_CLASS_H_
