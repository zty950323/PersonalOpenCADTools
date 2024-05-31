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

    class TZ_BASIC_STATIC_EXPORT GeneralType
    {
    public:
        typedef void* (*instantiationMethod)();

        /// Construction
        GeneralType(const GeneralType& type);
        GeneralType();
        /// Destruction
        virtual ~GeneralType();

        /// Creates a instance of this type
        void* createInstance();
        /// Creates a instance of the named type
        static void* createInstanceByName(const char* TypeName, bool bLoadModule = false);
        static void* createInstanceByName(const std::string& TypeName, bool bLoadModule = false);
        static void importModuleByName(const char* TypeName);

        static GeneralType badType();
        static void init();
        static void destruct();

        static int getAllDerivedFrom(const GeneralType type, std::vector<GeneralType>& List);
        /// Returns the given named type if is derived from parent type, otherwise return bad type
        static GeneralType getTypeIfDerivedFrom(const char* name, const GeneralType parent, bool bLoadModule = false);
        static int getNumTypes();
        static const GeneralType createType(const GeneralType parent, const char* name, instantiationMethod method = nullptr);

        static GeneralType fromName(const char* name);
        static GeneralType fromKey(unsigned int key);

        const char* getName() const;
        const GeneralType getParent() const;
        bool isDerivedFrom(const GeneralType type) const;

        unsigned int getKey() const;
        bool isBad() const;

        // Define some operators.
        void operator=(const GeneralType type);
        bool operator==(const GeneralType type) const;
        bool operator!=(const GeneralType type) const;

        bool operator<(const GeneralType type) const;
        bool operator<=(const GeneralType type) const;
        bool operator>=(const GeneralType type) const;
        bool operator>(const GeneralType type) const;

    protected:
        static std::string getModuleName(const char* ClassName);

    private:
        unsigned int m_index;

        static std::map<std::string, unsigned int> m_typeMap;
        static std::vector<TypeData*> m_typeData;
        static std::set<std::string> m_loadModuleSet;
    };

    inline unsigned int GeneralType::getKey() const
    {
        return m_index;
    }

    inline bool GeneralType::operator!=(const GeneralType type) const
    {
        return (getKey() != type.getKey());
    }

    inline void GeneralType::operator=(const GeneralType type)
    {
        m_index = type.getKey();
    }

    inline bool GeneralType::operator==(const GeneralType type) const
    {
        return (getKey() == type.getKey());
    }

    inline bool GeneralType::operator<(const GeneralType type) const
    {
        return (getKey() < type.getKey());
    }

    inline bool GeneralType::operator<=(const GeneralType type) const
    {
        return (getKey() <= type.getKey());
    }

    inline bool GeneralType::operator>=(const GeneralType type) const
    {
        return (getKey() >= type.getKey());
    }

    inline bool GeneralType::operator>(const GeneralType type) const
    {
        return (getKey() > type.getKey());
    }

    inline bool GeneralType::isBad() const
    {
        return (m_index == 0);
    }
}  // namespace Base

#endif // BASIC_BASE64_H
