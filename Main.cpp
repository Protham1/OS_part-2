#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include "Cache.h"

using namespace std;

void readConfig(int& c, int& b, int& n) {
    cout << "Enter cache size (C): ";
    cin >> c;
    cout << "Enter block size (B): ";
    cin >> b;
    cout << "Enter associativity (N): ";
    cin >> n;
}

int main(int argc, char** argv) {
    int c, b, n;
    readConfig(c, b, n);
    G::Cache cache2(c, b, n);
    cache2.readMemory();
    cache2.testMem();
    return 0;
}
