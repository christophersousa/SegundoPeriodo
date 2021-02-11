class aluno:
    def __init__(self, n, i, m):
        self.nome = n
        self.idade = i
        self.matricula = m

a = aluno('Cris', 20, '20201370024')
print('O nome do aluno:', a.nome)
print('A idade do aluno:', a.idade)
print('A matricula do aluno:', a.matricula)
