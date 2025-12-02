#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cctype>
#include <vector>
#include <array>

using namespace std;

void skrivUtVek(const vector<int>& vek){
    for(size_t i = 0; i < vek.size(); ++i){
        cout << vek[i] << endl;
    }
}

void fyllMedVarde(vector<int>& vek, int varde){
    for(size_t i = 0; i < vek.size(); ++i){
        vek[i] = varde;
    }
}

bool innehaller(const vector<int>& vek, int varde){
    for(size_t i = 0; i < vek.size(); ++i){
        if(vek[i] == varde)
            return true;
    }
    return false;
}

vector<int> minst(const vector<int>& vek, size_t startIndex){
    vector<int> minst{vek[startIndex], 0};
    for(size_t i = startIndex; i <= vek.size()-1; ++i){
        if(vek[i] <= minst[0]){
            minst[0] = vek[i];
            minst[1] = i;
        }
    }
    return minst;
}

vector<int> storst(const vector<int>& vek){
    vector<int> storst{vek[0], 0};
    for(size_t i = 0; i < vek.size(); ++i){
        if(vek[i] > storst[0]){
            storst[0] = vek[i];
            storst[1] = i;
        }
    }
    return storst;
}

bool arSorterad(const vector<int>& vek){
    for(size_t i = 0; i < vek.size()-1; ++i){
        if(vek[i] > vek[i+1]){
            return false;
        }
    }
    return true;
}

void skrivUtVaxel(int antalKronor){
    const vector<int> valorer{500, 200, 100, 50, 20, 10};

    for(int i = 0; i < 6; ++i){
        int antalSedlar = floor(antalKronor / valorer[i]);
        if (antalSedlar == 0)
            continue;
        cout << floor(antalKronor / valorer[i]) << " x " << valorer[i] << endl;
        antalKronor -= valorer[i] * floor(antalKronor / valorer[i]);
    }

    cout << '\n' << antalKronor << " i rest!" << endl;
}

vector<int> fyllMedUnikaSlumptal(vector<int> vek, size_t minst, size_t storst){
    fyllMedVarde(vek, 0);
    srand(time(NULL));
    int randomNum{};

    if(!(vek.size() <= storst - minst + 1)){
        cout << "Det givna intervallet är inte tillräckligt stort för att ge alla index i vectorn unika slumpmässiga tal! '\n" << endl;;
        assert(false);
    }

    for(size_t i = 0; i < vek.size(); ++i){
        bool dublett = true;

        while(dublett){
            randomNum = minst + (rand() % (storst - minst + 1));
            for(size_t i = 0; dublett; ++i){
                if(vek[i] == randomNum){
                    break;
                }
                if(i == vek.size() - 1){
                    dublett = false;
                }
            }
        }

        vek[i] = randomNum;
    }
    return vek;
}

int lottoSpel(vector<int>& playerNums){
    vector<int> slumpTal = {0,0,0,0,0,0,0};
    int points = 0;
    slumpTal = fyllMedUnikaSlumptal(slumpTal, 1, 35);

    cout << "De slumpade talen var:" << endl;
    skrivUtVek(slumpTal);
    cout << endl;

    for(size_t i = 0; i < playerNums.size(); ++i){
        if(innehaller(slumpTal, playerNums[i])){
            points += 1;
        }
    }

    return points;
}

void provaMatris(){
    array<array<int, 6>, 3> m{{
            {{20, 21, 22, 23, 24, 25}},
            {{2, 3, 4 , 5, 6, 7}},
            {{7, 11, 13, 17, 19, 23}}
    }};

    const int antalRader = m.size();
    const int antalKolumner = m[0].size();

    for(int r = 0; r < antalRader; ++r){
        for(int k = 0; k < antalKolumner; ++k){
            cout << '\t' << m[r][k];
            cout << endl;
        }
        cout << endl;
    }
}

bool arNoll(int i){
    if(i == 0){
        return true;
    }
    else return false;
}

void skrivutSudoku(const array<array<int,9>,9>& sudoku){
    cout << "+---------+---------+---------+" << endl;

    for(size_t r = 0; r < sudoku.size(); ++r){
        for(size_t k = 0; k < sudoku[0].size(); ++k){
            if(k == 0){
                if(arNoll(sudoku[r][k])){
                    cout << '|' << ' ' << ' ';
                }
                else{
                    cout << '|' << ' ' << sudoku[r][k];
                }
            }
            else if(k == 1 || k == 2 || k == 4 || k == 5 || k == 7 || k == 8){
                if(arNoll(sudoku[r][k])){
                    cout << ' ' << ' ' << ' ';
                }
                else{
                    cout << ' ' << ' ' << sudoku[r][k];
                }
            }
            else if(k == 3 || k == 6){
                if(arNoll(sudoku[r][k])){
                    cout << ' ' << '|'  << ' ' << ' ';
                }
                else{
                    cout << ' ' << '|'  << ' ' << sudoku[r][k];
                }
            }
        }

        cout << ' ' << '|' << endl;
        if(r == 2 || r == 5){
            cout << "+---------+---------+---------+" << endl;
        }
    }

    cout << "+---------+---------+---------+" << endl;
}

void provaSkrivSudoku(){
    array<array<int, 9>,9> sudoku{{
        {{6,0,2,5,8,1,3,9,7}},
        {{7,8,1,9,0,4,5,2,0}},
        {{5,0,0,6,2,7,8,0,1}},
        {{0,7,4,2,9,0,6,8,3}},
        {{9,3,8,4,1,0,2,0,5}},
        {{2,6,5,0,7,3,0,0,4}},
        {{0,5,6,0,4,2,7,3,9}},
        {{0,2,0,3,6,9,1,5,8}},
        {{3,1,9,0,0,8,0,6,0}}
    }};
    skrivutSudoku(sudoku);
}

void sorteraMedSelectionsort(vector<int>& vek){
    for(size_t i = 0; i < vek.size(); ++i){
        int minstTalIndex  = minst(vek, i)[1];
        int minstTal = vek[minstTalIndex];
        vek[minstTalIndex] = vek[i];
        vek[i] = minstTal;
    }
}

void sorteraMedBubbelsort(vector<int>& vek){
    bool sorterad = false;
    while(!sorterad){
        int andringar = 0;
        for(size_t i = 0; i < vek.size()-1; ++i){
           if(vek[i] > vek[i+1]){
                int placeHolder = vek[i];
                vek[i] = vek[i+1];
                vek[i+1] = placeHolder;
                andringar += 1;
            }
        }
        if(andringar == 0){
            sorterad = true;
        }
    }
}

void vectorIN(){
    vector<int> test{4,3,2,1};
    sorteraMedBubbelsort(test);
    skrivUtVek(test);
}



















