#include <iostream>
#include <algorithm>
#include <assert.h>
#include <string>
#include <iomanip>

using namespace std;

// estrutura para armazenar alunos e vetor de alunos
typedef struct
{
    int matriculaAluno;
    string nomeAluno;
    int anoEntrada;
    int mesEntrada;
    int diaEntrada;
    float nota1;
    float nota2;
    float nota3;
    float mediaAluno;
    string situacaoSemestral;

} alunos;

// variaveis globais
int opcaoGlobal = 0;
int opcao_busca_global = 0;
int qntdAlunos = 0;
alunos *lista = NULL;
char continua;

void vetoresStruct(alunos *lista, int qntdAlunos)
{
    for (int i = 0; i < qntdAlunos; i++)
    {
        cout << "Matricula: " << (lista + i)->matriculaAluno << endl;
        cout << "Nome do aluno: " << (lista + i)->nomeAluno << endl;
        cout << "Data de entrada: " << (lista + i)->diaEntrada << " " << (lista + i)->mesEntrada << " " << (lista + i)->anoEntrada << endl;
        cout << fixed << setprecision(3) << "Notas: " << (lista + i)->nota1 << " " << (lista + i)->nota2 << " " << (lista + i)->nota3 << endl;
        cout << fixed << setprecision(3) << "Media: " << ((lista + i)->nota1 + (lista + i)->nota2 + (lista + i)->nota3) / 3 << endl;
        cout << "Situacao atual: " << (lista + i)->situacaoSemestral << endl;
        cout << endl;
    }
}
string situacao(float semestre)
{
    if (semestre >= 7.00)
    {
        return "APROVADO";
    }
    else
        return "REPROVADO";
}

void opcoes_de_entrada()
{
    cout << "======= Bem vindo ao sistema de alunos =======" << endl;
    cout << endl;
    cout << "============ O que deseja fazer? ============" << endl;
    cout << "======= Ordenar por media. Aperte 1 =========" << endl;
    cout << "========= Procurar aluno.  Aperte 2 =========" << endl;
    cout << "========= Adicionar aluno. Aperte 3 =========" << endl;
    cout << "========= Mostrar alunos.  Aperte 4 =========" << endl;
    cout << "======== Sair do sistema.  Aperte 5 =========" << endl;
}

void opcoes_de_busca()
{
    cout << "Como deseja realizar a busca?" << endl;
    cout << "Buscar por primeiro nome. Aperte 1" << endl;
    cout << "Buscar Matricula. Aperte 2" << endl;
    cout << "Buscar por Media. Aperte 3" << endl;
    cout << "Sair do sistema. Aperte 4" << endl;
}

void adicionar_alunos()
{
    alunos novoAluno;
    cout << "Informe o numero de matricula do aluno: ";
    cin >> novoAluno.matriculaAluno;
    cout << endl
         << "Adicione o nome do aluno: ";
    cin.ignore(256, '\n');
    getline(cin, novoAluno.nomeAluno);
    transform(novoAluno.nomeAluno.begin(), novoAluno.nomeAluno.end(), novoAluno.nomeAluno.begin(), ::toupper);
    cout << endl
         << "Digite a data de entrada do aluno: ";
    cin >> novoAluno.anoEntrada >> novoAluno.mesEntrada >> novoAluno.diaEntrada;
    cout << endl
         << "Digite as tres notas do aluno: ";
    cin >> novoAluno.nota1 >> novoAluno.nota2 >> novoAluno.nota3;
    novoAluno.mediaAluno = (novoAluno.nota1 + novoAluno.nota2 + novoAluno.nota3) / 3.0;
    cout <<fixed << setprecision(1)<< endl
         << "Media do aluno: " << novoAluno.mediaAluno;
    novoAluno.situacaoSemestral = situacao((novoAluno.nota1 + novoAluno.nota2 + novoAluno.nota3) / 3.0);
    transform(novoAluno.situacaoSemestral.begin(), novoAluno.situacaoSemestral.end(), novoAluno.situacaoSemestral.begin(), ::toupper);
    cout << endl
         << "Situacao semestral do aluno: " << novoAluno.situacaoSemestral << endl <<endl;

    // alocaçãp de memoria
    alunos *tamlista = new alunos[qntdAlunos + 1];
    for (int i = 0; i < qntdAlunos; ++i)
    {
        tamlista[i] = lista[i];
    }

    tamlista[qntdAlunos] = novoAluno;
    delete[] lista;
    lista = tamlista;
    ++qntdAlunos;
    cin.ignore();
}
// busca de aluno por primeiro nome
int buscar_aluno(alunos lista[], int qntdAlunos)
{
    string procuraAluno;
    bool armazenado = false;

    cout << "Qual aluno deseja procurar? " << endl;
    getline(cin, procuraAluno);

    for (int i = 0; i < qntdAlunos; i++)
    {

        if (lista[i].nomeAluno == procuraAluno)
        {
            armazenado = true;
            cout << "O aluno " << procuraAluno << " foi encontrado." << endl;
            cout << "N de Matricula: " << lista[i].matriculaAluno << endl;
            cout << "Data de entrada: " << lista[i].diaEntrada << " " << lista[i].mesEntrada << " " << lista[i].anoEntrada << endl;
            cout << "Nome completo: " << lista[i].nomeAluno << endl;
            cout << "Notas: "
                 << lista[i].nota1 << lista[i].nota2 << lista[i].nota3 << endl;
            cout << "Situacao atual: " << lista[i].situacaoSemestral << endl;
        }
    }
    if (armazenado == false)
    {
        cout << "O aluno nao foi encontrado." << endl;
    }
    return 0;
}

int buscar_aluno_matricula(alunos lista[], int qntdAlunos)
{
    int matricula;
    bool armazenado;
    cout << "Digite a matricula do Aluno" << endl;
    cin >> matricula;

    for (int i = 0; i < qntdAlunos; i++)
    {
        if (lista[i].matriculaAluno == matricula)
        {
            armazenado = true;
            cout << "O aluno com a matricula " << matricula << " foi encontrado." << endl;
            cout << "N de Matricula: " << lista[i].matriculaAluno << endl;
            cout << "Data de entrada: " << lista[i].diaEntrada << " " << lista[i].mesEntrada << " " << lista[i].anoEntrada << endl;
            cout << "Nome completo: " << lista[i].nomeAluno << endl;
            cout << "Notas: "
                 << " 1 " << lista[i].nota1 << ". 2 " << lista[i].nota2 << ". 3 " << lista[i].nota3 << endl;
            cout << "Situacao atual: " << lista[i].situacaoSemestral << endl;
        }
        if (armazenado == false)
        {
            cout << "Matricula nao encontrada " << endl;
        }
    }
    return 0;
}

void buscar_aluno_media(alunos lista[], int qntdAlunos)
{
    float media;
    bool armazenado;
    cout << "Digite a media semestral do aluno " << endl;
    cin >> media;

    for (int i = 0; i < qntdAlunos; i++)
    {
        if (lista[i].mediaAluno == media)
        {
            armazenado = true;
            cout << "O aluno com a media " << media << " foi encontrado." << endl;
            cout << "N de Matricula: " << lista[i].matriculaAluno << endl;
            cout << "Data de entrada: " << lista[i].diaEntrada << " " << lista[i].mesEntrada << " " << lista[i].anoEntrada << endl;
            cout << "Nome completo: " << lista[i].nomeAluno << endl;
            cout << "Notas: "
                 << lista[i].nota1  << lista[i].nota2  << lista[i].nota3 << endl;
            cout << "Situacao atual: " << lista[i].situacaoSemestral << endl;
        }
        }
        if (armazenado == false)
        {
            cout << "Nao foi possivel encontrar alunos com esta media semestral. " << endl;
        }
}

// metodo de ordenação bubble
void ordenaAlunos(alunos *lista, int qntdAlunos)
{
    cout << "Os alunos estao sendo ordenados " << endl;
    if (qntdAlunos > 1)
    {
        for (int i = 0; i < qntdAlunos - 1; i++)
        {
            if (lista[i].mediaAluno > lista[i + 1].mediaAluno)
            {
                alunos tam = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = tam;
            }
        }
        ordenaAlunos(lista, qntdAlunos - 1);
    }
}

int escolhaOpcao()
{
    int opcao;

    while (1)
    {

        cout << "Digite sua escolha: ";
        if (cin >> opcao)
        {
            if (opcao <= 5 && opcao >= 1)
            {
                return opcao;
            }
            else
            {
                cout << "Numero invalido, tente novamente:  " << endl;
            }
        }
        else
        {
            cout << "Digite um numero. " << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

int opcaoBusca()
{
    int opcao_busca_global;
    while (1)
    {
        cout << "Digite sua escolha: ";

        if (cin >> opcao_busca_global)
        {
            cin.ignore();
            if (opcao_busca_global >= 1 && opcao_busca_global <= 5)
                return opcao_busca_global;
            else
                cout << endl
                     << "Numero invalido, tente novamente: " << endl;
        }
        else
        {
            cout << "Digite um numero. " << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

void invalido()
{
    cout << endl
         << "Entrada invalida, tente novamente" << endl;
}

void opcoes(int opcao, int opcao_busca_global)
{
    switch (opcao)
    {
    case 1:
        ordenaAlunos(lista, qntdAlunos);
        vetoresStruct(lista, qntdAlunos);
        break;
    case 2:
        opcoes_de_busca();
        opcao_busca_global = opcaoBusca();
        system("cls");
        // 1escolha opcao 2opcao busca
        switch (opcao_busca_global)
        {
        case 1:
            cout << "Estamos procurando o Aluno pelo nome, aguarde... " << endl;
            buscar_aluno(lista, qntdAlunos);
            break;
        case 2:
            cout << "Estamos procurando o aluno pelo Num de matricula, aguarde... " << endl;
            buscar_aluno_matricula(lista, qntdAlunos);
            break;

        case 3:
            cout << "Estamos procurando o aluno pela Media semestral, aguarde..." << endl;
            buscar_aluno_media(lista, qntdAlunos);
            break;
        case 4:
            cout << "Saindo do sitema. " << endl;
            exit(0);

        default:
            invalido();
            break;
        }
        break;
    case 3:
        adicionar_alunos();
        break;
    case 4:
        vetoresStruct(lista, qntdAlunos);
        break;
    case 5:
        cout << "Saindo do sistema. " << endl;
        exit(0);
    default:
        invalido();
        break;
    }
}

void alunosPredefinidos()
{
    lista = new alunos[4];

    lista[0].matriculaAluno = 78953476;
    lista[0].nomeAluno = "VILMA PENHA DE NORONHA";
    lista[0].anoEntrada = 2020;
    lista[0].mesEntrada = 03;
    lista[0].diaEntrada = 18;
    lista[0].nota1 = 3.3;
    lista[0].nota2 = 6;
    lista[0].nota3 = 8.7;
    lista[0].mediaAluno = (lista[0].nota1 + lista[0].nota2 + lista[0].nota3) / 3;
    lista[0].situacaoSemestral = "REPROVADO";

    lista[1].matriculaAluno = 23781290;
    lista[1].nomeAluno = "VAGNER RODRIGUES KARPINSKI";
    lista[1].anoEntrada = 2022;
    lista[1].mesEntrada = 03;
    lista[1].diaEntrada = 15;
    lista[1].nota1 = 5.6;
    lista[1].nota2 = 6.5;
    lista[1].nota3 = 8.4;
    lista[1].mediaAluno = (lista[1].nota1 + lista[1].nota2 + lista[1].nota3) / 3;
    lista[1].situacaoSemestral = "REPROVADO";

    lista[2].matriculaAluno = 2389156;
    lista[2].nomeAluno = "DANIEL ORIVALDO DA SILVA";
    lista[2].anoEntrada = 2022;
    lista[2].mesEntrada = 03;
    lista[2].diaEntrada = 15;
    lista[2].nota1 = 7.6;
    lista[2].nota2 = 7;
    lista[2].nota3 = 6.4;
    lista[2].mediaAluno = (lista[2].nota1 + lista[2].nota2 + lista[2].nota3) / 3;
    lista[2].situacaoSemestral = "APROVADO";

    lista[3].matriculaAluno = 45346738;
    lista[3].nomeAluno = "LUIZ EDUARDO ANDRE DA MOTA";
    lista[3].anoEntrada = 2023;
    lista[3].mesEntrada = 03;
    lista[3].diaEntrada = 15;
    lista[3].nota1 = 8.25;
    lista[3].nota2 = 5.7;
    lista[3].nota3 = 8.5;
    lista[3].mediaAluno = (lista[3].nota1 + lista[3].nota2 + lista[3].nota3) / 3;
    lista[3].situacaoSemestral = "APROVADO";

    qntdAlunos = 4;
}

int main() 
{
    alunosPredefinidos();

    do
    {
        opcoes_de_entrada();
        opcaoGlobal = escolhaOpcao();
        system("cls");
        opcoes(opcaoGlobal, opcao_busca_global);

        cout << "Deseja escolher outra opcao? 'S' para continuar " << endl;
        cin >> continua;
        cin.ignore();
    } while (continua == 'S' || continua == 's');

    delete[] lista;

    return 0;
}