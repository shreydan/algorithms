#include <iostream>
#include <string>
using namespace std;

class LongestCommonSubsequence {
   public:
    string x, y, z;
    int m, n;
    int **c;
    char **b;

    LongestCommonSubsequence(string x, string y) {
        this->x = x;
        this->y = y;

        this->m = this->x.length();
        this->n = this->y.length();

        c = new int *[m + 1];
        for (int i = 0; i < m + 1; i++)
            c[i] = new int[n + 1];

        b = new char *[m + 1];
        for (int i = 0; i < m + 1; i++)
            b[i] = new char[n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                b[i][j] = ' ';
            }
        }
    }

    void construct() {
        for (int i = 0; i < m + 1; i++) {
            c[i][0] = 0;
        }
        for (int j = 0; j < n + 1; j++) {
            c[0][j] = 0;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (x.at(i - 1) == y.at(j - 1)) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = '\\';
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = '|';
                } else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = '-';
                }
            }
        }
    }

    void print_lcs(int i, int j) {
        while (i > 0 && j > 0) {
            if (b[i][j] == '\\') {
                z += x[i - 1];
                i--;
                j--;
            } else if (b[i][j] == '|') {
                i--;
            } else if (b[i][j] == '-') {
                j--;
            }
        }
    }

    string getLCS() {
        print_lcs(m, n);
        return z;
    }

    void print_c() {
        cout << "    ";
        for (int i = 0; i < y.length(); i++) {
            cout << y.at(i) << " ";
        }
        cout << endl;
        for (int i = 0; i < m + 1; i++) {
            if (i == 0)
                cout << "  ";
            else
                cout << x.at(i - 1) << " ";
            for (int j = 0; j < n + 1; j++) {
                cout << c[i][j] << " ";
            }
            cout << '\n';
        }
        cout << "\n\n";
    }
    void print_b() {
        cout << "    ";
        for (int i = 0; i < y.length(); i++) {
            cout << y.at(i) << " ";
        }
        cout << endl;
        for (int i = 0; i < m + 1; i++) {
            if (i == 0)
                cout << "  ";
            else
                cout << x.at(i - 1) << " ";
            for (int j = 0; j < n + 1; j++) {
                cout << b[i][j] << " ";
            }
            cout << '\n';
        }
        cout << "\n\n";
    }
};

int main() {
    string x = "ABCBDAB";
    string y = "BDCABA";
    LongestCommonSubsequence lcs(x, y);
    lcs.construct();
    string z = lcs.getLCS();
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
    cout << "Z: " << z << "\n\n";
    lcs.print_c();
    lcs.print_b();
}