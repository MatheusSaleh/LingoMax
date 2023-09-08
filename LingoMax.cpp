#include <iostream>
#include <cstring>

using namespace std;

struct Idiomas{
    int codigo;
    char descricao[30];
    int status;
};

struct IndiceIdioma{
    int codigo;
    int endereco;
};

struct Licoes{
    int cod_licao;
    int cod_idioma;
    int total_niveis;
    int status;
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
    int status;
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
    int status;
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
        cout << "\nDigite o status (O - Para Registro Ativo / 1 - Para Registro Excluido)";
        cin >> idiomas[i].status;
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
        cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido)";
        cin >> licoes[i].status;
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
        cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido)";
        cin >> exercicios[i].status;
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
        cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido)";
        cin >> usuarios[i].status;
    }
}

void inclusaoNaTabelaDeIdiomas(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int &cont, int cod){
    cont++;
    idiomas[cont].codigo = cod;
    cout << "Descricao: ";
    gets(idiomas[cont].descricao);
    cout << "Status: (0 - Para Registro Ativo / 1 - Para Registro Excluido)";
    cin >> idiomas[cont].status;
    int i;
    for (i = cont - 1; indiceIdioma[i].codigo > cod; i--){
        indiceIdioma[i + 1].codigo = indiceIdioma[i].codigo;
        indiceIdioma[i + 1].endereco = indiceIdioma[i].endereco;
    }
    indiceIdioma[i + 1].codigo = cod;
    indiceIdioma[i + 1].endereco = cont;
    cout << "\n\nInclusao Realizada Com Sucesso";
}

void buscaAleatoriaNaTabelaDeIdiomas(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceIdioma[m].codigo; m = (i+f) / 2){
        if(cod > indiceIdioma[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceIdioma[m].codigo){
        cout << "\n\n Idioma ja cadastrado - nao pode ser cadastrado novamente";
        i = indiceIdioma[m].endereco;
        cout << "\nCodigo do Idioma: " << idiomas[i].codigo;
        cout << "\tDescricao: " << idiomas[i].descricao;
    }
    else
        inclusaoNaTabelaDeIdiomas(indiceIdioma, idiomas, cont, cod);
}

void inclusaoNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int &cont, int cod){
    cont++;
    licoes[cont].cod_licao = cod;
    cout << "Digite o codigo do idioma: ";
    cin >> licoes[cont].cod_idioma;
    cout << "Digite o total de niveis: ";
    cin >> licoes[cont].total_niveis;
    cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido)";
    cin >> licoes[cont].status;
    int i;
    for(i = cont - 1; indiceLicoes[i].codigo > cod; i--){
        indiceLicoes[i + 1].codigo = indiceLicoes[i].codigo;
        indiceLicoes[i + 1].endereco = indiceLicoes[i].endereco;
    }
    indiceLicoes[i + 1].codigo = cod;
    indiceLicoes[i + 1].endereco  = cont;
    cout << "\n\nInclusao Realizada com Sucesso!";
}

void buscaAleatoriaNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceLicoes[m].codigo; m = (i + f) / 2){
        if(cod > indiceLicoes[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceLicoes[m].codigo){
        cout << "\n\n Licao ja cadastrada - nao pode ser cadastrado novamente";
        i = indiceLicoes[m].endereco;
        cout << "\nCodigo da Licao: " << licoes[i].cod_licao;
        cout << "\tCodigo do Idioma: " << licoes[i].cod_idioma;
        cout << "\tTotal de Niveis: " << licoes[i].total_niveis;
    }
    else
        inclusaoNaTabelaDeLicoes(indiceLicoes, licoes, cont, cod);
}

void inclusaoNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int &cont, int cod){
    cont++;
    exercicios[cont].cod_exercicio = cod;
    cout << "Nivel de Dificuldade: ";
    cin >> exercicios[cont].nivel_dificuldade;
    cin.ignore();
    cout << "Descricao: ";
    gets(exercicios[cont].descricao);
    cout << "Resposta Correta: ";
    gets(exercicios[cont].resposta_correta);
    cout << "Pontuacao: ";
    cin >> exercicios[cont].pontuacao;
    cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido)";
    cin >> exercicios[cont].status;
    int i;
    for(i = cont - 1; indiceExercicios[i].codigo > cod; i--){
        indiceExercicios[i + 1].codigo = indiceExercicios[i].codigo;
        indiceExercicios[i + 1].endereco = indiceExercicios[i].endereco;
    }
    indiceExercicios[i + 1].codigo = cod;
    indiceExercicios[i + 1].endereco = cont;
    cout << "\n\nInclusao Realizada Com Sucesso!";
}

void buscaAleatoriaNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceExercicios[m].codigo; m = (i + f) / 2){
        if(cod > indiceExercicios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceExercicios[m].codigo){
        cout << "\n\n Exercicio ja cadastrado - nao pode ser cadastrado novamente";
        i = indiceExercicios[m].endereco;
        cout << "\nCodigo do Exercicio: " << exercicios[i].cod_exercicio;
        cout << "\tNivel de Dificuldade: " << exercicios[i].nivel_dificuldade;
        cout << "\tDescricao: " << exercicios[i].descricao;
        cout << "\tResposta Correta: " << exercicios[i].resposta_correta;
        cout << "\tPontuacao: " << exercicios[i].pontuacao;
    }
    else
        inclusaoNaTabelaDeExercicios(indiceExercicios, exercicios, cont, cod);
}

void inclusaoNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int &cont, int cod)
{
    cont++;
    usuarios[cont].codigo = cod;
    cout << "Nome: ";
    gets(usuarios[cont].nome);
    cout << "Codigo do Idioma: ";
    cin >> usuarios[cont].codigo_idioma;
    cout << "Nivel Atual: ";
    cin >> usuarios[cont].nivel_atual;
    cout << "Pontuacao Total: ";
    cin >> usuarios[cont].pontuacao_total;
    cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido)";
    cin >> usuarios[cont].status;
    int i;
    for(i = cont - 1; indiceUsuarios[i].codigo > cod; i--){
        indiceUsuarios[i + 1].codigo = indiceUsuarios[i].codigo;
        indiceUsuarios[i + 1].codigo = indiceUsuarios[i].endereco;
    }
    indiceUsuarios[i + 1].codigo = cod;
    indiceUsuarios[i + 1].endereco = cont;
    cout << "\n\nInclusao Realizada com Sucesso!";
}

void buscaAleatoriaNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceUsuarios[m].codigo; m = (i + f) / 2){
        if(cod > indiceUsuarios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceUsuarios[m].codigo){
        cout << "\n\n Usuario ja cadastrado - nao pode ser cadastrado novamente";
        i = indiceUsuarios[i].endereco;
        cout << "\nCodigo do Usuario: " << usuarios[i].codigo;
        cout << "\tNome: " << usuarios[i].nome;
        cout << "\tCodigo do Idioma: " << usuarios[i].codigo_idioma;
        cout << "\tNivel Atual: " << usuarios[i].nivel_atual;
        cout << "\tPontuacao Total: " << usuarios[i].pontuacao_total;
        cout << "\tStatus: " << usuarios[i].status;
    }
    else
        inclusaoNaTabelaDeUsuarios(indiceUsuarios, usuarios, cont, cod);
}

void exclusaoNaTabelaDeIdiomas(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceIdioma[m].codigo; m = (i + f) / 2){
        if(cod > indiceIdioma[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceIdioma[m].endereco;
    if((cod == indiceIdioma[m].codigo) && idiomas[i].status == 0){
        idiomas[i].status = 1;
        cout << "\n\n Idioma excluido com sucesso";
    }
    else
        cout << "Idioma nao cadastrado";
}

void exclusaoNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceLicoes[m].codigo; m = (i + f) / 2){
        if(cod > indiceLicoes[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceLicoes[m].endereco;
    if((cod == indiceLicoes[m].codigo) && licoes[i].status == 0){
        licoes[i].status = 1;
        cout << "\n\nLicao excluida com sucesso";
    }
    else
        cout << "Licao Nao Cadastrada";
}

void exclusaoNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceExercicios[m].codigo; m = (i + f) / 2){
        if(cod > indiceExercicios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceExercicios[m].endereco;
    if((cod == indiceExercicios[m].codigo) && exercicios[i].status == 0){
        exercicios[i].status = 1;
        cout << "\n\nExercicio excluido com sucesso";
    }
    else
        cout << "Exercicio nao cadastrado";
}

void exclusaoNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int &cont, int cod){
    int i = 0, f = cont;
    int m = (i+ f)/ 2;
    for(; f >= i && cod != indiceUsuarios[m].codigo; m = (i + f) / 2){
        if(cod > indiceUsuarios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceUsuarios[m].endereco;
    if((cod == indiceUsuarios[m].codigo) && usuarios[i].status == 0){
        usuarios[i].status = 1;
        cout << "\n\nUsuario Excluido com sucesso";
    }
    else
        cout << "Usuario nao cadastrado";
}

void leituraExaustivaNaTabelaDeIdioma(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int cont){
    for(int k = 0; k < cont; k++){
        int i = indiceIdioma[k].endereco;
        if(idiomas[i].status == 0){
            cout << "\nCodigo: " << idiomas[i].codigo;
            cout << "\tDescricao: " << idiomas[i].descricao << "\n";
        }
    }
}

void leituraExaustivaNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int cont){
    for(int k = 0; k < cont; k++){
            int i = indiceLicoes[k].endereco;
            if(licoes[i].status == 0){
                cout << "\nCodigo: " << licoes[i].cod_licao;
                cout << "\tCodigo do Idioma: " << licoes[i].cod_idioma;
                cout << "\tTotal de Niveis: " << licoes[i].total_niveis << "\n";
            }
    }
}

void leituraExaustivaNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int cont){
    for(int k = 0; k < cont; k++){
        int i = indiceExercicios[k].endereco;
        if(exercicios[i].status == 0){
            cout << "\nCodigo: " << exercicios[i].cod_exercicio;
            cout << "\tNivel de Dificuldade: " << exercicios[i].nivel_dificuldade;
            cout << "\tDescricao: " << exercicios[i].descricao;
            cout << "\tResposta Correta: " << exercicios[i].resposta_correta;
            cout << "\tPontuacao: " << exercicios[i].pontuacao;
        }
    }
}

void leituraExaustivaNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int cont){
    for(int k = 0; k < cont; k++){
        int i = indiceUsuarios[k].endereco;
        if(usuarios[i].status == 0){
            cout << "\nCodigo: " << usuarios[i].codigo;
            cout << "\tNome: " << usuarios[i].nome;
            cout << "\tCodigo do Idioma: " << usuarios[i].codigo_idioma;
            cout << "\tNivel Atual: " << usuarios[i].nivel_atual;
            cout << "\tPontuacao Total: " << usuarios[i].pontuacao_total;
        }
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

    //CONTADORES
    int contIdioma = 5;
    int contLicoes = 5;
    int contExercicio = 5;
    int contUsuario = 5;

    //Tabela Do Indice De Idioma
    indiceIdioma[0].codigo = 1;
    indiceIdioma[1].codigo = 2;
    indiceIdioma[2].codigo = 3;
    indiceIdioma[3].codigo = 4;
    indiceIdioma[4].codigo = 5;

    indiceIdioma[0].endereco = 4;
    indiceIdioma[1].endereco = 2;
    indiceIdioma[2].endereco = 1;
    indiceIdioma[3].endereco = 0;
    indiceIdioma[4].endereco = 3;

    //Tabela do Indice De Licoes
    indiceLicoes[0].codigo = 1;
    indiceLicoes[1].codigo = 2;
    indiceLicoes[2].codigo = 3;
    indiceLicoes[3].codigo = 4;
    indiceLicoes[4].codigo = 5;

    indiceLicoes[0].endereco = 4;
    indiceLicoes[1].endereco = 2;
    indiceLicoes[2].endereco = 1;
    indiceLicoes[3].endereco = 0;
    indiceLicoes[4].endereco = 3;

    //Tabela do Indice De Exercicios
    indiceExercicios[0].codigo = 1;
    indiceExercicios[1].codigo = 2;
    indiceExercicios[2].codigo = 3;
    indiceExercicios[3].codigo = 4;
    indiceExercicios[4].codigo = 5;

    indiceExercicios[0].endereco = 4;
    indiceExercicios[1].endereco = 2;
    indiceExercicios[2].endereco = 1;
    indiceExercicios[3].endereco = 0;
    indiceExercicios[4].endereco = 3;

    //Tabela do Indice De Usuarios
    indiceUsuarios[0].codigo = 1;
    indiceUsuarios[1].codigo = 2;
    indiceUsuarios[2].codigo = 3;
    indiceUsuarios[3].codigo = 4;
    indiceUsuarios[4].codigo = 5;

    indiceExercicios[0].endereco = 4;
    indiceExercicios[1].endereco = 2;
    indiceExercicios[2].endereco = 1;
    indiceExercicios[3].endereco = 0;
    indiceExercicios[4].endereco = 3;

    //Tabela de Idiomas
    vIdioma[0].codigo = 11;
    strcpy(vIdioma[0].descricao, "Frances");
    vIdioma[0].status = 0;

    vIdioma[1].codigo = 2;
    strcpy(vIdioma[1].descricao, "Russo");
    vIdioma[1].status = 0;

    vIdioma[2].codigo = 14;
    strcpy(vIdioma[2].descricao, "Italiano");
    vIdioma[2].status = 0;

    vIdioma[3].codigo = 6;
    strcpy(vIdioma[3].descricao, "Espanhol");
    vIdioma[3].status = 0;

    vIdioma[4].codigo = 8;
    strcpy(vIdioma[4].descricao, "Alemao");
    vIdioma[4].status = 0;

    //Licao de Frances
    vLicoes[0].cod_licao = 8;
    vLicoes[0].cod_idioma = 4; //Codigo do Indice Frances
    vLicoes[0].total_niveis = 3;
    vLicoes[0].status = 0;

    //Licao de Russo
    vLicoes[1].cod_licao = 11;
    vLicoes[1].cod_idioma = 3; //Codigo do Indice Russo
    vLicoes[1].total_niveis = 4;
    vLicoes[1].status = 0;

    //Licao de Italiano
    vLicoes[2].cod_licao = 14;
    vLicoes[2].cod_idioma = 2; //Codigo do Indice Italiano
    vLicoes[2].total_niveis = 5;
    vLicoes[2].status = 0;

    //Licao de Espanhol
    vLicoes[3].cod_licao = 6;
    vLicoes[3].cod_idioma = 5;  //Codigo do Indice Espanhol
    vLicoes[3].total_niveis = 6;
    vLicoes[3].status = 0;

    //Licao de Alemao
    vLicoes[4].cod_licao = 2;
    vLicoes[4].cod_idioma = 1; //Codigo do Indice Alemao
    vLicoes[4].total_niveis = 7;
    vLicoes[4].status = 0;

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
      cout << "9 - Realizar Inclusao na Tabela de Idioma \n";
      cout << "10 - Realizar Inclusao na Tabela de Licoes \n";
      cout << "11 - Realizar Inclusao na Tabela de Exercicio \n";
      cout << "12 - Realizar Inclusao na Tabela de Usuarios \n";
      cout << "13 - Realizar Exclusao na Tabela de Idioma \n";
      cout << "14 - Realizar Exclusao na Tabela de Licoes \n";
      cout << "15 - Realizar Exclusao na Tabela de Exercicios \n";
      cout << "16 - Realizar Exclusao na Tabela de Usuarios \n";
      cout << "17 - Realizar Leitura Exaustiva na Tabela de Idioma \n";
      cout << "18 - Realizar Leitura Exaustiva na Tabela de Licoes \n";
      cout << "19 - Realizar Leitura Exaustiva na Tabela de Exercicios \n";
      cout << "20 - Realizar Leitura Exaustiva na Tabela de Usuarios \n";
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
        break;
      case 7:
        cout << "Voce escolheu realizar a leitura da tabela de exercicios \n";
        leituraDeExercicios(vExercicios, quantidadeDeExercicios);
        break;
      case 8:
        cout << "Voce escolheu realizar a leitura da tabela de usuarios \n";
        leituraDeUsuarios(vUsuarios, quantidadeDeUsuarios);
      case 9:
        cout << "Voce escolheu realizar inclusao na tabela de Idiomas \n";
        for(int codIdioma = 5; codIdioma != 0;){
            cout << "\n\nInforme o Codigo do Idioma  a ser inserido (0 Para Encerrar): ";
            cin >> codIdioma;
            cin.ignore();
            if (codIdioma != 0){
                buscaAleatoriaNaTabelaDeIdiomas(indiceIdioma, vIdioma, contIdioma, codIdioma);
            }
        }
        break;
      case 10:
        cout << "Voce escolheu realizar inclusao na tabela de Licoes \n";
        for(int codLicao = 5; codLicao != 0;){
            cout << "\n\nInforme o Codigo da Licao a ser inserida (0 Para Encerrar): ";
            cin >> codLicao;
            if(codLicao != 0){
                buscaAleatoriaNaTabelaDeLicoes(indiceLicoes, vLicoes, contLicoes, codLicao);
            }
        }
        break;
      case 11:
        cout << "Voce escolheu realizar inclusao na tabela de Exercicio \n";
        for(int codExercicio = 5; codExercicio != 0;){
            cout << "\n\nInforme o Codigo do Exercicio a ser incluido (0 Para Encerrar): ";
            cin >> codExercicio;
            if(codExercicio != 0){
                buscaAleatoriaNaTabelaDeExercicios(indiceExercicios, vExercicios, contExercicio, codExercicio);
            }
        }
        break;
      case 12:
        cout << "Voce escolheu realizar inclusao na tabela de Usuarios \n";
        for(int codUsuario = 5; codUsuario != 0;){
            cout << "\n\nInforme o Codigo do Usuario a ser incluido (0 Para Encerrar): ";
            cin >> codUsuario;
            if(codUsuario != 0){
                buscaAleatoriaNaTabelaDeUsuarios(indiceUsuarios, vUsuarios, contUsuario, codUsuario);
            }
        }
        break;
      case 13:
        cout << "Voce escolheu realizar exclusao na tabela de idiomas \n";
        for(int codIdioma = 5; codIdioma != 0;){
            cout << "\n\nInforme o codigo do idioma a ser excluido (0 Para Encerrar): ";
            cin >> codIdioma;
            if(codIdioma != 0){
                exclusaoNaTabelaDeIdiomas(indiceIdioma, vIdioma, contIdioma, codIdioma);
            }
        }
        break;
      case 14:
        cout << "Voce escolheu realizar exclusao na tabela de licoes \n";
        for(int codLicoes = 5; codLicoes != 0;){
            cout << "\n\nInforme o codigo da licao a ser excluida (0 Para Encerrar): ";
            cin >> codLicoes;
            if(codLicoes != 0){
                exclusaoNaTabelaDeLicoes(indiceLicoes, vLicoes, contLicoes, codLicoes);
            }
        }
        break;
      case 15:
        cout << "Voce escolheu realizar exclusao na tabela de exercicios \n";
        for(int codExercicio = 5; codExercicio != 0;){
            cout << "\n\nInforme o codigo do exercicio a ser excluido (0 Para Encerrar): ";
            cin >> codExercicio;
            if(codExercicio != 0){
                exclusaoNaTabelaDeExercicios(indiceExercicios, vExercicios, contExercicio, codExercicio);
            }
        }
        break;
      case 16:
        cout << "Voce escolheu realizar exclusao na tabela de usuarios \n";
        for(int codUsuario = 5; codUsuario != 0;){
            cout << "\n\nInforme o codigo do usuario a ser excluido (0 Para Encerrar): ";
            cin >> codUsuario;
            if(codUsuario != 0){
                exclusaoNaTabelaDeUsuarios(indiceUsuarios, vUsuarios, contUsuario, codUsuario);
            }
        }
      case 17:
        cout << "Voce escolheu realizar leitura exaustiva na tabela de Idiomas \n";
        leituraExaustivaNaTabelaDeIdioma(indiceIdioma, vIdioma, contIdioma);
        break;
      case 18:
        cout << "Voce escolheu realizar leitura exaustiva na tabela de Licoes \n";
        leituraExaustivaNaTabelaDeLicoes(indiceLicoes, vLicoes, contLicoes);
        break;
      case 19:
        cout << "Voce escolheu realizar leitura exaustiva na tabela de Exercicios \n";
        leituraExaustivaNaTabelaDeExercicios(indiceExercicios, vExercicios, contExercicio);
        break;
      case 20:
        cout << "Voce escolheu realizar leitura exaustiva na tabela de Usuarios \n";
        leituraExaustivaNaTabelaDeUsuarios(indiceUsuarios, vUsuarios, contUsuario);
        break;
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
