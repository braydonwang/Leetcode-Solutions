class OrderedStream {
public:
    vector<string> vec;
    int count = 1;
    OrderedStream(int n) : vec(n + 1) {};
    
    vector<string> insert(int idKey, string value) {
        vector<string> ret;
        vec[idKey] = value;
        while (count < vec.size() && !vec[count].empty()) {
            ret.push_back(vec[count]);
            count++;
        }
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */