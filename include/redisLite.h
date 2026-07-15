#include "../include/hashMap.h"
#include "../include/dynamicArray.h"
#include <string>
#include <sstream>
using namespace std;
class RedisLite{
private:
    HashMap<string, string> store;
    string toLower(const string& str);
    void set(string& key, string& value);
    void get(string& key);
    void remove(string& key);
    void exists(string& key);
    void count();
    void clear();
    void show();
public:
    RedisLite() = default;
    void run();
};