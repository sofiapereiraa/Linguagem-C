# 🎓 Sistema de Cadastro de Alunos
Projeto desenvolvido em linguagem C para gerenciamento de alunos. O sistema permite cadastrar estudantes, listar informações, calcular médias e verificar a situação acadêmica de cada aluno.

---

## 🚀 Funcionalidades
- 👨‍🎓 Cadastro de alunos (Nome, CPF, Turma, Notas de trabalhos e Notas de provas)
-  Listagem de alunos cadastrados
- Geração automática de ID para cada aluno
-  Cálculo da média final
-  Verificação da situação do aluno (Aprovado, Recuperação e Reprovado)
-  Menu interativo
-  Encerramento do programa

---

## 🛠️ Tecnologias Utilizadas
- Linguagem C
- Biblioteca stdio.h
- Biblioteca string.h
  
---

## 📐 Critério de Avaliação
- Trabalhos: (t1 + t2 + t3) / 3
- Provas: (p1 + 2*p2 + 3*p3) / 6
- Média final: (Trabalhos + Provas) / 2

Situação
- ≥ 6 → Aprovado
- 4 a 5,99 → Recuperação
- < 4 → Reprovado

---

## ▶️ Compilação

No terminal:

gcc sistema.c -o sistema

▶️ Execução
./sistema
