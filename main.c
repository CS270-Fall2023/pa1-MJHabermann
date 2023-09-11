#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getTokens(char *s, char ***args);

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
    for(int i = 0; i < counter; i++)
    {
        free(arrayOfTokens[i]);
    }
    free(arrayOfTokens);
    return 0;
}
int getTokens(char *s, char ***args)
{
    int strLength = strlen(s);
    *args = malloc(sizeof(char **));
    int tokCount = 0;
    int tokStart = 0;
    int tokEnd = 0;
    char **arrayToken = *args;
    while (tokStart < strLength)
    {
        //skips past double spaces
        while (s[tokStart] == ' ')
        {
            tokStart++;
        }
        tokEnd = tokStart;
        // while the string is not a whitespace and the end of the string is less than the length
        while (s[tokEnd] != ' ' && s[tokEnd] != '\0')
        {
            tokEnd++;
        }
        // The length of the string will be taken by grabbing the end and finding the start
        int tokLen = tokEnd - tokStart;
        // Allocate memory to the token and +1 for null terminator
        if (tokLen > 0)
        {
            char *token = malloc(sizeof(char) * (tokLen + 1));
            // memcpy writes the memory of s(a token) to token so we can add it to the array of tokens
            memcpy(token, s + tokStart, tokLen);
            // adds null terminator to the string
            token[tokLen] = '\0';
            // adds token to the array of tokens
            arrayToken[tokCount] = token;
            // adds one to the token count
            tokCount++;
            // realloc expands the memory allocated by 1
            arrayToken = realloc(arrayToken, sizeof(char **) * (tokCount + 1));
            // assigns args to be the
            *args = arrayToken;
        }
        // We want to start on the next string
        tokStart = tokEnd;
    }
    return tokCount;
}