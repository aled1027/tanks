#include "utils/point_vector.h"
#include "Entity.h"
#include "Tank.h"
#include <iostream>

int main() {

    Point p(-1.0,-2.0);
    Entity ent_def();
    Entity ent_norm(p,1.0,2.0,3.0,4.0,5.0);

    std::cout << "exiting..." << std::endl;
    return 0;
}
