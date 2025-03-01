#include <iostream>
#include <vector>
#include "LRUCache.hpp"  // 確保這裡有包含 LRUCache.h

int main() {
    // 模擬輸入
    std::vector<std::string> operations = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    std::vector<std::vector<int>> values = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};

    // 輸出輸入的操作和參數
    std::cout << "Input Operations: [";
    for (size_t i = 0; i < operations.size(); ++i) {
        std::cout << "\"" << operations[i] << "\"";
        if (i < operations.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    std::cout << "Input Values: [";
    for (size_t i = 0; i < values.size(); ++i) {
        std::cout << "{";
        for (size_t j = 0; j < values[i].size(); ++j) {
            std::cout << values[i][j];
            if (j < values[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}";
        if (i < values.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    // 儲存輸出結果
    std::vector<std::string> output;

    LRUCache* cache = nullptr;

    for (size_t i = 0; i < operations.size(); ++i) {
        const std::string& op = operations[i];
        
        if (op == "LRUCache") {
            // 初始化 LRUCache
            int capacity = values[i][0];
            cache = new LRUCache(capacity);
            output.push_back("null"); // 對於初始化，使用 "null"
        } 
        else if (op == "put") {
            // 調用 put 方法
            int key = values[i][0];
            int value = values[i][1];
            cache->put(key, value);
            output.push_back("null"); // put 方法不返回值，使用 "null"
        } 
        else if (op == "get") {
            // 調用 get 方法
            int key = values[i][0];
            int result = cache->get(key);
            output.push_back(result == -1 ? "-1" : std::to_string(result)); // 將結果轉換為字符串
        }
    }

    // 輸出結果
    std::cout << "Output: [";
    for (size_t i = 0; i < output.size(); ++i) {
        std::cout << output[i];
        if (i < output.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    // 釋放資源
    delete cache;

    return 0;
}
