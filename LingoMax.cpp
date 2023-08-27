#include <iostream>

using namespace std;

struct Idiomas{
    int codigo;
    char descricao[30];
};

struct IndiceIdioma{
    int codigo;
    int endereco;
};

struct Licoes{
    int cod_licao;
    int cod_idioma;
    int total_niveis;
};

struct IndiceLicoes{
    int codigo;
    int endereco;
};

struct Exercicios{
    int cod_exercicio;
    int nivel_dificuldade;
    char descricao[30];
    char resposta_correta[30];
    int pontuacao;
};

struct IndiceExercicios{
    int codigo;
    int endereco;
};

struct Usuarios{
    int codigo;
    char nome[30];
    int codigo_idioma;
    int nivel_atual;
    int pontuacao_total;
};

struct IndiceUsuarios{
    int codigo;
    int endereco;
};

void leituraDoIndiceDeIdiomas(struct IndiceIdioma indiceIdioma[], int contIdioma){
    for(int i = 0; i < contIdioma; i++){
        cout << "\n\nCodigo do Indice do Idioma: " << (i + 1) << ": ";
        cin >> indiceIdioma[i].codigo;
        cout << "Endereco Fisico na Area de Dados de Idioma: ";
        cin >> indiceIdioma[i].endereco;
    }
}

void leituraDoIndiceDeLicoes(struct IndiceLicoes indiceLicoes[], int contLicoes){
    for(int i = 0; i < contLicoes; i++){
        cout << "\n\nCodigo do Indice da Licao: " << (i + 1) << ": ";
        cin >> indiceLicoes[i].codigo;
        cout << "Endereco Fisico na Area de Dados de Licao: ";
        cin >> indiceLicoes[i].endereco;
    }
}

void leituraDoIndiceDeExercicios(struct IndiceExercicios indiceExercicios[], int contExercicios){
    for(int i = 0; i < contExercicios; i++){
        cout << "\n\nCodigo do Indice do Exercicio: " << (i + 1) << ": ";
        cin >> indiceExercicios[i].codigo;
        cout << "Endereco Fisico na Area de Dados de Exercicio";
        cin >> indiceExercicios[i].endereco;
    }
}

void leituraDoIndiceDeUsuarios(struct IndiceUsuarios indiceUsuarios[], int contUsuarios){
    for(int i = 0; i < contUsuarios; i++){
        cout << "\n\nCodigo do Indice do Usuario: " << (i + 1) << ": ";
        cin >> indiceUsuarios[i].codigo;
        cout << "Endereco Fisico na Area de Dados de Usuario: ";
        cin >> indiceUsuarios[i].endereco;
    }
}

void leituraDeIdiomas(struct Idiomas idiomas[], int &cont){
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++){
        cout << "\n\nCodigo do Idioma " << (i+1) << ": ";
        cin >> idiomas[i].codigo;
        cin.ignore();
        cout << "\nDigite a descricao do idioma: ";
        gets(idiomas[i].descricao);
    }
}

void leituraDeLicoes(struct Licoes licoes[], int &cont){
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++){
        cout << "\n\nCodigo da Licao " << (i + 1) << ": ";
        cin >> licoes[i].cod_licao;
        cout << "Digite o codigo do idioma: ";
        cin >> licoes[i].cod_idioma;
        cout << "Digite o total de niveis: ";
        cin >> licoes[i].total_niveis;
    }
}

void leituraDeExercicios(struct Exercicios exercicios[], int &cont){
    int i = 0;
    for(int saida = 1; i < 5 && saida != 0; i++){
        cout << "\n\nCodigo do Exercicio " << (i + 1) << ": ";
        cin >> exercicios[i].cod_exercicio;
        cout << "Nivel de Dificuldade: ";
        cin >> exercicios[i].nivel_dificuldade;
        cin.ignore();
        cout << "Descricao: ";
        gets(exercicios[i].descricao);
        cout << "Resposta Correta: ";
        gets(exercicios[i].resposta_correta);
        cout << "Pontuacao: ";
        cin >> exercicios[i].pontuacao;
    }
}

void leituraDeUsuarios(struct Usuarios usuarios[], int &cont){
    int i = 0;
    for(int saida = 1; i < 5 && saida != 0; i++){
        cout << "\n\nCodigo do Usuario " << (i + 1) << ": ";
        cin >> usuarios[i].codigo;
        cout << "Nome: ";
        gets(usuarios[i].nome);
        cout << "Codigo do Idioma: ";
        cin >> usuarios[i].codigo_idioma;
        cout << "Nivel Atual: ";
        cin >> usuarios[i].nivel_atual;
        cout << "Pontuacao Total:";
        cin >> usuarios[i].pontuacao_total;
    }
}





int main(){
    //INDICES
    IndiceIdioma indiceIdioma[5];
    IndiceLicoes indiceLicoes[5];
    IndiceExercicios indiceExercicios[5];
    IndiceUsuarios indiceUsuarios[5];

    //TABELAS
    Idiomas vIdioma[5];
    Licoes vLicoes[5];
    Exercicios vExercicios[5];
    Usuarios vUsuarios[5];



    int opcao;

    //QUANTIDADES
    int quantidadeDeIdiomas = 5;
    int quantidadeDeLicoes = 5;
    int quantidadeDeExercicios = 5;
    int quantidadeDeUsuarios = 5;

    do{
      cout << "Selecione uma opcao: \n";
      cout << "1 - Realizar Leitura do Indice do Idioma \n";
      cout << "2 - Realizar Leitura do Indice de Licoes \n";
      cout << "3 - Realizar Leitura do Indice de Exercicio \n";
      cout << "4 - Realizar Leitura do Indice de Usuario \n";
      cout << "5 - Realizar Leitura da Tabela do Idioma \n";
      cout << "6 - Realizar Leitura da Tabela de Licoes \n";
      cout << "7 - Realizar Leitura da Tabela de Exercicios \n";
      cout << "8 - Realizar Leitura da Tabela de Usuarios \n";
      cout << "0 - Para Encerrar\n";
      cin >> opcao;
      switch(opcao)
      {
      case 1:
        cout << "Voce escolheu realizar a leitura do Indice do Idioma \n";
        leituraDoIndiceDeIdiomas(indiceIdioma, 5);
        break;
      case 2:
        cout << "Voce escolheu realizar a leitura do Indice de Licoes \n";
        leituraDoIndiceDeLicoes(indiceLicoes, 5);
        break;
      case 3:
        cout << "Voce escolheu realizar a leitura do Indice de Exercicios \n";
        leituraDoIndiceDeExercicios(indiceExercicios, 5);
        break;
      case 4:
        cout << "Voce escolheu realizar a leitura do Indice de Usuarios \n";
        leituraDoIndiceDeUsuarios(indiceUsuarios, 5);
        break;
      case 5:
        cout << "Voce escolheu realizar a leitura da tabela de Idiomas \n";
        leituraDeIdiomas(vIdioma, quantidadeDeIdiomas);
        break;
      case 6:
        cout << "Voce escolheu realizar a leitura da tabela de licoes \n";
        leituraDeLicoes(vLicoes, quantidadeDeLicoes);
      case 7:
        cout << "Voce escolheu realizar a leitura da tabela de exercicios \n";
        leituraDeExercicios(vExercicios, quantidadeDeExercicios);
      case 8:
        cout << "Voce escolheu realizar a leitura da tabela de usuarios \n";
        leituraDeUsuarios(vUsuarios, quantidadeDeUsuarios);
      case 0:
        cout << "Encerrando o programa... \n";
        break;
      default:
        cout << "Opcao Invalida. Tente Novamente. \n";
        break;
      }
    }
    while(opcao != 0);
    return 0;
}
