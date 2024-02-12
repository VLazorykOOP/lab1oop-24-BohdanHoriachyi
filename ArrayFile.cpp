#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>

using namespace std;
const int sizemax = 100;

int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        std::cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
int ConsoleInputArray(int size, int A[])
{
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; std::cin >> A[i];
    }
    return size;
}
int RndInputArray(int size, int A[])
{
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand() % 100 - 50;
        r2 = rand() % 100 - 50;
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    cout << endl;
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console \n";
    cout << "    2.  Random \n";
    cout << "    3.  Exit \n";
}
void WriteArrayTextFile(int n, int* arr, const char* fileName)
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close();
}
void WriteArrayBinFile(int n, int* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) * sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int Task1(int n, int A[])
{
    int  i, min = 1000, k = -1;
    for (i = 0; i < n; i++) {
        if (0 < A[i] && A[i] < min) {
            min = A[i];
            k = i;
        }
    }
    cout << min << " " << k;
    return 0;
}
int Task2(int n, int A[])
{
    int  i, minVal = -1000, t;
    cout << "T:" << endl;
    std::cin >> t;
    cout << endl;
    for (i = 0; i < n; i++) {
        if (A[i] > t) {
            break;
        }
        if (A[i] > minVal && A[i] < 0) {
            minVal = A[i];
        }
    }
    cout << minVal << endl;
    return 0;
}
int main() {
    int A[sizemax], n, nom, nom1;
    int* newA = nullptr;
    ShowMainMenu();
    std::cin >> nom;
    switch (nom) {
    case 1:
        MenuInput();
        std::cin >> nom;
        cout << "1-local array" << endl << "2-Dynamic array" << endl;
        std::cin >> nom1;
        if (nom == 1) {
            if (nom1 == 1) {//ruchki local
                n = ConsoleInputSizeArray(sizemax);
                ConsoleInputArray(n, A);
                Task1(n, A);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
            }
            if (nom1 == 2) {//ruchki
                n = ConsoleInputSizeArray(sizemax);
                newA = new int[n];
                ConsoleInputArray(n, newA);
                Task1(n, newA);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
                delete[]newA;
            }
        }
        if (nom == 2) {
            if (nom1 == 1) {
                n = ConsoleInputSizeArray(sizemax);
                RndInputArray(n, A);
                Task1(n, A);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
            }
            if (nom1 == 2) {
                n = ConsoleInputSizeArray(sizemax);
                newA = new int[n];
                RndInputArray(n, newA);
                Task1(n, newA);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
                delete[]newA;
            }
        }

        break;
    case 2:
        MenuInput();
        std::cin >> nom;
        cout << "1-local array" << endl << "2-Dynamic array" << endl;
        std::cin >> nom1;
        if (nom == 1) {
            if (nom1 == 1) {//ruchki local
                n = ConsoleInputSizeArray(sizemax);
                ConsoleInputArray(n, A);
                Task2(n, A);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
            }
            if (nom1 == 2) {//ruchki dynamic
                n = ConsoleInputSizeArray(sizemax);
                newA = new int[n];
                ConsoleInputArray(n, newA);
                Task2(n, newA);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
                delete[]newA;
            }
        }
        if (nom == 2) {
            if (nom1 == 1) {
                n = ConsoleInputSizeArray(sizemax);
                RndInputArray(n, A);
                Task2(n, A);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
            }
            if (nom1 == 2) {
                n = ConsoleInputSizeArray(sizemax);
                newA = new int[n];
                RndInputArray(n, newA);
                Task2(n, newA);
                WriteArrayTextFile(n, A, "TEXT.txt");
                WriteArrayBinFile(n, A, "Text2.bin");
                delete[]newA;
            }
        }
        break;
    }
}