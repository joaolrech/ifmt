import os
import math
import cmath

def inptAssociacao():
    while True:
        try:
            print('Selecione a associação do circuito:')
            print()
            print('1 - Série')
            print('2 - Paralelo\n')

            inpt = int(input())

            if inpt < 1 or inpt > 2:
                raise ValueError  

            os.system('clear')
            return inpt

        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def inptFloat(x):
    while True:
        try:
            inpt = float(input(f'Digite o valor de {x} (SI): '))

            if inpt < 0:
                raise ValueError

            return inpt

        except ValueError:
            print('Entrada inválida. Tente novamente.')

def inptPolar(x):
    while True:
        try:
            modulo = float(input(f'Digite o módulo de {x} (RMS): '))

            if modulo < 0:
                raise ValueError

            angulo = float(input(f'Digite o ângulo de {x} (°): '))

            retangular = cmath.rect(modulo, math.radians(angulo))

            os.system('clear')
            return retangular

        except ValueError:
            print('Entrada inválida. Tente novamente.')

def inptFonte():
    while True:
        try:
            print('A fonte é de tensão ou de corrente?')
            print()
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

def inptNovamente():
    while True:
        try:
            print('\nDeseja simular novamente?\n')
            print('1 - Sim')
            print('2 - Não\n')

            inpt = int(input())

            if inpt < 1 or inpt > 2:
                raise ValueError  

            os.system('clear')
            return inpt

        except ValueError:
            os.system('clear')
            print('Entrada inválida. Tente novamente.\n')

def zeqSerie(r, xl, xc):
    return r + 1j * xl - 1j * xc

def zeqParalelo(r, xl, xc):
    yr = 0 if r == 0 else 1 / r

    if l == 0:
        yl = 0
    elif xl == 0:
        yl = float('inf')
    else:
        yl = 1 / (1j * xl)

    yc = 0 if c == 0 or xc == float('inf') else 1 / (-1j * xc)

    return float('inf') if yr + yl + yc == 0 else 1 / (yr + yl + yc)

def output():
    print(f'Impedância retangular: {z:.2f} Ω')
    print(f'Impedância polar: {cmath.polar(z)[0]:.2f} ∠ {math.degrees(cmath.polar(z)[1]):.2f}° Ω')
    print()
    print(f'Tensão retangular: {v:.2f} V')
    print(f'Tensão polar: {cmath.polar(v)[0]:.2f} ∠ {math.degrees(cmath.polar(v)[1]):.2f}° V')
    print()
    print(f'Corrente retangular: {i:.2f} A')
    print(f'Corrente polar: {cmath.polar(i)[0]:.2f} ∠ {math.degrees(cmath.polar(i)[1]):.2f}° A')
    print()
    print(f'Velocidade angular: {ω:.2f} rad/s')
    print(f'Defasagem: {math.degrees(φ):.2f}°')
    if φ > 0:
        print(f'Fator de potência: {fp:.2f} indutivo')
    elif φ < 0:
        print(f'Fator de potência: {fp:.2f} capacitivo')
    else:
        print(f'Fator de potência: {fp:.2f} resistivo')
    print()
    print(f'Potência ativa: {p:.2f} W')
    print(f'Potência reativa: {q:.2f} VAr')
    print(f'Potência aparente: {abs(s):.2f} VAr')
    print()
    print(f'Potência complexa retangular: {s:.2f} VA')
    print(f'Potência complexa polar: {cmath.polar(s)[0]:.2f} ∠ {math.degrees(cmath.polar(s)[1]):.2f}° VA')

os.system('clear')
print('Bem vindo ao simulador de circuitos!\n')

while(True):
    associacao = inptAssociacao()

    f = inptFloat('F')
    r = inptFloat('R')
    l = inptFloat('L')
    c = inptFloat('C')

    ω = 2 * math.pi * f

    xl = ω * l

    if c == 0:
        xc = 0
    elif ω == 0:
        xc = float('inf')
    else:
        xc = 1 / (ω * c)

    if associacao == 1:
        z = zeqSerie(r, xl, xc)
    if associacao == 2:
        z = zeqParalelo(r, xl, xc)

    os.system('clear')
    tipoFonte = inptFonte()
    if tipoFonte == 'V':
        v = inptPolar(tipoFonte)
        i = float('inf') if z == 0 else v / z
    if tipoFonte == 'I':
        i = inptPolar(tipoFonte)
        v = i * z

    moduloV, anguloV = cmath.polar(v)
    moduloI, anguloI = cmath.polar(i)
    φ = ((anguloV - anguloI) + math.pi) % (2 * math.pi) - math.pi
    fp = math.cos(φ)
    s = v * i.conjugate()
    p = s.real
    q = s.imag

    if math.isinf(abs(z)):
        print('Circuito aberto.')
    elif z == 0:
        print('Curto-circuito.')
    else:
        output()

    novamente = inptNovamente()
    if novamente == 2:
        break
