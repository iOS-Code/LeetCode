int reverse(int x) {
    bool negative = false;
    if(x<0){
        negative = true;
        x = -x;
    }
    int nums = 0;
    int tmpNum;
    int tmp;
    int i;
    while(x){
        if(nums>(INT_MAX-x%10)/10)//溢出
            return 0;
        nums=nums*10+x%10;
        x = x/10;
    }
    if(negative)
        return -nums;
    return nums;
}
