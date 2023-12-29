#include <iostream>
#include <stack>
#include <locale.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    char expressao[50];
    cout << "DIGITE A EXPRESSAO MATEMATICA: ";
    cin >> expressao;
    char topoRetira;

    stack<char>pilha1;
    stack<char>retira;
    int contador=0;
    bool expressaoCorreta;


   /*for (int i=0; i < 50;i++){
        cout << expressao[i] << endl;
        if (expressao[i]=='\0'){
            break;
        }
    }
*/
   do{

        if(*(expressao+contador)=='(' ||
            *(expressao+contador)=='[' ||
            *(expressao+contador)=='{')
        {

            pilha1.push(*(expressao+contador));

        }

        else if (*(expressao+contador)==')'||
            *(expressao+contador)==']'||
            *(expressao+contador)=='}')
        {

            retira.push(pilha1.top());
            pilha1.pop();
            topoRetira = retira.top();

            if((*(expressao+contador) == ')' && retira.top() != '(' ) ||
                (*(expressao+contador) == ']' && retira.top() !='[' ) ||
                (*(expressao+contador) == '}' && retira.top() != '{'))

                {
                expressaoCorreta=false;
                cout << "EXPRESSAO MAL FORMULADO" << endl;
                break;
            }
        }

        ++contador;
    } while ( expressao[contador] != '\0');

        if ( pilha1.empty()){
            expressaoCorreta=true;
            cout << "EXPRESSAO BEM FORMULADA" << endl;

        }
        else{
            cout << "EXPRESSÃO MAL FORMULADA" << endl;
        }

    return 0;
}
