int getMask(int num){
    int mask =0;
    while(num > 0){
        mask = (mask << 1) | 1;
        num >>= 1;
    } 
    return mask;
}
int findComplement(int num) {
    int temp = getMask(num);
    return (~num)&temp;
}