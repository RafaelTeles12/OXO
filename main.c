#include <stdio.h>

//Jogo da Velha - Linguagem C - Rafael Teles

//Criação da matriz do jogo e inicialização da varável de jogador
char oxo[3][3];
char jogador = 'x';

//Função para imprimir o tabuleiro
void imprimirTabuleiro(){
  
  printf("\n  1   2   3 ");
  printf("\n1 %c | %c | %c ", oxo[0][0],oxo[0][1],oxo[0][2]);
  printf("\n -----------");
  printf("\n2 %c | %c | %c ", oxo[1][0],oxo[1][1],oxo[1][2]);
  printf("\n -----------");
  printf("\n3 %c | %c | %c ", oxo[2][0],oxo[2][1],oxo[2][2]);
  
}

//Função para a execução da jogada
void jogar(){
  
  int linha, coluna, validez = 0;
  
  do{
    
    if (jogador=='x'){
      printf("\n\nJogador x: digite a linha e a coluna separadamente: ");
    }
    else{
      printf("\n\nJogador o: digite a linha e a coluna separadamente: ");
    }
  
    scanf("%d %d", &linha, &coluna);
    
    if (linha>3||coluna>3||linha<1||coluna<1){
      printf("\nLinha e/ou coluna inválida. Tente novamente.");
    }
    else if (oxo[linha-1][coluna-1]=='x'||oxo[linha-1][coluna-1]=='o'){
      printf("\nPosição já ocupada. Tente novamente.");
    }
    else {
      oxo[linha-1][coluna-1]=jogador;
      validez++;
    }
    
  } while (validez==0);

  if (jogador=='x'){
    jogador='o';
  } else{jogador='x';}
  
}

//Função para verificar se houve vencedor
int verificarVitoria(char jogador){
  int vitoria=0, contador=0;

  for(int i=0; i<3; i++){
    contador=0;
    for(int j=0; j<3; j++){
      if(oxo[i][j]==jogador){
        contador++;
      }
      
      if (contador==3){
      vitoria++;
      }
    }
  }

  for(int i=0; i<3; i++){
    contador=0;
    for(int j=0; j<3; j++){
      if(oxo[j][i]==jogador){
        contador++;
      }

      if (contador==3){
      vitoria++;
      }
    }
  }

  if(oxo[0][0]==jogador && oxo[1][1]==jogador && oxo[2][2]==jogador){
    vitoria++;
  }

  if(oxo[2][0]==jogador && oxo[1][1]==jogador && oxo[0][2]==jogador){
    vitoria++;
  }
  
  return vitoria;
}

//Execução principal
int main() {

  //Inicialização da matriz
  for(int i=0;i<=2;i++){
    for(int j=0;j<=2;j++){
      oxo[i][j]=' ';
    }
  }

  printf("OXO\n");

  for(int i=0;i<=8;i++){
    imprimirTabuleiro();
    jogar();
    if(verificarVitoria('x')>0){
      printf("\n\nJogador x venceu!");
      break;
    }
    else if(verificarVitoria('o')>0){
      printf("\n\nJogador o venceu!");
      break;
    }
  }

  //Se não houve vencedor - declara empate
  if (verificarVitoria('x')==0 && verificarVitoria('o')==0){
    printf("\n\nEmpate!");
  }

  return 0;
}