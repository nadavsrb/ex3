#pragma once

#include "Operation.hpp"

using namespace std;

namespace CacheManager {
    void performOperation(unique_ptr<Operation>& operation, bool isSearched, bool isClear);

    string search(unique_ptr<Operation>& operation);
}