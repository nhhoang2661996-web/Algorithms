char* sortString(char* s) {
    int n = strlen(s);
    int count[26] = {0};
    char* result = malloc((n + 1) * sizeof(char));
    int index = 0; 
     
    for (int i = 0; i < n; i++) count[s[i] - 'a']++;

    while (index < n) {
        int move = 0;
        while (move < 26) {
            if (count[move] > 0) {
                result[index++] = move + 'a';
                count[move]--;
            }
            move++;
        }
        while (move > 0) {
            move--;
            if (count[move] > 0) {
                result[index++] = move + 'a';
                count[move]--;
            }
        }
    }
    result[index] = '\0';
    return result;
}