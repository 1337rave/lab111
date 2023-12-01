#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    char path[] = "test.txt";
    char path[] = "output.txt";

    FILE* sourceFile;
    FILE* destinationFile;

    sourceFile = fopen(path, "r");

    if (sourceFile == NULL)
    {
        perror("Error opening source file");
        return 1;
    }

    destinationFile = fopen(path, "w");

    if (destinationFile == NULL)
    {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    char c;
    char word[100];
    int wordLength = 0;
    int isWord = 0;

    while ((c = fgetc(sourceFile)) != EOF)
    {
        if (isalpha(c))
        {
            word[wordLength++] = c;
            isWord = 1;
        }
        else
        {
            if (isWord)
            {
                word[wordLength] = '\0';
                if (wordLength >= 7)
                {
                    fprintf(destinationFile, "%s ", word);
                }
                wordLength = 0;
                isWord = 0;
            }
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);

    cout << "Operation completed successfully\n";

    return 0;
}