//
//  main.cpp
//  MyProje
//
//  Created by fethi can sert on 09/04/2022.
//
// Merhaba Fatma hocam ben Fethi Can Sert
// Cok zamanim olmadigi icin tek tek aciklamak istemiyorum islemleri zaten hepsi kolay islemler.
// Bakinca anlarsiniz diye dusunuyorum.
// Key = rvcrscfvt
// PlainText = paymoremoney
// CyperText =rrlmwbkaspdh
// Veriyor.
// eksik olan harf yerine x yazip oyle hesapliyor.
// ama 9 12 15 gibi 3'etam bolulen sayilarda hicbir ekleme yapmiyor duz bir sekilde calisiyor.
// https://www.youtube.com/watch?v=JK3ur6W4rvw mantigi bu videodan ogrenip yaptim.

#include <iostream>

using namespace std;

int main() {
    
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int  key[3][3] = { {3, 20, 9}, {10, 9, 4}, {20, 17, 17} };
    int intAlphabet[100];
    char inputletterArray[100];
    char strKey[10];
    int IntKey[10];
    int realKey[3][3];
    int arr[100];
    
    int sizeofletter;
    bool ignoreone=false;
    bool ignoretwo=false;
    cout<<"Enter 9 Letter Key Please : ";
    cin.get(strKey,10);
    cout<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (strlen(strKey)==9) {
    }else{
        cout<<"Please enter valid key !!\n";
        cout<<"Start again application please\n";
        return 0;
    }
    
    for (int i=0; i<9; i++) {
    
        for (int j=0; j<26; j++) {
            if (strKey[i]==alphabet[j]) {
                IntKey[i]=j;
                break;
            }
        }
    }
    
    int index=0;
    for (int j=0; j<3; ++j){
        realKey[j][0]=IntKey[index];
        realKey[j][1]=IntKey[index+1];
        realKey[j][2]=IntKey[index+2];
        index=index+3;
    }
        cout<<"This is your key : \n";
        cout<<"\t\t\t\t\t"<<realKey[0][0]<<" "<<realKey[1][0]<<" "<<realKey[2][0]<<endl;
        cout<<"\t\t\t\t\t"<<realKey[0][1]<<" "<<realKey[1][1]<<" "<<realKey[2][1]<<endl;
        cout<<"\t\t\t\t\t"<<realKey[0][2]<<" "<<realKey[1][2]<<" "<<realKey[2][2]<<endl;
    
        
    
    cout<<endl;
    
    
    cout<<"Enter Your PlainText Please : ";
    cin.get(inputletterArray,100);
    cout<<endl;
    sizeofletter = strlen(inputletterArray);

    if (sizeofletter%3==1) {
        cout<<"2 letter miss!\n";
        cout<<"'x' added to end of input PlainText\n";
        ignoretwo=true;
        inputletterArray[sizeofletter]='x';
        inputletterArray[sizeofletter+1]='x';
    }
    else if(sizeofletter%3==2){
        cout<<"1 letter miss!\n";
        cout<<"'x' added to end of input PlainText\n";
        inputletterArray[sizeofletter]='x';
        ignoreone=true;
    }
    
    sizeofletter = strlen(inputletterArray);
    
    cout<<"PlainText : "<<inputletterArray<<endl;
    cout<<"Size of letter : "<<sizeofletter<<endl;
  
    
    for (int j=0; j<sizeofletter; j++) {
        int counter=0;
    for (int i=0; i<26; i++) {
        if (inputletterArray[j]==alphabet[i]){
            intAlphabet[j]=counter;
            break;
        }
        counter++;
    }
}
    
    
    int x=sizeofletter/3;
    cout<<"Repeat of Encryption : "<<x<<endl<<endl;
    
    int c;
    int r1;
    int r2;
    int r3;
    int d=0;
    int k=0;
    for (int i=0; i<x; i++) {
        cout<<i+1<<"."<<"Encryption :"<<endl;
        for (int j=0; j<3; ++j) {
            
            r1=intAlphabet[d]*realKey[j][0];
            r2=intAlphabet[d+1]*realKey[j][1];
            r3=intAlphabet[d+2]*realKey[j][2];
            c=(r1+r2+r3)%26;
            cout<<"C"<<j+1<<" = ("<<r1<<"+"<<r2<<"+"<<r3<<") mod 26 = "<<c<<endl;
            arr[k]=c;
            k++;
        }
        d=d+3;
        cout<<endl;
        
    }
    cout<<"CyperText : ";
    if (ignoreone) {
        sizeofletter--;
    }
    for (int i=0; i<sizeofletter; i++) {
        cout<<alphabet[arr[i]]<<"";
    }
    
    cout<<endl<<endl;
    
    cout<<"Encrypiton Successfuly Done!\n\n";
    
    return  0;
    
}
