#include <iostream>
using namespace std;

/*
VARS:

m       : length of pattern
n       : length of text
text    : text
pattern : pattern
*/

class KMP {
   private:
    int *prefix;

    void compute_prefix() {
        prefix[0] = 0;
        int k = 0;
        for (int q = 1; q < m; q++) {
            while (k > 0 && pattern.at(k) != pattern.at(q)) {
                k = prefix[k - 1];
            }
            if (pattern.at(k) == pattern.at(q)) {
                k++;
            }
            prefix[q] = k;
        }
    }

    void matcher() {
        compute_prefix();
        int q = 0;
        for (int i = 0; i < n; i++) {
            while (q > 0 && pattern.at(q + 1) != text.at(i)) {
                q = prefix[q];
            }
            if (pattern.at(q + 1) == text.at(i)) {
                q++;
            }
            if (q == m - 1) {
                cout << "pattern occurs from index " << i - m + 1 << endl;
                q = prefix[q];  // look for more matches
            }
        }
    }

   public:
    string text;
    string pattern;
    int m, n;

    void print_prefix() {
        for (int i = 0; i < m; i++) cout << prefix[i];
        cout << endl;
    }

    void match() {
        matcher();
    }

    KMP(string text, string pattern) {
        this->text = text;
        this->pattern = pattern;
        m = pattern.length();
        n = text.length();
        prefix = new int[m];
    }
};

int main() {
    KMP test("abcdefabcghiabcitu", "abc");
    test.match();
    return 0;
}