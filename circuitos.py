import os
import math
import cmath
import matplotlib.pyplot as plt
import numpy as np

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
            if inpt < 0:
                raise ValueError
            return inpt
        except ValueError:
            print('Entrada inválida. Tente novamente.')

def inptpolar(x):
    while True:
        try:
            modulo = float(input(f'Digite o módulo de {x}: '))
            if modulo < 0:
                raise ValueError
            angulo = float(input(f'Digite o ângulo de {x}: '))
            retangular = cmath.rect(modulo, math.radians(angulo))
            os.system('clear')
            return retangular
        except ValueError:
            print('Entrada inválida. Tente novamente.')

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

# corrigir essa funcao
def zeqparalelo(r, xl, xc):
    yr = 1 / r if r != 0 else 0
    yl = 1 / (1j * xl) if xl != 0 else 0
    yc = 1 / (- 1j * xc) if xc != 0 else 0
    
    if yr == 0 and yl == 0 and yc == 0:
        return 0
    else:
        return 1 / (yr + yl + yc)

def triangulodepotencia():
    plt.figure(figsize = (8, 6))

    plt.plot([0, p], [0, 0], 'b-', label = 'potência Ativa (P)')
    plt.plot([p, p], [0, q], 'r-', label = 'Potência Reativa (Q)')
    plt.plot([0, p], [0, q], 'g--', label = 'Potência Aparente (S)')

    plt.fill([0, p, p], [0, 0, q], color = 'lightgrey', alpha = 0.3)

    plt.text(p / 2, -max(abs(q), abs(p)) * 0.05, f'{p:.2f} W', ha = 'center', va = 'top', color = 'b')
    plt.text(p + max(abs(p), abs(q)) * 0.05, q / 2, f'{q:.2f} VAr', ha = 'left', va = 'center', color = 'r')
    plt.text(p / 2, q / 2, f'{abs(s):.2f} VA', ha = 'center', va ='bottom', color = 'g')

    plt.title('Triângulo de Potências')
    plt.xlabel('Potência Ativa (W)')
    plt.ylabel('Potência Reativa (VAr)')
    plt.axhline(0, color = 'black', linewidth = 0.5)
    plt.axvline(0, color = 'black', linewidth = 0.5)
    plt.grid(True, linestyle = '--', alpha = 0.6)
    plt.legend()
    plt.axis('equal')

    plt.show()

def diagramafasorial():
    plt.figure(figsize = (8, 8))

    plt.quiver(0, 0, v.real, v.imag, angles = 'xy', scale_units = 'xy', scale = 1, color = 'b', label = 'Tensão (V)')
    plt.quiver(0, 0, i.real, i.imag, angles = 'xy', scale_units = 'xy', scale = 1, color = 'r', label = 'Corrente (I)')

    max_val = max(abs(v), abs(i)) * 1.2
    plt.xlim(-max_val, max_val)
    plt.ylim(-max_val, max_val)

    plt.axhline(0, color = 'black', linewidth = 0.8)
    plt.axvline(0, color = 'black', linewidth = 0.8)
    plt.grid(True, linestyle = '--', alpha = 0.6)

    plt.text(v.real * 1.05, v.imag * 1.05, 'V', color = 'b', fontsize = 12)
    plt.text(i.real * 1.05, i.imag * 1.05, 'I', color = 'r', fontsize = 12)

    plt.title('Diagrama Fasorial')
    plt.xlabel('Parte Real')
    plt.ylabel('Parte Imaginária')
    plt.legend()
    plt.gca().set_aspect('equal')

    plt.show()

def onda():
    t = np.linspace(0, 2 / f, 1000)

    onda_v = modulov * np.cos(ω * t + angulov)
    onda_i = moduloi * np.cos(ω * t + anguloi)

    plt.figure(figsize = (10, 6))
    plt.plot(t, onda_v, label = 'Tensão (V)', color = 'b')
    plt.plot(t, onda_i, label = 'Corrente (I)', color = 'r', linestyle = '--')

    plt.title('Forma de Onda no Tempo')
    plt.xlabel('Tempo (s)')
    plt.ylabel('Amplitude')
    plt.grid(True, linestyle = '--', alpha = 0.6)
    plt.legend()
    plt.tight_layout()

    plt.show()

def output():
    print(f'Impedância retangular: {z:.3g} Ω')
    print(f'Impedância polar: {cmath.polar(z)[0]:.3g} ∠ {math.degrees(cmath.polar(z)[1]):.3g}° Ω')
    print()
    print(f'Tensão retangular: {v:.3g} V')
    print(f'Tensão polar: {cmath.polar(v)[0]:.3g} ∠ {math.degrees(cmath.polar(v)[1]):.3g}° V')
    print()
    print(f'Corrente retangular: {i:.3g} A')
    print(f'Corrente polar: {cmath.polar(i)[0]:.3g} ∠ {math.degrees(cmath.polar(i)[1]):.3g}° A')
    print()
    print(f'Velocidade angular: {ω:.3g} rad/s')
    print(f'Defasagem: {math.degrees(φ):.3g}°')
    print(f'Fator de potência: {fp:.3g}')
    print()
    print(f'Potência ativa: {p:.3g} W')
    print(f'Potência reativa: {q:.3g} VAr')
    print(f'Potência aparente: {abs(s):.3g} VAr')
    print()
    print(f'Potência complexa retangular: {s:.3g} VA')
    print(f'Potência complexa polar: {cmath.polar(s)[0]:.3g} ∠ {math.degrees(cmath.polar(s)[1]):.3g}° VA')
    print()

os.system('clear')
print('Bem vindo ao simulador de circuitos CA!\n')

associacao = inptassociacao()

f = inptfloat('F')
r = inptfloat('R')
l = inptfloat('L')
c = inptfloat('C')

ω = 2 * math.pi * f
xl = ω * l
xc = 1 / (ω * c) if c != 0 and ω != 0 else 0

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
φ = ((angulov - anguloi) + math.pi) % (2 * math.pi) - math.pi
fp = math.cos(φ)
s = v * i.conjugate()
p = s.real
q = s.imag

output()
triangulodepotencia()
diagramafasorial()
onda()