#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(void) 
{
    char* input_text = get_string("Please Enter the Text that needs to be analyzed :");

    int text_len = strlen(input_text);

    int letter_count = 0, word_count = 1, sentence_count = 0;

    for (int i =0; i < text_len; i++)
    {
        if ((input_text[i] >= 'a' && input_text[i] <= 'z') || (input_text[i] >= 'A' && input_text[i] <= 'Z'))
       {
           letter_count++;
       }
       else if (input_text[i] == ' ')
       {
           word_count++;
       }
       else if (input_text[i] == '.' || input_text[i] == '!' || input_text[i] == '?')
       {
           sentence_count++;
       }

    }

    float index = 0.0588 * (100 * (float) letter_count / (float) word_count) - 0.296 * (100 * (float) sentence_count / (float) word_count) - 15.8;

    int grade = round(index);
    
    //printf ("Actual Grade :%f, Letter Count : %i , word Count : %i, sentence count:%i ", index, letter_count, word_count, sentence_count);

    if(grade < 1 )
    {
        printf("\n Grade Before 1");
    }

    else if (grade > 1 && grade < 16)
    {
        printf("\n Grade %i", grade);
    }

    else 
    {
        printf("\n Grade 16+");
    }

}