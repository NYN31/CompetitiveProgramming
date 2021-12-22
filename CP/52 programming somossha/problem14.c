#include<stdio.h>

int main()
{
    int T, i;
    char first_line[10001];
    char second_line[2];
    scanf("%d", &T);

    for(i = 1; i <= T; i++){
        scanf("%[^\n]", first_line);
        scanf("%s", second_line);

        int count, j;
        count = 0;
        for(j = 0; j < strlen(first_line); j++){
            if(second_line[0] == first_line[j]){
                count++;
            }
        }
        if(count == 0){
            printf("%c is not present\n", second_line);
        }
        else{
            printf("Occurrence of '%c' in '%s' = %d\n", second_line[0], first_line, count);
        }
    }
    return 0;
}
