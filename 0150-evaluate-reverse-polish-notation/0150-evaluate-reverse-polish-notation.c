int compute(int l, int r, char op) {
    switch (op) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return l / r; 
        default:  return 0;    
    }
}
bool isNumber(char *s) {
    return (strlen(s) > 1 || (s[0] >= '0' && s[0] <= '9'));
}
int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int index = 0;
    for (int i = 0; i < tokensSize; i ++){
        if (isNumber(tokens[i])){
            stack[index++] = atoi(tokens[i]);
        }else {
            int num2 = stack[--index];
            int num1 = stack[--index];
            int n = compute(num1,num2,tokens[i][0]);
            stack[index++] = n;
        }
    }
    return stack[0];
}