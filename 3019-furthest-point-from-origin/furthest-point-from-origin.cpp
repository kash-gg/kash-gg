class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int a = 0;
        int b= 0;
        int c=0;
        for(int i = 0;i<moves.length();i++){
            if(moves[i]=='L'){
                a++;
            }
            else if(moves[i]=='R'){
                b++;
            }
            else{
                c++;
            }
        }
        return abs(a-b) +c;
    }
};