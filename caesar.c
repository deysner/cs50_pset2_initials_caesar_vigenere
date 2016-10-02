/**
 * caesar.c
 *
 * Yevgeniya Deysner
 * j.deysner@gmail.com
 *
 * problem set2 of CS50
 * problem caesar
 */
 
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (int arrayCount, string arrayOfArguments[])
{
    //checks if the number of arguments is correct
    if (arrayCount != 2) 
    {
        printf("just one argument allowed\n");
        return 1;
    }
    string inputStringK = arrayOfArguments[1];
    //converts input string to integer instead of atoi
    int mult = 1;
    int inputK = 0;
    for(int i = strlen(inputStringK)-1; i >= 0; i = i-1)
    {
        char currentSymbol = inputStringK[i];
        int currentInt = currentSymbol-48;
        inputK = inputK+currentInt*mult;
        mult = mult*10;
    }
    // normalizes inputK
    while (inputK >=26)
    {
        inputK = inputK-26;    
    }
    //asks for input and encodes it
    string Word = GetString();
    for (int i = 0, n = strlen(Word); i < n; i++)
    {
        if ((Word[i] > 64 && Word[i] < 91) || (Word[i] > 96 && Word[i] < 123))
        {
            char newChar = Word[i]+inputK;
            if ((Word[i] > 64 && Word[i] < 91) && newChar > 90)
            {
                newChar = newChar-26;
            } 
            if ((Word[i] > 96 && Word[i] < 123) && (newChar > 122 || newChar < 0) )
            {
                newChar = newChar-26;
            } 

            printf("%c", newChar);
        }
        else
        {
            printf("%c", Word[i]);
        }
    }
    printf("\n");
    return 0;
}