class aluno:
    def __init__(self, matricula, nome, notas =[]):
        self.__matricula = matricula
        self.__nome = nome
        self.__nota = notas 
    
    #Metodos de Acesso
    @property
    def matricula(self):
        return str(self.matricula)
    @property
    def nome(self):
        return self.__nome
    
    #Metodos de Alteração
    @nome.setter
    def nome (self, novo_nome):
        self.__nome = novo_nome
    
    def media(self):
        soma = 0
        for i in range(len(self.__nota)):
            soma += self.__nota[i]
        media = soma / len(self.__nota)
        return media
    
    def adicionar_notas(self, adicionar):
        self.__nota.append(adicionar)
    
    def __str__(self):
        return 'Matricula: {}\nNome: {}\nNotas = {}'.format(self.__matricula, self.__nome, self.__nota)
    