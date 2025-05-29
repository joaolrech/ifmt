import os
import math
import cmath

grupor = [1, 4, 5, 7, 8, 9, 11]
grupol = [2, 4, 6, 7, 8, 10, 11]
grupoc = [3, 5, 6, 7, 9, 10, 11]

def inptassociacao():
    while True:
        try:
            print('Selecione a associação do circuito:')
            print('1 - R')
            print('2 - L')
            print('3 - C')
            print('4 - R+L')
            print('5 - R+C')
            print('6 - L+C')
            print('7 - R+L+C')
            print('8 - R//L')
            print('9 - R//C')
            print('10 - L//C')
            print('11 - R//L//C\n')
            inpt = int(input())
            if inpt < 1 or inpt > 11:
                raise ValueError
            os.system('clear')
            return inpt
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def inptfloat(x):
    while True:
        try:
            print(f'Digite o valor de {x} (SI):\n')
            inpt = float(input())
            os.system('clear')
            return inpt
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def inptpolar(x):
    while True:
        try:
            print(f'Digite o módulo e o ângulo de {x}:\n')
            modulo = float(input())
            angulo = float(input())
            retangular = cmath.rect(modulo, math.radians(angulo))
            os.system('clear')
            return retangular
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def inptfonte():
    while True:
        try:
            print('A fonte é de tensão ou de corrente?')
            print('V - Tensão')
            print('I - Corrente\n')
            inpt = input()
            inpt = inpt.upper()
            if inpt not in ['I', 'V']:
                raise ValueError
            os.system('clear')
            return inpt
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

os.system('clear')
print('Bem vindo ao simulador de circuitos CA!\n')

associacao = inptassociacao()

f = inptfloat('F')
w = 2 * math.pi * f

if associacao in grupor:
    r = inptfloat('R')
if associacao in grupol:
    l = inptfloat('L')
    xl = w * l
if associacao in grupoc:
    c = inptfloat('C')
    xc = 1 / (w * c)

match associacao:
    case 1:
        z = r
    case 2:
        z = 1j * xl
    case 3:
        z = - 1j * xc
    case 4:
        z = r + 1j * xl
    case 5:
        z = r - 1j * xc
    case 6:
        z = 1j * xl - 1j * xc
    case 7:
        z = r + 1j * xl - 1j * xc
    case 8:
        z = 1 / (1 / r + 1 / (1j * xl))
    case 9:
        z = 1 / (1 / r + 1 / (- 1j * xc))
    case 10:
        z = 1 / (1 / (1j * xl) + 1 / (- 1j * xc))
    case 11:
        z = 1 / (1 / r + 1 / (1j * xl) + 1 / (- 1j * xc))

tipofonte = inptfonte()
if tipofonte == 'V':
    v = inptpolar(tipofonte)
    i = v / z
if tipofonte == 'I':
    i = inptpolar(tipofonte)
    v = i * z

modulov, angulov = cmath.polar(v)
moduloi, anguloi = cmath.polar(i)
φ = angulov - anguloi
fp = math.cos(φ)
s = v * i.conjugate()
p = s.real
q = s.imag

print(f'Defasagem: {math.degrees(φ):.3g}°')
print(f'Potência ativa: {p:.3g} W')
print(f'Potência reativa: {q:.3g} VAr')
print(f'Potência aparente: {s:.3g} VA')
print(f'Fator de potência: {fp:.3g}')
print(f'Impedância: {z:.3g} Ω')
print(f'Tensão: {v:.3g} V')
print(f'Corrente: {i:.3g} A')