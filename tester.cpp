#include "CacheOperation.hpp"
#include <iostream>
#include <ctime>
#include  "CurrentTime.hpp"

using namespace std;
int main() {
    CurrentTime ct = CurrentTime();
    cout<<ct.getTime();
    return 0;
}
