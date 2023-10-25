#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

// Búsqueda Binaria

vector<int> binarySearch (string elString) {
    
    vector<int> charYcomparaciones{0,0};
    
    int left = 0;
    int right = elString.size()-1;
    
    //cout<<right<<endl;
    
    int comparaciones = 0;
    
    while (right-left>=0) {
        int mid = left + (right-left)/2;
        comparaciones++;
        if (elString[mid]!=elString[mid+1] && elString[mid]!=elString[mid-1]) {
            charYcomparaciones[0]=elString[mid];
            charYcomparaciones[1]=comparaciones;
            break;
        } else if (elString[mid]!=elString[mid+1] && elString[mid]==elString[mid-1]) {
            if (mid-1-left==0) {
            charYcomparaciones[0]=elString[mid+1];
            charYcomparaciones[1]=comparaciones;
            break;
            }
            else if ((mid-1-left)%2==0) {
                left = mid+1;    
            } 
            else {right = mid-2;}
            
        } else if (elString[mid]==elString[mid+1] && elString[mid]!=elString[mid-1]) {
            if ((right-(mid+1))==0) {
            charYcomparaciones[0]=elString[mid-1];
            charYcomparaciones[1]=comparaciones;
            break;
            }
            else if ((right-(mid+1))%2==0) {
                right = mid-1;    
            } else {left = mid+2;}
            
        }
    }
    
    return charYcomparaciones;
}

vector<int> sequentialSearch (string elString) {
    string::size_type comparaciones = 0;
    vector<int> charYcomparaciones{0,0};
    for (string::size_type i = 0; i < elString.size(); i++) {
    if (elString[i] == elString[i+1]){
        comparaciones++;
        i++;
    }
    else if (comparaciones == elString.size()/2) {
        charYcomparaciones[0]=elString[i];
        charYcomparaciones[1]=comparaciones;
        break;
    } else {
        comparaciones++;
        charYcomparaciones[0]=elString[i];
        charYcomparaciones[1]=comparaciones;
        break;
    }
}   
    return charYcomparaciones;
}

int main() {

int cantidadStrings=0;
cin>>cantidadStrings;

vector<int> comparacionesS;
vector<int> comparacionesB;

string elString;

for (int i = 0; i < cantidadStrings; i++) {

cin>>elString;

vector<int> respSeq = sequentialSearch(elString);
vector<int> respBin = binarySearch(elString);

comparacionesS.insert(comparacionesS.end(), begin(respSeq), end(respSeq));
comparacionesB.insert(comparacionesB.end(), begin(respBin), end(respBin));

}

for (int i = 0; i < cantidadStrings*2; i+=2) {
printf("%c %d ", comparacionesS[i], comparacionesS[i+1]);
printf("%c %d\n", comparacionesB[i], comparacionesB[i+1]);
}

return 0;

}
