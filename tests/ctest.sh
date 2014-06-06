#g++ test.cpp Entity.cpp -lboost_unit_test_framework -o test
g++ -o test.o ../Entity.o ../utils/point_vector.o -lboost_unit_test_framework

