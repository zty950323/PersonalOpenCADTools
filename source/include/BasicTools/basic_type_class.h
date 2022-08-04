/**
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 1. You can modify and use this program at will.
 * 2. But it is suggested that it is more suitable for learning and teaching
 * purposes.
 *
 * @version 1.0
 * @brief This file provides a tool with the capabilities of a basic 64-bit codec.
 * @file main.cpp
 * @author Tom Zhao(18872770445@163.com)
 * @since 2022-07-24
 * @date Created: 2022-07-24
 * @date Last modified: 2022-07-24
 *
 * Github: @link https://github.com/zty950323/PersonalOpenCADTools @endlink
 * Homepage: @link https://blog.csdn.net/zhaotianyu950323 @endlink
 * Blog: @link https://www.zhihu.com/people/Tom_Zhao @endlink
 */

#ifndef BASIC_TYPE_CLASS_H
#define BASIC_TYPE_CLASS_H

#include "basic_export.h"

#include <string>
#include <map>
#include <set>
#include <vector>

namespace Base
{
    struct TypeData;

    class TZ_BASIC_STATIC_EXPORT Type
    {
    public:
        /// Construction
        Type(const Type& type);
        Type();
        /// Destruction
        virtual ~Type();

        /// Creates a instance of this type
        void* createInstance();
        /// Creates a instance of the named type
        static void* createInstanceByName(const char* TypeName, bool bLoadModule = false);
        static void importModule(const char* TypeName);

        typedef void* (*instantiationMethod)();

        static Type fromName(const char* name);
        static Type fromKey(unsigned int key);
        const char* getName() const;
        const Type getParent() const;
        bool isDerivedFrom(const Type type) const;

        static int getAllDerivedFrom(const Type type, std::vector<Type>& List);
        /// Returns the given named type if is derived from parent type, otherwise return bad type
        static Type getTypeIfDerivedFrom(const char* name, const Type parent, bool bLoadModule = false);

        static int getNumTypes();

        static const Type createType(const Type parent, const char* name, instantiationMethod method = nullptr);

        unsigned int getKey() const;
        bool isBad() const;

        void operator=(const Type type);
        bool operator==(const Type type) const;
        bool operator!=(const Type type) const;

        bool operator<(const Type type) const;
        bool operator<=(const Type type) const;
        bool operator>=(const Type type) const;
        bool operator>(const Type type) const;

        static Type badType();
        static void init();
        static void destruct();

    protected:
        static std::string getModuleName(const char* ClassName);

    private:
        unsigned int m_index;

        static std::map<std::string, unsigned int> m_typeMap;
        static std::vector<TypeData*> m_typeData;
        static std::set<std::string> m_loadModuleSet;
    };

    inline unsigned int
        Type::getKey() const
    {
        return this->m_index;
    }

    inline bool
        Type::operator!=(const Type type) const
    {
        return (this->getKey() != type.getKey());
    }

    inline void
        Type::operator=(const Type type)
    {
        this->m_index = type.getKey();
    }

    inline bool
        Type::operator==(const Type type) const
    {
        return (this->getKey() == type.getKey());
    }

    inline bool
        Type::operator<(const Type type) const
    {
        return (this->getKey() < type.getKey());
    }

    inline bool
        Type::operator<=(const Type type) const
    {
        return (this->getKey() <= type.getKey());
    }

    inline bool
        Type::operator>=(const Type type) const
    {
        return (this->getKey() >= type.getKey());
    }

    inline bool
        Type::operator>(const Type type) const
    {
        return (this->getKey() > type.getKey());
    }

    inline bool
        Type::isBad() const
    {
        return (this->m_index == 0);
    }
} // namespace Base

#endif // BASIC_BASE64_H