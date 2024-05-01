
#include<iostream>
#include<Windows.h>
using namespace std;

int main() {

    const int rows = 13;
    const int cols = 13;
    char arr[rows][cols] = {};
    int x;
    int y;

    int ship = 5;

    bool gameOver = false;

    char number = 49;


    const int cor_3_y_1 = 7;
    const int cor_3_x_1 = 9;

    const int cor_4_y_1 = 4;
    const int cor_4_x_1 = 2;
    const int cor_4_x_2 = 3;

    const int cor_5_y_1 = 9;
    const int cor_5_x_1 = 6;
    const int cor_5_x_2 = 7;
    const int cor_5_x_3 = 8;


    int heals_1_c = 3;
    int heals_2_c = 4;
    int heals_3_c = 2;
    int heals_4_c = 1;
    int heals_5_c = 3;

    bool dead_1_c = false;
    bool dead_2_c = false;
    bool dead_3_c = false;
    bool dead_4_c = false;
    bool dead_5_c = false;

    for (int i = 0; i < rows; i++) {
        if (i == 1)
            number = 49;
        for (int j = 0; j < cols; j++) {
            if (i > 1 && j == 0 && i < rows - 2 || j > 1 && i == 0 && j < cols - 2) {
                arr[i][j] = number;
                number++;
            }
            else if (i == cols - 2 && j == 0 || j == cols - 2 && i == 0) {
                arr[i][j] = 48;
            }
            else if (i == 1 || j == 1 || j == cols - 1 || i == rows - 1) {
                arr[i][j] = '#';
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }

    while (true) {
        for (int i = 0; i < rows; i++) {
            char symbol = '|';
            for (int j = 0; j < cols; j++) {
                if (i <= 1 || j == 0 || j == cols - 1 || i == rows - 1)
                    cout << arr[i][j] << " ";
                else {
                    cout << arr[i][j] << symbol;
                }
            }
            cout << endl;
        }

        if (ship == 0) {
            Sleep(1500);
            system("cls");
            break;
        }

        cout << "Ryadok -> ";
        cin >> y;
        cout << "Stovpchuk -> ";
        cin >> x;

        if (x < 1 || x > rows - 3 || y < 1 || y > cols - 3) {
            cout << "Ne corectni coordunatu ):" << endl;
            Sleep(1500);
            system("cls");
            continue;
        }
        if ((x == cor_3_x_1 && y == cor_3_y_1) && heals_3_c > 0) {
            arr[y + 1][x + 1] = '@';
            heals_3_c--;
        }
        else if ((x == cor_4_x_1 && y == cor_4_y_1) || (x == cor_4_x_2 && y == cor_4_y_1) && heals_4_c > 0) {
            arr[y + 1][x + 1] = '@';
            heals_4_c--;
        }
        else if ((x == cor_5_x_1 && y == cor_5_y_1) || (x == cor_5_x_2 && y == cor_5_y_1) || (x == cor_5_x_3 && y == cor_5_y_1) && heals_5_c > 0) {
            arr[y + 1][x + 1] = '@';
            heals_5_c--;
        }
        else {
            arr[y + 1][x + 1] = 'x';
        }
        if (heals_3_c == 0 && !dead_3_c) {
            ship--;
            arr[cor_3_y_1 + 1][cor_3_x_1 + 1] = '-';
            dead_3_c = true;
        }
        if (heals_4_c == 0 && !dead_4_c) {
            ship--;
            arr[cor_4_y_1 + 1][cor_4_x_1 + 1] = '-';
            arr[cor_4_y_1 + 1][cor_4_x_2 + 1] = '-';
            dead_4_c = true;
        }
        if (heals_5_c == 0 && !dead_5_c) {
            ship--;
            arr[cor_5_y_1 + 1][cor_5_x_1 + 1] = '-';
            arr[cor_5_y_1 + 1][cor_5_x_2 + 1] = '-';
            arr[cor_5_y_1 + 1][cor_5_x_3 + 1] = '-';
            dead_5_c = true;
        }

        system("cls");
    }

    return 0;
}
