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

#include <cassert>

namespace Base
{
    using namespace std;

    struct TypeData
    {
        TypeData(const char* theName,
            const GeneralType type = GeneralType::badType(),
            const GeneralType theParent = GeneralType::badType(),
            GeneralType::instantiationMethod method = nullptr
        ) : name(theName), parent(theParent), type(type), instMethod(method) { }

        string name;
        GeneralType parent;
        GeneralType type;
        GeneralType::instantiationMethod instMethod;
    };

    map<string, unsigned int> GeneralType::m_typeMap;
    vector<TypeData*> GeneralType::m_typeData;
    set<string> GeneralType::m_loadModuleSet;

    /*-- Construction/Destruction --*/
    /**
     * A constructor.
     * A more elaborate description of the constructor.
     */
    GeneralType::GeneralType()
        : m_index(0)
    {
    }

    GeneralType::GeneralType(const GeneralType& type)
        : m_index(type.m_index)
    {
    }

    /**
     * A destructor.
     * A more elaborate description of the destructor.
     */
    GeneralType::~GeneralType()
    {
    }

    void* GeneralType::createInstance()
    {
        instantiationMethod method = m_typeData[m_index]->instMethod;
        return method ? (*method)() : nullptr;
    }

    void* GeneralType::createInstanceByName(const char* TypeName, bool bLoadModule)
    {
        // if not already, load the module
        if (bLoadModule)
            importModuleByName(TypeName);

        // now the type should be in the type map
        GeneralType t = fromName(TypeName);
        if (t == badType())
            return nullptr;

        return t.createInstance();
    }

    void* GeneralType::createInstanceByName(const std::string& TypeName, bool bLoadModule /*= false*/)
    {
        if (TypeName.size() == 0) {
            return nullptr;
        }

        const auto& nameStr = TypeName.c_str();
        return createInstanceByName(nameStr, bLoadModule);
    }

    void GeneralType::importModuleByName(const char* TypeName)
    {
        // cut out the module name
        string Mod = getModuleName(TypeName);
        // ignore base modules
        if (Mod != "App" && Mod != "Gui" && Mod != "Base") {
            // remember already loaded modules
            set<string>::const_iterator pos = m_loadModuleSet.find(Mod);
            if (pos == m_loadModuleSet.end()) {
                // Interpreter().loadModule(Mod.c_str());
#ifdef TZ_OPEN_LOG_IMPORT_INFO
                Console().Log("Act: Module %s loaded through class %s \n", Mod.c_str(), TypeName);
#endif
                m_loadModuleSet.insert(Mod);
            }
        }
    }

    string GeneralType::getModuleName(const char* ClassName)
    {
        string temp(ClassName);
        string::size_type pos = temp.find_first_of("::");

        if (pos != std::string::npos)
            return string(temp, 0, pos);
        else
            return string();
    }

    GeneralType GeneralType::badType()
    {
        GeneralType bad;
        bad.m_index = 0;
        return bad;
    }

    const GeneralType GeneralType::createType(const GeneralType parent, const char* name, instantiationMethod method)
    {
        GeneralType newType;
        newType.m_index = static_cast<unsigned int>(GeneralType::m_typeData.size());
        TypeData* typeData = new TypeData(name, newType, parent, method);
        GeneralType::m_typeData.push_back(typeData);

        // add to dictionary for fast lookup
        GeneralType::m_typeMap[name] = newType.getKey();

        return newType;
    }


    void GeneralType::init()
    {
        assert(GeneralType::m_typeData.size() == 0);
        GeneralType::m_typeData.push_back(new TypeData("BadType"));
        GeneralType::m_typeMap["BadType"] = 0;
    }

    void GeneralType::destruct()
    {
        for (std::vector<TypeData*>::const_iterator it = m_typeData.begin(); it != m_typeData.end(); ++it)
            delete* it;
        m_typeData.clear();
        m_typeMap.clear();
        m_loadModuleSet.clear();
    }

    GeneralType GeneralType::fromName(const char* name)
    {
        std::map<std::string, unsigned int>::const_iterator pos;

        pos = m_typeMap.find(name);
        if (pos != m_typeMap.end())
            return m_typeData[pos->second]->type;
        else
            return GeneralType::badType();
    }

    GeneralType GeneralType::fromKey(unsigned int key)
    {
        if (key < m_typeData.size())
            return m_typeData[key]->type;
        else
            return GeneralType::badType();
    }

    const char* GeneralType::getName() const
    {
        return m_typeData[m_index]->name.c_str();
    }

    const GeneralType GeneralType::getParent() const
    {
        return m_typeData[m_index]->parent;
    }

    bool GeneralType::isDerivedFrom(const GeneralType type) const
    {

        GeneralType temp(*this);
        do {
            if (temp == type)
                return true;
            temp = temp.getParent();
        } while (temp != badType());

        return false;
    }

    int GeneralType::getAllDerivedFrom(const GeneralType type, std::vector<GeneralType>& List)
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

    int GeneralType::getNumTypes()
    {
        return static_cast<int>(m_typeData.size());
    }

    GeneralType GeneralType::getTypeIfDerivedFrom(const char* name, const GeneralType parent, bool bLoadModule)
    {
        if (bLoadModule)
            importModuleByName(name);

        GeneralType type = fromName(name);

        if (type.isDerivedFrom(parent))
            return type;
        else
            return GeneralType::badType();
    }
}  // namespace Base
