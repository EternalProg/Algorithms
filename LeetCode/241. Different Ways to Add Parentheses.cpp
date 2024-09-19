
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {
                        switch (c) {
                            case '+': {
                                result.push_back(l + r);
                                break;
                            }
                            case '-': {
                                result.push_back(l - r);
                                break;
                            }
                            case '*': {
                                result.push_back(l * r);
                                break;
                            }
                        }
                    }
                }
            }
        }


        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};
