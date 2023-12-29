#include <iostream>
#include <algorithm>
#include <chrono>
#include <queue>

using namespace std::chrono;

using namespace std;

template <class T>
class vQueue{
public:
    void enqueue(T e){
        vet.push_back(e);
    }
    T dequeue(){

        T r = vet[0];
        vet.erase(vet.begin());
    }
    bool empty(){
        return vet.empty();
    }
    bool size(){
        return vet.size();
    }

private:
    vector<T> vet;
};


long randomico(int _inicial, int _final)
{
   static bool ligado = true;
   int numero;

   if(ligado) //se ligado=true inicializa os randomicos
   {
      srand(time(0));
      ligado = false;
   }

   if(_final == 0) //se nao tiver max
      numero = rand();
   else
      numero = rand() % (_final - _inicial); //final-inicial garante o intervalo de numeros

   return numero + _inicial; //num+inicial garante o min
}



string geraLetraRandomicoMinuscula(int _qtd)
{
   int vezes = 0;
   string s;
   while(vezes < _qtd)
   {
     int c;
     c = randomico(97, 122);
     s += string(1, c);
     ++vezes;
   }
   return s;
}

string geraLetraRandomicoMaiscula(int _qtd)
{
   int vezes = 0;
   string s;
   while(vezes < _qtd)
   {
     int c;
     c = randomico(65, 90);
     s += string(1, c);
     ++vezes;
   }
   return s;
}

int main() {



    for( int x =1; x<100; ++x) {
        vQueue<string>fila;
        vector <string> nomes;

        for( int i = 0; i<10000; ++i) {
            string s = geraLetraRandomicoMaiscula(1) + geraLetraRandomicoMinuscula(9);
            nomes.push_back(s);
        }

        auto start = chrono::high_resolution_clock::now();

        for(int i=0; i < 10000;i++){
            fila.enqueue(nomes[i]);
        }

     /*  for( int i = 0; i<nomes.size(); ++i) {
            cout << nomes[i] << endl;
        }*/

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

	    cout << "Tempo para criar fila com os elementos do vetor: "<< duration.count() << endl;

        auto start2 = chrono::high_resolution_clock::now();

        while(!fila.empty()){
            fila.dequeue();
        }
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout << "Tempo para retirar os elementos da fila: "<< duration2.count() << endl;

    }

}
