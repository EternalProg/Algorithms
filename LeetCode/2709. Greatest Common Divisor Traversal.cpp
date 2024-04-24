#pragma GCC optimize("O3", "unroll-loops")
class UnionFind {
public:
    vector<int> root, size;
    UnionFind(int n) : root(n), size(n) {
        size.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        if (x == root[x])
            return x;
        else
            return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return;
        if (size[rX] > size[rY])
            swap(rX, rY);
        root[rX] = rY;
        size[rY] += size[rX];
    }

    bool connected(int x, int y) { return Find(x) == Find(y); }

    void reset(int x) { // Useful for removal
        root[x] = x;
        size[x] = 1;
    }
};

class Solution {
public:
    vector<int> prime;
    vector<int> num_state;

    bitset<100001> sieved = 0;

    void Sieve(int n) { // TC: O(n log log n)
        sieved[0] = sieved[1] = 1;
        int&& n_sqrt = int(sqrt(n));
        for (int i = 2; i <= n_sqrt; i++) {
            if (!sieved[i]) {
                for (int j = i * i; j <= n; j += i)
                    sieved[j] = 1;
            }
        }
        prime.reserve((int)log(n));
        for (int i = 2; i <= n; i++)
            if (!sieved[i])
                prime.push_back(i);
    }
    // Different from the one for DFS
    void build_commonFactor_path(auto& nums, int M, UnionFind& graph) {
        num_state.assign(M + 1, 0);

        for (int x : nums)
            num_state[x] = 1;

        for (int p : prime) {
            for (int i = p * 2; i <= M; i += p) {
                if (num_state[i] == 1) {
                    graph.Union(i, p);
                }
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int M = *max_element(nums.begin(), nums.end());
        int sqrtM = sqrt(M);
        Sieve(M);
        bitset<100001> S = 0;
        for (int x : nums) {
            if (x == 1)
                return 0;
            S[x] = 1;
        }
        nums.clear();
        for (int i = 2; i <= M; i++)
            if (S[i])
                nums.push_back(i);

        int n = nums.size(), sz = 0;
        UnionFind graph(M + 1);
        build_commonFactor_path(nums, M, graph);
        int x0 = nums[0];
        for (int i = 1; i < n; i++)
            if (!graph.connected(x0, nums[i]))
                return 0;
        return 1;
    }
};
