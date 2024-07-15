//
// This file contains the implementation of the MultiMap class template.
// MultiMap is a container that allows mapping of keys to values, where each key can have multiple values.
//
// Author: eylony1403@gmail.com

#pragma once

#include <map>
#include <vector>
#include <string>

template <typename T>
class MultiMap
{
public:
    /**
     * Returns a reference to the value associated with the given index.
     * The index is used to access the value in the internal map.
     * Throws an exception if the index is out of range.
     *
     * @param key The index used to access the value.
     * @return A reference to the value associated with the given index.
     * @throws std::out_of_range if the index is out of range.
     */
    T &getValueByIndex(int key);

    /**
     * Returns a reference to the value associated with the given key.
     * The key is used to access the value in the internal map.
     * Throws an exception if the key is not found.
     *
     * @param key The key used to access the value.
     * @return A reference to the value associated with the given key.
     * @throws std::out_of_range if the key is not found.
     */
    T &getValueByKey(std::string key);

    /**
     * Adds a new key-value pair to the MultiMap.
     * The key is associated with the given value.
     * The keyStr is used as the key in the internal map.
     *
     * @param key The index associated with the value.
     * @param keyStr The key used to access the value.
     * @param value The value to be associated with the key.
     */
    void addValue(int key, std::string keyStr, T value);

    /**
     * Checks if the MultiMap contains the given key.
     *
     * @param key The key to be checked.
     * @return true if the key is found, false otherwise.
     */
    bool containsKey(std::string key);

    /**
     * Checks if the MultiMap contains the given index.
     *
     * @param key The index to be checked.
     * @return true if the index is within the range of the internal map, false otherwise.
     */
    bool containsIndex(int key);

    /**
     * Returns the index associated with the given key.
     *
     * @param key The key used to find the index.
     * @return The index associated with the given key, or -1 if the key is not found.
     */
    int getIndexByKey(std::string key);

    /**
     * Returns the key associated with the given index.
     * Throws an exception if the index is out of range.
     *
     * @param key The index used to find the key.
     * @return The key associated with the given index.
     * @throws std::out_of_range if the index is out of range.
     */
    std::string getKeyByIndex(int key);

private:
    std::vector<std::string> _translator; // Stores the keys in the order they were added
    std::map<std::string, T> _map; // Stores the key-value pairs
};
