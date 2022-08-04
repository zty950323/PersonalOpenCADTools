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

#include "BasicTools/basic_type_class.h"

# include <cassert>

namespace Base
{
    using namespace std;
    struct TypeData
    {
        TypeData(const char* theName,
            const Type type = Type::badType(),
            const Type theParent = Type::badType(),
            Type::instantiationMethod method = nullptr
        ) : name(theName), parent(theParent), type(type), instMethod(method) { }

        string name;
        Type parent;
        Type type;
        Type::instantiationMethod instMethod;
    };

    map<string, unsigned int> Type::m_typeMap;
    vector<TypeData*> Type::m_typeData;
    set<string> Type::m_loadModuleSet;

    /*-- Construction/Destruction --*/
    /**
    * A constructor.
    * A more elaborate description of the constructor.
    */
    Type::Type()
        : m_index(0)
    {
    }


    Type::Type(const Type& type)
        : m_index(type.m_index)
    {
    }

    /**
    * A destructor.
    * A more elaborate description of the destructor.
    */
    Type::~Type()
    {
    }

    void* Type::createInstance()
    {
        instantiationMethod method = m_typeData[m_index]->instMethod;
        return method ? (*method)() : nullptr;
    }

    void* Type::createInstanceByName(const char* TypeName, bool bLoadModule)
    {
        // if not already, load the module
        if (bLoadModule)
            importModule(TypeName);

        // now the type should be in the type map
        Type t = fromName(TypeName);
        if (t == badType())
            return nullptr;

        return t.createInstance();
    }

    void Type::importModule(const char* TypeName)
    {
        // cut out the module name
        string Mod = getModuleName(TypeName);
        // ignore base modules
        if (Mod != "App" && Mod != "Gui" && Mod != "Base") {
            // remember already loaded modules
            set<string>::const_iterator pos = m_loadModuleSet.find(Mod);
            if (pos == m_loadModuleSet.end()) {
                // Interpreter().loadModule(Mod.c_str());
#ifdef TZOT_LOG_LOAD_MODULE
                Console().Log("Act: Module %s loaded through class %s \n", Mod.c_str(), TypeName);
#endif
                m_loadModuleSet.insert(Mod);
            }
        }
    }

    string Type::getModuleName(const char* ClassName)
    {
        string temp(ClassName);
        std::string::size_type pos = temp.find_first_of("::");

        if (pos != std::string::npos)
            return string(temp, 0, pos);
        else
            return string();
    }

    Type Type::badType()
    {
        Type bad;
        bad.m_index = 0;
        return bad;
    }

    const Type Type::createType(const Type parent, const char* name, instantiationMethod method)
    {
        Type newType;
        newType.m_index = static_cast<unsigned int>(Type::m_typeData.size());
        TypeData* typeData = new TypeData(name, newType, parent, method);
        Type::m_typeData.push_back(typeData);

        // add to dictionary for fast lookup
        Type::m_typeMap[name] = newType.getKey();

        return newType;
    }


    void Type::init()
    {
        assert(Type::m_typeData.size() == 0);
        Type::m_typeData.push_back(new TypeData("BadType"));
        Type::m_typeMap["BadType"] = 0;
    }

    void Type::destruct()
    {
        for (std::vector<TypeData*>::const_iterator it = m_typeData.begin(); it != m_typeData.end(); ++it)
            delete* it;
        m_typeData.clear();
        m_typeMap.clear();
        m_loadModuleSet.clear();
    }

    Type Type::fromName(const char* name)
    {
        std::map<std::string, unsigned int>::const_iterator pos;

        pos = m_typeMap.find(name);
        if (pos != m_typeMap.end())
            return m_typeData[pos->second]->type;
        else
            return Type::badType();
    }

    Type Type::fromKey(unsigned int key)
    {
        if (key < m_typeData.size())
            return m_typeData[key]->type;
        else
            return Type::badType();
    }

    const char* Type::getName() const
    {
        return m_typeData[m_index]->name.c_str();
    }

    const Type Type::getParent() const
    {
        return m_typeData[m_index]->parent;
    }

    bool Type::isDerivedFrom(const Type type) const
    {

        Type temp(*this);
        do {
            if (temp == type)
                return true;
            temp = temp.getParent();
        } while (temp != badType());

        return false;
    }

    int Type::getAllDerivedFrom(const Type type, std::vector<Type>& List)
    {
        int cnt = 0;

        for (std::vector<TypeData*>::const_iterator it = m_typeData.begin(); it != m_typeData.end(); ++it)
        {
            if ((*it)->type.isDerivedFrom(type))
            {
                List.push_back((*it)->type);
                cnt++;
            }
        }
        return cnt;
    }

    int Type::getNumTypes()
    {
        return static_cast<int>(m_typeData.size());
    }

    Type Type::getTypeIfDerivedFrom(const char* name, const Type parent, bool bLoadModule)
    {
        if (bLoadModule)
            importModule(name);

        Type type = fromName(name);

        if (type.isDerivedFrom(parent))
            return type;
        else
            return Type::badType();
    }
}  // namespace Base
