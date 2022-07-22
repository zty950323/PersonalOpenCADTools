#ifndef  TZSTD_MAP_VALUE_FINDER_H
#define TZSTD_MAP_VALUE_FINDER_H

#include <map>
#include <utility>

template<class Key, class Value>
class TzStdMapValueFinder
{
public:
    TzStdMapValueFinder(Value & value, Key & key) : m_key(key), m_value(value)
    {

    }
    bool operator() (const typename std::map<Key, Value>::value_type & sPair)
    {
        if (sPair.second == m_value)
        {
            return true;
        }
        return false;
    }
private:
    const Key & m_key;
    const typename Value& m_value;
};

#endif