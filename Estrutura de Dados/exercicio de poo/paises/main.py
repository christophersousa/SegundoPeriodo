from pais import pais

nome = pais('Brasil', 'Brasilia', [1000, 5000])

nome.adicionar_fronteira('Uruguai')
nome.adicionar_fronteira('Chile')
nome.adicionar_fronteira('Agentina')

print(nome)
print(nome.fronteira())