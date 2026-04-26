#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000006

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

bool isBalanced(char* s) {
    top = -1;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else {
            if (top == -1) return false;

            char top_ch = pop();

            if (ch == ')' && top_ch != '(') return false;
            if (ch == '}' && top_ch != '{') return false;
            if (ch == ']' && top_ch != '[') return false;
        }
    }

    return top == -1;
}

int main() {
    char s1[] = "[{()}]";
    printf("Input: %s => Output: %s\n", s1, isBalanced(s1) ? "true" : "false");

    char s2[] = "[()()]{}";
    printf("Input: %s => Output: %s\n", s2, isBalanced(s2) ? "true" : "false");

    char s3[] = "{[)";
    printf("Input: %s => Output: %s\n", s3, isBalanced(s3) ? "true" : "false");

    char s4[] = "({[{}]})";
    printf("Input: %s => Output: %s\n", s4, isBalanced(s4) ? "true" : "false");

    return 0;
}