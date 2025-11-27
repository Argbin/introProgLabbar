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

}

void vectorIN(){
    vector<int> vek{1, 2, 2, 5};
    cout << arSorterad(vek) << endl;
}








