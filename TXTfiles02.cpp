#include <iostream>
using namespace std;


int CountOfWords(const char* path, char begin);



int main()
{
    const char* pathStatist = "E:\\statistics.txt";
    const char* pathText = "E:\\text.txt";

    FILE* statistics;
    
    char begin;
    cout << "Enter begin symbol: ";
    cin >> begin;

    if (fopen_s(&statistics, pathStatist, "w") != NULL)
    {
        cout << "Error";
    }

    else
    {

        fprintf(statistics, "%s", "words: ");
        fprintf(statistics, "%d", CountOfWords(pathText, begin));


    }

}



int CountOfWords(const char* path, char begin)
{
    FILE* TEXT;

    int c;
    int words = 1;
    bool isStart = false;

    if (fopen_s(&TEXT, path, "r") != NULL)
    {
        cout << "Error";
    }

    else
    {
        while (!feof(TEXT))
        {
            c = fgetc(TEXT);

            if (c == begin)
            {
                isStart = true;
            }

            if (isStart && c == ' ')
            {
                words++;
            }
        }
    }

    return words;
}

