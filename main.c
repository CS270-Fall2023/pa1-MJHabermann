/**
 * @file main.c
 * @author Michael J Habermann
 * @brief This program asks the user for input and outputs back the tokens
 * @date 2023-09-13
 * 
 * 
 */
#include "getTokens.h"


int main(void)
{
    char **arrayOfTokens = NULL;
    char str[256];
    int counter = 0;
    printf("Please, enter the string: ");
    scanf("%[^\n]%*c", str);
    // fgets(str, 256,stdin);
    // printf("%s\n",s);
    counter = getTokens(str, &arrayOfTokens);
    printf("Number of tokens: %d\n", counter);
    for (int i = 0; i <= counter; i++)
    {
        printf("token %d: %s\n", i + 1, (arrayOfTokens)[i]);
    }
    for (int i = 0; i < counter; i++)
    {
        free(arrayOfTokens[i]);
    }
    free(arrayOfTokens);
    return 0;
}
