#define CRT_SECURE_NO_WARNINGS
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
    }

    destinationFile = fopen(path, "w");

    if (destinationFile == NULL)
    {
        perror("Error opening destination file");
        fclose(sourceFile);
    }

    char buffer[1000];

    while (fgets(buffer, 1000, sourceFile) != NULL)
    {
        fputs(buffer, destinationFile);
    }
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;

}