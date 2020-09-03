#pragma once

#include "Operation.hpp"

using namespace std;

namespace CacheManager {
    void performOperation(Operation*& operation, bool isSearched, bool isClear);

    string search(Operation*& operation);
}