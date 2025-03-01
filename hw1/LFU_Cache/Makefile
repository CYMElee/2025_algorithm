CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OBJS = LFUCache.o main.o


TARGET = LFUCache

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)
