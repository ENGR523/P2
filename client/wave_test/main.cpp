#include <iostream>

#include "wave_test.h"

using namespace std;

int main(){
    
    cout << "\nPrinting out the Test WAV values:\n";

    for(int i =0; i < WAVE_LENGTH; ++i){
        cout << WAVE_DATA[i] << endl;
    }
    
    cout << "\nAnd sampling rate:\n"; 
    cout << WAVE_SAMPLE_RATE << endl; 

    return 0;
}
