#include <iostream>
#include <cstring>

void addColumn(int** arr, int rows, int& colm, int pos) {
    int** temp = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        temp[i] = new int[colm + 1];

        for (int j = 0; j < colm + 1; ++j) {
            if (j < pos) {
                temp[i][j] = arr[i][j];
            }
            else if (j == pos) {
                std::cout << "Enter number: ";
                std::cin >> temp[i][j];
            }
            else {
                temp[i][j] = arr[i][j - 1];
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = temp;
    ++colm;
}

void deleteColumn(int**& arr, int rows, int& colm, int pos) {
    if (pos < 0 || pos >= colm) {
        return;
    }

    int** temp = new int* [rows];

    for (int i = 0; i < rows; ++i) {
        temp[i] = new int[colm - 1];

        for (int j = 0; j < colm - 1; ++j) {
            if (j < pos) {
                temp[i][j] = arr[i][j];
            }
            else {
                temp[i][j] = arr[i][j + 1];
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = temp;
    --colm;
}

void shiftRows(int** arr, int rows, int colm, int count) {
    count = count % rows;

    for (int k = 0; k < count; ++k) {
        for (int j = 0; j < colm; ++j) {
            int temp = arr[rows - 1][j];

            for (int i = rows - 1; i > 0; --i) {
                arr[i][j] = arr[i - 1][j];
            }

            arr[0][j] = temp;
        }
    }
}

void shiftColumns(int** arr, int rows, int colm, int count) {
    count = count % colm;

    for (int k = 0; k < count; ++k) {
        for (int i = 0; i < rows; ++i) {
            int temp = arr[i][colm - 1];

            for (int j = colm - 1; j > 0; --j) {
                arr[i][j] = arr[i][j - 1];
            }

            arr[i][0] = temp;
        }
    }
}

void transpose(int** arr, int rows, int cols) {
    int** temp = new int* [cols];

    for (int i = 0; i < cols; ++i) {
        temp[i] = new int[rows];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    arr = temp;
}

int main()
{


    const int SIZE = 5;

    char** names = new char* [SIZE];
    char** phones = new char* [SIZE];

    for (int i = 0; i < SIZE; ++i) {
        names[i] = new char[100];
        phones[i] = new char[20];

        std::cout << "Enter name: ";
        std::cin.getline(names[i], 100);

        std::cout << "Enter phone: ";
        std::cin.getline(phones[i], 20);
    }

    int choice;

    do {
        std::cout << "\n1. Search by name";
        std::cout << "\n2. Search by phone";
        std::cout << "\n3. Change data";
        std::cout << "\n0. Exit\n";

        std::cin >> choice;

        if (choice == 1) {
            char name[100];
            std::cin >> name;

            for (int i = 0; i < SIZE; ++i) {
                if (strcmp(names[i], name) == 0) {
                    std::cout << phones[i] << "\n";
                }
            }
        }

        else if (choice == 2) {
            char phone[20];
            std::cin >> phone;

            for (int i = 0; i < SIZE; ++i) {
                if (strcmp(phones[i], phone) == 0) {
                    std::cout << names[i] << "\n";
                }
            }
        }

        else if (choice == 3) {
            int index;
            std::cin >> index;

            if (index >= 0 && index < SIZE) {
                std::cin.getline(names[index], 100);
                std::cin.getline(phones[index], 20);
            }
        }

    } while (choice != 0);

    for (int i = 0; i < SIZE; ++i) {
        delete[] names[i];
        delete[] phones[i];
    }

    delete[] names;
    delete[] phones;

    //6

    //char** surname = new char* [5];

    //for (int i = 0; i < 5; ++i) {
    //    surname[i] = new char[100];

    //    std::cout << "Enter surname: ";
    //    std::cin.getline(surname[i], 100);
    //}

    //for (int i = 0; i < 5; ++i) {
    //    for (int j = 0; j < 4 - i; ++j) {
    //        if (strcmp(surname[j], surname[j + 1]) > 0) {
    //            char* temp = surname[j];
    //            surname[j] = surname[j + 1];
    //            surname[j + 1] = temp;
    //        }
    //    }
    //}

    //std::cout << "\nSorted surnames:\n";

    //for (int i = 0; i < 5; ++i) {
    //    std::cout << surname[i] << "\n";
    //    delete[] surname[i];
    //}

    //delete[] surname;
}

