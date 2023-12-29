#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <fstream>
using namespace std;

void jogaNaPilha(string valor, stack <int> &pilha1){
    for (int i=0; i < valor.size(); i++){
        pilha1.push(valor[i]-'0');
    }
    return;
}

void mostraResultado (stack <int> &resultado){
    stack <int> resultadoOrdemCerta;

        while(!resultado.empty()){
        resultadoOrdemCerta.push(resultado.top());
        resultado.pop();
        cout << resultadoOrdemCerta.top();
            if(resultado.empty()){
                break;
            }

    }
}

int main(){
     setlocale(LC_ALL, "Portuguese");
    //Declarando variaveis que vão receber os valores das pilhas
    string valor1, valor2;

    //Declarando as pilhas
    stack <int> pilha1;
    stack <int> pilha2;
    stack <int> resultado;

    cout << "INFORME O VALOR DA PRIMEIRA PILHA: ";
    cin >> valor1;

    cout << "INFORME O VALOR DA SEGUNDA PILHA: ";
    cin >> valor2;

    jogaNaPilha(valor1, pilha1);
    jogaNaPilha(valor2, pilha2);


    cout << endl << endl ;


  //  cout << "topo da pilha invertida 1: " <<  pilha1Invertida.top() << endl;
  //  cout << "topo da pilha invertida 2: " <<  pilha2Invertida.top() << endl << endl;

    while (true){
       int vaiUm;

        if(pilha1.empty()){  //Confiro se a pilha está vazia. Caso sim, ele acrescenta o valor zero para completar a soma entre as pilhas.
            pilha1.push(0);
        }
        if(pilha2.empty()){ //Confiro se a pilha está vazia. Caso sim, ele acrescenta o valor zero para completar a soma entre as pilhas.
            pilha2.push(0);
        }

        int somaPilha =pilha1.top() + pilha2.top();//Soma entre os elementos do tempo das pilhas.

        if (vaiUm ==1){
        somaPilha+=vaiUm;
        }

        if(somaPilha < 10) {

            resultado.push(somaPilha);
            vaiUm=0;
        }
        else if(somaPilha >=10){
            somaPilha = somaPilha % 10;
            resultado.push(somaPilha);
            vaiUm=1;
        }

        pilha1.pop();  //Remove os últimos valores
        pilha2.pop();  //Remove os últimos valores

            //cout << resultado.top();

        if (pilha1.empty() && pilha2.empty()){
            if (vaiUm>=1){
                resultado.push(vaiUm);
                //cout << resultado.top() << endl;
            }
            break;
        }

    }
        mostraResultado(resultado);


    return 0;
}
