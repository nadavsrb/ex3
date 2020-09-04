#pragma once

#include "Operation.hpp"
#include <string>
#include <memory>

using namespace std;
class Operation;
class CacheManager {
public:
    CacheManager(unique_ptr<Operation>& op);

    /**
     * @brief Does an operation.
     * 
     * @param operation - the operation.
     * @param isSearched - is the operation is searched or not.
     * @param isClear - if the operation is clear or not.
     */
    void performOperation(bool isSearched, bool isClear);

    /**
     * @brief Search an operation in the cache.
     * 
     * @param operation
     * @return string 
     */
    string search();

private:
    unique_ptr<Operation> _operation;
};