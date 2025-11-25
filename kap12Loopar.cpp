
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std ;

//Kylskåpsloopar
void refrigeratorWithWhileTrue(){
    while(true){
        float temp;
        cin >> temp;

        if(temp < -273){
            break;
        }
        else if(temp <= 2){
            cout << "För kallt!" << endl;
        }
        else if(temp >= 8){
            cout << "För varmt!" << endl;
        }
        else{
            cout << "Lagom!" << endl;
        }
    }
}

void refrigeratorWithWhileCondition(){
    float temp = 0;

    while(temp > -273){
        cin >> temp;
        if(temp <= 2){
            cout << "För kallt!" << endl;
        }
        else if(temp >= 8){
            cout << "För varmt!" << endl;
        }
        else{
            cout << "Lagom!" << endl;
        }
    }
}

//Summatest
int sumAnalytics(int n){
    return (n*(n+1))/2;
}

int sumLoop(int n){
    int summa = 0;
    for(int i=0; i<=n; i+=1){
        summa += i;
    }
    return summa;
}

void compareSumCalc(int n){
    int resultone = sumLoop(n);
    int resulttwo = sumAnalytics(n);
    int diff = resultone - sumAnalytics(n);
    cout << "sumLoop(" << n << ") = " << resultone << endl
         << "sumAnalytics(" << n << ") = " << resulttwo << endl
         << "diff = " << diff << endl;
    assert(diff == 0);
}

void compareMultipleSumCalc(){
    for(int n=0; n<100; n+=20){
        compareSumCalc(n);
    }
}

//Gissningsspel
int newNumber(int n){
    srand(time(NULL));
    return rand() % (n + 1);
}

int userGuess(){
    int num;
    cin >> num;
    return num;
}

void playRound(){
    cout << "Utför en spelomgång." << endl;

    const int n = 10;
    const int computerNum = newNumber(n);
    int numberOfGuesses = 0;

    cout << "Datorn tänker på ett tal mellan 0 och " << n << endl
         << "gissa vilket!" << endl;

    while(true){
        numberOfGuesses += 1;
        if(userGuess() == computerNum){
            break;
        }
        else{
            cout << "Fel!" << endl;
        }
    }

    cout << "Du gissade rätt!" << endl
         << "Det tog " << numberOfGuesses << " försök!" << endl;
}



void LoopIN(){
    playRound();
}




































