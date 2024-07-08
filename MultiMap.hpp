// @author: eylony1403@gmail.com

#pragma once

#include <map>
#include <vector>
#include <string>

template <typename T>
class MultiMap
{
public:
    MultiMap() {}

    T &getValueByIndex(int key) const
    {
        std::string keyStr = _translator[key];
        return _map.at(keyStr);
    }

    T &getValueByKey(std::string key) const
    {
        return _map.at(key);
    }

    void addValue(int key, std::string keyStr, T value)
    {
        _translator[key] = keyStr;
        _map[keyStr] = value;
    }

private:
    std::vector<std::string> _translator;
    std::map<std::string, T> _map;
};