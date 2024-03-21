#include <stdio.h>
#include <string.h>

char str[100], pat[100], rep[100], ans[100];

void read() {
    printf("Enter the string: ");
    scanf(" %[^\n]", str);
    getchar(); 
    printf("Enter the pattern string: ");
    scanf(" %[^\n]", pat);
    getchar();  

    printf("Enter the replacement string: ");
    scanf(" %[^\n]", rep);
    getchar();  
}

void pat_match() {
    int i = 0, j = 0, c = 0, m = 0;
    int flag = 0;

    while (str[c] != '\0') {
        if (str[m] == pat[i]) {
            i++;
            m++;
            if (pat[i] == '\0') {
                printf("\nPattern '%s' found at position %d", pat, c);
                for (int k = 0; rep[k] != '\0'; k++, j++)
                    ans[j] = rep[k];
                i = 0;
                c = m;
                flag = 1;
            }
        } else {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';

    if (flag == 0)
        printf("\nPattern '%s' not found in string '%s'", pat, str);
    else
        printf("\nThe resulting string is: %s", ans);
}

int main() {
    read();
    pat_match();
    return 0;
}
