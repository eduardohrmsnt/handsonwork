#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{
    int iValor;
    int iOpcao;
    int iResultado;


    /*Menu desenvolvido usando o looping do-while, enquanto a
    opcao nao for v�lida ele vai continuar carregando o menu at� que se escolha uma op��o valida*/
    do{

        cout<< "Escolha uma das opcoes: \n" << endl;

        cout << "1 - Binario para decimal." << endl;
        cout << "2 - Decimal para binario.\n" << endl;

        cin >> iOpcao;
        if (iOpcao < 1 || iOpcao > 2)/*Condicional para caso  a op��o digita n�o for a
        que est� informada na tela carregue o menu novamente*/

         cout<< "Digite uma opcao valida."<< endl;
         Sleep(2000); //Aguarda dois segundos
         system("cls");//Limpa o console


      } while (iOpcao < 1 || iOpcao > 2);//Enquanto a op��o nao for v�lida ir� carregar o menu

      //Comando switch para cada uma das op�oes do menu
      switch(iOpcao){

      case 1://1 - Binario para decimal.
        {
        //Dec recebe 0 para come�o da incrementa��o do resultado em decimal.
        //d recebe 1 pois � o numero inicial da base.
        int dec = 0,d=1;
        cout << "Digite o valor em binario: " <<endl;
        cin >> iValor;

        //Looping do-while interpretado como "fa�a enquanto tal condi��o for satisfeita"
        do{


            dec = dec+(iValor%10)*d;
            /*Caso a sobra seja maior que 0 ele vai icrementar na variavel DEC, caso for 0
            ele vai somar 0 ao DEC*/

            d = d*2; //Vai para o pr�ximo valor (1,2,4,8,16,32...)

            iValor = iValor/10; //Divide a base bin�ria para o c�lculo posterior.

        }while(iValor!=0);//Ele sair� do loop quando a variavel iValor for igual a 0

        cout<< "Resultado:" << dec << endl;//Mostra o resultado para o usu�rio.

        }
        break;

      case 2://2 - Decimal para binario

        int bin[7];//Criado o vetor bin de 7 posi��es para armazenar cada posi��o do bin�rio
        do{
            cout << "Digite o valor em decimal: " <<endl;
            cin >>iValor;

            if (iValor < 0 || iValor > 255)//Verifica��o para que s� possa digitar valores entre 0 e 255
            {
                cout << "Digite um valor v�lido!"<<endl;
                Sleep(2000);
                system("cls");


            }
            else{

                for (int iPos = 7; iPos >= 0; iPos --) /*Looping for com iPos sendo as posi��es no caso 7, lembrando
                 que o vetor come�a com a posi��o 0.*/

                {
                    if(iValor % 2 == 0)//Se a sobra for igual a 0 a posi��o atual receber� o valor 0
                    {
                        bin[iPos] = 0;

                    }
                    else //Se n�o, ser� 1
                    {
                        bin[iPos] = 1;
                    }
                        iValor = iValor/2;
                }

            }
        }while(iValor < 0 || iValor > 255);
        cout << "Resultado:"<<bin[0]<<bin[1]<<bin[2]<<bin[3]<<bin[4]<<bin[5]<<bin[6]<<bin[7]<<endl;
        //Concatena as posi��es do array para que tenha o resultado
        break;
      }

    return 0;
}

