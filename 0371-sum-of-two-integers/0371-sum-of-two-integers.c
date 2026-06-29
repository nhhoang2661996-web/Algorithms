int getSum(int a, int b) {
    int sum = a^b;
    unsigned int carry = (unsigned int)(a&b) <<1;
    while(carry != 0){
        a = sum;
        sum = sum^carry;
        carry = (a&carry) <<1;
    }
    return sum;
}