import os
import math
import cmath
import numpy as np
import matplotlib.pyplot as plt

def inptassociacao():
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
            modulo = float(input(f'Digite o módulo de {x} (RMS): '))

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

def inptnovamente():
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

def zeqserie(r, xl, xc):
    return r + 1j * xl - 1j * xc

def zeqparalelo(r, xl, xc):
    yr = 0 if r == 0 else 1 / r

    if l == 0:
        yl = 0
    elif xl == 0:
        yl = float('inf')
    else:
        yl = 1 / (1j * xl)

    if c == 0 or xc == float('inf'):
        yc = 0
    else:
        yc = 1 / (-1j * xc)

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

def triangulodepotencia():
    plt.figure(figsize = (8, 6))

    plt.plot([0, p], [0, 0], 'b-', label = 'Potência Ativa (P)')
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

    plt.figure(figsize=(10, 6))

    v_pico = modulov * math.sqrt(2)
    i_pico = moduloi * math.sqrt(2)

    onda_v = v_pico * np.cos(ω * t + angulov)
    plt.plot(t, onda_v, label = 'Tensão (V)', color = 'b')

    onda_i = i_pico * np.cos(ω * t + anguloi)
    plt.plot(t, onda_i, label = 'Corrente (I)', color = 'r', linestyle = '--')

    plt.title('Forma de Onda no Tempo')
    plt.xlabel('Tempo (s)')
    plt.ylabel('Amplitude')
    plt.grid(True, linestyle = '--', alpha = 0.6)
    plt.legend()
    plt.tight_layout()

    plt.show()

os.system('clear')
print('Bem vindo ao simulador de circuitos!\n')

while(True):
    associacao = inptassociacao()

    f = inptfloat('F')
    r = inptfloat('R')
    l = inptfloat('L')
    c = inptfloat('C')

    ω = 2 * math.pi * f

    xl = ω * l

    if c == 0:
        xc = 0
    elif ω == 0:
        xc = float('inf')
    else:
        xc = 1 / (ω * c)

    if associacao == 1:
        z = zeqserie(r, xl, xc)
    if associacao == 2:
        z = zeqparalelo(r, xl, xc)

    os.system('clear')
    tipofonte = inptfonte()
    if tipofonte == 'V':
        v = inptpolar(tipofonte)
        i = float('inf') if z == 0 else v / z
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

    if math.isinf(abs(z)):
        print('Circuito aberto.')
    elif z == 0:
        print('Curto-circuito.')
    else:
        output()

    if ω == 0:
        print("\nCircuito em corrente contínua. Não se aplicam fasores, forma de onda senoidal ou triângulo de potência.")
    elif not (math.isfinite(abs(v)) and math.isfinite(abs(i))):
        print('\nNão é possível exibir os gráficos (valores de tensão ou corrente são infinitos ou inválidos).')
    else:
        triangulodepotencia()
        diagramafasorial()
        onda()

    novamente = inptnovamente()
    if novamente == 2:
        break