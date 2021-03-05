class pais:
    def __init__(self, nome, capital, dimensao = []):
        self.__nome = nome
        self.__capital = capital
        self.__dimesao = dimensao
        self.__fronteira = []
    
    @property
    def nome(self):
        return self.__nome

    @property
    def capital(self):
        return self.__capital

    @property
    def dimensao(self):
        return self.__dimesao
    
    @nome.setter
    def nome(self, novo_nome):
        self.__nome = novo_nome
    
    @capital.setter
    def capital(self, nova_capital):
        self.__capital = nova_capital
    
    def nova_dimensao(self, novo):
        self.__dimesao.append(novo)
    
    def fronteira(self):
        return "As fronteiras são: {}".format(self.__fronteira)
    
    def adicionar_fronteira(self, pais):
        if pais not in self.__fronteira:
            self.__fronteira.append(pais)
    
    def __str__(self):
        return 'Pais: {}\nCapital: {}\nDimensão do pais: {}'.format(self.__nome, self.__capital, self.__dimesao)
    