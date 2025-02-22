/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) { 
        long long left = 1, right = n;
        while(1){
            long long l = left, r = right;
            long long mid = l+r;
            mid/=2;
            int ans = guess(mid);
            if(ans == 0){
                return mid;
            }
            else if(ans == -1){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
    }
};