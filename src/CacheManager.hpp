#include "CacheOperation.hpp"

using namespace std;

namespace CacheManager {
    void performOperation(int argc, const char *argv[]);

    string search(const shared_ptr<CacheOperation>& operation);
}