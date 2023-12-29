#include <iostream>
#include <stdio.h>

using namespace std;

class Lista{

public:
    string nome;
    int idade;
    Lista *proximo;
    Lista *anterior;
    Lista *primeiro;
    Lista *ultimo;

    void filaVazia(){
        Lista *aux = new Lista;
        primeiro = aux;
        ultimo = primeiro;

    }

    void inserirNumeroFila(Lista *aux,int valor, string nome){
        aux = new Lista;
        aux->idade = valor;
        cout << "Inserindo na fila: " << "Nome: " <<aux->nome <<"\tidade: " << aux->idade << endl;
        ultimo->proximo = aux;
        ultimo = ultimo->proximo;
        aux->proximo = NULL;

    }

    void imprimir(Lista *aux){
        aux = primeiro->proximo;

        while(aux !=NULL){
            cout << "Nome: " <<aux->nome <<"\tidade: " << aux->idade << endl;
            aux = aux->proximo;
        }
    }

    void removendoNumeroFila(Lista *aux){
        aux = primeiro->proximo;
        while(aux!=NULL){
            cout << "Removendo da fila: " <<  "Nome: " <<aux->nome <<"\tidade: " << aux->idade << endl;
            primeiro = primeiro->proximo;
            aux = aux->proximo;
        }
        if(aux == NULL){
            cout << "Fila vazia..." << endl;
        }

    }
};

int main (){

    Lista *lista;
    lista = new Lista;
    lista->filaVazia();

    for(int i = 1; i <=20; i++){
        lista->inserirNumeroFila(lista,i,"gui");
    }
    cout << "\n\n";
    lista->removendoNumeroFila(lista);
    //lista->imprimir(lista);

    /*lista = lista->anterior;
    delete lista->proximo;
    lista->proximo = NULL;

    //considerando que vc está no inicio
    lista = lista->proximo;
    delete lista->anterior;
    lista->anterior = NULL;*/


    return 0;
}
