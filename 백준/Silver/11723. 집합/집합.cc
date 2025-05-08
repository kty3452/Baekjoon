#include <stdio.h>
#include <string.h>

int main() {
    int M, x, S = 0;
    char cmd[10];

    scanf("%d", &M);

    while (M--) {
        scanf("%s", cmd);

        if (!strcmp(cmd, "add")) {
            scanf("%d", &x);
            S |= (1 << x);
        }
        else if (!strcmp(cmd, "remove")) {
            scanf("%d", &x);
            S &= ~(1 << x);
        }
        else if (!strcmp(cmd, "check")) {
            scanf("%d", &x);
            printf("%d\n", (S & (1 << x)) ? 1 : 0);
        }
        else if (!strcmp(cmd, "toggle")) {
            scanf("%d", &x);
            S ^= (1 << x);
        }
        else if (!strcmp(cmd, "all")) {
            S = (1 << 21) - 1;
        }
        else if (!strcmp(cmd, "empty")) {
            S = 0;
        }
    }

    return 0;
}
