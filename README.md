asa-problem1
===========

Project assignment for the Analysis and Synthesis of Algorithms course 

LEIC-A # 2013/2014
www.tecnico.ulisboa.pt/ 

 The Problem
-
Nowadays there are many ways of sharing information (texts, images, videos, etc..) between people. Some people end up forming groups so that when any member of the group gets something, everyone in the group has access to this information through a sequence of shares.
Suppose that each person has a range of other people with whom he shares the receiving. Your task is classify people into groups for sharing, so that when a group of people gets something, all other will also receive.

 Input
-
The input file must contain information about the shares:

  - A line with the number of people N, and the number of shares P.
  
  - A list of P lines, where each line contains two integers u and v (separated by a blank space) which represent a share. Each line indicates that the person sharing what u get with v.
  
It is assumed that the identification of people and an integer between 1 and N.

 Output
-
The program should write to output the following information: 

  - A line with the number of maximums groups of people who share information; 
  
  - A line with the maximum size of the largest group of people who share information; 
  
  - A line with the number of maximums groups of people who share information only within the group;


Examples
-

- Input 1<br/>

  8 10 <br/>
  1 2 <br/>
  1 3 <br/>
  3 4 <br/>
  4 2 <br/>
  2 1 <br/>
  2 5 <br/>
  5 6 <br/>
  6 7 <br/>
  7 5 <br/>
  4 8 <br/>
  
- Output 1<br/>

  3 <br/>
  4 <br/>
  2 <br/>
  
- Input 2<br/>

  7 5 <br/>
  2 3 <br/>
  3 4 <br/>
  5 6 <br/>
  6 7 <br/>
  7 5 <br/>
  
- Output 2<br/>

  5 <br/>
  3 <br/>
  3 <br/>

===

README by [manuelalves](https://github.com/manuelalves) - https://github.com/manuelalves/asa-problem1/

asa-problem2
===========
Project assignment for the Analysis and Synthesis of Algorithms course

LEIC-A # 2013/2014 www.tecnico.ulisboa.pt/

The Problem

A segurança é uma preocupação importante em vários tipos de eventos, particularmente aqueles que envolvem grandes grupos de pessoas, multidões. Eventos como jogos de futebol ou manifestações exigem bastante trabalho logístico por parte das forças de segurança envolvidas. Neste trabalho iremos considerar um modelo simples de controlo de multidões. Consideramos o mapa de uma cidade, onde existem pontos, onde as pessoas se podem concentrar e ligações entre esses pontos. Dois pontos podem estar ligados, no máximo, de uma forma. A nossa preocupação é garantir que não há comunicação, entre um conjunto de pontos críticos. Se houver comunicação entre todos os pontos críticos é mais provável que seja iniciado um motim, num desses pontos. Se tal acontecer a desordem irá extender-se a todo os outros pontos que lhes estejam directamente ligados, e assim sucessivamente a todos os pontos que sejam atingíveis a partir do ponto inicial. Para evitar comprometer a segurança da cidade inteira as forças de segurança podem barrar algumas das ligações, por forma a evitar que seja iniciado um motim. Para minimizar os custos desta operação, queremos minimizar o número de ligações que é necessário barrar. Assim o objectivo deste projecto consiste em modelar este problema, utilizando estruturas de dados e algoritmos adequados, por forma a que, dado o mapa de uma cidade e uma lista de pontos críticos, o algoritmo calcule o número mínimo de ligações que é necessário barrar. O objectivo é que os pontos críticos não estejam todos em comunição. Queremos que pelo menos um conjunto não vazio de pontos críticos fique isolado dos restantes, minimizando o número de ligações a barrar.

Input

A primeira linha do input contém dois inteiros. O primeiro indica o número de pontos n e o segundo inteiro o número de ligações m.

Seguem-se as ligações, uma por linha. Cada linha contém dois inteiros, que identiﬁcam os pontos que estão ligados. Estes números u e v respeitam as seguintes restrições: 0 ≤ u < v < n.

Após as linhas das ligações existe uma linha que contém apenas um número h, a indicar o número de problemas que se seguem. Todos estes problemas, i.e., conjuntos de pontos, devem ser resolvidos sobre o grafo lido anteriormente. As seguintes h linhas contém a listas de pontos críticos. O primeiro número de cada linha, k indica quantos pontos críticos existem nessa linha, com 1 ≤ k ≤ n. Os seguintes k números são os dos pontos críticos.

Todos os números que esteja numa mesma linha são separados por um espaço em branco.

Output

Para cada caso de testes o output deve consistir em h linhas, cada uma com apenas um número, o número mínimo de ligações a barrar, para o respectivo problema. A ordem dos números deve ser a dada no input. Cada linha de output não deve conter mais nenhum caracter, para além dos dígitos da resposta e do ’\n’.

Examples

Input 1

4 4 
0 2 
0 3 
1 2 
1 3 
2 
2 0 1 
2 0 2 

Output 1

2 
2 

Input 2
5 5 
0 2 
0 3 
1 2 
1 3 
0 4 
1 
3 0 1 4 

Output 2

1 

Input 3
6 4 
0 4 
0 5 
1 4 
1 5 
1 
2 0 1 

Output 3

2 

README by [manuelalves](https://github.com/manuelalves) - https://github.com/manuelalves/asa-problem1/
