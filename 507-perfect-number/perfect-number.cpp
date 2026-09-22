class Solution {
public:
    bool checkPerfectNumber(int num) {
        int add = 0;
        for(int i=1; i<num; i++){
            if(num % i == 0){
                add = add + i;
            }
        }
        return add == num;
    }
};