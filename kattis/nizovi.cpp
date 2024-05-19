#include <bits/stdc++.h>
#define SPACE for(int i=0; i<n; i++) printf("  ");
using namespace std;

int main(void) {
    char c, l='\0';
    int n = 0;
    int be = 1;
    while(1) {
        c = getchar();
        if ((l == '}') && (c == ',')) {
            printf(",\n");
            continue;
        }
        switch(c) {
        case ' ':
            break;
        case ',':
            printf(",\n");
            be = 1;
            break;
        case '{':
            SPACE;
            printf("{\n");
            n++;
            break;
        case '}':
            n--;
            if(l != '{')
                printf("\n");
            SPACE;
            printf("}");
            be = 1;
            break;
        case '\n':
            printf("\n");
            return 0;
        default:
            if(be == 1) {
                SPACE;
                be = -1;
            }
            printf("%c", c);
            break;
        }
        l = c;
    }
    return 0;
}
