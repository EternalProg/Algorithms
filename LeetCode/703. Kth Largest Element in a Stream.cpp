
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;

    KthLargest(int k, vector<int>& nums) : k(k) {
        for(int num : nums) {
            add(num); 
        }
    }
    
    int add(int val) {
        if (min_heap.size() < k) {
            min_heap.push(val);
        } else if (val > min_heap.top()) {
            min_heap.pop();
            min_heap.push(val);
        }

        return min_heap.top();
    }
};
