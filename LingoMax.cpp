#include <iostream>
#include <cstring>

using namespace std;

struct Idiomas
{
    int codigo;
    char descricao[30];
    int status;
};

struct IndiceIdioma
{
    int codigo;
    int endereco;
};

struct Licoes
{
    int cod_licao;
    int cod_idioma;
    int total_niveis;
    int status;
};

struct IndiceLicoes
{
    int codigo;
    int endereco;
};

struct Exercicios
{
    int cod_exercicio;
    int nivel_dificuldade;
    char descricao[30];
    char resposta_correta[30];
    double pontuacao;
    int status;
};

struct IndiceExercicios
{
    int codigo;
    int endereco;
};

struct Usuarios
{
    int codigo;
    char nome[30];
    int codigo_idioma;
    int nivel_atual;
    double pontuacao_total;
    int status;
};

struct IndiceUsuarios
{
    int codigo;
    int endereco;
};

void inclusaoNaTabelaDeIdiomas(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int &cont, int cod)
{
    cont++;
    idiomas[cont].codigo = cod;
    cout << "Descricao: ";
    gets(idiomas[cont].descricao);
    cout << "Status: (0 - Para Registro Ativo / 1 - Para Registro Excluido)";
    cin >> idiomas[cont].status;
    int i;
    for (i = cont - 1; indiceIdioma[i].codigo > cod; i--)
    {
        indiceIdioma[i + 1].codigo = indiceIdioma[i].codigo;
        indiceIdioma[i + 1].endereco = indiceIdioma[i].endereco;
    }
    indiceIdioma[i + 1].codigo = cod;
    indiceIdioma[i + 1].endereco = cont;
    cout << "\n\nInclusao Realizada Com Sucesso";
}

void buscaAleatoriaNaTabelaDeIdiomas(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int &cont, int cod)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceIdioma[m].codigo; m = (i+f) / 2)
    {
        if(cod > indiceIdioma[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceIdioma[m].codigo)
    {
        cout << "\n\n Idioma ja cadastrado - nao pode ser cadastrado novamente";
        i = indiceIdioma[m].endereco;
        cout << "\nCodigo do Idioma: " << idiomas[i].codigo;
        cout << "\tDescricao: " << idiomas[i].descricao;
    }
    else
        inclusaoNaTabelaDeIdiomas(indiceIdioma, idiomas, cont, cod);
}

void mostraDescricaoDoIdioma(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int cont, int cod)
{
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceIdioma[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceIdioma[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceIdioma[m].codigo)
    {
        i = indiceIdioma[m].endereco;
        cout << "\nDescricao do Idioma: " << idiomas[i].descricao << "\n";
    }
    else
        cout << "\n\n Idioma nao encontrado";
}

void inclusaoNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int &cont, int cod, struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int contIdioma)
{
    cont++;
    licoes[cont].cod_licao = cod;
    cout << "Digite o codigo do idioma: ";
    cin >> licoes[cont].cod_idioma;
    mostraDescricaoDoIdioma(indiceIdioma, idiomas, contIdioma, licoes[cont].cod_idioma);
    cout << "Digite o total de niveis: ";
    cin >> licoes[cont].total_niveis;
    cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido): ";
    cin >> licoes[cont].status;
    int i;
    for(i = cont - 1; indiceLicoes[i].codigo > cod; i--)
    {
        indiceLicoes[i + 1].codigo = indiceLicoes[i].codigo;
        indiceLicoes[i + 1].endereco = indiceLicoes[i].endereco;
    }
    indiceLicoes[i + 1].codigo = cod;
    indiceLicoes[i + 1].endereco  = cont;
    cout << "\n\nInclusao Realizada com Sucesso!";
}

void buscaAleatoriaNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int &cont, int cod, struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int contIdioma)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceLicoes[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceLicoes[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceLicoes[m].codigo)
    {
        cout << "\n\n Licao ja cadastrada - nao pode ser cadastrado novamente";
        i = indiceLicoes[m].endereco;
        cout << "\nCodigo da Licao: " << licoes[i].cod_licao;
        cout << "\tCodigo do Idioma: " << licoes[i].cod_idioma;
        cout << "\tTotal de Niveis: " << licoes[i].total_niveis;
    }
    else
        inclusaoNaTabelaDeLicoes(indiceLicoes, licoes, cont, cod, indiceIdioma, idiomas, contIdioma);
}

void inclusaoNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int &cont, int cod)
{
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
    for(i = cont - 1; indiceExercicios[i].codigo > cod; i--)
    {
        indiceExercicios[i + 1].codigo = indiceExercicios[i].codigo;
        indiceExercicios[i + 1].endereco = indiceExercicios[i].endereco;
    }
    indiceExercicios[i + 1].codigo = cod;
    indiceExercicios[i + 1].endereco = cont;
    cout << "\n\nInclusao Realizada Com Sucesso!";
}

void buscaAleatoriaNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int &cont, int cod)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceExercicios[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceExercicios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceExercicios[m].codigo)
    {
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

void inclusaoNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int &cont, int cod, struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int contIdioma)
{
    cont++;
    usuarios[cont].codigo = cod;
    cout << "Nome: ";
    gets(usuarios[cont].nome);
    cout << "Codigo do Idioma: ";
    cin >> usuarios[cont].codigo_idioma;
    mostraDescricaoDoIdioma(indiceIdioma, idiomas, contIdioma, usuarios[cont].codigo_idioma);
    cout << "Nivel Atual: ";
    cin >> usuarios[cont].nivel_atual;
    cout << "Pontuacao Total: ";
    cin >> usuarios[cont].pontuacao_total;
    cout << "Digite o status (0 - para Registro Ativo / 1 - para Registro Excluido)";
    cin >> usuarios[cont].status;
    int i;
    for(i = cont - 1; indiceUsuarios[i].codigo > cod; i--)
    {
        indiceUsuarios[i + 1].codigo = indiceUsuarios[i].codigo;
        indiceUsuarios[i + 1].codigo = indiceUsuarios[i].endereco;
    }
    indiceUsuarios[i + 1].codigo = cod;
    indiceUsuarios[i + 1].endereco = cont;
    cout << "\n\nInclusao Realizada com Sucesso!";
}

void buscaAleatoriaNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int &cont, int cod, struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int contIdioma)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceUsuarios[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceUsuarios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == indiceUsuarios[m].codigo)
    {
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
        inclusaoNaTabelaDeUsuarios(indiceUsuarios, usuarios, cont, cod, indiceIdioma, idiomas, contIdioma);
}

void exclusaoNaTabelaDeIdiomas(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int &cont, int cod)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceIdioma[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceIdioma[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceIdioma[m].endereco;
    if((cod == indiceIdioma[m].codigo) && idiomas[i].status == 0)
    {
        idiomas[i].status = 1;
        cout << "\n\n Idioma excluido com sucesso";
    }
    else
        cout << "Idioma nao cadastrado";
}

void exclusaoNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int &cont, int cod)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceLicoes[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceLicoes[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceLicoes[m].endereco;
    if((cod == indiceLicoes[m].codigo) && licoes[i].status == 0)
    {
        licoes[i].status = 1;
        cout << "\n\nLicao excluida com sucesso";
    }
    else
        cout << "Licao Nao Cadastrada";
}

void exclusaoNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int &cont, int cod)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for(; f >= i && cod != indiceExercicios[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceExercicios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceExercicios[m].endereco;
    if((cod == indiceExercicios[m].codigo) && exercicios[i].status == 0)
    {
        exercicios[i].status = 1;
        cout << "\n\nExercicio excluido com sucesso";
    }
    else
        cout << "Exercicio nao cadastrado";
}

void exclusaoNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int &cont, int cod)
{
    int i = 0, f = cont;
    int m = (i+ f)/ 2;
    for(; f >= i && cod != indiceUsuarios[m].codigo; m = (i + f) / 2)
    {
        if(cod > indiceUsuarios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indiceUsuarios[m].endereco;
    if((cod == indiceUsuarios[m].codigo) && usuarios[i].status == 0)
    {
        usuarios[i].status = 1;
        cout << "\n\nUsuario Excluido com sucesso";
    }
    else
        cout << "Usuario nao cadastrado";
}

void leituraExaustivaNaTabelaDeIdioma(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], int cont)
{
    for(int k = 0; k < cont; k++)
    {
        int i = indiceIdioma[k].endereco;
        if(idiomas[i].status == 0)
        {
            cout << "\nCodigo: " << idiomas[i].codigo;
            cout << "\tDescricao: " << idiomas[i].descricao << "\n";
        }
    }
}

void leituraExaustivaNaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], int cont)
{
    for(int k = 0; k < cont; k++)
    {
        int i = indiceLicoes[k].endereco;
        if(licoes[i].status == 0)
        {
            cout << "\nCodigo: " << licoes[i].cod_licao;
            cout << "\tCodigo do Idioma: " << licoes[i].cod_idioma;
            cout << "\tTotal de Niveis: " << licoes[i].total_niveis << "\n";
        }
    }
}

void leituraExaustivaNaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], int cont)
{
    for(int k = 0; k < cont; k++)
    {
        int i = indiceExercicios[k].endereco;
        if(exercicios[i].status == 0)
        {
            cout << "\nCodigo: " << exercicios[i].cod_exercicio;
            cout << "\tNivel de Dificuldade: " << exercicios[i].nivel_dificuldade;
            cout << "\tDescricao: " << exercicios[i].descricao;
            cout << "\tResposta Correta: " << exercicios[i].resposta_correta;
            cout << "\tPontuacao: " << exercicios[i].pontuacao << "\n";
        }
    }
}

void leituraExaustivaNaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int cont)
{
    for(int k = 0; k < cont; k++)
    {
        int i = indiceUsuarios[k].endereco;
        if(usuarios[i].status == 0)
        {
            cout << "\nCodigo: " << usuarios[i].codigo;
            cout << "\tNome: " << usuarios[i].nome;
            cout << "\tCodigo do Idioma: " << usuarios[i].codigo_idioma;
            cout << "\tNivel Atual: " << usuarios[i].nivel_atual;
            cout << "\tPontuacao Total: " << usuarios[i].pontuacao_total << "\n";
        }
    }
}

void reorganizacaoDaTabelaDeIdioma(struct IndiceIdioma indiceIdioma[], struct IndiceIdioma novoIndiceIdioma[], struct Idiomas idiomas[], struct Idiomas novoIdioma[], int &cont)
{
    int j = -1;
    for (int k = 0; k < cont; k++)
    {
        int i = indiceIdioma[k].endereco;
        if(idiomas[i].status == 0)
        {
            j++;
            novoIdioma[j].codigo = idiomas[i].codigo;
            strcpy(novoIdioma[j].descricao, idiomas[i].descricao);
            novoIdioma[j].status = 0;
            novoIndiceIdioma[j].codigo = novoIdioma[j].codigo;
            novoIndiceIdioma[j].endereco = j;
        }
    }
    cont = j + 1;
    cout << "\n\nTabela reorganizada com sucesso!\n\n";
}

void reorganizacaoDaTabelaDeLicoes(struct IndiceLicoes indiceLicoes[], struct IndiceLicoes novoIndiceLicoes[], struct Licoes licoes[], struct Licoes novoLicoes[], int &cont)
{
    int j = -1;
    for(int k = 0; k < cont; k++)
    {
        int i = indiceLicoes[k].endereco;
        if(licoes[i].status == 0)
        {
            j++;
            novoLicoes[j].cod_licao = licoes[i].cod_licao;
            novoLicoes[j].cod_idioma = licoes[i].cod_idioma;
            novoLicoes[j].total_niveis = licoes[i].total_niveis;
            novoLicoes[j].status = 0;
            novoIndiceLicoes[j].codigo = novoLicoes[j].cod_licao;
            novoIndiceLicoes[j].endereco = j;
        }
    }
    cont = j + 1;
    cout << "\n\nTabela reorganizada com sucesso!\n\n";
}

void reorganizacaoDaTabelaDeExercicios(struct IndiceExercicios indiceExercicios[], struct IndiceExercicios novoIndiceExercicios[], struct Exercicios exercicios[], struct Exercicios novoExercicios[], int &cont)
{
    int j = -1;
    for(int k = 0; k < cont; k++)
    {
        int i = indiceExercicios[k].endereco;
        if(exercicios[i].status == 0)
        {
            j++;
            novoExercicios[j].cod_exercicio = exercicios[i].cod_exercicio;
            novoExercicios[j].nivel_dificuldade = exercicios[i].nivel_dificuldade;
            strcpy(novoExercicios[j].descricao, exercicios[i].descricao);
            strcpy(novoExercicios[j].resposta_correta, exercicios[i].resposta_correta);
            novoExercicios[j].pontuacao = exercicios[i].pontuacao;
            novoExercicios[j].status = 0;
            novoIndiceExercicios[j].codigo = novoExercicios[j].cod_exercicio;
            novoIndiceExercicios[j].endereco = j;
        }
    }
    cont = j + 1;
    cout << "\n\nTabela reorganizada com sucesso!\n\n";
}

void reorganizacaoDaTabelaDeUsuarios(struct IndiceUsuarios indiceUsuarios[], struct IndiceUsuarios novoIndiceUsuarios[], struct Usuarios usuarios[], struct Usuarios novoUsuarios[], int &cont)
{
    int j = -1;
    for(int k = 0; k < cont; k++)
    {
        int i = indiceUsuarios[k].endereco;
        if(usuarios[i].status == 0)
        {
            j++;
            novoUsuarios[j].codigo = usuarios[i].codigo;
            strcpy(novoUsuarios[j].nome, usuarios[i].nome);
            novoUsuarios[j].codigo_idioma = usuarios[i].codigo_idioma;
            novoUsuarios[j].nivel_atual = usuarios[i].nivel_atual;
            novoUsuarios[j].pontuacao_total = usuarios[i].pontuacao_total;
            novoUsuarios[j].status = 0;
            novoIndiceUsuarios[j].codigo = novoUsuarios[j].codigo;
            novoIndiceUsuarios[j].endereco = j;
        }
    }
    cont = j + 1;
    cout << "\n\nTabela reorganizada com sucesso!\n\n";
}

void realizarExercicio(struct IndiceIdioma indiceIdioma[], struct Idiomas idiomas[], struct IndiceLicoes indiceLicoes[], struct Licoes licoes[], struct IndiceExercicios indiceExercicios[], struct Exercicios exercicios[], struct IndiceUsuarios indiceUsuarios[], struct Usuarios usuarios[], int contIdiomas, int contLicoes, int contExercicios, int contUsuarios)
{
    int codigoDoUsuarioQueIraRealizarExercicio;
    int codigoDoExercicioDesejado;
    char respostaDoUsuarioAoExercicio[30];
    int codigoDaLicaoDesejada;
    cout << "Digite o codigo do usuario que esta realizando o exercicio: ";
    cin >> codigoDoUsuarioQueIraRealizarExercicio;

    int iDoUsuario = 0, fDoUsuario = contUsuarios - 1;
    int mDoUsuario = (iDoUsuario + fDoUsuario) / 2;
    for(; fDoUsuario >= iDoUsuario && codigoDoUsuarioQueIraRealizarExercicio != indiceUsuarios[mDoUsuario].codigo; mDoUsuario = (iDoUsuario + fDoUsuario) / 2)
    {
        if(codigoDoUsuarioQueIraRealizarExercicio > indiceUsuarios[mDoUsuario].codigo)
            iDoUsuario = mDoUsuario + 1;
        else
            fDoUsuario = mDoUsuario - 1;
    }
    if(codigoDoUsuarioQueIraRealizarExercicio == indiceUsuarios[mDoUsuario].codigo)
    {
        iDoUsuario = indiceUsuarios[mDoUsuario].endereco;
        cout << "\n\n INFORMACOES DO USUARIO \n\n";
        cout << "Nome: " << usuarios[iDoUsuario].nome << "\n";

        cout << "Digite o codigo do exercicio que voce deseja fazer: ";
        cin >> codigoDoExercicioDesejado;
        cin.ignore();

        int iDoExercicio = 0, fDoExercicio = contExercicios - 1;
        int mDoExercicio = (iDoExercicio + fDoExercicio) / 2;
        for(; fDoExercicio >= iDoExercicio && codigoDoExercicioDesejado != indiceExercicios[mDoExercicio].codigo; mDoExercicio = (iDoExercicio + fDoExercicio) / 2)
        {
            if(codigoDoExercicioDesejado > indiceExercicios[mDoExercicio].codigo)
                iDoExercicio = mDoExercicio + 1;
            else
                fDoExercicio = mDoExercicio - 1;
        }
        if(codigoDoExercicioDesejado == indiceExercicios[mDoExercicio].codigo)
        {
            iDoExercicio = indiceExercicios[mDoExercicio].endereco;
            if(exercicios[iDoExercicio].nivel_dificuldade <= usuarios[iDoUsuario].nivel_atual)
            {
                cout << "\n\nINFORMACOES DO EXERCICIO\n\n";
                cout << "Descricao: " << exercicios[iDoExercicio].descricao << "\n";
                cout << "Sua Resposta: ";
                gets(respostaDoUsuarioAoExercicio);
                if(strcmp(exercicios[iDoExercicio].resposta_correta, respostaDoUsuarioAoExercicio) == 0)
                {
                    cout << "\n\nVOCE RESPONDEU AO EXERCICIO CORRETAMENTE\n\n";
                    usuarios[iDoUsuario].pontuacao_total = usuarios[iDoUsuario].pontuacao_total + exercicios[iDoExercicio].pontuacao;
                    if(usuarios[iDoUsuario].pontuacao_total == 100 || usuarios[iDoUsuario].pontuacao_total < 100)
                    {
                        cout << "\n\nVOCE FOI PROMOVIDO AO PROXIMO NIVEL, SERA ADICIONADO UMA UNIDADE AO SEU NIVEL ATUAL\n\n ";
                        usuarios[iDoUsuario].nivel_atual = usuarios[iDoUsuario].nivel_atual + 1;

                        cout << "Digite o codigo ao qual essa licao pertence: ";
                        cin >> codigoDaLicaoDesejada;

                        int iDaLicao = 0, fDaLicao = contLicoes - 1;
                        int mDaLicao = (iDaLicao + fDaLicao) / 2;
                        for(; fDaLicao >= iDaLicao && codigoDaLicaoDesejada != indiceLicoes[mDaLicao].codigo; mDaLicao = (iDaLicao + fDaLicao) / 2)
                        {
                            if(codigoDaLicaoDesejada > indiceLicoes[mDaLicao].codigo)
                                iDaLicao = mDaLicao + 1;
                            else
                                fDaLicao = mDaLicao - 1;
                        }
                        if(codigoDaLicaoDesejada == indiceLicoes[mDaLicao].codigo)
                        {
                            iDaLicao = indiceLicoes[mDaLicao].endereco;
                            if(usuarios[iDoUsuario].nivel_atual == licoes[iDaLicao].total_niveis)
                            {
                                cout << "\n\nVoce atingiu o total de niveis dessa licao, agora voce tem direito a um certificado de proficiencia\n\n";
                            }
                            else
                            {
                                cout << "\n\nContinue em frente para atingir o certificado de proficiencia\n\n";
                            }
                        }
                        else
                        {
                            cout << "\n\n Licao Nao Encontrada \n\n";
                        }
                    }
                }
                else
                {
                    cout << "\n\nVOCE RESPONDEU AO EXERCICIO INCORRETAMENTE\n\n";
                    usuarios[iDoUsuario].pontuacao_total = usuarios[iDoUsuario].pontuacao_total - (usuarios[iDoUsuario].pontuacao_total * 0.10);
                }
            }
            else
            {
                cout << "Voce nao pode realizar esse exercicio pois ele e de um nivel maior que o seu nivel atual \n";
            }
        }
        else
        {
            cout << "Exercicio nao encontrado\n";
        }
    }
    else
    {
        cout << "Usuario nao encontrado \n";
    }
}

void selectionSortUsuariosPorPontuacao(Usuarios usuarios[], IndiceUsuarios indiceUsuarios[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(usuarios[indiceUsuarios[j].endereco].pontuacao_total > usuarios[indiceUsuarios[maxIndex].endereco].pontuacao_total)
            {
                maxIndex = j;
            }
        }
        if(maxIndex != i)
        {
            int temp = indiceUsuarios[i].endereco;
            indiceUsuarios[i].endereco = indiceUsuarios[maxIndex].endereco;
            indiceUsuarios[maxIndex].endereco = temp;
        }
    }
}

int main()
{
    //INDICES
    IndiceIdioma indiceIdioma[10];
    IndiceLicoes indiceLicoes[10];
    IndiceExercicios indiceExercicios[10];
    IndiceUsuarios indiceUsuarios[10];

    //TABELAS
    Idiomas vIdioma[10];
    Licoes vLicoes[10];
    Exercicios vExercicios[10];
    Usuarios vUsuarios[10];

    //NOVAS TABELAS
    Idiomas novoVetIdioma[10];
    Licoes novoVetLicoes[10];
    Exercicios novoVetExercicios[10];
    Usuarios novoVetUsuarios[10];

    //NOVOS INDICES
    IndiceIdioma novoIndiceIdioma[10];
    IndiceLicoes novoIndiceLicoes[10];
    IndiceExercicios novoIndiceExercicios[10];
    IndiceUsuarios novoIndiceUsuarios[10];

    int opcao;

    //CONTADORES
    int contIdioma = 5;
    int contLicoes = 5;
    int contExercicio = 5;
    int contUsuario = 5;

    //CODIGO
    int codIdioma;

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

    indiceUsuarios[0].endereco = 4;
    indiceUsuarios[1].endereco = 2;
    indiceUsuarios[2].endereco = 1;
    indiceUsuarios[3].endereco = 0;
    indiceUsuarios[4].endereco = 3;

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

    //Tabela de Licoes
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

    //Tabela De Exercicios
    vExercicios[0].cod_exercicio = 8;
    vExercicios[0].nivel_dificuldade = 2;
    strcpy(vExercicios[0].descricao, "Exercicio 1");
    strcpy(vExercicios[0].resposta_correta, "A");
    vExercicios[0].pontuacao = 3;
    vExercicios[0].status = 0;

    vExercicios[1].cod_exercicio = 12;
    vExercicios[1].nivel_dificuldade = 3;
    strcpy(vExercicios[1].descricao, "Exercicio 2");
    strcpy(vExercicios[1].resposta_correta, "A");
    vExercicios[1].pontuacao = 3;
    vExercicios[1].status = 0;

    vExercicios[2].cod_exercicio = 5;
    vExercicios[2].nivel_dificuldade = 4;
    strcpy(vExercicios[2].descricao, "Exercicio 3");
    strcpy(vExercicios[2].resposta_correta, "B");
    vExercicios[2].pontuacao = 4;
    vExercicios[2].status = 0;

    vExercicios[3].cod_exercicio = 6;
    vExercicios[3].nivel_dificuldade = 5;
    strcpy(vExercicios[3].descricao, "Exercicio 4");
    strcpy(vExercicios[3].resposta_correta, "D");
    vExercicios[3].pontuacao = 2;
    vExercicios[3].status = 0;

    vExercicios[4].cod_exercicio = 1;
    vExercicios[4].nivel_dificuldade = 6;
    strcpy(vExercicios[4].descricao, "Exercicio 5");
    strcpy(vExercicios[4].resposta_correta, "C");
    vExercicios[4].pontuacao = 1;
    vExercicios[4].status = 0;

    //Tabela de Usuarios
    vUsuarios[0].codigo = 8;
    strcpy(vUsuarios[0].nome, "Luiz Carlos Begosso");
    vUsuarios[0].codigo_idioma = 2;
    vUsuarios[0].nivel_atual = 12;
    vUsuarios[0].pontuacao_total = 32;
    vUsuarios[0].status = 0;

    vUsuarios[1].codigo = 12;
    strcpy(vUsuarios[1].nome, "Luiz Ricardo Begosso");
    vUsuarios[1].codigo_idioma = 1;
    vUsuarios[1].nivel_atual = 8;
    vUsuarios[1].pontuacao_total = 21;
    vUsuarios[1].status = 0;

    vUsuarios[2].codigo = 5;
    strcpy(vUsuarios[2].nome, "Almir Rogerio Camolesi");
    vUsuarios[2].codigo_idioma = 3;
    vUsuarios[2].nivel_atual = 7;
    vUsuarios[2].pontuacao_total = 84;
    vUsuarios[2].status = 0;

    vUsuarios[3].codigo = 6;
    strcpy(vUsuarios[3].nome, "Alex Polleto");
    vUsuarios[3].codigo_idioma = 5;
    vUsuarios[3].nivel_atual = 5;
    vUsuarios[3].pontuacao_total = 9;
    vUsuarios[3].status = 0;

    vUsuarios[4].codigo = 1;
    strcpy(vUsuarios[4].nome, "Douglas Sanches da Cunha");
    vUsuarios[4].codigo_idioma = 4;
    vUsuarios[4].nivel_atual = 2;
    vUsuarios[4].pontuacao_total = 7;
    vUsuarios[4].status = 0;

    do
    {
        cout << "Selecione uma opcao: \n";
        cout << "1 - Realizar Inclusao na Tabela de Idioma \n";
        cout << "2 - Realizar Inclusao na Tabela de Licoes \n";
        cout << "3 - Realizar Inclusao na Tabela de Exercicio \n";
        cout << "4 - Realizar Inclusao na Tabela de Usuarios \n";
        cout << "5 - Realizar Exclusao na Tabela de Idioma \n";
        cout << "6 - Realizar Exclusao na Tabela de Licoes \n";
        cout << "7 - Realizar Exclusao na Tabela de Exercicios \n";
        cout << "8 - Realizar Exclusao na Tabela de Usuarios \n";
        cout << "9 - Realizar Leitura Exaustiva na Tabela de Idioma \n";
        cout << "10 - Realizar Leitura Exaustiva na Tabela de Licoes \n";
        cout << "11 - Realizar Leitura Exaustiva na Tabela de Exercicios \n";
        cout << "12 - Realizar Leitura Exaustiva na Tabela de Usuarios \n";
        cout << "13 - Realizar Reorganizacao na Tabela de Idioma \n";
        cout << "14 - Realizar Reorganizacao na Tabela de Licoes \n";
        cout << "15 - Realizar Reorganizacao na Tabela de Exercicios \n";
        cout << "16 - Realizar Reorganizacao na Tabela de Usuarios \n";
        cout << "17 - Praticar Exercicios \n";
        cout << "18 - Realizar Rankeamento de usuarios \n";
        cout << "0 - Para Encerrar\n";
        cin >> opcao;
        switch(opcao)
        {
        case 1:
            cout << "Voce escolheu realizar inclusao na tabela de Idiomas \n";

            cout << "\n\nInforme o Codigo do Idioma  a ser inserido (0 Para Encerrar): ";
            cin >> codIdioma;
            cin.ignore();
            if (codIdioma != 0)
            {
                buscaAleatoriaNaTabelaDeIdiomas(indiceIdioma, vIdioma, contIdioma, codIdioma);
            }

            break;
        case 2:
            cout << "Voce escolheu realizar inclusao na tabela de Licoes \n";
            for(int codLicao = 5; codLicao != 0;)
            {
                cout << "\n\nInforme o Codigo da Licao a ser inserida (0 Para Encerrar): ";
                cin >> codLicao;
                if(codLicao != 0)
                {
                    buscaAleatoriaNaTabelaDeLicoes(indiceLicoes, vLicoes, contLicoes, codLicao, indiceIdioma, vIdioma, contIdioma);
                }
            }
            break;
        case 3:
            cout << "Voce escolheu realizar inclusao na tabela de Exercicio \n";
            for(int codExercicio = 5; codExercicio != 0;)
            {
                cout << "\n\nInforme o Codigo do Exercicio a ser incluido (0 Para Encerrar): ";
                cin >> codExercicio;
                if(codExercicio != 0)
                {
                    buscaAleatoriaNaTabelaDeExercicios(indiceExercicios, vExercicios, contExercicio, codExercicio);
                }
            }
            break;
        case 4:
            cout << "Voce escolheu realizar inclusao na tabela de Usuarios \n";
            for(int codUsuario = 5; codUsuario != 0;)
            {
                cout << "\n\nInforme o Codigo do Usuario a ser incluido (0 Para Encerrar): ";
                cin >> codUsuario;
                cin.ignore();
                if(codUsuario != 0)
                {
                    buscaAleatoriaNaTabelaDeUsuarios(indiceUsuarios, vUsuarios, contUsuario, codUsuario, indiceIdioma, vIdioma, contIdioma);
                }
            }
            break;
        case 5:
            cout << "Voce escolheu realizar exclusao na tabela de idiomas \n";
            for(int codIdioma = 5; codIdioma != 0;)
            {
                cout << "\n\nInforme o codigo do idioma a ser excluido (0 Para Encerrar): ";
                cin >> codIdioma;
                if(codIdioma != 0)
                {
                    exclusaoNaTabelaDeIdiomas(indiceIdioma, vIdioma, contIdioma, codIdioma);
                }
            }
            break;
        case 6:
            cout << "Voce escolheu realizar exclusao na tabela de licoes \n";
            for(int codLicoes = 5; codLicoes != 0;)
            {
                cout << "\n\nInforme o codigo da licao a ser excluida (0 Para Encerrar): ";
                cin >> codLicoes;
                if(codLicoes != 0)
                {
                    exclusaoNaTabelaDeLicoes(indiceLicoes, vLicoes, contLicoes, codLicoes);
                }
            }
            break;
        case 7:
            cout << "Voce escolheu realizar exclusao na tabela de exercicios \n";
            for(int codExercicio = 5; codExercicio != 0;)
            {
                cout << "\n\nInforme o codigo do exercicio a ser excluido (0 Para Encerrar): ";
                cin >> codExercicio;
                if(codExercicio != 0)
                {
                    exclusaoNaTabelaDeExercicios(indiceExercicios, vExercicios, contExercicio, codExercicio);
                }
            }
            break;
        case 8:
            cout << "Voce escolheu realizar exclusao na tabela de usuarios \n";
            for(int codUsuario = 5; codUsuario != 0;)
            {
                cout << "\n\nInforme o codigo do usuario a ser excluido (0 Para Encerrar): ";
                cin >> codUsuario;
                if(codUsuario != 0)
                {
                    exclusaoNaTabelaDeUsuarios(indiceUsuarios, vUsuarios, contUsuario, codUsuario);
                }
            }
        case 9:
            cout << "Voce escolheu realizar leitura exaustiva na tabela de Idiomas \n";
            leituraExaustivaNaTabelaDeIdioma(indiceIdioma, vIdioma, contIdioma);
            break;
        case 10:
            cout << "Voce escolheu realizar leitura exaustiva na tabela de Licoes \n";
            leituraExaustivaNaTabelaDeLicoes(indiceLicoes, vLicoes, contLicoes);
            break;
        case 11:
            cout << "Voce escolheu realizar leitura exaustiva na tabela de Exercicios \n";
            leituraExaustivaNaTabelaDeExercicios(indiceExercicios, vExercicios, contExercicio);
            break;
        case 12:
            cout << "Voce escolheu realizar leitura exaustiva na tabela de Usuarios \n";
            leituraExaustivaNaTabelaDeUsuarios(indiceUsuarios, vUsuarios, contUsuario);
            break;
        case 13:
            cout << "Voce escolheu realizar reorganizacao na tabela de idiomas \n";
            reorganizacaoDaTabelaDeIdioma(indiceIdioma, novoIndiceIdioma, vIdioma, novoVetIdioma, contIdioma);
            break;
        case 14:
            cout << "Voce escolheu realizar reorganizacao na tabela de licoes \n";
            reorganizacaoDaTabelaDeLicoes(indiceLicoes, novoIndiceLicoes, vLicoes, novoVetLicoes, contLicoes);
            break;
        case 15:
            cout << "Voce escolheu realizar reorganizacao na tabela de exercicios \n";
            reorganizacaoDaTabelaDeExercicios(indiceExercicios, novoIndiceExercicios, vExercicios, novoVetExercicios, contExercicio);
            break;
        case 16:
            cout << "Voce escolheu realizar reorganizacao na tabela de usuarios \n";
            reorganizacaoDaTabelaDeUsuarios(indiceUsuarios, novoIndiceUsuarios, vUsuarios, novoVetUsuarios, contUsuario);
            break;
        case 17:
            cout << "Voce escolheu praticar exercicios \n";
            realizarExercicio(indiceIdioma, vIdioma, indiceLicoes, vLicoes, indiceExercicios, vExercicios, indiceUsuarios, vUsuarios, contIdioma, contLicoes, contExercicio, contUsuario);
            break;
        case 18:
            selectionSortUsuariosPorPontuacao(vUsuarios, indiceUsuarios, contUsuario);
            for(int i = 0; i < contUsuario; i++)
            {
                int enderecoUsuario = indiceUsuarios[i].endereco;
                cout << "Nome: " << vUsuarios[enderecoUsuario].nome << ", Pontuacao Total: " << vUsuarios[enderecoUsuario].pontuacao_total << "\n";
            }
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
