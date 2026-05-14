int nextGreaterElement(int n) {
    char s[12];
    sprintf(s, "%d", n);
    int len = strlen(s);
    int p = -1;
    int c =-1;
    int min =0;
    for (int i = 0; i < len - 1; i++) {
        if (s[i] < s[i+1]) {
            p = i;
            c = i+1;
            min = s[i+1];
        } 
        else if (p != -1) {
            if (s[i+1] > s[p] && s[i+1] <= min) {
             min = s[i+1];
             c = i+1;
            }
        }
    }
    
    if (p < 0) return -1;
    char temp = s[p];
    s[p] = s[c];
    s[c] = temp;

    int left = p + 1;
    int right = len - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    
    long long val = atoll(s);
    if (val >= INT_MIN && val <= INT_MAX) {
    
        int result = (int)val;
        return result;
    }
    return -1;
}