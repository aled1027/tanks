CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11
OBJS =	Tank.o Entity.o utils/point_vector.o 
LIBS =
TARGET =		main

TEST_LIBS = -lboost_unit_test_framework
TEST_TARGET = tests/test.cpp
SOURCES = Tank.cpp Entity.cpp utils/point_vector.cpp

$(TARGET):	$(OBJS)
			$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
		rm -f $(OBJS) $(TARGET)

run:	$(TARGET)
		./$(TARGET)

# should fix test -- it's not done correctly
test:	$(TARGET)
		$(CXX) $(TEST_TARGET) $(SOURCES) $(LIBS) $(TEST_LIBS) $(CXXFLAGS)
