class RandomizedSet {
public:
    unordered_map<int,int> map;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        v.push_back(val);
        map[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        } 
        int num = v.back();
        v[map[val]] = num;
        map[num] = map[val];
        map.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */