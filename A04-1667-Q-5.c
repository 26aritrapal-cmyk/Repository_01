#include <stdio.h> 
int main() {
    char *str = "abcab";
    int len = 0;
    char *p = str;
    while (*p != '\0') {
        len++;
        p++;
    }
    int longest_match_len = 0;
    for (int i = len - 1; i > 0; i--) {
        int match = 1; 
        for (int j = 0; j < i; j++) {
            if (*(str + j) != *(str + (len - i) + j)) {
                match = 0;
                break;
            }
        }
        if (match == 1) {
            longest_match_len = i;
            break;
        }
    }
    printf("Answer: \"");
    for (int i = 0; i < longest_match_len; i++) {
        putchar(*(str + i));
    }
    printf("\"\n");   
    return 0;
}