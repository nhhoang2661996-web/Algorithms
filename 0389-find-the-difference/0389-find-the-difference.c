char findTheDifference(char* s, char* t) {
    char result = 0;
    while (*s) result ^= *s++;
    while (*t) result ^= *t++;
    return result;
}