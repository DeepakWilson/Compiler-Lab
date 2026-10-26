
#include <stdio.h>
#include <string.h>

void generate(char *e, char *ops, char *t) {
    int i, n, found;

    while (1) {
        n = strlen(e);
        found = 0;

        for (i = 1; i < n - 1; i++) {
            if (strchr(ops, e[i])) {
                printf("%c := %c%c%c\n",
                       *t, e[i-1], e[i], e[i+1]);

                e[i-1] = *t;
                memmove(&e[i], &e[i+2], n-i-1);

                (*t)--;
                found = 1;
                break;
            }
        }

        if (!found)
            break;
    }
}

int main(void) {
    char e[50], t = 'Z', lhs;

    printf("Enter the expression: ");
    scanf("%49s", e);

    char *p = strchr(e, '=');
    if (!p) {
        printf("Invalid expression\n");
        return 1;
    }

    lhs = e[0];
    memmove(e, p + 1, strlen(p + 1) + 1);

    printf("Intermediate code:\n");
    generate(e, "*/", &t);
    generate(e, "+-", &t);
    printf("%c := %s\n", lhs, e);

    return 0;
}
