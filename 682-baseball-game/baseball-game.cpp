class Solution {
public:
    int calPoints(vector<string>& operations) {
        int a;
        vector<int> b;
        for (int i = 0; i < operations.size(); i++) {
            string c = operations[i]; 

            if (c == "+") {
                int last = b[b.size() - 1];
                int secondLast = b[b.size() - 2];
                b.push_back(last + secondLast);
            } else if (c == "D") {
                b.push_back(2 * b.back());
            } else if (c == "C") {
                b.pop_back();
            } else {
         
                b.push_back(stoi(c));
            }
        }
        int total = 0;
        for (int i = 0; i < b.size(); i++) {
            total += b[i];
        }

        return total;
    }
};