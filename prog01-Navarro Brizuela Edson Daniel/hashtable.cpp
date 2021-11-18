#include <iostream>
#include <list>
#include <cstring>
using namespace std;

// Hashtable to implement 905, Jimmy

class HashTable{
    private:
        static const int hashGroup = 10;
        list<pair<int, string>> table[hashGroup];   //list 1, index 0, list 2, index 1
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const{
    int sum{};
    for(int i = 0; i < hashGroup; i++){
        sum += table[i].size();
    }
    if(!sum){
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key){
    return key % hashGroup; //Key: 905, in return, this function wil split out 5
}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exist. Value replaced. " << endl;
            break;
        }
    }
    if(!keyExists){
        cell.emplace_back(key, value);
    }
    return;
}

void HashTable::removeItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++){
        if(bItr->first == key){
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed. " << endl;
            break;
        }
    }

    if(!keyExists){
        cout << "[WARNING] Item not found. " << endl;
    }
    return;
}

void HashTable::printTable(){
    for(int i{}; i < hashGroup; i++){
        if(table[i].size() == 0) continue;
        auto bItr = table[i].begin();
        for(; bItr != table[i].end(); bItr++){
            cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}

int main(){
    HashTable ht;
    if(ht.isEmpty()){
        cout << "[INFO] Correct answer. " << endl;
    } else{
        cout << "[ERROR] Incorrect answer. " << endl;
    }

    ht.insertItem(905, "Jimmy");
    ht.insertItem(201, "Edson");
    ht.insertItem(332, "Daniel");
    ht.insertItem(124, "Priscila");
    ht.insertItem(107, "Jorge");
    ht.insertItem(929, "Juan");
    ht.insertItem(928, "Javier");
    ht.insertItem(928, "Jose");

    ht.printTable();

    ht.removeItem(332);
    ht.removeItem(100);

    if(ht.isEmpty()){
        cout << "[INFO] Incorrect answer" << endl;
    } else{
        cout << "[ERROR] Correct answer. " << endl;
    }

    return 0;
}