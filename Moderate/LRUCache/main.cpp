#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_map>

using namespace std;

// a simplier version of LRU cache

class LRUCache {
    // store keys of cache
    list<int> deq;

    // store references of key in cache
    unordered_map<int, list<int>::iterator> m;
    int csize;
public:
    LRUCache(int);
    void refer(int);
    void display();
};

LRUCache::LRUCache(int n){
    csize = n;
}

void LRUCache::refer(int val){
    if (m.find(val) == m.end()){
        if(deq.size() == csize){
            int last = deq.back();
            deq.pop_back();
            m.erase(last);
        }
    } else {
        deq.erase(m.at(val));
    }

    deq.push_front(val);
    m[val] = deq.begin();
}

void LRUCache::display(){
    for (auto it = deq.begin(); it != deq.end(); it++){
        cout << (*it) << " " ;
    }
    cout << endl;
}

int main()
{
    LRUCache cache(4);
    cache.refer(1);
    cache.refer(2);
    cache.refer(3);
    cache.refer(1);
    cache.refer(4);
    cache.refer(5);
    cache.display();
    return 0;
}
