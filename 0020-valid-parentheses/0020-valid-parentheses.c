bool isValid(char* s) {
    char *top = s;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            *top++ = s[i];
        } 
        else {
            if (top == s) return false;
            char last = *(--top);
            if (s[i] == ')' && last != '(') return false;
            if (s[i] == ']' && last != '[') return false;
            if (s[i] == '}' && last != '{') return false;
        }
    }
    return top == s;
}