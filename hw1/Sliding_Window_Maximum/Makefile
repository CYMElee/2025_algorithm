CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OBJS = Sliding_Window_Maximum.o


TARGET = Sliding_Window_Maximum

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)