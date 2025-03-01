# 定義編譯器和編譯選項
CXX = g++
CXXFLAGS = -Wall -g

# 定義可執行檔名稱
TARGET = lru_cache_example

# 定義源文件
SRCS = main.cpp LRUCache.cpp
# 定義頭文件
HEADERS = LRUCache.h

# 定義對應的物件文件
OBJS = $(SRCS:.cpp=.o)

# 默認目標
all: $(TARGET)

# 編譯可執行檔
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 編譯每個源文件
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理編譯產物
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
