# 📚 Projeto de Dicionário em C

Um projeto de dicionário criado em linguagem C que utiliza estruturas de dados como **árvores binárias** e **listas encadeadas** para gerenciar palavras e seus significados. Este repositório é destinado a fornecer um sistema eficiente de armazenamento e consulta de palavras, incluindo funcionalidades de cadastro, busca e listagem de palavras.
## 📋 Índice

- [Sobre o Projeto](#-sobre-o-projeto)
- [Estrutura do Projeto](#-estrutura-do-projeto)
- [Funcionalidades](#-funcionalidades)
- [Como Executar](#-como-executar)
- [Dependências](#-dependências)
- [Contribuição](#-contribuição)
- [Licença](#-licença)
## 📖 Sobre o Projeto

Este projeto foi desenvolvido para explorar conceitos de **estruturas de dados em C**, como:
- Árvore binária para gerenciar palavras de forma hierárquica e facilitar a busca.
- Lista encadeada para armazenar cada palavra com seu respectivo significado.

A implementação foi feita em linguagem C, com foco em otimização e gerenciamento de memória.



## 🗂 Estrutura do Projeto
```bash
📁 dicionario-em-c
├── 📁main
        ├── 📄 main.c # Arquivo principal do projeto 
└── 📄 README.md # Documentação do projeto
└── Estrutura dicionario em C(Visual).pdf #estrutura visual do codigo
```
## ⚙️ Funcionalidades

O projeto implementa as seguintes funcionalidades:

1. **Cadastrar Palavra**: Permite inserir uma nova palavra no dicionário com seu significado.
2. **Buscar Palavra**: Procura uma palavra no dicionário, ignorando maiúsculas/minúsculas.
3. **Remover Palavra**: Exclui uma palavra específica do dicionário.
4. **Listar Palavras**: Exibe todas as palavras cadastradas em ordem alfabética.
5. **Limpeza de Tela**: Função para limpar a tela (compatível com sistemas Windows e Linux).
6. **Sair do Programa**: Encerra a execução do programa.

## 🚀 Como Executar

### Pré-requisitos

- **Compilador C** (GCC, por exemplo)

### Passo a Passo

1. Clone o repositório:
   ```bash
   git clone https://github.com/wallacemt/dicionario-estrutura-de-dados.git

   cd dicionario-estrutura-de-dados
2. Compile o programa:
```bash
    gcc main.c
```
# 📦 Dependências
- strings.h: Para utilizar strcasecmp(), que permite comparação de strings sem considerar maiúsculas e minúsculas.

- stdlib.h: Para alocação de memória dinâmica e manipulação de ponteiros.

- stdio.h: Para operações básicas de entrada e saída.

# 👥 Contribuição
Contribuições são bem-vindas! Siga os passos abaixo para contribuir:

- Faça um Fork do projeto

- Crie uma nova Branch (git checkout -b feature/NovaFuncionalidade)

- Commit suas mudanças (git commit -m 'Adiciona nova funcionalidade')

- Push na Branch (git push origin feature/NovaFuncionalidade)

- Abra um Pull Request

## 📜 Licença
Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para mais detalhes.
### **🌟 Se você gostou desse projeto, deixe uma estrela no repositório para apoiar o desenvolvimento!**