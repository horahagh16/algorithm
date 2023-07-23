#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string directions;
        cin >> directions;

        int x = 0, y = 0, min_distance = 0;
        for (char direction : directions) {
            switch (direction) {
                case 'A':
                    x++;
                    break;
                case 'F':
                    x++;
                    y--;
                    break;
                case 'E':
                    y--;
                    break;
                case 'D':
                    x--;
                    break;
                case 'C':
                    x--;
                    y++;
                    break;
                case 'B':
                    y++;
                    break;
            }
        }

        min_distance = max(0, max(abs(x), max(abs(y), abs(x + y))));

        cout << min_distance << endl;
    }

    return 0;
}
