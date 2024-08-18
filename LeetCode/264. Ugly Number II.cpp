class Solution {
public:
    void check_for_duplicate_and_push(
        long numb, priority_queue<long, vector<long>, greater<long>>& min_heap,
        set<long>& seen) {
        if (!seen.count(numb)) {
            min_heap.push(numb);
            seen.insert(numb);
        }
    }

    int nthUglyNumber(int n) {
        if (n <= 6)
            return n;

        set<long> seen;
        priority_queue<long, vector<long>, greater<long>> min_heap;
        min_heap.push(1);
        seen.insert(1);

        for (int i = 1; i != n; ++i) {
            long numb = min_heap.top();
            min_heap.pop();

            check_for_duplicate_and_push(numb * 2, min_heap, seen);
            check_for_duplicate_and_push(numb * 3, min_heap, seen);
            check_for_duplicate_and_push(numb * 5, min_heap, seen);
        }

        return min_heap.top();
    }
};
