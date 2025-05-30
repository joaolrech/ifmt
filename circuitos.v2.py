import os
import math
import cmath

def inptassociacao():
    while True:
        try:
            print('Selecione a associação do circuito:')
            print('S - Série')
            print('P - Paralelo\n')
            inpt = input().upper()
            if inpt not in ['S', 'P']:
                raise ValueError
            os.system('clear')
            return inpt
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def inptfloat(x):
    while True:
        try:
            inpt = float(input(f'Digite o valor de {x} (SI): '))
            return inpt
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def inptpolar(x):
    while True:
        try:
            modulo = float(input(f'Digite o módulo de {x}: '))
            angulo = float(input(f'Digite o ângulo de {x}: '))
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
            inpt = input().upper()
            if inpt not in ['I', 'V']:
                raise ValueError
            os.system('clear')
            return inpt
        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def zeqserie(r, xl, xc):
    return r + 1j * xl - 1j * xc

def zeqparalelo(r, xl, xc):
    yr = 0; yl = 0; yc = 0

    if r != 0:
        yr = 1 / r
    if xl != 0:
        yl  = 1 / (1j * xl)
    if xc != 0:
        yc  = 1 / (1j * xc)
    
    if yr == 0 and yl == 0 and yc == 0:
        return 0
    else:
        return 1 / (yr + yl - yc)

os.system('clear')
print('Bem vindo ao simulador de circuitos CA!\n')

associacao = inptassociacao()

f = inptfloat('F')
r = inptfloat('R')
l = inptfloat('L')
c = inptfloat('C')

ω = 2 * math.pi * f
xl = ω * l
if c != 0 and ω != 0:
    xc = 1 / (ω * c)
else:
    xc = 0

if associacao == 'S':
    z = zeqserie(r, xl, xc)
else:
    z = zeqparalelo(r, xl, xc)

os.system('clear')
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
print(f'Velocidade angular: {ω:.3g} rad/s')