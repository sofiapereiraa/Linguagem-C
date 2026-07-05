# 🏐 Sistema de Controle de Elenco de Voleibol

Sistema desenvolvido em **linguagem C** para gerenciamento de atletas de voleibol.

Este projeto permite cadastrar, consultar, editar e remover atletas, além de registrar estatísticas por partida e gerar relatórios com médias de desempenho.

---

## 📋 Funcionalidades

- Cadastro de atletas
- Listagem de atletas cadastrados
- Busca de atletas por CPF
- Edição de informações dos atletas
- Remoção de atletas
- Cadastro de estatísticas por partida
- Geração de relatório individual
- Cálculo automático das médias de:
  - Pontos
  - Bloqueios
  - Aces
  - Passes

---

## 📊 Informações registradas

Cada atleta possui:

- ID
- Nome
- CPF
- Idade
- Altura
- Peso
- Posição

Para cada partida são registrados:

- Pontos
- Bloqueios
- Aces
- Passes

Ao visualizar o relatório, o sistema calcula automaticamente a média de cada estatística.

---

## 🛠️ Tecnologias utilizadas

- Linguagem C
- Programação estruturada
- Structs
- Vetores
- Manipulação de strings

---

## ▶️ Como executar

Compile o arquivo utilizando um compilador C (GCC).

```bash
gcc atletas.c -o atletas.exe
atletas.exe
```



