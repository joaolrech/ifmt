import os

def soma(x, y):
    pass
    
def subtracao(x, y):
    pass
    
def multiplicacao(x, y):
    pass
    
def divisao(x, y):
    pass
    
def inpt():
    while True:
        try:
            print(
                'Selecione a associação do circuito.\n'
                '1 - R\n'
                '2 - L\n'
                '3 - C\n'
                '4 - R+L\n'
                '5 - R+C\n'
                '6 - L+C\n'
                '7 - R+L+C\n'
                '8 - R//L\n'
                '9 - R//C\n'
                '10 - L//C\n'
                '11 - R//L//C'
            )
            inpt = int(input())
            if inpt < 1 or inpt > 11:
                raise ValueError
            return inpt
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

os.system('clear')
print('Bem vindo ao simulador de circuitos CA!\n')
associacao = inpt()