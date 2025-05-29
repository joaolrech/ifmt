#include <stdio.h>
#include <string.h>

//1. Faça um algoritmo que receba a idade de 50 pessoas e, calcule
//   e imprima a quantidade de pessoas com idade superior a 21 anos,
//   quantas mulheres com idade de 20 a 30 anos e qual a média de
//   idade das pessoas com pressão alta e que são obesas.

void q01()
{
    int x, o, p, ct1 = 0, ct2 = 0, ct3 = 0, sexo;
    float i, soma = 0;

    for(x = 0; x < 50; x ++)
    {
        printf("Digite sua idade e seu sexo. (1 para masculino e 0 para feminino)\n");
        scanf("%f", &i);
        scanf("%d", &sexo);
        printf("Você possui pressão alta? (1 para sim e 0 para não)\n");
        scanf("%d", &p);
        printf("Você é obeso? (1 para sim e 0 para não)\n");
        scanf("%d", &o);

        if(i>21)
            ct1++;
        if(i>=20 && i<=30 && sexo==0)
            ct2++;
        if(p==1 && o==1)
        {
            ct3++;
            soma+=i;
        }
    }

    printf("Quantidade de pessoas com idade superior a 21 anos: %d\n", ct1);
    printf("Quantidade de mulheres com idade entre 20 e 30 anod: %d\n", ct2);
    printf("Média de idade das pessoas que são obesas e possuem pressão alta: %.2f\n", soma/ct3);
}

//2. Faça um algoritmo que leia vários números e informe quantos
//   desses números estão no intervalo de 250 a 500 e qual o % de
//   números múltiplos de 7.

void q02()
{
    float ct2 = 0;
    int i, n, ct1 = 0;

    for(i = 0; i < 99; i ++)
    {
        printf("Digite um número inteiro.\n");
        scanf("%d", &n);

        if(n >= 250 && n <= 500)
            ct1 ++;
        if(n % 7 == 0)
            ct2 ++;
    }

    printf("Quantidade de números entre 250 e 500: %.d\n", ct1);
    printf("Porcentagem de números múltiplos de 7: %.2f%%\n", ct2 / 99 * 100);
}

//3. Faça um algoritmo que imprima todos os números pares de 111 a
//   213 e o dobro dos ímpares que se encontram no intervalo de 1 até 99.

void q03()
{
    int x;

    for(x = 111; x <= 213; x ++)
        if(x % 2 == 0)
            printf("%d\n", x);
    
    for(x = 1; x <= 99; x ++)
        if(x % 2 == 1)
            printf("%d\n", x * 2);
}

//4. Faça um algoritmo para imprimir todos os divisores de um número.
//   Para um dado número n, o programa testa todos os números de 1 até n.

void q04()
{
    int n, i;

    printf("Digite o valor de n.\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i ++)
        if(n % i == 0)
            printf("%d\n", i);
}

//5. Faça um algoritmo que receba a idade, a altura e o peso de 20 pessoas, calcule e mostre: 
//   Quantos pesam mais de 70 kg e possuem a idade maior ou igual a 20 anos; 
//   A média das alturas das pessoas com idade entre 18 a 40 anos;
//   O percentual das pessoas com peso até 35 kg entre todas as pessoas. 

void q05()
{
    int x, i, gordovelho = 0, entre = 0;
    float a, p, m, s = 0, leve = 0;

    for(i = 0; i < 20; i ++)
    {
        printf("Digite sua idade, sua altura e seu peso.\n");
        scanf("%d", &i);
        scanf("%f", &a);
        scanf("%f", &p);

        if(p > 70 && i >= 20)
            gordovelho ++;
        if(i >= 18 && i <= 40)
        {
            entre ++;
            s += a;
        }
        if(p <= 35)
            leve ++;
    }
    
    printf("Quantidade de pessoas acima de 20 anos que pesam mais de 70kg: %d\n", gordovelho);
    printf("Média das alturas das pessoas entre 18 e 40 anos: %.2f\n", s / entre);
    printf("Percentual de pessoas com peso até 35kg: %.2f%%\n", leve / 20 * 100);

}

//6. Criar um algoritmo que imprima todos os números de 1 até 100,
//   inclusive, a soma e a média de todos eles.

void q06()
{
    float m, x, s = 0, c = 0;

    for(x = 1; x <= 100; x ++)
    {
        printf("%.0f\n", x);
        
        s += x;
        c ++;
    }

    m = s / c;

    printf("Soma: %.0f\n", s);
    printf("Média: %.2f\n", m);
}

//7. Faça um programa que mostre os números entre 1000 e 2000 que,
//   quando divididos por 11, produzam resto igual a 5.

void q07()
{
    int i;

    for(i = 1000; i <= 2000; i ++)
        if(i % 11 == 5)
            printf("%d\n", i);
}

//8. Criar um algoritmo que leia um número (NUM) e então imprima os
//   múltiplos de 3 e 5, ao mesmo tempo, no intervalo fechado de 1 a NUM.

void q08()
{
    int x, n = 0;

    printf("Digite um número.\n");
    scanf("%d", &n);

    for(x = 1; x <= n; x ++)
        if(x % 3 == 0 && x % 5 == 0)
            printf("%d\n", x);
}

//9. Escreva um algoritmo que leia 200 números inteiros e imprima
//   quantos são pares e quantos são ímpares.

void q09()
{
    int n, x, p = 0, i = 0;

    for(x = 0; x < 200; x ++)
    {
        printf("Digite um número.\n");
        scanf("%d", &n);

        if(n % 2 == 0)
            p ++;
        else
            i ++;
    }

    printf("Quantidade de números pares: %d\n", p);
    printf("Quantidade de números ímpares: %d\n", i);
}

//10. Escreva um algoritmo que receba 15 números e imprima
//    quantos números maiores que 30 foram digitados.

void q10()
{
    int n, x, c = 0;

    for(x = 0; x < 15; x ++)
    {
        printf("Digite um número.\n");
        scanf("%d", &n);

        if(n > 30)
            c ++;
    }

    printf("Foram digitados %d números maiores que 30.\n", c);
}

//11. Escreva um algoritmo que leia um conjunto de 50 fichas, cada uma
//    contendo, a altura e o código do sexo de uma pessoa (código = 1 se
//    for masculino e 2 se for feminino), e calcule e imprima: 
//    - A média de altura das mulheres; 
//    - A média de altura da turma.

void q11()
{
    int i, sexo, c = 0;
    float a, soma = 0, somamulheres = 0;

    for(i = 0; i < 50; i ++)
    {
        printf("Digite a altura e o sexo da pessoa. (1 para masculino e 2 para feminino)\n");
        scanf("%f", &a);
        scanf("%d", &sexo);

        soma += a;

        if(sexo == 2)
        {
            c ++;
            somamulheres += a;
        }
    }

    printf("Média de altura da turma: %.2f\n", soma / 50);
    printf("Média de altura das mulheres: %.2f\n", somamulheres / c);
}

//12. Um cinema possui capacidade de 100 lugares e está sempre com ocupação total.
//    Certo dia, cada espectador respondeu a um questionário, no qual constava: 
//    - Sua idade; 
//    - Sua opinião em relação ao filme, segundo as seguintes notas:
//    Ótimo;
//    Bom;
//    Regular;
//    Ruim;
//    Péssimo.
//    Elabore um algoritmo que, lendo estes dados, calcule e imprima: 
//    - A quantidade de respostas ótimo; 
//    - A diferença percentual entre respostas bom e regular; 
//    - A média de idade das pessoas que responderam ruim; 
//    - A percentagem de respostas péssimo.

void q12()
{
    int x;
    float i, si = 0, ca = 0, cb = 0, cc = 0, cd = 0, ce = 0, pbc;
    char o;

    for(x = 0; x < 100; x ++)
    {
        printf("Digite sua idade.\n");
        scanf("%f", &i);

        printf("Qual sua opinião em relação ao filme assistido?\n");
        printf("A - Ótimo, B - Bom, C - Regular, D - Ruim, E - Péssimo.\n");
        scanf(" %c", &o);

        if(o == 'A')
            ca++;
        else if(o == 'B')
            cb++;
        else if(o == 'C')
            cc++;
        else if(o == 'D')
        {
            cd++;
            si += i;
        }
        else if(o == 'E')
            ce++;
        else
        {
            printf("Opção inválida.\n");
            x--;
        }

        if(cc != 0)
            pbc = (cb - cc) / cc * 100;
        else
            pbc = 100;
    }

    printf("Quantidade de respostas 'Ótimo': %.0f\n", ca);
    printf("Diferença percentual entre respostas 'Bom' e 'Regular': %.2f%%\n", pbc);
    printf("Média de idade das pessoas que responderam 'Ruim': %.2f\n", si / cd);
    printf("Porcentagem de respostas 'Péssimo': %.2f%%\n", ce / 100 * 100);
}

//13. Criar um algoritmo que receba vários números inteiros e positivos e imprima
//    o produto dos números ímpares digitados e a soma dos pares. O algoritmo
//    encerra quando o zero ou um número negativo é digitado.

void q13()
{
    int n, s = 0, p = 1;

    printf("Digite um número.\n");
    scanf("%d", &n);

    while(n > 0)
    {
        if(n % 2 == 0)
            s += n;
        else
            p *= n;

        printf("Digite um número.\n");
        scanf("%d", &n);
    }

    printf("Produto dos números ímpares: %d\n", p);
    printf("Soma dos números pares: %d\n", s);
}

//14. Os alunos de informática tiveram cinco provas (uma de cada matéria/disciplina): 1, 2, 3, 4 e 5.
//    Considere aprovado o aluno com nota igual ou superior a 7.0. 
//    Criar um algoritmo que leia o Nome dos alunos e as suas respectivas cinco notas.
//    Inicialmente o algoritmo deve perguntar quantos alunos existem na turma e deve também imprimir: 
//    - Nome dos que foram aprovados em todas as matérias; 
//    - Nome dos alunos aprovados nas matérias 1 e 4; 
//    - A porcentagem dos aprovados na matéria 3.

void q14()
{
    int i, j, q;

    printf("Digite a quantidade de alunos da turma.\n");
    scanf("%d", &q);
    
    float n[q][5], c = 0;
    char nome[q][99];

    for(i = 1; i <= q; i ++)
    {
        printf("Digite o nome do aluno %d.\n", i);
        scanf("%s", nome[i]);

        printf("Digite as notas do aluno nas matérias 1, 2, 3, 4 e 5, respectivamente.\n");
        for(j = 0; j < 5; j ++)
            scanf("%f", &n[i][j]);
    }

    printf("Alunos aprovados em todas as matérias:\n");
    for(i = 1; i <= q; i ++)
        if(n[i][0] >= 7 && n[i][1] >= 7 && n[i][2] >= 7 && n[i][3] >= 7 && n[i][4] >= 7)
            printf("%s\n", nome[i]);

    printf("Alunos aprovados nas matérias 1 e 4:\n");
    for(i = 1; i <= q; i ++)
        if(n[i][0] >= 7 && n[i][3] >= 7)
            printf("%s\n", nome[i]);

    for(i = 1; i <= q; i ++)
        if(n[i][2] >= 7)
            c ++;
    printf("Porcentagem de alunos aprovados na matéria 3: %.2f%%\n", c / q * 100);
}

//15. Existem três candidatos a uma vaga no Senado. Feita a eleição, os votos são registrados em disco.
//    O voto de cada eleitor foi codificado da seguinte forma: 
//    1 2 3 - Voto para os candidatos. 
//    0 - Voto branco. 
//    4 - Voto nulo. 
//    Deseja-se saber: 
//    - O número do candidato vencedor; 
//    - O número de votos em branco; 
//    - O número de votos nulos; 
//    - O número de eleitores que compareceram às urnas. 
//    Admite-se que não são possíveis empates. Então, construa um algoritmo que execute esta tarefa,
//    sabendo que o voto de cada eleitor é lido do disco através do comando leia (VOTO).
//    O voto finalizador tem código –1, e não deve ser computado.

void q15()
{
    int v, b = 0, v1 = 0, v2 = 0, v3 = 0, n = 0, w, t = 0, m;

    printf("Digite seu voto.\n");
    printf("0 - Branco, 1 - Candidato 1, 2 - Candidato 2, 3 - Candidato 3, 4 - Nulo.\n");
    scanf("%d", &v);

    while(v != -1)
    {
        t ++;
        
        if(v == 0)
            b ++;
        else if(v == 1)
            v1 ++;
        else if(v == 2)
            v2 ++;
        else if(v == 3)
            v3 ++;
        else if(v == 4)
            n ++;
        else
            printf("Voto inválido.\n");

        printf("Digite seu voto.\n");
        printf("0 - Branco, 1 - Candidato 1, 2 - Candidato 2, 3 - Candidato 3, 4 - Nulo.\n");
        scanf("%d", &v);
    }

    if(v1 > v2 && v1 > v3)
    {
        w = 1;
        m = v1;
    }
    else if(v2 > v1 && v2 > v3)
    {
        w = 2;
        m = v2;
    }
    else
    {
        w = 3;
        m = v3;
    }

    printf("Com %d votos, o vencedor foi o candidato %d.\n", m, w);
    printf("Quantidade de votos em branco: %d\n", b);
    printf("Quantidade de votos nulos: %d\n", n);
    printf("Quantidade de eleitores que compareceram às urnas: %d\n", t);
}

//16. Uma Empresa de fornecimento de energia elétrica faz a leitura mensal dos
//    medidores de consumo. Para cada consumidor, são digitados os seguintes dados: 
//    - Número do consumidor; 
//    - Quantidade de kWh consumidos durante o mês;
//    - Tipo (código) do consumidor:
//    1 - Residencial, preço em reais por kWh = 0,3;
//    2 – comercial, preço em reais por kWh = 0,5;
//    3 – industrial, preço em reais por kWh = 0,7;
//    Os dados devem ser lidos até que seja encontrado um consumidor com Número 0 (zero). 
//    Escreva um algoritmo que calcule e imprima: 
//    - O custo total para cada consumidor; 
//    - O total de consumo para os três tipos de consumidor; 
//    - A média de consumo dos tipos 1 e 2.

void q16()
{
    int nc, tc, i, count = 0, keep = 0;
    float c, p, sres = 0, scom = 0, sind = 0;

    printf("Digite o número do consumidor.\n");
    scanf("%d", &nc);

    while(nc != 0)
    {
        if(keep == 0)
        {
            printf("Digite a quantidade de kWh consumidos.\n");
            scanf("%f", &c);
        }

        printf("Digite o tipo do consumidor.\n");
        printf("1 - Residencial, 2 - Comercial, 3 - Industrial.\n");
        scanf("%d", &tc);

        switch(tc)
        {
            case 1:
                p = c * 0.3;
                sres += c;
                count ++;
                keep = 0;
                break;
            case 2:
                p = c * 0.5;
                scom += c;
                count ++;
                keep = 0;
                break;
            case 3:
                p = c * 0.7;
                sind += c;
                keep = 0;
                break;
            default:
                printf("Tipo inválido.\n");
                keep = 1;
        }

        if(keep == 0)
        {
            printf("Custo do consumidor %d: R$%.2f\n", nc, p);
            printf("Digite o número do consumidor.\n");
            scanf("%d", &nc);
        }
    }

    printf("Consumo total residencial: %.0fkWh\n", sres);
    printf("Consumo total comercial: %.0fkWh\n", scom);
    printf("Consumo total industrial: %.0fkWh\n", sind);
    printf("Consumo médio de residencial e comercial: %.2fkWh\n", (sres + scom) / count);
}

//17. Escreva um algoritmo que receba o número da conta e o saldo de várias
//    pessoas. O algoritmo deve imprimir todas as contas, os respectivos saldos
//    e uma das mensagens: positivo/negativo. Ao final, o percentual de pessoas
//    com saldo negativo. O algoritmo acaba quando se digita um número negativo para a conta. 

void q17()
{
    int c;
    float s, t = 0, n = 0;

    printf("Digite o número da conta.\n");
    scanf("%d", &c);

    while(c >= 0)
    {
        printf("Digite o saldo da conta.\n");
        scanf("%f", &s);

        printf("Número da conta: %d\n", c);
        printf("Saldo da conta: %.2f\n", s);

        if(s > 0)
            printf("Saldo positivo.\n");
        else if(s < 0)
        {
            printf("Saldo negativo.\n");
            n ++;
        }
        else
            printf("Saldo nulo.\n");

        t ++;

        printf("Digite o número da conta.\n");
        scanf("%d", &c);
    }

    printf("Porcentagem de contas que estão com saldo negativo: %.2f%%\n", n / t * 100);
}

//18. Uma fábrica produz e vende vários produtos e para cada um deles tem-se o nome,
//    quantidade produzida e quantidade vendida. Criar um algoritmo que imprima: 
//    - Para cada produto, nome, quantidade no estoque e uma mensagem se
//    o produto tiver menos de 50 itens no estoque; 
//    - Nome e quantidade do produto com maior estoque.

void q18()
{
    int me = 0, i, p[99], v[99], e[99];
    char nome[99][99], maiornome[99];

    for(i = 0; i < 5; i ++)
    {
        printf("Digite o nome do produto.\n");
        scanf("%s", nome[i]);

        printf("Quantas unidades foram produzidas?\n");
        scanf("%d", &p[i]);

        printf("Quantas unidades foram vendidas?\n");
        scanf("%d", &v[i]);

        e[i] = p[i] - v[i];

        if(e[i] > me)
        {
            me = e[i];
            strcpy(maiornome, nome[i]);
        }
    }

    for(i = 0; i < 5; i ++)
    {
        printf("Nome: %s\n", nome[i]);
        printf("Quantidade no estoque: %d\n", e[i]);

        if(e[i] < 50)
            printf("Alerta! Baixa quantidade em estoque.\n");
    }

    printf("Com %d unidades, %s é o produto com maior estoque.\n", me, maiornome);
}

//19. Numa universidade, os alunos das turmas de informática fizeram uma prova de algoritmos.
//    Cada turma possui um número de alunos. Criar um algoritmo que imprima para cada turma: 
//    - Quantidade de alunos aprovados; 
//    - Média de cada turma; 
//    - Percentual de reprovados. 
//    Considere aprovado aluno com nota igual ou superior a 7.0. O programa
//    deve ler onúmero de alunos de cada turma e só finalizar o
//    programa quando um número não positivo de alunos for digitado.

void q19()
{
    int i, q;
    float a = 0, r = 0, n, m, p, s = 0;

    printf("Digite a quantidade de alunos da turma.\n");
    scanf("%d", &q);

    while(q > 0)
    {
        for(i = 1; i <= q; i ++)
        {
            printf("Digite a nota do aluno %d.\n", i);
            scanf("%f", &n);

            s += n;

            if(n >= 7)
                a ++;
            else
                r ++;
        }

        m = s / q;
        p = r / q * 100;

        printf("Quantidade de alunos aprovados: %.0f\n", a);
        printf("Média da turma: %.2f\n", m);
        printf("Percentual de alunos reprovados: %.2f%%\n", p);

        printf("Digite a quantidade de alunos da turma.\n");
        scanf("%d", &q);
    }
}

//20. Desenvolva um algoritmo que leia o nome, a idade e o sexo de várias pessoas.
//    O programa vai perguntar se o usuário quer ou não continuar. No final, mostre:

void q20()
{
    char nome[99], pessoavelha[99], mulherjovem[99];
    int i, c = 0, idade, sexo, soma = 0, homensmais30 = 0, mulheresmenos18 = 0, maioridade = 0, menoridademulher = -1;
    float media, total = 0;

    while(c !=1 )
    {
        printf("Digite seu nome, sua idade e seu sexo. (1 para masculino e 0 para feminino)\n");
        scanf("%s", nome);
        scanf("%d", &idade);
        scanf("%d", &sexo);

        soma += idade;
        total ++;

        if(idade > maioridade)
        {
            maioridade = idade;
            strcpy(pessoavelha, nome);
        }
        if(sexo == 0 && idade < menoridademulher || menoridademulher == -1)
        {
            menoridademulher = idade;
            strcpy(mulherjovem, nome);
        }
        if(sexo == 1 && idade > 30)
            homensmais30 ++;
        if(sexo == 0 && idade < 18)
            mulheresmenos18 ++;

        printf("Deseja continuar? (0 para sim e 1 para não)\n");
        scanf("%d", &c);
    }

    media = soma / total;

    printf("Nome da pessoa mais velha: %s\n", pessoavelha);
    printf("Nome da mulher mais jovem: %s\n", mulherjovem);
    printf("Média da idade: %.2f\n", media);
    printf("Quantidade de homens com mais de 30 anos: %d\n", homensmais30);
    printf("Quantidade de mulheres com menos de 18 anos: %d\n", mulheresmenos18);
}

//21. Dado um país A, com 5.000.000 de habitantes e uma taxa de natalidade de 3% ao ano,
//    e um país B com 7.000.000 de habitantes e uma taxa de natalidade de 2% ao ano,
//    escreva um algoritmo, que imprima o tempo necessário para que a
//    população do país A ultrapasse a população do país B.

void q21()
{
    float a = 5000000, b = 7000000;
    int t = 0;

    while(a <= b)
    {
        a *= 1.03;
        b *= 1.02;
        t ++;
    }

    printf("Tempo necessário: %d anos.\n", t);
}

//22. Criar um algoritmo que leia os limites inferior e superior de um intervalo
//    e imprima todos os números pares no intervalo aberto e seu somatório.
//    Suponha que os números digitados são um intervalo crescente. 

void q22()
{
    int i, a, b, s = 0;

    printf("Digite o limite inferior e o limite superior do intervalo.\n");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("Saídas:\n");
    for(i = a; i < b; i ++)
    {
        if(i % 2 == 0)
        {
            s += i;
            printf("%d\n", i);
        }
    }

    printf("Soma %d\n", s);
}

//23. Uma rainha requisitou os serviços de um monge, o qual exigiu o pagamento
//    em grãos de trigo da seguinte maneira: os grãos de trigo estariam dispostos
//    em um tabuleiro de xadrez, de tal forma que a primeira casa do tabuleiro
//    tivesse um grão, e as casas seguintes o dobro da anterior. Construa um
//    algoritmo que calcule quantos grãos de trigo a Rainha deverá pagar ao monge.

void q23()
{
    int i;
    unsigned long t = 0, g = 1;

    for (i = 1; i <= 64; i ++)
    {
        t += g;
        g *= 2;
    }
    
    printf("A rainha deverá pagar %lu graos de trigo ao monge.\n", t);
}

//24. Construa um algoritmo que leia uma quantidade indeterminada de números inteiros
//    positivos e identifique qual foi o maior número digitado. O final da série
//    de números digitada deve ser indicado pela entrada de -1.

void q24()
{
    int n, m;

    printf("Digite um número inteiro e positivo.\n");
    scanf("%d", &n);

    while(n != -1)
    {
        if(n > m)
            m = n;

        printf("Digite um número inteiro e positivo.\n");
        scanf("%d", &n);
    }

    printf("Maior número digitado: %d\n", m);
}

int main()
{
    int questao;

    printf("Digite a questão a ser executada.\n");
    scanf("%d", &questao);

    switch(questao)
    {
        case 1:
            q01();
            break;
        case 2:
            q02();
            break;
        case 3:
            q03();
            break;			
        case 4:
            q04();
            break;
        case 5:
            q05();
            break;
        case 6:
            q06();
            break;
        case 7:
            q07();
            break;
        case 8:
    	    q08();
    	    break;
        case 9:
    	    q09();
    	    break;
        case 10:
    	    q10();
    	    break;
        case 11:
    	    q11();
    	    break;
        case 12:
    	    q12();
    	    break;
        case 13:
    	    q13();
    	    break;
        case 14:
    	    q14();
    	    break;
        case 15:
    	    q15();
    	    break;
        case 16:
    	    q16();
    	    break;
        case 17:
    	    q17();
    	    break;
        case 18:
    	    q18();
    	    break;
        case 19:
    	    q19();
    	    break;
        case 20:
    	    q20();
    	    break;
        case 21:
    	    q21();
    	    break;
        case 22:
    	    q22();
    	    break;
        case 23:
    	    q23();
    	    break;
        case 24:
    	    q24();
    	    break;
        default:
    	    printf("Opção inválida.\n");
    }
    
    return 0;
}