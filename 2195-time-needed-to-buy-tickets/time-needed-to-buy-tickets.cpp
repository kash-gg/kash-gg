class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i); // person index
        }
        int time=0;
        while(!q.empty()){
            int a = q.front();
            q.pop();

            tickets[a]--;
            time++;

            if(a==k && tickets[a]==0){
                return time;
            }
            if (tickets[a] > 0) {
                q.push(a);
            }
        }
        return time;
    }
};