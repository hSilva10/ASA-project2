# ASA-project2
ASA PROJECT 2 - Trocas Comerciais

### Tema: trocas comerciais entre regiões via uma ferrovia de alta velocidade.

##### Problemas: 
    - situação inicial ineficiente 
    - algumas regiões não mantêm trocas comerciais com regiões vizinhas
    - restrições ornamentais -> governo necessita minimizar os custos de insfraestrutura apenas financiando os troços necessários para conseguir garantir ligações entre o maior número de regiões e apenas entre as que já mantenham trocas comerciais.

##### Objetivos:
    - estimar qual o valor máximo de trocas comerciais passíveis de ser passado para a rede ferroviária

##### dados:
    - a localização de cada região deve ser caracterizada pela latitude/longitude da estação ferroviária da sua capital;
    - as ligações entre as estações ferroviárias pode ser feita em linha reta (ignorando relevo ou outros potenciais obstáculos).

##### formação do grado não dirigido:
    - Boris Delaunau, defeniu para um conjunto de pontos P dispostos num plano T(P), tal que nenhum ponto p pertencente a P está dentro de qualquer triângulo t pertencente a T(P).
    - Assim usando esta triangulação, dado um conjunto de pontos representando as estações rodoviárias da capital de cada região, é possível contruir um grafo planar não dirigido G =(V,E) -> V = vértices (conjunto de regiões), E = arcos (ligações entre estações rodoviárias da capital de cada região defenidas como próximas pela triangulação).
    
#### Neste projeto:
    - assume-se que:
        - os custos de cada troço de ferroviária são os mesmos;
        - após a aplicação de Delaunay obtemos um grado G=(V,E) onde V designa uma região, e E o conjunto de arcos, onde a função de pesos *w* representa, para cada arco (u,v) pertencente a E o valor em M$(euros) de trocas comerciais entre as regiões u e v.

###### Problema: dado um grafo G = (V,E) pretende-se calcular o valor máximo de trocas comerciais, minimizando os custos insfraestrutura (número de troços).

##### Input:
    - informação relativa a um grafo não dirigido G = (V,E):
        - linha com o número de vértices V (com V >= 1);
        - linha contendo o número de arcos E (com E >= 0);
        - sequência de E linhas, em que cada linha contém um arco (u,v) e contém 3 inteiros (dois inteiros -> vértices u,v; um inteiro -> w(u,v) valor da troca comercial)
    (os identificadores dos vértices são inteiros entre 1 e V)

##### Output:
    - Deverá escrever o valor máximo de trocas comerciais, minimizando os custos infraestrutura (número de troços);