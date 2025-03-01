#include <iostream>
#include <vector>
#include <string>
#include "LFUCache.hpp"

using namespace std;

int main() {
    // Input
    vector<string> commands = {"LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"};
    vector<vector<int>> values = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {3}, {4, 4}, {1}, {3}, {4}};

    vector<string> output;  // 使用 string 來儲存 null
    LFUCache* cache = nullptr;

    // 顯示 Input
    cout << "Input:" << endl;
    cout << "[";
    for (size_t i = 0; i < commands.size(); ++i) {
        cout << "\"" << commands[i] << "\"";
        if (i < commands.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < values[i].size(); ++j) {
            cout << values[i][j];
            if (j < values[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < values.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // 執行指令
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "LFUCache") {
            cache = new LFUCache(values[i][0]);
            output.push_back("null");
        } else if (commands[i] == "put") {
            cache->put(values[i][0], values[i][1]);
            output.push_back("null");
        } else if (commands[i] == "get") {
            int result = cache->get(values[i][0]);
            output.push_back(to_string(result));
        }
    }

    // 顯示 Output
    cout << "Output:" << endl;
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i < output.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // 釋放記憶體
    if (cache) {
        delete cache;
    }

    return 0;
}
