#include <iostream>
#include <stdio.h>

using namespace std;

bool confere (char * palavra, int first, int last){
    if (palavra[first] != palavra[last]){
        return false;
    }

    return confere(palavra, palavra[first+1], palavra[last-1]);

}


int main (){

    char *palavra;
    cout << "INFORME A PALAVRA: " << endl;
    cin >> palavra;
    int ultimo = palavra.size();

    confere(palavra,0,ultimo);

    return 0;
}




