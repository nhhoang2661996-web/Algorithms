int getMax(int* piles, int pilesSize){
    int max = 0;
    for(int i = 0 ; i < pilesSize; i++){
        if(piles[i] > max) max = piles[i];
    }
    return max;
}
int getHour(int p, int k){
    return (p + k - 1)/k;
}
long long getMaxHours(int* piles, int pilesSize,int k){
    long long maxH = 0;
    for(int i = 0 ; i < pilesSize; i++){
        maxH += getHour(piles[i],k);
    }
    return maxH;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = getMax(piles, pilesSize);
    int k = 0;
    while(left<=right){
        k = left + (right - left)/2;
        long long time = getMaxHours(piles, pilesSize, k);
        if(time > h) left = k + 1;
        else right = k - 1;
    }
    return left;
}