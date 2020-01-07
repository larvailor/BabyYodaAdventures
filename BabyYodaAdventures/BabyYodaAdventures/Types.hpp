#ifndef TYPES_HPP
#define TYPES_HPP

#include <memory>
#include <vector>
#include <map>
#include <stack>

template<typename T>
template<class T>
using unique = std::unique_ptr<T>;

template<typename T>
template<class T>
using shared = std::shared_ptr<T>;

template<class T>
using shared_vector = std::shared_ptr<std::vector<T>>;

template<typename TKey, typename TValue>
template<typename TKey, class TValue>
using shared_map = std::shared_ptr<std::map<TKey, TValue>>;

template<class T>
using shared_stack = std::shared_ptr<std::stack<T>>;

#endif
