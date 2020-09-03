#pragma once

#include "Operation.hpp"

using namespace std;

namespace CacheManager {
    void performOperation(Operation*& operation);

    string search(Operation*& operation);
}