class Retangulo:
    def __init__(self, base, altura):
        self.base = base
        self.altura = altura

    def calculando_Area(self):
        return self.base*self.altura

while True:

    b = int(input('\nDigite a Base do Triangulo: '))
    a = int(input('Digite a Altura do Triangulo: '))

    retangulo = Retangulo( b, a)
    print()
    print('*'*25)
    print('\nBase do triangulo:',retangulo.base)
    print('Altura do triangulo:', retangulo.altura)
    print('Área do triangulo:', retangulo.calculando_Area())
    print()
    print('*'*25)
    
    cont = input('\nDeseja continua ? ').upper()
    if cont != 'SIM':
        break
print('FIM!!')
