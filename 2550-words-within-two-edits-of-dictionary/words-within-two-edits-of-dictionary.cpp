class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> result;
        for (int i = 0; i < queries.size(); i++) {
            string q = queries[i];
            for (int j = 0; j < dictionary.size(); j++) {
                int diff = 0;
                string d = dictionary[j];
                for (int k = 0; k < q.size(); k++) {
                    if (q[k] != d[k]) {
                        diff++;
                    }
                }
                if(diff<=2){
                    result.push_back(q);
                    break;
                }
            }
        }
        return result;
    }
};