class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int totalsal = 0;
        for(int a : salary){
            totalsal += a;
        }
        int maxsal = *max_element(salary.begin(), salary.end());
        int minsal = *min_element(salary.begin(), salary.end());

        return (double)(totalsal - maxsal - minsal) / (n - 2);
    }
};