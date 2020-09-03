#pragma once

#include "Operation.hpp"

using namespace std;

namespace CacheManager {
    /**
     * @brief Does an operation.
     * 
     * @param operation - the operation.
     * @param isSearched - is the operation is searched or not.
     * @param isClear - if the operation is clear or not.
     */
    void performOperation(Operation* operation, bool isSearched, bool isClear);

    /**
     * @brief Search an operation in the cache.
     * 
     * @param operation
     * @return string 
     */
    string search(Operation* operation);
}