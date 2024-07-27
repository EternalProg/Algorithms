class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        vector<vector<int>> costMatrix(26, vector<int>(26, INT_MAX));
        
        // Заповнення матриці вартостей
        for (int i = 0; i < original.size(); ++i) {
            costMatrix[original[i] - 'a'][changed[i] - 'a'] = min(costMatrix[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        
        // Сам до себе вартість 0
        for (int i = 0; i < 26; ++i) {
            costMatrix[i][i] = 0;
        }
        
        // Алгоритм Флойда-Уоршалла
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (costMatrix[i][k] != INT_MAX && costMatrix[k][j] != INT_MAX) {
                        costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                    }
                }
            }
        }
        
        // Обчислення загальної вартості конвертації
        long long totalCost = 0;
        for (int i = 0; i < n; ++i) {
            int src = source[i] - 'a';
            int tgt = target[i] - 'a';
            if (costMatrix[src][tgt] == INT_MAX) {
                return -1;  // Неможливо перетворити
            }
            totalCost += costMatrix[src][tgt];
        }
        
        return totalCost;
    }
};
