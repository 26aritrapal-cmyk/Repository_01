#include <stdio.h>
void *malloc(unsigned long size);
void free(void *ptr);
int main() {
    int n;
    printf("Enter the number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of strings.\n");
        return 1;
    }
    char **names = (char **)malloc(n * 8); 
    if (names == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    char buffer[100];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        int len = 0;
        while (buffer[len] != '\0') {
            len++;
        }
        names[i] = (char *)malloc((len + 1) * sizeof(char));
        if (names[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        for (int j = 0; j <= len; j++) {
            names[i][j] = buffer[j];
        }
    }
    printf("\nStrings entered in order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);
    return 0;
}
