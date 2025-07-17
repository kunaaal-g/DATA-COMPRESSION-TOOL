#include <stdio.h>
#include <string.h>
#include <ctype.h>  
void compressRLE(char *input) 
{
    int len = strlen(input);
    for (int i = 0; i < len; i++) 
    {
        int count = 1;
        while (i < len - 1 && input[i] == input[i + 1]) 
        {
            count++;
            i++;
        }
        printf("%c%d", input[i], count);
    }
    printf("\n");
}
void decompressRLE(char *input) 
{
    int i = 0;
    while (input[i] != '\0') 
    {
        char ch = input[i++];
        int count = 0;
        while (isdigit(input[i])) {
            count = count * 10 + (input[i++] - '0');
        }
        for (int j = 0; j < count; j++) 
        {
            printf("%c", ch);
        }
    }
    printf("\n");
}
int main() 
{
    char input[100], choice;
    printf("Enter string: ");
    scanf("%s", input);
    printf("Choose (c)ompress or (d)ecompress: ");
    scanf(" %c", &choice);
    if (choice == 'c') 
    {
        printf("Compressed Output: ");
        compressRLE(input);
    } else if (choice == 'd') 
    {
        printf("Decompressed Output: ");
        decompressRLE(input);
    } else 
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
