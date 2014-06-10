CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11
OBJS =	sdl_utils.o Bullet.o Tank.o Entity.o utils/point_vector.o main.o
TARGET =		main
LIBS = -lSDL -lSDL_image -lSDL_ttf 

TEST_LIBS = -lboost_unit_test_framework
TEST_TARGET = tests/test.cpp
SOURCES = sdl_utils.cpp Bullet.cpp Tank.cpp Entity.cpp utils/point_vector.cpp

$(TARGET):	$(OBJS)
			$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
		rm -f $(OBJS) $(TARGET) test

run:	$(TARGET)
		./$(TARGET)

# should fix test -- it's not done correctly
test:	$(TARGET)
		$(CXX) $(TEST_TARGET) $(SOURCES) $(LIBS) $(TEST_LIBS) $(CXXFLAGS) -o test
		./test


