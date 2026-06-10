int lengthOfLongestSubstring(char* s) {
    int maxLen = 0;
    int map[256] = {0};
    int left = 0;
    int right = 0;
    while(s[right] != '\0'){
        char t = s[right];
        if (map[t] > left){
            left = map[t];
        }
        map[t] = right + 1;
        int len = right - left + 1; 
        if (len > maxLen){
            maxLen = len;
        }
        right++;
    }
    return maxLen;
}
