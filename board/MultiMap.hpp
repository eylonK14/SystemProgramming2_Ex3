// @author: eylony1403@gmail.com

#pragma once

#include <map>
#include <vector>
#include <string>

/**
 * @brief A class representing a MultiMap data structure.
 *
 * @tparam T The type of values stored in the MultiMap.
 */
template <typename T>
class MultiMap
{
public:
    /**
     * @brief Get the value at the specified index.
     *
     * @param key The index of the value to retrieve.
     * @return T& A reference to the value at the specified index.
     */
    T &getValueByIndex(int key)
    {
        size_t i = static_cast<size_t>(key);
        return _map.at(_translator[i]);
    }

    /**
     * @brief Get the value associated with the specified key.
     *
     * @param key The key of the value to retrieve.
     * @return T& A reference to the value associated with the specified key.
     */
    T &getValueByKey(std::string key)
    {
        return _map.at(key);
    }

    /**
     * @brief Add a value to the MultiMap.
     *
     * @param key The index of the value.
     * @param keyStr The key associated with the value.
     * @param value The value to add.
     */
    void addValue(int key, std::string keyStr, T value)
    {
        size_t i = static_cast<size_t>(key);
        _map.insert(std::make_pair(keyStr, value));
        _translator.push_back(keyStr);
    }

    /**
     * @brief Check if the MultiMap contains the specified key.
     *
     * @param key The key to check.
     * @return true if the MultiMap contains the key, false otherwise.
     */
    bool containsKey(std::string key)
    {
        return _map.find(key) != _map.end();
    }

    /**
     * @brief Check if the MultiMap contains the specified index.
     *
     * @param key The index to check.
     * @return true if the MultiMap contains the index, false otherwise.
     */
    bool containsIndex(int key)
    {
        size_t i = static_cast<size_t>(key);
        return i < _translator.size();
    }

    /**
     * @brief Get the index associated with the specified key.
     *
     * @param key The key to search for.
     * @return int The index associated with the key, or -1 if the key is not found.
     */
    int getIndexByKey(std::string key)
    {
        std::vector<std::string>::iterator itr = std::find(_translator.begin(), _translator.end(), key);
        if (itr != _translator.cend())
        {
            return std::distance(_translator.begin(), itr);
        }
        return -1;
    }

    /**
     * @brief Get the key at the specified index.
     *
     * @param key The index of the key to retrieve.
     * @return std::string The key at the specified index.
     */
    std::string getKeyByIndex(int key)
    {
        return _translator[key];
    }

private:
    std::vector<std::string> _translator; // Stores the keys in the MultiMap
    std::map<std::string, T> _map;        // Stores the values in the MultiMap
};