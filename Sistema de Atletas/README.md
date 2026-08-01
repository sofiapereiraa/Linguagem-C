# 🏐 Sistema de Controle de Elenco de Voleibol

Sistema desenvolvido para gerenciamento de atletas de voleibol.

O projeto permite cadastrar, consultar, editar e remover atletas, além de registrar estatísticas por partida e gerar relatórios individuais com médias de desempenho.

Atualmente o projeto está na **versão 1.1**, com melhorias na organização do código e implementação de validações de dados.

---

## 📋 Funcionalidades

- ✅ Cadastro de atletas
- ✅ Listagem de atletas cadastrados
- ✅ Busca de atletas por CPF
- ✅ Edição de informações dos atletas
- ✅ Remoção de atletas
- ✅ Cadastro de estatísticas por partida
- ✅ Geração de relatório individual
- ✅ Cálculo automático das médias de desempenho:
  - Pontos
  - Bloqueios
  - Aces
  - Passes

---

## 📊 Informações registradas

### Dados do atleta:

- ID
- Nome
- CPF
- Idade
- Altura
- Peso
- Posição

### Estatísticas por partida:

- Pontos
- Bloqueios
- Aces
- Passes

O sistema calcula automaticamente as médias de desempenho de cada atleta com base nas estatísticas cadastradas.

---

## 🛠️ Tecnologias e conceitos utilizados

- Linguagem C
- Programação estruturada
- Structs
- Vetores
- Manipulação de strings
- Funções
- Validação de dados
- CRUD completo

---

# 📌 Versões

## 🚀 v1.1 - Validações e refatoração (Atual)

Novidades:

- ✅ Criação de funções separadas para melhor organização do código
- ✅ Validação de nome (sem números e tamanho mínimo)
- ✅ Validação de CPF 
- ✅ Validação de idade
- ✅ Validação de altura
- ✅ Validação de peso
- ✅ Validação da posição do atleta
- ✅ Melhor organização das operações CRUD
- ✅ Correções de bugs relacionados à entrada de dados

---

## 🏁 v1.0 - Primeira versão funcional

- Implementação inicial do sistema
- Cadastro e gerenciamento básico de atletas
- Operações principais de CRUD

---

## ▶️ Como executar

Compile o arquivo utilizando um compilador C, como o GCC.

```bash
gcc atletas.c -o atletas.exe
atletas.exe
```

