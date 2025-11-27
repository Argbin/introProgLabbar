#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cctype>

using namespace std ;

void charExperiment(){
    char ch1 = 'R';
    char ch2 = 82;
    int i1 = 'R';
    int i2 = 82;

    cout << ch1 << endl;
    cout << ch2 << endl;
    cout << i1 << endl;
    cout << i2 << endl;
}

void writePartOfAscii(){
    for (int asciiNum = 'a'-5; asciiNum <= 'z'+5; ++asciiNum){
        char sign = asciiNum;
        cout << asciiNum << "\t" << sign << "\n";
    }
}

void stringDemo1(){
    string str1 = "ABC";
    cout << str1 << " has the size " << str1.size() << endl;
    cout << "str1[0] == " << str1[0] << endl << endl;

    string str2 = "ÅÄÖ";
    cout << str2 << " has the size " << str2.size() << endl;
    cout << "str2[0] == " << str2[0] << endl << endl;
}

void stringDemo2(){
    string name = "lisa";
    name[0] = toupper(name[0]);
    cout << name << endl;
}

void stringDemo3(){
    string name = "Lisa";
    string lastName = "Simpson";

    string fullName = name + " " + lastName;

    cout << fullName << endl;
}

void stringDemo4(){
    string str = "Ha en bra dag!";
    for (unsigned int i=0; i<str.size(); ++i){
        cout << str[i] << "-";
    }
    cout << endl;
}

string upperCaseCoverter(const string& str){
    string upperStr;
    for (unsigned int i=0; i < str.size(); ++i){
        upperStr += toupper(str[i]);
    }
    return upperStr;
}

void upperCaseConverterTester(){
    cout << "Testing upperCaseConverter function" << endl;
    assert(upperCaseCoverter("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ");
    cout << "Test was a success!" << endl;
}

string firstCaseToUpperConverter(const string& str){
    if(str.empty()){
        return "";
    }

    string upperStr;
    upperStr += toupper(str[0]);
    for (unsigned int i=1; i < str.size(); ++i){
        if(str[i - 1] == ' '){
            upperStr += toupper(str[i]);
        }
        else{
            upperStr += tolower(str[i]);
        }
    }
    return upperStr;
}

void firstCaseToUpperConverterTester(){
    cout << "Testing firstCaseToUpperConverter" << endl;
    assert(firstCaseToUpperConverter("ha en BRA DAG!") == "Ha En Bra Dag!");
    assert(firstCaseToUpperConverter("HA EN BRA DAG!") == "Ha En Bra Dag!");
    assert(firstCaseToUpperConverter("") == "");
    cout << "Test was a success!" << endl;
}

string reduced(const string& str){
    string reducedStr;
    bool lastWasSpace = false;

    for(unsigned int i = 0; i < str.size(); ++i){
        if(str[i] != ' '){
            reducedStr += str[i];
            lastWasSpace = false;
        }
        else if(lastWasSpace == false){
            reducedStr += str[i];
            lastWasSpace = true;
        }
    }
    return reducedStr;
}

void reducedTester(){
    cout << "Testing reduced" << endl;
    assert( reduced("  Ha en bra   dag!  ") == " Ha en bra dag! ");
    assert( reduced(" A    B C   ") == " A B C ");
    assert( reduced("ABC") == "ABC");
    cout << "Test was a success!" << endl;
}

string trimmed(const string& str){

    string trimmedStr{};
    size_t lastCharIndex{};
    size_t firstCharIndex{};

    //Om ingen bokstav hittades, returna ""
    if(empty(str)){
        return "";
    }

    //Hitta index på första bokstaven
    for(size_t i = 0; i < str.size()-1; ++i){
        if(str[i] != ' '){
            firstCharIndex = i;
            break;
        }
    }

    //Hitta index för sista bokstaven
    for(size_t i = str.size()-1; i >= firstCharIndex; --i){
        if(str[i] != ' '){
            lastCharIndex = i;
            break;
        }
    }

    //Skapa en string som innegåller första och sista bokstaven sammt allt däremellan
    for(size_t i = firstCharIndex; i <= lastCharIndex; ++i){
        trimmedStr += str[i];
    }

    return trimmedStr;
}

void trimmedTester(){
    cout << "Testing trimmed" << endl;
    assert( trimmed("  Ha en bra dag!   ") == "Ha en bra dag!");
    assert( trimmed(" A    B  C ") == "A    B  C");
    assert( trimmed("    ") == "");
    assert( trimmed("abc") == "abc");
    cout << "Test was a success!" << endl;
}

bool isVokal(char ch){
    string vokaler = "aeiouyAEIOUY";
    for(unsigned int i = 0; i < vokaler.size(); ++i){
        if(vokaler[i] == ch){
            return true;
        }
    }
    return false;
}

bool isKonsonant(char ch){
    string konsonanter = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    for(unsigned int i = 0; i < konsonanter.size(); ++i){
        if(konsonanter[i] == ch){
            return true;
        }
    }
    return false;
}

string isprik(const string& str){
    string translation;
    for(unsigned int i = 0; i < str.size(); ++i){
        if(isVokal(str[i])){
            translation += 'i';
        }
        else{
            translation += str[i];
        }
    }
    return translation;
}

string rovarsprak(const string& str){
    string translation;
    for(size_t i = 0; i < str.size(); ++i){
        if(isKonsonant(str[i])){
            translation += tolower(str[i]);
            translation += 'o';
            translation += tolower(str[i]);
        }
        else{
            translation += tolower(str[i]);
        }
    }
    translation[0] = toupper(translation[0]);
    return translation;
}

bool isRovarsprak(const string& str){
    bool lastWasKonsonant = false;
    for(size_t i = 0; i < str.size(); ++i){
        if(isKonsonant(str[i]) && lastWasKonsonant == false){
            if(tolower(str[i+1]) != 'o'){
                return false;
            }
            lastWasKonsonant = true;
        }
        else if(isKonsonant(str[i]) && lastWasKonsonant == true){
            lastWasKonsonant = false;
        }
    }
    return true;
}

string klartextFranRovarsprak(const string& str){
    string klartext{};
    if(isRovarsprak(str)){
        for(size_t i = 0; i < str.size(); ++i){
            if(isKonsonant(str[i])){
                klartext += str[i];
                i += 2;
            }
            else if(isVokal(str[i])){
                klartext += str[i];
            }
        }
        return klartext;
    }
    else{
        return "Detta är inte rövarspråk!";
    }
}




void charAndStringIN(){
    cout << klartextFranRovarsprak(rovarsprak(("Hej"))) << endl;
}























