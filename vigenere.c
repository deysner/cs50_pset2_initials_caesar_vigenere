/**
 * vigenere.c
 *
 * Yevgeniya Deysner
 * j.deysner@gmail.com
 *
 * problem set2 of CS50
 * problem vigenere
 */
 
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (int arrayCount, string arrayOfArguments[])
{
    //checks if the number of arguments is correct
    if (arrayCount != 2) 
    {
        printf("Just one argument allowed\n");
        return 1;
    }
    string inputStringKeyWord = arrayOfArguments[1];
    int n = strlen(inputStringKeyWord);
    //checks if the argument is only alphabetic characters
    for ( int i = 0; i < n; i++)
    {
        char currentSymbol = inputStringKeyWord[i];
        if (currentSymbol < 65 || ( currentSymbol > 92 && currentSymbol < 97) ||currentSymbol >122)
        {
            printf("only alphabetic characters allowed in the argument\n");
            return 1;
        }
          
    }
    //converts input key word to array containing numbers from 0 to 26 
    char encodedSymbol;
    char key[n]; 
    for(int i = 0; i < n; i++)
    {
        char currentSymbol = inputStringKeyWord[i];
        if (currentSymbol > 64 && currentSymbol < 91) 
        {
            encodedSymbol = currentSymbol-65;
            key[i] = encodedSymbol;
            
        } 
        if (currentSymbol > 96 && currentSymbol < 123)
        {
            encodedSymbol = currentSymbol-97;
            key[i] = encodedSymbol;
        } 
    }
    //encoding
    string plainText = GetString();
    int j = 0; //current position of encoding key
    char newChar;
    for (int i = 0; i < strlen(plainText); i++)
    {
        if (
            (plainText[i] > 64 && plainText[i] < 91) ||
            (plainText[i] > 96 && plainText[i] < 123)
            )
        {
           newChar = plainText[i]+key[j];
           //j returns to initial position if key ends
           j++;
           if (j >= strlen(inputStringKeyWord))
           {
               j = 0;
           }
           
           if ((plainText[i] > 64 && plainText[i] < 91) && newChar > 90)
           {
               newChar = newChar -26;
           }
          
            if ((plainText[i] > 96 && plainText[i] < 123) && (newChar > 122 || newChar < 0))
           {
               newChar = newChar -26;
           }
          
        }
        else
        {
            newChar = plainText[i];
        }
        printf("%c", newChar);
    }
    printf("\n");
    return 0;
}