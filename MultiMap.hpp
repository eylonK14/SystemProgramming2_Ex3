// @author: eylony1403@gmail.com

#pragma once

#include <map>
#include <vector>
#include <string>

template <typename T>
class MultiMap
{
public:
    T &getValueByIndex(int key)
    {
        size_t i = static_cast<size_t>(key);
        return _map.at(_translator[i]);
    }

    T &getValueByKey(std::string key)
    {
        return _map.at(key);
    }

    void addValue(int key, std::string keyStr, T value)
    {
        size_t i = static_cast<size_t>(key);
        _map.insert(std::make_pair(keyStr, value));
        _translator.push_back(keyStr);
    }

    bool containsKey(std::string key)
    {
        return _map.find(key) != _map.end();
    }

    bool containsIndex(int key)
    {
        size_t i = static_cast<size_t>(key);
        return i < _translator.size();
    }

    int getIndexByKey(std::string key)
    {
        std::vector<std::string>::iterator itr = std::find(_translator.begin(), _translator.end(), key);
        if (itr != _translator.cend())
        {
            return std::distance(_translator.begin(), itr);
        }
        return -1;
    }

    std::string getKeyByIndex(int key)
    {
        return _translator[key];
    }

private:
    std::vector<std::string> _translator;
    std::map<std::string, T> _map;
};