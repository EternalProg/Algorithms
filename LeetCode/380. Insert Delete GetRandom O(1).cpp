class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> idxMap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(idxMap.find(val) != idxMap.end()) return false;
        nums.push_back(val);
        idxMap[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(idxMap.find(val) == idxMap.end()) return false;
        int last = nums.back();
        idxMap[last] = idxMap[val];
        nums[idxMap[val]] = last;
        nums.pop_back();
        idxMap.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// https://www.youtube.com/watch?v=87zvYSoA5V4
