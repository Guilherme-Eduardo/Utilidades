
#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

bool parserOk(string parser){
    bool OK = true;
    stack <char> pilha;
    bool comentario = false;
    int i = 0;
    char ch,ch1;
    while( i < parser.length() && OK ){

        ch = parser[i];

        if(ch == '\"' && comentario==false){
            comentario=true;
            cout << "Empilhou: " <<  pilha.top()  << endl;
        }

       else if(ch == '\'' && comentario==false){
            comentario=true;
            cout << "Empilhou: " << pilha.top() << endl;
        }

        else if (ch == '\"' && comentario==true){
            comentario=false;
            cout << "Desempilhou: " << pilha.top() << endl;
        }

        else if (ch == '\'' && comentario==true){
            comentario=false;
            cout << "Desempilhou: " << pilha.top() << endl;
        }
        else if (parser[i]=='/' && parser[i+1]=='*'){
            comentario=true;

        }
       else if (parser[i]=='*' && parser[i+1]=='/'){
            comentario=false;
        }


        if(comentario==false){

            if( ch == '(' ||
                ch == '[' ||
                ch == '{' ){
                pilha.push(ch);
            }

            if( ch == ')'){
               ch1 = pilha.top();
               pilha.pop();
               if( ch1 != '('){
                  OK = false;
               }
            }
            else if( ch == ']'){
               ch1 = pilha.top();
               pilha.pop();
               if( ch1 != '['){
                  OK = false;
               }
            }
            else if( ch == '}'){
               ch1 = pilha.top();
               pilha.pop();
               if( ch1 != '{'){
                  OK = false;
               }
            }
        }
        ++i;
    }

    if( ! pilha.empty() ){
        OK = false;
        cout << "ch=" << ch << " ch1 = " << ch1 << endl;
        cout << "i=" << i << endl;
        for( int x = i; x<parser.length(); ++x){
            cout << parser[x];
        }
        while( ! pilha.empty() ){
            cout << "Nao bateu:" << pilha.top() << endl;
            pilha.pop();
        }
    }

    return OK;

}

int main(){
   string linhas="";
   std::ifstream leitura("teste.cpp");
   if(leitura)
   {
	  while(leitura.good()) //enquanto nao houver erro na leitura, como badbit ou failbit
	  {
         string temp;
         getline (leitura, temp); //le linha por linha
         temp += "\n"; //colocar o final de linha
	     linhas += temp;
	  }
   }

   string parser = "([{oi}])";
   //cout << parserOk(parser) << endl;
   cout << parserOk(linhas) << endl;
   return 0;
}
