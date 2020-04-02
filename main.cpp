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
    opcao nao for válida ele vai continuar carregando o menu até que se escolha uma opção valida*/
    do{

        cout<< "Escolha uma das opcoes: \n" << endl;

        cout << "1 - Binario para decimal." << endl;
        cout << "2 - Decimal para binario.\n" << endl;

        cin >> iOpcao;
        if (iOpcao < 1 || iOpcao > 2)/*Condicional para caso  a opção digita não for a
        que está informada na tela carregue o menu novamente*/

         cout<< "Digite uma opcao valida."<< endl;
         Sleep(2000); //Aguarda dois segundos
         system("cls");//Limpa o console


      } while (iOpcao < 1 || iOpcao > 2);//Enquanto a opção nao for válida irá carregar o menu

      //Comando switch para cada uma das opçoes do menu
      switch(iOpcao){

      case 1://1 - Binario para decimal.
        {
        //Dec recebe 0 para começo da incrementação do resultado em decimal.
        //d recebe 1 pois é o numero inicial da base.
        int dec = 0,d=1;
        cout << "Digite o valor em binario: " <<endl;
        cin >> iValor;

        //Looping do-while interpretado como "faça enquanto tal condição for satisfeita"
        do{


            dec = dec+(iValor%10)*d;
            /*Caso a sobra seja maior que 0 ele vai icrementar na variavel DEC, caso for 0
            ele vai somar 0 ao DEC*/

            d = d*2; //Vai para o próximo valor (1,2,4,8,16,32...)

            iValor = iValor/10; //Divide a base binária para o cálculo posterior.

        }while(iValor!=0);//Ele sairá do loop quando a variavel iValor for igual a 0

        cout<< "Resultado:" << dec << endl;//Mostra o resultado para o usuário.

        }
        break;

      case 2://2 - Decimal para binario

        int bin[7];//Criado o vetor bin de 7 posições para armazenar cada posição do binário
        do{
            cout << "Digite o valor em decimal: " <<endl;
            cin >>iValor;

            if (iValor < 0 || iValor > 255)//Verificação para que só possa digitar valores entre 0 e 255
            {
                cout << "Digite um valor válido!"<<endl;
                Sleep(2000);
                system("cls");


            }
            else{

                for (int iPos = 7; iPos >= 0; iPos --) /*Looping for com iPos sendo as posições no caso 7, lembrando
                 que o vetor começa com a posição 0.*/

                {
                    if(iValor % 2 == 0)//Se a sobra for igual a 0 a posição atual receberá o valor 0
                    {
                        bin[iPos] = 0;

                    }
                    else //Se não, será 1
                    {
                        bin[iPos] = 1;
                    }
                        iValor = iValor/2;
                }

            }
        }while(iValor < 0 || iValor > 255);
        cout << "Resultado:"<<bin[0]<<bin[1]<<bin[2]<<bin[3]<<bin[4]<<bin[5]<<bin[6]<<bin[7]<<endl;
        //Concatena as posições do array para que tenha o resultado
        break;
      }

    return 0;
}

