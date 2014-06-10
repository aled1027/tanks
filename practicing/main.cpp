#include "h.h"
#include "class.h"

#include <iostream>
using namespace std;

int global = 0;

int main() {
    cout << global << endl;
    cout << global << endl;
    callMe();
    cout << global << endl;
    return 0;
}
