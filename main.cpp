#include<iostream>
#include "BlackGPIO/BlackGPIO.h"
#include <unistd.h>
#include <cstdlib>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<string>

using namespace std;

void acendeVermelho(){
  BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);
               ledR.setValue(BlackLib::high);
               ledG.setValue(BlackLib::low);
               ledB.setValue(BlackLib::low);
               sleep(3);
               ledR.setValue(BlackLib::low);
               ledG.setValue(BlackLib::low);
               ledB.setValue(BlackLib::low);

  }

  void acendeVerde (){
    BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);
           ledR.setValue(BlackLib::low);
           ledG.setValue(BlackLib::high);
           ledB.setValue(BlackLib::low);
           sleep(3);
           ledR.setValue(BlackLib::low);
           ledG.setValue(BlackLib::low);
           ledB.setValue(BlackLib::low);
  }

  void acendeAzul(){
    BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);
           ledR.setValue(BlackLib::low);
           ledG.setValue(BlackLib::low);
           ledB.setValue(BlackLib::high);
           sleep(3);
           ledR.setValue(BlackLib::low);
           ledG.setValue(BlackLib::low);
           ledB.setValue(BlackLib::low);
  }

void acendeTodas(){
  BlackLib::BlackGPIO   ledR(BlackLib::GPIO_60,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledG(BlackLib::GPIO_50,BlackLib::output, BlackLib::SecureMode);
    BlackLib::BlackGPIO   ledB(BlackLib::GPIO_51,BlackLib::output, BlackLib::SecureMode);
          ledR.setValue(BlackLib::high);
           ledG.setValue(BlackLib::high);
           ledB.setValue(BlackLib::high);
           sleep(3);
               ledR.setValue(BlackLib::low);
           ledG.setValue(BlackLib::low);
           ledB.setValue(BlackLib::low);
}

void perdeuPlay(){
          BlackLib::BlackGPIO   vermelho(BlackLib::GPIO_15,BlackLib::output, BlackLib::SecureMode);
	  vermelho.setValue(BlackLib::high);	
	  sleep(3);
          vermelho.setValue(BlackLib::low);
}

int main(int argc, char *argv[])
{
    BlackLib::BlackGPIO   botao(BlackLib::GPIO_115,BlackLib::input, BlackLib::SecureMode);
    

int i = 0;
int n;
int V[100];

int pontuacao = 0;
int numerojogador;
int contador=0;
int ganhador=0;
int vencedor=0;
cout << "Informe o numero de jogadores:" << endl;
cin >> numerojogador;

int vetor[numerojogador];

while (contador < numerojogador){
cout << endl;
cout<<endl;
cout <<"vez do jogador "<<contador+1<< " jogar" <<endl;
i=0;

	while(botao.getValue()=="0"){
         
    		int random = rand () % 4; 
   
       if (random == 1){
      		     acendeVermelho();
             
    		}
   		 else if (random == 2)
    		{
    		    acendeVerde();
          
    		}
    		else if (random == 3)
    		{
   		     acendeAzul();
          
    		}
    		else 
    		{
   		     acendeTodas();
          
           
   		 }
         
      V[i] = random;
      i++;

	}

   for(int j = 0; j < i; j++){
          //cout << V[j] << " ";
          cout << "Digite a sequência de cores " << endl;
          cin >> n;
          if(n==V[j]){
                if(n==1){
                  acendeVermelho();
		  pontuacao = pontuacao + 10;
                }else if (n==2){
                  acendeVerde();
		  pontuacao = pontuacao + 10;
                }else if (n==3){
                  acendeAzul();
		  pontuacao = pontuacao + 10;
                }else{
                  acendeTodas();
		  pontuacao = pontuacao + 30;
                }
          }
	  else{
            cout << "Perdeu Playboy" << endl;
            cout << "Sua pontuacao foi de " <<pontuacao << " pontos" << endl;
	    perdeuPlay();
	    j=i;
          }
   }  

if (pontuacao>ganhador){
	ganhador = pontuacao;
	vencedor = contador + 1;	
}
contador = contador + 1;
pontuacao=0; 

}  
cout<<endl;
cout<<"****************"<<endl;
cout <<"O jogador "<< vencedor<< " ganhou, e fez "<< ganhador <<" pontos"<< endl; 
return 0;
}
