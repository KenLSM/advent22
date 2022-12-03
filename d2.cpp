#include <bits/stdc++.h>

using namespace std;

int main() {
    char abc, xyz;
    int points = 0;
    int points2 = 0;
    while(true) {
        cin >> abc >> xyz;
        if(cin.eof()) {
            break;
        }
        switch(xyz) {
            // shape points
            case 'X': {
                points += 1;
                break;
            }
            case 'Y': {
                points += 2;
                break;
            }
            case 'Z': {
                points += 3;
                break;
            }
        }
        // outcome points
        if(abc == 'A' && xyz == 'Y') { points += 6; }
        if(abc == 'A' && xyz == 'X') { points += 3; }

        if(abc == 'B' && xyz == 'Z') { points += 6; }
        if(abc == 'B' && xyz == 'Y') { points += 3; }

        if(abc == 'C' && xyz == 'X') { points += 6; }
        if(abc == 'C' && xyz == 'Z') { points += 3; }

        printf("%c %c %d\n", abc, xyz, points);


        // Z = Win = 6
        // Y = Draw = 3
        // X = Lose = 0

        /**
         * Against scissors (C)
         * To win = 6 + Rock (1)
         * To draw = 3 + Scissors (3)
         * To lose = 0 + Paper (2)
         */
        if(abc == 'C') {
            switch(xyz) {
                case 'X': {
                    points2 += 2; // lose
                    break;
                }
                case 'Y': {
                    points2 += 6; // draw
                    break;
                }
                case 'Z': {
                    points2 += 7; // win
                    break;
                }
            }
        }

        /**
         * Against rock (A)
         * To win = 6 + Paper (2)
         * To draw = 3 + Rock (1)
         * To lose = 0 + Scissors (3)
         */
        if(abc == 'A') {
            switch(xyz) {
                case 'X': {
                    points2 += 3; // lose
                    break;
                }
                case 'Y': {
                    points2 += 4; // draw
                    break;
                }
                case 'Z': {
                    points2 += 8; // win
                    break;
                }
            }
        }

        /**
         * Against paper (A)
         * To win = 6 + Scissors (3)
         * To draw = 3 + Paper (2)
         * To lose = 0 + Rock (1)
         */
        if(abc == 'B') {
            switch(xyz) {
                case 'X': {
                    points2 += 1; // lose
                    break;
                }
                case 'Y': {
                    points2 += 5; // draw
                    break;
                }
                case 'Z': {
                    points2 += 9; // win
                    break;
                }
            }
        }
    }

    cout << "Q1: " << points << endl;
    cout << "Q2: " << points2 << endl;
    return 1;
}