#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cctype>
#include <vector>

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

vector<int> minst(const vector<int>& vek){
    vector<int> minst{vek[0], 0};
    for(size_t i = 0; i < vek.size(); ++i){
        if(vek[i] < minst[0]){
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
        for(size_t n = 0; n < slumpTal.size(); ++n){
            if(playerNums[i] == slumpTal[n]){
                points += 1;
                break;
            }
        }
    }

    return points;
}

void vectorIN(){
    vector<int> input{1,2,3,4,5};
    cout << lottoSpel(input) << endl;
}



















