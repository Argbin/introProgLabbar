#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cctype>
#include <vector>
#include <array>

struct Vaxel3 {
    int m_antal500 ;
    int m_antal200 ;
    int m_antal100 ;
    int m_antal20 ;
    int m_antal10 ;
    int m_antal5 ;
    int m_antal1 ;
};

using namespace std;

Vaxel3 vaxel3FranAntal(int a500, int a200, int a100, int a20, int a10, int a5, int a1){
    Vaxel3 i{};
    i.m_antal500 = a500;
    i.m_antal200 = a200;
    i.m_antal100 = a100;
    i.m_antal20 = a20;
    i.m_antal10 = a10;
    i.m_antal5 = a5;
    i.m_antal1 = a1;
    return i;
}

Vaxel3 vaxel3FranBelop(int belop){
    Vaxel3 i{};
    while(belop%500 > 200){
        i.m_antal500 += 1;
        belop -= 500;
    }
    while(belop%200 > 100){
        i.m_antal200 += 1;
        belop -= 200;
    }
    while(belop%100 > 20){
        i.m_antal100 += 1;
        belop -= 100;
    }
    while(belop%20 > 10){
        i.m_antal20 += 1;
        belop -= 20;
    }
    while(belop%10 > 5){
        i.m_antal10 += 1;
        belop -= 10;
    }
    while(belop%5 > 1){
        i.m_antal5 += 1;
        belop -= 5;
    }
    while(belop%1 != 0){
        i.m_antal1 += 1;
        belop -= 1;
    }
    return i;
}

void structIN(){
    Vaxel3 i = vaxel3FranBelop(1235);
    cout <<  i.m_antal500 << endl;
    cout <<  i.m_antal200 << endl;
    cout <<  i.m_antal100 << endl;
    cout <<  i.m_antal20 << endl;
    cout <<  i.m_antal10 << endl;
    cout <<  i.m_antal5 << endl;
    cout <<  i.m_antal1 << endl;


}


























