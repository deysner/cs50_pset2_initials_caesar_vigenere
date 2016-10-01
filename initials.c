/**
 * initials.c
 *
 * Yevgeniya Deysner
 * j.deysner@gmail.com
 *
 * problem set2 of CS50
 * problem initials
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

//prototype    
char getUpperCaseChar(char);

int main(void)
{
    // get line of text
    string s = GetString();
    
    printf("%c", getUpperCaseChar( s[0] ) );

    for(int i=0; i< strlen(s); i++)
    {
        if (s[i]==' ')
        {
            i++;
            char symbol = s[i];
            char upperSymbol = getUpperCaseChar( symbol );
            //printf("%c" , symbol);
            printf("%c" , upperSymbol);
        }   
    }
    printf("\n");
    
}

char getUpperCaseChar(char currentChar)
{
    char result = currentChar;
    if (currentChar >= 'a' && currentChar < ('a'+26))
    {
        result = currentChar-32;
    }
    return result;
}