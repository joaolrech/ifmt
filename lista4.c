#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1. Faça um programa em C que armazene 15 números inteiros em um vetor e depois
//   permita que o usuário digite um número inteiro para ser buscado no vetor, se
//   for encontrado o programa deve imprimir a posição desse número no vetor, caso
//   contrário, deve imprimir a mensagem: "Não encontrado.".

void q01()
{
    int x[15], i, num, pos = 0;

    for(i = 0; i < 15; i ++)
    {
        printf("Digite o número da posição %d.\n", i + 1);
        scanf("%d", &x[i]);
    }

    printf("Digite o número a ser encontrado.\n");
    scanf("%d", &num);

    for(i = 0; i < 15; i ++)
        if(num == x[i])
            pos = i;

    if(pos == 0)
        printf("Não encontrado.\n");
    else
        printf("Posição do número %d: %d\n", num, pos);
}
    
//2. Faça um programa que armazene 10 letras em um vetor e imprima uma listagem
//   numerada.

void q02()
{
    char x[10];
    int i;

    for(i = 0; i < 10; i ++)
    {
        printf("Digite a letra da posição %d.\n", i + 1);
        scanf(" %c", &x[i]);
    }

    for(i = 0; i < 10; i ++)
        printf("Letra da posição %d: %c\n", i + 1, x[i]);
}

//3. Construa uma programa em C que armazene 15 números em um vetor e imprima
//   uma listagem numerada contendo o número e uma das mensagens: par ou ímpar.

void q03()
{
    int i, x[10];

    for(i = 0; i < 10; i ++)
    {
        printf("Digite o número da posição %d.\n", i + 1);
        scanf("%d", &x[i]);
    }

    for(i = 0; i < 10; i ++)
    {
        printf("Número da posição %d: %d", i + 1, x[i]);

        if(x[i] % 2 == 0)
            printf(" (par)\n");
        else
            printf(" (ímpar)\n");
    }
}

//4. Faça um programa que armazene 8 números em um vetor e imprima todos os
//   números. Ao final, imprima o total de números múltiplos de seis.

void q04()
{
    int i, x[8], cont = 0;

    for(i = 0; i < 8; i ++)
    {
        printf("Digite o número da posição %d.\n", i + 1);
        scanf("%d", &x[i]);

        if(x[i] % 6 == 0)
            cont ++;
    }

    for(i = 0; i < 8; i ++)
        printf("Número da posição %d: %d\n", i + 1, x[i]);

    printf("Quantidade de números múltiplos de 6: %d\n", cont);
}

//5. Faça um programa que armazene as notas das provas 1 e 2 de 15 alunos. Calcule
//   e armazene a média arredondada. Armazene também a situação do aluno: 1 -
//   Aprovado ou 2 - Reprovado. Ao final o programa deve imprimir uma listagem
//   contendo as notas, a média e a situação de cada aluno em formato tabulado.
//   Utilize quantos vetores forem necessários para armazenar os dados.

void q05()
{
    float n1[15], n2[15], media[15];
    int i, situacao[15];

    for(i = 0; i < 15; i ++)
    {
        printf("Digite a nota da prova 1 e a nota da prova 2 do aluno %d.\n", i + 1);
        scanf("%f", &n1[i]);
        scanf("%f", &n2[i]);

        media[i] = ((n1[i] + n2[i]) / 2);

        if(media[i] >= 6)
            situacao[i] = 1;
        else
            situacao[i] = 2;
    }

    printf("Aluno    Prova 1    Prova 2    Média    Situação\n");

    for(i = 0; i < 15; i ++)
    {
        printf("%-8d %-10.2f %-10.2f %-9.2f", i + 1, n1[i], n2[i], media[i]);

        if(situacao[i] == 1)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");
    }
}

//6. Construa um programa que permita armazenar o salário de 20 pessoas. Calcular
//   e armazenar o novo salário sabendo-se que o reajuste foi de 8%. Imprimir uma
//   listagem numerada com o salário e o novo salário. Declare quantos vetores forem
//   necessários.

void q06()
{
    float salario[20], novosalario[20];
    int i;

    for(i = 0; i < 20; i ++)
    {
        printf("Digite o salário do trabalhador %d.\n", i + 1);
        scanf("%f", &salario[i]);

        novosalario[i] = salario[i] * 1.08;
    }

    printf("Trabalhador    Salário Antigo    Salário Novo\n");

    for(i = 0; i < 20; i ++)
        printf("%-14d %-17.2f %-13.2f\n", i + 1, salario[i], novosalario[i]);
}

//7. Crie um programa que leia o preço de compra e o preço de venda de 100 mercadorias
//   (utilize vetores). Ao final, o programa deverá imprimir quantas mercadorias
//   proporcionam:
//   • lucro < 10%
//   • 10% <= lucro <= 20%
//   • lucro > 20%

void q07()
{
    int i, cont1 = 0, cont2 = 0, cont3 = 0;
    float pc[100], pv[100];

    for(i = 0; i < 100; i ++)
    {
        printf("Digite o preço de compra e o preço de venda da mercadoria %d.\n", i + 1);
        scanf("%f", &pc[i]);
        scanf("%f", &pv[i]);

        if(pv[i] < pc[i] * 1.1)
            cont1 ++;
        if(pv[i] >= pc[i] * 1.1 && pv[i] <= pc[i] * 1.2)
            cont2 ++;
        if(pv[i] > pc[i] * 1.2)
            cont3 ++;
    }

    printf("Quantidade de mercadorias que proporcionam menos de 10%% de lucro: %d\n", cont1);
    printf("Quantidade de mercadorias que proporcionam entre 10%% e 20%% de lucro: %d\n", cont2);
    printf("Quantidade de mercadorias que proporcionam mais de 20%% de lucro: %d\n", cont3);
}

//8. Construa um programa que armazene o código, a quantidade, o valor de compra
//   e o valor de venda de 30 produtos. A listagem pode ser de todos os produtos ou
//   somente de um ao se digitar o código.

void q08()
{
    int cod[30], quant[30], i;
    float vc[30], vv[30];

    for(i = 0; i < 30; i ++)
    {
        printf("Digite o código, a quantidade, o valor de compra e o valor de venda do produto.\n");
        scanf("%d", &cod[i]);
        scanf("%d", &quant[i]);
        scanf("%f", &vc[i]);
        scanf("%f", &vv[i]);
    }

    printf("Código    Quantidade    Valor de Compra    Valor de Venda\n");

    for(i = 0; i < 30; i ++)
        printf("%-10d %-13d R$%-17.2f R$%-14.2f\n", cod[i], quant[i], vc[i], vv[i]);
}

//9. Faça um programa em C que leia dois conjuntos de números inteiros, tendo
//   cada um 10 elementos. Ao final o programa deve listar os elementos comuns aos
//   conjuntos.

void q09()
{
    int i, j, c1[10], c2[10];

    for(i = 0; i < 10; i ++)
    {
        printf("Digite o número %d do conjunto 1.\n", i + 1);
        scanf("%d", &c1[i]);
        printf("Digite o número %d do conjunto 2.\n", i + 1);
        scanf("%d", &c2[i]);
    }

    printf("Elementos comuns aos dois conjuntos:\n");

    for(i = 0; i < 10; i ++)
        for(j = 0; j < 10; j ++)
        {
            if(c1[i] == c2[j])
            printf("%d\n", c2[j]);
        }
}

//10. Faça um programa que leia um vetor vet de 10 elementos e obtenha um vetor w
//    cujos componentes são os fatoriais dos respectivos componentes de vet.

void q10()
{
    int w[10], vet[10], i, j;

    for(i = 0; i < 10; i ++)
    {
        printf("Digite o elemento %d do vetor.\n", i + 1);
        scanf("%d", &vet[i]);

        w[i] = 1;

        for(j = 1; j <= vet[i]; j ++)
            w[i] *= j;
    }

    printf("Vetor w:\n");

    for(i = 0; i < 10; i++)
        printf("%d\n", w[i]);
}

//11. Construa um programa que leia dados para um vetor de 100 elementos inteiros.
//    Imprimir o maior e o menor, sem ordenar, o percentual de números pares e a
//    média dos elementos do vetor.

void q11()
{
    int i, vet[100], maior, menor, soma = 0, pares = 0;

    for(i = 0; i < 100; i ++)
    {
        printf("Digite o valor do elemento %d.\n", i + 1);
        scanf("%d", &vet[i]);

        if(i == 0)
            maior = menor = vet[i];
        else
        {
            if(vet[i] > maior)
                maior = vet[i];
            if(vet[i] < menor)
                menor = vet[i];
            if(vet[i] % 2 == 0)
                pares ++;
        }

        soma += vet[i];
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Percentual de números pares: %.2f%%\n", (pares / 100.0) * 100);
    printf("Média: %.2f\n", soma / 100.0);
}

//12. Crie um programa para gerenciar um sistema de reservas de mesas em uma casa
//    de espetáculo. A casa possui 30 mesas de 5 lugares cada. O programa deverá
//    permitir que o usuário escolha o código de uma mesa (100 a 129) e forneça a
//    quantidade de lugares desejados. O programa deverá informar se foi possível
//    realizar a reserva e atualizar a reserva. Se não for possível, o programa deverá
//    emitir uma mensagem. O programa deve terminar quando o usuário digitar
//    o código 0 (zero) para uma mesa ou quando todos os 150 lugares estiverem
//    ocupados.

void q12()
{
    int mesa[30], num, quant, i, j, soma;

    for(i = 0; i < 30; i ++)
        mesa[i] = 0;

    while(1)
    {
        printf("Escolha o número da sua mesa (100 a 129) e a quantidade de lugares.\n");
        scanf("%d", &num);
        scanf("%d", &quant);

        if(num == 0)
            break;

        if (num < 100 || num > 129)
        {
            printf("Código da mesa inválido.\n");
            continue;
        }

        if(quant < 1)
        {
            printf("Quantidade de lugares inválida.\n");
            continue;
        }

        num -= 100;

        if((mesa[num] + quant) > 5)
            printf("A mesa escolhida não tem essa quantidade de lugares disponíveis.\n");
        else
        {
            mesa[num] += quant;
            printf("Sua reserva foi feita.\n");
        }

        soma = 0;
        for(j = 0; j < 30; j ++)
            soma += mesa[j];
        if(soma == 150)
            break;
    }
}

//13. Construa um programa que realize as reservas de passagens áreas de uma companhia.
//    O programa deve permitir cadastrar o número de 10 voos e definir a
//    quantidade de lugares disponíveis para cada um. Após o cadastro, leia vários
//    pedidos de reserva, constituídos do número da carteira de identidade do cliente e
//    do número do voo desejado. Para cada cliente, verificar se há possibilidade no
//    voo desejado. Em caso afirmativo, imprimir o número da identidade do cliente e
//    o número do voo, atualizando o número de lugares disponíveis. Caso contrário,
//    avisar ao cliente a inexistência de lugares. A leitura do número 0 (zero) para o voo
//    desejado indica o término da leitura de reservas.

void q13()
{
    
}

//14. Faça um programa que armazene 50 números inteiros em um vetor. O programa
//    deve gerar e imprimir um segundo vetor em que cada elemento é o quadrado do
//    elemento do primeiro vetor.

void q14()
{
    int vet1[50], vet2[50], i;

    for(i = 0; i < 50; i ++)
    {
        printf("Digite o número %d\n", i + 1);
        scanf("%d", &vet1[i]);
    }

    for(i = 0; i < 50; i ++)
    {
        vet2[i] = vet1[i] * vet1[i];
        printf("%d\n", vet2[i]);
    }
}

//15. Faça um programa que leia e armazene vários números, até digitar o número 0.
//    Imprimir quantos números iguais ao último número foram lidos. O limite de
//    números é 100.

void q15()
{
    int i, j, num[100], ultimo, quant = 0;

    for(i = 0; i < 100; i ++)
    {
        printf("Digite o número %d\n", i + 1);
        scanf("%d", &num[i]);

        if(num[i] == 0)
            break;

        ultimo = num[i];
    }

    for(j = 0; j < i - 1; j ++)
        if(num[j] == ultimo)
            quant ++;

    printf("Quantidade de números iguais ao último número inserido: %d\n", quant);
}

//16. Crie um programa em C para ler um conjunto de 100 números reais e informe:
//    • quantos números lidos são iguais a 30
//    • quantos são maior que a média
//    • quantos são iguais a média

void q16()
{
    int i, somaigual30 = 0, somamaiormedia = 0, somaigualmedia = 0;
    float num[100], soma = 0, media;

    for(i = 0; i < 100; i ++)
    {
        printf("Digite o número %d\n", i + 1);
        scanf("%f", &num[i]);

        soma += num[i];
    }
    
    media = soma / 100;

    for(i = 0; i < 100; i ++)
    {
        if(num[i] == 30)
            somaigual30 ++;
        if(num[i] > media)
            somamaiormedia ++;
        if(num[i] == media)
            somaigualmedia ++;
    }

    printf("Quantidade de números iguais a 30: %d\n", somaigual30);
    printf("Quantidade de números maiores que a média: %d\n", somamaiormedia);
    printf("Quantidade de números iguais a média: %d\n", somaigualmedia);
}

//17. Faça um programa que leia um conjunto de 30 valores inteiros, armazene-os em
//    um vetor e os imprima ao contrário da ordem de leitura.

void q17()
{
    int i, num[30];

    for(i = 0; i < 30; i ++)
    {
        printf("Digite o número %d\n", i + 1);
        scanf("%d", &num[i]);
    }

    for(i = 29; i >= 0; i --)
        printf("%d\n", num[i]);
}

//18. Faça um programa em C que permita entrar com dados para um vetor VET do tipo
//    inteiro com 20 posições, em que podem existir vários elementos repetidos. Gere
//    um vetor VET2 ordenado a partir do vetor VET e que terá apenas os elementos
//    não repetidos.

void q18()
{
    
}

//19. Suponha dois vetores de 30 elementos cada, contendo: código e telefone. Faça
//    um programa que permita buscar pelo código e imprimir o telefone.

void q19()
{
    int i, cod[30], tel[30], busca;
    srand(time(NULL));

    for(i = 0; i < 30; i ++)
    {
        cod[i] = i + 1;
        tel[i] = 900000000 + rand() % 100000000;
    }

    printf("Digite o código (1 a 30).\n");
    scanf("%d", &busca);

    if(busca < 1 || busca > 30)
        printf("Código inválido.\n");
    else
        for(i = 0; i < 30; i ++)
            if(cod[i] == busca)
                printf("Telefone: %d\n", tel[i]);
}

//20. Faça um programa que leia a matrícula e a média de 100 alunos. Ordene da maior
//    para a menor nota e imprima uma relação contendo todas as matrículas e médias.

void q20()
{
    
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
        default:
    	    printf("Opção inválida.\n");
    }
    
    return 0;
}