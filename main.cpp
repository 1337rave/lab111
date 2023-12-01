#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    const char sourcePath[] = "test.txt";
    const char destinationPath[] = "output.txt";

    FILE* sourceFile = fopen(sourcePath, "r");

    if (sourceFile == NULL)
    {
        cout << "Error opening source file!" << endl;
        return 1;
    }

    FILE* destinationFile = fopen(destinationPath, "w");

    if (destinationFile == NULL)
    {
        cout << "Error opening destination file!" << endl;
        fclose(sourceFile);
        return 1;
    }

    char buffer[1000];

    while (fgets(buffer, sizeof(buffer), sourceFile) != NULL)
    {
        fputs(buffer, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    cout << "Files copied successfully\n";

    return 0;
}