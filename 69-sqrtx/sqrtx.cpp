class Solution {
public:
    int mySqrt(int x) {
        
        int left = 1, right = x;
        int result = 0;
        if(x==1|| x==1)return x;

        while(left<=right){
            long mid = left+ (right-left)/2;

            long square = mid * mid;

            if(square==x){
                return mid;
            }
            else if (square <x){
                result = mid;
                left = mid +1;
            }
            else{
                right = mid -1;
            }
        }
        return result;
    }
};