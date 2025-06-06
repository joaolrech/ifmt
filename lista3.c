#include <stdio.h>
#include <string.h>

//1. Faça um programa que imprima todos os números de 1 até 100.

void q01()
{
    int i;

    for(i = 0; i < 100; i ++)
        printf("%d\n", i + 1);
}

//2. Faça um programa que imprima todos os números pares de 100 até 1.

void q02()
{
    int i;

    for(i = 0; i < 100; i ++)
        if((i + 1) % 2 == 0)
            printf("%d\n", i + 1);
}

//3. Faça um programa que imprima os múltiplos de 5, no intervalo de 1 até 500.

void q03()
{
    int i;

    for(i = 0; i < 500; i ++)
        if((i + 1) % 5 == 0)
            printf("%d\n", i + 1);
}
        
//4. Faça um programa que permita entrar com o nome, a idade e o sexo de 20
//   pessoas. O programa deve imprimir o nome da pessoa se ela for do sexo masculino
//   e tiver mais de 21 anos.

void q04()
{
    int i, idade, sexo;
    char nome[99];

    for(i = 0; i < 20; i ++)
    {
        printf("Digite seu nome, sua idade, e seu gênero.\n");
        printf("0 - Feminino, 1 - Masculino\n");
        scanf(" %99[^\n]", nome);
        scanf("%d", &idade);
        scanf("%d", &sexo);

        if(idade > 21 && sexo == 1)
            printf("%s\n", nome);
    }
}

//5. Sabendo-se que a unidade lógica e aritmética calcula o produto através de somas
//   sucessivas, crie um programa que calcule o produto de dois números inteiros
//   lidos. Suponha que os números lidos sejam positivos.

void q05()
{
    int a, b, i, soma = 0;

    printf("Digite dois números inteiros.\n");
    scanf("%d", &a);
    scanf("%d", &b);

    for(i = 0; i < b; i ++)
        soma += a;

    printf("Produto: %d\n", soma);
}

//6. Crie um programa que imprima os 20 primeiros termos da série de Fibonacci.
//   Observação: os dois primeiros termos desta série são 1 e 1 e os demais são gerados
//   a partir da soma dos anteriores. Exemplo:
//   • 1 + 1 = 2, terceiro termo;
//   • 1 + 2 = 3, quarto termo, etc.

void q06()
{
    int i, t1 = 0, t2 = 1, r;

    printf("%d\n", t2);
    
    for(i = 0; i < 19; i ++)
    {
        r = t1 + t2;

        t1 = t2;
        t2 = r;

        printf("%d\n", r);
    }
}

//7. Crie um programa que permita entrar com o nome, a nota da
//   prova 1 e da prova 2 de 15 alunos. Ao final, imprimir uma listagem, contendo:
//   nome, nota da prova 1, nota da prova 2, e média das notas de cada aluno. Ao final,
//   imprimir a média geral da turma.

void q07()
{
    int i;
    float p1[15], p2[15], media[15], somageral = 0;
    char nome[15][99];

    for(i = 0; i < 15; i ++)
    {
        printf("Digite o nome do aluno.\n");
        scanf(" %99[^\n]", nome[i]);
        printf("Digite a nota da prova 1.\n");
        scanf("%f", &p1[i]);
        printf("Digite a nota da prova 2.\n");
        scanf("%f", &p2[i]);

        media[i] = (p1[i] + p2[i]) / 2;
        
        somageral += media[i];
    }

    for(i = 0; i < 15; i ++)
    {
        printf("Nome do aluno: %s\n", nome[i]);
        printf("Nota da prova 1: %.2f\n", p1[i]);
        printf("Nota da prova 2: %.2f\n", p2[i]);
        printf("Média do aluno: %.2f\n", media[i]);

        printf("\n");
    }

    printf("Média geral: %.2f\n", somageral / 15);
}

//8. Faça um programa que permita entrar com o nome e o salário bruto de 10 pessoas.
//   Após ler os dados, imprimir o nome e o valor da alíquota do imposto de renda
//   calculado conforme a tabela a seguir:
//   Salário IRRF
//   Salário menor que R$1300,00 Isento
//   Salário maior ou igual a R$1300,00 e menor que R$2300,00 10% do salário bruto
//   Salário maior ou igual a R$2300,00 15% do salário bruto

void q08()
{
    int i;
    float sal[10], al[10];
    char nome[10][99];

    for(i = 0; i < 10; i ++)
    {
        al[i] = 0;

        printf("Digite o nome.\n");
        scanf(" %99[^\n]", nome[i]);
        printf("Digite o salário bruto.\n");
        scanf("%f", &sal[i]);

        if(sal[i] >= 2300)
            al[i] = sal[i] * 0.15;
        else if(sal[i] >= 1300 && sal[i] < 2300)
            al[i] = sal[i] * 0.1;
    }

    for(i = 0; i < 10; i ++)
    {
        printf("Nome: %s\n", nome[i]);
        
        if(al[i] == 0)
            printf("Isento.\n");
        else
            printf("Valor da alíquota: R$%.2f\n", al[i]);

        printf("\n");
    }
}

//9. No dia da estréia do filme "Procurando Dory", uma grande emissora de TV realizou
//   uma pesquisa logo após o encerramento do filme. Cada espectador respondeu
//   a um questionário no qual constava sua idade e a sua opinião em relação ao filme:
//   excelente - 3; bom - 2; regular - 1. Criar um programa que receba a idade e a
//   opinião de 20 espectadores, calcule e imprima:
//   • A média das idades das pessoas que responderam excelente;
//   • A quantidade de pessoas que responderam regular;
//   • A percentagem de pessoas que responderam bom entre todos os expectadores
//   analisados.

void q09()
{
    int x, o;
    float idade, cont1 = 0, cont2 = 0, cont3 = 0, somaidades = 0;

    for(x = 0; x < 20; x ++)
    {
        printf("Digite sua idade.\n");
        scanf("%f", &idade);

        printf("Qual sua opinião em relação ao filme assistido?\n");
        printf("1 - Regular, 2 - Bom, 3 - Excelente\n");
        scanf("%d", &o);

        if(o == 1)
            cont1 ++;
        else if(o == 2)
            cont2 ++;
        else if(o == 3)
        {
            cont3 ++;
            somaidades += idade;
        }
        else
        {
            printf("Opção inválida.\n");
            x--;
        }
    }

    printf("Quantidade de pessoas que responderam 'Regular': %.0f\n", cont1);
    printf("Média de idade das pessoas que responderam 'Excelente': %.2f\n", somaidades / cont3);
    printf("Porcentagem de pessoas que responderam 'Bom': %.2f%%\n", (cont2 / 20) * 100);
}

//10. Em um campeonato Europeu de Volleyball, se inscreveram 30 países. Sabendo-se
//    que na lista oficial de cada país consta, além de outros dados, peso e idade de 12
//    jogadores, crie um programa que apresente as seguintes informações:
//    • O peso médio e a idade média de cada um dos times;
//    • O atleta mais pesado de cada time;
//    • O atleta mais jovem de cada time;
//    • O peso médio e a idade média de todos os participantes.

void q10()
{   int i, j, idade, menoridade = 999;
    char nomepais[99][30], nomeatleta[99][12], atletapesado[99], atletajovem[99];
    float somapeso, somaidade, peso, maiorpeso = -1, somageralpeso = 0, somageralidade = 0;

    for(i = 0; i < 30; i ++)
    {   
        somapeso = 0;
        somaidade = 0;

        printf("Digite o nome do país.\n");
        scanf(" %99[^\n]", nomepais[i]);

        for(j = 0; j < 12; j ++)
        {   
            printf("Digite o nome, o peso e a idade do atleta número %d\n", j + 1);
            scanf(" %99[^\n]", nomeatleta[j]);
            scanf("%f", &peso);
            scanf("%d", &idade);

            somapeso += peso;
            somaidade += idade;

            if(idade < menoridade)
            {   
                menoridade = idade;
                strcpy(atletajovem, nomeatleta[j]);
            }

            if(peso > maiorpeso)
            {   
                maiorpeso = peso;
                strcpy(atletapesado, nomeatleta[j]);
            }
        }

        somageralidade += somaidade;
        somageralpeso += somapeso;

        printf("Peso médio dos atletas do(a) %s: %f\n", nomepais[i], somapeso / 12);
        printf("Idade média dos atletas do(a) %s: %f\n", nomepais[i], somaidade / 12);
        printf("Atleta mais pesado do(a) %s: %s\n", nomepais[i], atletapesado);
        printf("Atleta mais jovem do(a) %s: %s\n", nomepais[i], atletajovem);
    }

    printf("Peso médio de todos os participantes: %f\n", somageralpeso / (12 * 30));
    printf("Idade média de todos os participantes: %f\n", somageralidade / (12 * 30));
}

//11. Construa um programa que leia vários números e informe quantos números
//    entre 100 e 200 foram digitados. Quando o valor 0 (zero) for lido, o algoritmo
//    deverá cessar sua execução.

void q11()
{
    int x, num, cont = 0;

    printf("Digite um número inteiro.\n");
    scanf("%d", &num);

    while(x != 0)
    {
        if(num >= 100 && num <= 200)
            cont ++;

        printf("Digite um número inteiro.\n");
        scanf("%d", &num);
    }

    printf("Quantidade de números digitados entre 100 e 200: %d\n", cont);
}

//12. Dado um país A, com 5 milhões de habitantes e uma taxa de natalidade de 3% ao
//    ano, e um país B com 7 milhões de habitantes e uma taxa de natalidade de 2% ao
//    ano, fazer um programa que calcule e imprima o tempo necessário para que a
//    população do país A ultrapasse a população do país B.

void q12()
{
    float a = 5000000, b = 7000000;
    int anos = 0;

    while(a <= b)
    {
        a *= 1.03;
        b *= 1.02;

        anos ++;
    }
    
    printf("Tempo necessário: %d anos.\n", anos);
}

//13. Uma empresa de fornecimento de energia elétrica faz a leitura mensal dos medidores
//    de consumo. Para cada consumidor, são digitados os seguintes dados:
//    • número do consumidor
//    • quantidade de kWh consumidos durante o mês
//    • tipo (código) do consumidor
//    1 - residencial, preço em reais por kWh = 0,3
//    2 - comercial, preço em reais por kWh = 0,5
//    3 - industrial, preço em reais por kWh = 0,7
//    Os dados devem ser lidos até que seja encontrado o consumidor com número 0
//    (zero). O programa deve calcular e imprimir:
//    • O custo total para cada consumidor
//    • O total de consumo para os três tipos de consumidor
//    • A média de consumo dos tipos 1 e 2

void q13()
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

//14. Faça um programa que leia vários números inteiros e apresente o fatorial de cada
//    número. O algoritmo encerra quando se digita um número menor do que 1.

void q14()
{
    int num, i;
    unsigned long fatorial;

    printf("Digite um número inteiro.\n");
    scanf("%d", &num);

    while(num > 1)
    {
        fatorial = 1;

        for(i = 1; i <= num; i ++)
            fatorial *= i;

        printf("%lu\n", fatorial);

        printf("Digite um número inteiro.\n");
        scanf("%d", &num);
    }
}

//15. Faça um programa que permita entrar com a idade de várias pessoas e
//    imprima:
//    • total de pessoas com menos de 21 anos
//    • total de pessoas com mais de 50 anos

void q15()
{
    int i, novos = 0, velhos = 0, idade, quant;

    printf("Digite a quantidade de pessoas.\n");
    scanf("%d", &quant);

    for(i = 0; i < quant; i ++)
    {
        printf("Digite sua idade.\n");
        scanf("%d", &idade);

        if(i < 21)
            novos ++;
        else if(i > 50)
            velhos ++;
    }

    printf("Total de pessoas com menos de 21 anos: %d\n", novos);
    printf("Total de pessoas com mais de 50 anos: %d\n", velhos);
}

//16. Sabendo-se que a unidade lógica e aritmética calcula a divisão por meio de subtrações
//    sucessivas, criar um algoritmo que calcule e imprima o resto da divisão de
//    números inteiros lidos. Para isso, basta subtrair o divisor ao dividendo, sucessivamente,
//    até que o resultado seja menor do que o divisor. O número de subtrações
//    realizadas corresponde ao quociente inteiro e o valor restante da subtração corresponde
//    ao resto. Suponha que os números lidos sejam positivos e que o dividendo
//    seja maior do que o divisor.

void q16()
{
    int a, b, cont = 0;

    printf("Digite dois números inteiros positivos, em ordem decrescente.\n");
    scanf("%d", &a);
    scanf("%d", &b);

    while(a > b)
    {
        a -= b;

        cont ++;
    }

    printf("Quociente: %d\n", cont);
    printf("Resto: %d\n", a);
}

//17. Crie um programa que possa ler um conjunto de pedidos de compra e
//    calcule o valor total da compra. Cada pedido é composto pelos seguintes campos:
//    • número de pedido
//    • data do pedido (dia, mês, ano)
//    • preço unitário
//    • quantidade
//    O programa deverá processar novos pedidos até que o usuário digite 0 (zero)
//    como número do pedido.

void q17()
{
    char data[10];
    float preco, precototal = 0;
    int quant, num;

    printf("Digite o número do pedido.\n");
    scanf("%d", &num);

    while(num != 0)
    {
        printf("Digite a data, o preço unitário e a quantidade desejada.\n");
        scanf(" %10[^\n]", data);
        scanf("%f", &preco);
        scanf("%d", &quant);

        precototal += (preco * quant);

        printf("Digite o número do pedido.\n");
        scanf("%d", &num);
    }

    printf("Valor total: R$%.2f\n", precototal);
}

//18. Uma pousada estipulou o preço para a diária em R$30,00 e mais uma taxa de
//    serviços diários de:
//    • R$15,00, se o número de dias for menor que 10;
//    • R$8,00, se o número de dias for maior ou igual a 10;
//    Faça um programa que imprima o nome, a conta e o número da conta de cada
//    cliente e ao final o total faturado pela pousada.
//    O programa deverá ler novos clientes até que o usuário digite 0 (zero) como
//    número da conta.

void q18()
{
    char nome[99];
    int num, preco, dias, total = 0;

    printf("Digite o número da sua conta.\n");
    scanf("%d", &num);

    while(num != 0)
    {
        printf("Digite seu nome e a quantidade de diárias.\n");
        scanf(" %99[^\n]", nome);
        scanf("%d", &dias);

        preco = dias * 30;

        if(dias < 10)
            preco += 15 * dias;
        else if(dias >= 10)
            preco += 8 * dias;

        total += preco;

        printf("Nome: %s\n", nome);
        printf("Número da conta: %d\n", num);
        printf("Valor: R$%d.00\n", preco);

        printf("Digite o número da sua conta.\n");
        scanf("%d", &num);
    }

    printf("Total faturado pela pousada: R$%d.00\n", total);
}

//19. Em uma Universidade, os alunos das turmas de informática fizeram uma prova
//    de algoritmos. Cada turma possui um número de alunos. Criar um programa que
//    imprima:
//    • quantidade de alunos aprovados;
//    • média de cada turma;
//    • percentual de reprovados.
//    Obs.: Considere aprovado com nota >= 7.0

void q19()
{
    int turmas, alunos, i, j, aprovados = 0, reprovados = 0;
    float nota, totalalunos = 0;

    printf("Digite o número de turmas.\n");
    scanf("%d", &turmas);

    float media[turmas];

    for(i = 0; i < turmas; i ++)
    {
        media[i] = 0;

        printf("Digite o número de alunos na turma %d.\n", i + 1);
        scanf("%d", &alunos);

        totalalunos += alunos;

        for(j = 0; j < alunos; j ++)
        {
            printf("Digite a nota do aluno %d.\n", j + 1);
            scanf("%f", &nota);

            media[i] += nota / alunos;

            if(nota >=7)
                aprovados ++;
            else
                reprovados ++;
        }
    }

    printf("Quantidade de alunos aprovados: %d\n", aprovados);
    for(i = 0; i < turmas; i ++)
        printf("Média da turma %d: %.2f\n", i + 1, media[i]);
    printf("Percentual de alunos reprovados: %.2f%%\n", (reprovados / totalalunos) * 100);
}

//20. Uma pesquisa de opinião realizada no Rio de Janeiro, teve as seguintes perguntas:
//    • Qual o seu time de coração?
//    1 - Fluminense;
//    2 - Botafogo;
//    3 - Vasco;
//    4 - Flamengo;
//    5 - Outros
//    • Onde você mora?
//    1 - RJ;
//    2 - Niterói;
//    3 - Outros
//    • Qual o seu salário?
//    Faça um programa que imprima:
//    • o número de torcedores por clube;
//    • a média salarial dos torcedores do Botafogo;
//    • o número de pessoas moradoras do Rio de Janeiro, torcedores de outros clubes;
//    • o número de pessoas de Niterói torcedoras do Fluminense
//    Obs.: O programa encerra quando se digita 0 para o time.

void q20()
{
    int time, endereco, contflu = 0, contbot = 0, contvas = 0, contfla = 0, contoutro = 0, contnitflu = 0;
    float salario, somasalariobot;

    printf("Qual o seu time de coração?\n");
    printf("1 - Fluminense, 2 - Botafogo, 3 - Vasco, 4 - Flamengo, 5 - Outro\n");
    scanf("%d", &time);

    while(time != 0)
    {
        if(time < 1 || time > 5)
        {
            printf("Opção inválida.\n");

            printf("Qual o seu time de coração?\n");
            printf("1 - Fluminense, 2 - Botafogo, 3 - Vasco, 4 - Flamengo, 5 - Outro\n");
            scanf("%d", &time);

            continue;
        }

        printf("Onde você mora?\n");
        printf("1 - Rio de Janeiro, 2 - Niterói, 3 - Outro\n");
        scanf("%d", &endereco);

        printf("Qual o seu salário?\n");
        scanf("%f", &salario);

        switch(time)
        {
            case 1:
                contflu ++;
                if(endereco == 2)
                    contnitflu ++;
                break;
            case 2:
                contbot ++;
                somasalariobot += salario;
                break;
            case 3:
                contvas ++;
                break;
            case 4:
                contfla ++;
                break;
            case 5:
                if(endereco == 1)
                    contoutro ++;
                break;
        }

        printf("Qual o seu time de coração?\n");
        printf("1 - Fluminense, 2 - Botafogo, 3 - Vasco, 4 - Flamengo, 5 - Outro\n");
        scanf("%d", &time);
    }

    printf("Quantidade de torcedores do Fluminense: %d\n", contflu);
    printf("Quantidade de torcedores do Botafogo: %d\n", contbot);
    printf("Quantidade de torcedores do Vasco: %d\n", contvas);
    printf("Quantidade de torcedores do Flamengo: %d\n", contfla);
    if(contbot == 0)
        printf("Não há dados suficientes para calcular a média salarial dos torcedores do Botafogo.\n");
    else
        printf("Média salarial dos torcedores do Botafogo: R$%.2f\n", somasalariobot / contbot);
    printf("Quantidade de pessoas que moram no Rio de Janeiro e torcem para outros clubes: %d\n", contoutro);
    printf("Quantidade de pessoas que moram em Niterói e torcem para o Fluminense: %d\n", contnitflu);
}

//21. Em uma universidade cada aluno possui os seguintes dados:
//    • Renda pessoal;
//    • Renda familiar;
//    • Total gasto com alimentação;
//    • Total gasto com outras despesas;
//    Faça um programa que imprima a porcentagem dos alunos que gasta acima de
//    R$200,00 com outras despesas. O número de alunos com renda pessoal maior
//    que a renda familiar e a porcentagem gasta com alimentação e outras despesas
//    em relação às rendas pessoal e familiar.
//    Obs.: O programa encerra quando se digita 0 para a renda pessoal.

void q21()
{
    float rp, rf, ga, go, contgeral = 0;
    int contgo = 0, contrico = 0;

    printf("Digite sua renda pessoal.\n");
    scanf("%f", &rp);

    while(rp != 0)
    {
        printf("Digite sua renda familiar, o total gasto com alimentação e o total gasto com outras despesas.\n");
        scanf("%f", &rf);
        scanf("%f", &ga);
        scanf("%f", &go);

        if(go > 200)
            contgo ++;
        
        if(rp > rf)
            contrico ++;

        contgeral ++;

        printf("Percentual de gastos do aluno %.0f: %.2f%%", contgeral, ((ga + go) / (rf + rp)) * 100);

        printf("Digite sua renda pessoal.\n");
        scanf("%f", &rp);
    }

    printf("Percentual de alunos que gastam acima de R$200.00 com outras despesas: %.2f%%\n", (contgo / contgeral) * 100);
    printf("Número de alunos com renda pessoal maior do que a renda familiar: %d\n", contrico);
}

//22. Crie um programa que ajude o DETRAN a saber o total de recursos que foram
//    arrecadados com a aplicação de multas de trânsito.
//    O algoritmo deve ler as seguintes informações para cada motorista:
//    • número da carteira de motorista (de 1 a 4327);
//    • número de multas;
//    • valor de cada uma das multas.
//    Deve ser impresso o valor da dívida para cada motorista e ao final da leitura o
//    total de recursos arrecadados (somatório de todas as multas). O programa deverá
//    imprimir tambémo número da carteira do motorista que obteve o maior número
//    de multas.
//    Obs.: O programa encerra ao ler a carteira de motorista de valor 0.

void q22()
{
    int num, quant, i;
    float somageral = 0, soma, valor;

    printf("Digite o número da carteira de motorista.\n");
    scanf("%d", &num);

    while(num != 0)
    {
        printf("Digite o número de multas.\n");
        scanf("%d", &quant);

        soma = 0;

        for(i = 0; i < quant; i ++)
        {
            printf("Digite o valor da multa %d.\n", i + 1);
            scanf("%f", &valor);

            soma += valor;
        }

        printf("Dívida do motorista %d: R$%.2f\n", num, soma);

        somageral += soma;

        printf("Digite o número da carteira de motorista.\n");
        scanf("%d", &num);
    }

    printf("Total de recursos arrecadados: R$%.2f\n", somageral);
}

//23. Crie um programa que leia um conjunto de informações (nome, sexo, idade, peso
//    e altura) dos atletas que participaram de uma olimpíada, e informar:
//    • a atleta do sexo feminino mais alta;
//    • o atleta do sexo masculino mais pesado;
//    • a média de idade dos atletas.
//    Obs.: Deverão se lidos dados dos atletas até que seja digitado o nome @ para um
//    atleta.
//    Para resolver este exercício, consulte a aula 7 que aborda o tratamento de strings,
//    como comparação e atribuição de textos.

void q23()
{
    char nome[99], mulheralta[99], homempesado[99];
    int sexo, idade, contador = 0;
    float peso, altura, somaidade = 0, maioralturamulher = -1, maiorpesohomem = -1;

    printf("Digite o nome do atleta.\n");
    scanf(" %99[^\n]", nome);

    while(nome[0] != '@')
    {
        printf("Digite o gênero do atleta.\n");
        printf("0 - Feminino, 1 - Masculino.\n");
        scanf("%d", &sexo);
        printf("Digite a idade, a altura e o peso do atleta.\n");
        scanf("%d", &idade);
        scanf("%f", &altura);
        scanf("%f", &peso);

        if(sexo == 0 && altura > maioralturamulher)
        {   
            maioralturamulher = altura;
            strcpy(mulheralta, nome);
        }

        if(sexo == 1 && peso > maiorpesohomem)
        {   
            maiorpesohomem = peso;
            strcpy(homempesado, nome);
        }

        somaidade += idade;
        contador++;

        printf("Digite o nome do atleta.\n");
        scanf(" %99[^\n]", nome);
    }

    printf("Atleta do sexo feminino mais alta: %s\n", mulheralta);
    printf("Atleta do sexo masculino mais pesado: %s\n", homempesado);
    printf("Média de idade dos atletas: %.2f\n", somaidade / contador);
}

//24. Faça um programa que calcule quantos litros de gasolina são usados em uma
//    viagem, sabendo que um carro faz 10 km/litro. O usuário fornecerá a velocidade
//    do carro e o período de tempo que viaja nesta velocidade para cada trecho do
//    percurso. Então, usando as fórmulas distância = tempo x velocidade e litros
//    consumidos = distância / 10, o programa computará, para todos os valores não negativos
//    de velocidade, os litros de combustível consumidos. O programa deverá
//    imprimir a distância e o número de litros de combustível gastos naquele trecho.
//    Deverá imprimir também o total de litros gastos na viagem. O programa encerra
//    quando o usuário informar um valor negativo de velocidade.

void q24()
{
    float velocidade, distancia = 0, tempo;

    printf("Digite a velocidade (km/h).\n");
    scanf("%f", &velocidade);

    while(velocidade >= 0)
    {
        printf("Digite quanto tempo permaneceu na velocidade digitada (h).\n");
        scanf("%f", &tempo);

        distancia += velocidade * tempo;

        printf("Digite a velocidade (km/h).\n");
        scanf("%f", &velocidade);
    }

    printf("Distância percorrida: %.2fkm\n", distancia);
    printf("Consumo de combustível: %.2fL\n", distancia / 10);
}

//25. Faça um programa que calcule o imposto de renda de um grupo de contribuintes,
//    considerando que:
//    a) os dados de cada contribuinte (CIC, número de dependentes e renda bruta
//    anual) serão fornecidos pelo usuário via teclado;
//    b) para cada contribuinte será feito um abatimento de R$600 por dependente;
//    c) a renda líquida é obtida diminuindo-se o abatimento com os dependentes
//    da renda bruta anual;
//    d) para saber quanto o contribuinte deve pagar de imposto, utiliza-se a tabela
//    a seguir:
//    Renda Líquida         Imposto
//    até R$1000            Isento
//    de R$1001 a R$5000    15%
//    acima de R$5000       25%
//    e) o valor de CIC igual a zero indica final de dados;
//    f) o programa deverá imprimir, para cada contribuinte, o número do CIC e o
//    imposto a ser pago;
//    g) ao final o programa deverá imprimir o total do imposto arrecadado pela
//    Receita Federal e o número de contribuintes isentos;
//    h) leve em consideração o fato de o primeiro CIC informado poder ser zero.

void q25()
{
    int cic, dependentes, i, contisento = 0;
    float renda, imposto, somaimposto = 0;

    printf("Digite o seu CIC.\n");
    scanf("%d", &cic);

    while(cic != 0)
    {
        printf("Digite o número de dependentes e a renda bruta anual.\n");
        scanf("%d", &dependentes);
        scanf("%f", &renda);

        for(i = 0; i < dependentes; i ++)
        {
            renda -= 600;
        }

        if(renda <= 1000)
        {
            imposto = 0;
            contisento ++;
        }
        else if(renda > 1000 && renda <= 5000)
            imposto = renda * 0.15;
        else if(renda > 5000)
            imposto = renda * 0.25;

        somaimposto += imposto;

        printf("Número do CIC: %d\n", cic);

        if(imposto == 0)
        printf("Isento.\n");
        else
        printf("Imposto a ser pago: R$%.2f\n", imposto);

        printf("Digite o seu CIC.\n");
        scanf("%d", &cic);
    }

    printf("Total de imposto arrecadado pela Receita Federal: R$%.2f\n", somaimposto);
    printf("Quantidade de contribuintes isentos: %d\n", contisento);
}

//26. Foi feita uma pesquisa de audiência de canal de TV em várias casas de uma
//    certa cidade, em um determinado dia. Para cada casa visitada foram fornecidos o
//    número do canal (4, 5, 7, 12) e o número de pessoas que estavam assistindo a ele
//    naquela casa. Se a televisão estivesse desligada, nada seria anotado, ou seja, esta
//    casa não entraria na pesquisa. Criar um programa que:
//    • Leia um número indeterminado de dados, isto é, o número do canal e o
//    número de pessoas que estavam assistindo;
//    • Calcule e imprima a porcentagem de audiência em cada canal.
//    Obs.: Para encerrar a entrada de dados, digite o número do canal zero.

void q26()
{
    int canal, cont4 = 0, cont5 = 0, cont7 = 0, cont12 = 0, audiencia;
    float contgeral = 0;

    printf("Digite o canal que está sendo assistido.\n");
    scanf("%d", &canal);

    while(canal != 0)
    {
        if(canal != 4 && canal != 5 && canal != 7 && canal != 12)
        {
            printf("Opção inválida.\n");

            printf("Digite o canal que está sendo assistido.\n");
            scanf("%d", &canal);

            continue;
        }

        printf("Digite quantas pessoas estão assistindo.\n");
        scanf("%d", &audiencia);

        switch(canal)
        {
            case 4:
                cont4 += audiencia;
                break;
            case 5:
                cont5 += audiencia;
                break;
            case 7:
                cont7 += audiencia;
                break;
            case 12:
                cont12 += audiencia;
                break;
        }

        contgeral += audiencia;

        printf("Digite o canal que está sendo assistido.\n");
        scanf("%d", &canal);
    }

    printf("Percentual de audiência do canal 4: %.2f%%\n", (cont4 / contgeral) * 100);
    printf("Percentual de audiência do canal 5: %.2f%%\n", (cont5 / contgeral) * 100);
    printf("Percentual de audiência do canal 7: %.2f%%\n", (cont7 / contgeral) * 100);
    printf("Percentual de audiência do canal 12: %.2f%%\n", (cont12 / contgeral) * 100);
}

//27. Crie um programa que calcule e imprima o CR do período para os alunos de
//    computação. Para cada aluno, o algoritmo deverá ler:
//    • número da matrícula;
//    • quantidade de disciplinas cursadas;
//    • notas em cada disciplina;
//    Além do CR de cada aluno, o programa deve imprimir o melhor CR dos
//    alunos que cursaram 5 ou mais disciplinas.
//    • o fim da entrada de dados é marcada por uma matrícula inválida (matrículas
//    válidas de 1 a 5000);
//    • CR do aluno é igual à média aritmética de suas notas.

void q27()
{
    int matricula, disciplinas, i;
    float nota, somanota, cr, melhorcr = -1;

    printf("Digite o número da matrícula.\n");
    scanf("%d", &matricula);

    while(matricula >= 1 && matricula <=5000)
    {
        printf("Digite a quantidade de disciplinas cursadas.\n");
        scanf("%d", &disciplinas);

        somanota = 0;

        for(i = 0; i < disciplinas; i ++)
        {
            printf("Digite a nota da disciplina %d.\n", i + 1);
            scanf("%f", &nota);

            somanota += nota;
        }

        cr = somanota / disciplinas;

        printf("CR: %.2f\n", cr);

        if(disciplinas >= 5 && cr > melhorcr)
            melhorcr = cr;

        printf("Digite o número da matrícula.\n");
        scanf("%d", &matricula);
    }

    if(cr == -1)
        printf("Nenhum aluno cursou 5 ou mais disciplinas.\n");
    else
        printf("Melhor CR dos alunos que cursaram 5 ou mais disciplinas: %.2f\n", melhorcr);
}

//28. Construa um programa que receba a idade, a altura e o peso de várias pessoas,
//    Calcule e imprima:
//    • a quantidade de pessoas com idade superior a 50 anos;
//    • a média das alturas das pessoas com idade entre 10 e 20 anos;
//    • a porcentagem de pessoas com peso inferior a 40 quilos, dentre todas as
//    pessoas analisadas.

void q28()
{
    int i, idade, quant, contmais50 = 0, contmid = 0, contleve = 0;
    float altura, peso, somaalturamid = 0, contgeral = 0;

    printf("Digite a quantidade de pessoas.\n");
    scanf("%d", &quant);

    for(i = 0; i < quant; i ++)
    {
        printf("Digite sua idade, altura e peso.\n");
        scanf("%d", &idade);
        scanf("%f", &altura);
        scanf("%f", &peso);

        if(idade > 50)
            contmais50 ++;
        if(idade >= 10 && idade <= 20)
        {
            somaalturamid += altura;
            contmid ++;
        }
        if(peso < 40)
            contleve ++;

        contgeral ++;
    }

    printf("Quantidade de pessoas com idade superior a 50 anos: %d\n", contmais50);
    printf("Média das alturas das pessoas com idade entre 10 e 20 anos: %.2f\n", somaalturamid / contmid);
    printf("Percentual de pessoas com peso inferior a 40 quilos: %.2f%%\n", (contleve / contgeral) * 100);
}

//29. Construa um programa que receba o valor e o código de várias mercadorias
//    vendidas em um determinado dia. Os códigos obedecem a lista a seguir:
//    L - limpeza
//    A - Alimentação
//    H - Higiene
//    Calcule e imprima:
//    • o total vendido naquele dia, com todos os códigos juntos;
//    • o total vendido naquele dia em cada um dos códigos.
//    Obs.: Para encerrar a entrada de dados, digite o valor da mercadoria zero.

void q29()
{
    char cod;
    float preco, totalgeral = 0, totall = 0, totala = 0, totalh = 0;

    printf("Digite o código da mercadoria.\n");
    printf("L - Limpeza, A - Alimentação, H - Higiene.\n");
    scanf(" %c", &cod);

    while(cod != '0')
    {
        if(cod != 'L' && cod != 'A'  && cod != 'H')
        {
            printf("Opção inválida.\n");

            printf("Digite o código da mercadoria.\n");
            printf("L - Limpeza, A - Alimentação, H - Higiene.\n");
            scanf(" %c", &cod);

            continue;
        }

        printf("Digite o preço da mercadoria.\n");
        scanf("%f", &preco);

        totalgeral += preco;

        switch(cod)
        {
            case 'L':
                totall += preco;
                break;
            case 'A':
                totala += preco;
                break;
            case 'H':
                totalh += preco;
                break;
        }

        printf("Digite o código da mercadoria.\n");
        printf("L - Limpeza, A - Alimentação, H - Higiene.\n");
        scanf(" %c", &cod);
    }

    printf("Total vendido: R$%.2f\n", totalgeral);
    printf("Total vendido em limpeza: R$%.2f\n", totall);
    printf("Total vendido em alimentação: R$%.2f\n", totala);
    printf("Total vendido em higiene: R$%.2f\n", totalh);
}

//30. Faça um programa que receba a idade e o estado civil (C - casado, S - solteiro, V - viúvo
//    e D - desquitado ou separado) de várias pessoas. Calcule e imprima:
//    • a quantidade de pessoas casadas;
//    • a quantidade de pessoas solteiras;
//    • a média das idades das pessoas viúvas;
//    • a porcentagem de pessoas desquitadas ou separadas dentre todas as pessoas
//    analisadas.
//    Obs.: Para encerrar a entrada de dados, digite um número menor que zero para a
//    idade.

void q30()
{
    int idade, contcasado = 0, contsolteiro = 0, contseparado = 0, contviuvo = 0;
    float somaidadeviuvo = 0, contgeral = 0;
    char ec;

    printf("Digite sua idade.\n");
    scanf("%d", &idade);

    while(idade >= 0)
    {
        printf("Digite seu estado civil.\n");
        printf("C - Casado, S - Solteiro, V - Viúvo, D - Desquitado ou separado.\n");
        scanf(" %c", &ec);

        switch(ec)
        {
            case 'C':
                contcasado ++;
                break;
            case 'S':
                contsolteiro ++;
                break;
            case 'V':
                contviuvo ++;
                somaidadeviuvo += idade;
                break;
            case 'D':
                contseparado ++;
                break;
        }

        contgeral ++;

        printf("Digite sua idade.\n");
        scanf("%d", &idade);
    }

    printf("Quantidade de pessoas casadas: %d\n", contcasado);
    printf("Quantidade de pessoas solteiras: %d\n", contsolteiro);
    printf("Média das idades as pessoas viúvas: %.2f\n", somaidadeviuvo / contviuvo);
    printf("Percentual de pessoas desquitadas ou separadas: %.2f%%\n", (contseparado / contgeral) * 100);
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
        case 25:
    	    q25();
    	    break;
        case 26:
    	    q26();
    	    break;
        case 27:
    	    q27();
    	    break;
        case 28:
    	    q28();
    	    break;
        case 29:
    	    q29();
    	    break;
        case 30:
    	    q30();
    	    break;
        default:
    	    printf("Opção inválida.\n");
    }
    
    return 0;
}