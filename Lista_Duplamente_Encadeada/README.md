# ⛓️ Lista Duplamente Encadeada 

Após concluir o estudo da `Lista Linear Simplesmente Encadeada`, avançamos para uma estrutura bastante similar, a `Lista Linear Duplamente Encadeada`, que também é uma variação dos tipos de `Listas`. 📅

A `Lista Linear Duplamente Encadeada` é uma estrutura que organiza elementos em sequência linear. Diferente da `Lista Linear Sequencial`, os elementos são armazenados de forma `dispersa na memória`, conectados por ponteiros que seguem `duas direções`. Desta forma, cada nó está interligado tanto ao próximo quanto ao nó anterior, facilitando a navegação bidirecional da estrutura. 🔄

## Programas 📟

Com o intuito de simular uma `Lista Linear Duplamente Encadeada` `Ordenada`, foi desenvolvido um programa para cadastrar funcionários em uma empresa. Para isso, a aplicação deve organizar os funcionários primeiro por cargo de `gerente, supervisor ou peão` e, dentro de cada cargo, classificar os funcionários com base em seus `salários`, em ordem crescente.

<details>
<summary>Algoritmo do programa</summary>

### Função InserirFun

Para manipular os tipos de funcionários, foram adicionados `dois ponteiros`, `supervisor` e `peao`, que apontam para o primeiro elemento de cada categoria na lista. O cargo de `gerente` não precisou ser especificado, pois este é o elemento de maior valor na lista e pode coincidir com o ponteiro de início. Dessa forma, fica mais simples verificar a `existência de elementos` e identificar onde cada segmento `começa e termina`. 👥

Utilizando apenas a função principal `InserirFun`, após determinar o tipo de funcionário a ser inserido, com o auxílio dos ponteiros, o próximo passo é verificar em qual `posição` ele será inserido, levando em consideração a `existência` e o `salário` dos elementos dentro da sua categoria. Por fim, a função ajusta os ponteiros e nós, garantindo que o dado seja inserido corretamente na estrutura. 📍

</details>

Além disso, para utilizar um exemplo com `strings` de `Lista Linear Duplamente Encadeada`, foi elaborada uma aplicação que cadastra diferentes `nomes` e suas `frequências`. Desta forma, ao inserir nomes já existentes, apenas a sua frequência é incrementada.

<details>
<summary>Algoritmo do programa</summary>

### Função NovaPessoa

Para este programa, foi adicionada apenas uma função principal chamada `NovaPessoa`. Nesta função, verifica-se inicialmente se já existe algum nome igual ao que está sendo inserido, utilizando um while que percorre e compara o dado a ser inserido com o nome de cada nó. `Caso não exista`, o nome é inserido no final da lista; `caso exista`, apenas o valor da frequência é incrementado. 👥

</details>

## Funções 🛠️

Para esta aplicação, foram utilizadas algumas funções `básicas e específicas` para manipulação da `Lista Linear Duplamente Encadeada`.

<details>
<summary>Ler mais</summary>

### Funções Básicas
`Imprimir:` Exibe os elementos da lista.<br>
`Inicializar:` Inicializa uma nova lista.<br>
`Apagar:` Remove a lista existente e libera a memória.<br>
`Imprimir_Reverso:` Mostra os elementos da lista em ordem inversa.

### Funções Específicas:
`Inserir_Ini:` Adiciona um novo elemento no início da lista.<br>
`Inserir_Ord:` Adiciona um elemento mantendo a lista ordenada.<br>
`Remover:` Remove um elemento da lista pelo valor.<br>
`Buscar:` Encontra um elemento e retorna seu ponteiro.<br>
`Obter:` Retorna o valor de um nó específico.<br>
`Tamanho:` Mostra quantos elementos estão na lista.

</details>

## Conteúdos Relacionados 🗂️

Além disso, se desejarem explorar outros tipos de estruturas relacionadas, podem acessar os seguintes links: <br>
**[Lista Linear Sequencial](https://github.com/David-Mdrs/Estrutura_de_Dados_C/tree/main/Lista_Linear_Sequencial)** ➡️ <br>
**[Lista Simplesmente Encadeada](https://github.com/David-Mdrs/Estrutura_de_Dados_C/tree/main/Lista_Simplesmente_Encadeada)** 🔗

### Aproveitem o aprendizado! 📚