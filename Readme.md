Sistema de Gerenciamento de Catálogo de Séries em C++

Neste projeto, o grupo irá desenvolver um sistema de catálogo de séries de TV e streaming (STVS) em C++ com uma interface de linha de comando (CLI). O objetivo é criar um sistema organizado, seguindo padrões de programação orientada a objetos (POO) e práticas de programação robustas.

Requisitos do Sistema

O sistema deve ser implementado em C++.
Deve ter uma interface de linha de comando (CLI) que oferece as seguintes opções (menu principal e submenus):
1. Séries

a) Incluir um novo registro*

b) Recuperar um registro

c) Editar um registro

d) Excluir um registro.

2. Relatórios:

a) Registros ordenados por título

b) Registros ordenados por canal/streaming

c) Registros ordenados por ano

d) Registros ordenados por nota

3. Ajuda

4. Créditos

5. Sair

Os registros devem conter os seguintes campos para identificar uma série de TV:
- ID interno (int, único)

- Nome da série (string)

- Ano de lançamento (int)

- Temporada (int)

- Número de Episódios (int)

- Principais atores/atrizes (string)

- Personagens principais (string)

- Canal/streaming (string)

- Nota de classificação (int, 0-10, conf. sua avaliação da STVS)

Devem haver duas implementações de persistência de dados, com padrão DAO: uma para memória local (banco simulado) e outra para um banco de dados relacional remoto (MariaDB).
Boas Práticas de Programação

Adote uma abordagem orientada a objetos para projetar e implementar o sistema
Mantenha o código limpo, organizado e legível
Utilize nomes significativos para classes, métodos e variáveis
Divida o código em classes separadas para promover a modularidade e a reutilização de código
Comente o código de forma clara e concisa para explicar o propósito de classes, métodos e trechos complexos
Utilize constantes e enumerações para representar valores fixos e evitar números mágicos
Implemente tratamento de erros (exceções) e validações adequadas para garantir a robustez do sistema
Faça uso de padrões de projeto apropriados, como DAO (Data Access Object) e DTO (Data Transfer Object), para separar a lógica de acesso a dados do restante do código.
Desenvolvimento do Projeto

Comece projetando a estrutura geral do sistema, identificando as classes necessárias e suas relações
Divida o trabalho equilibradamente entre os membros do grupo, relembrando que trabalhar em equipes é um do benefícios do uso da POO, que permite codificação em paralelo
Implemente as classes e métodos de acordo com o design estabelecido, seguindo as boas práticas de programação
Teste o sistema cuidadosamente para garantir que todas as funcionalidades estejam funcionando corretamente e que não haja erros
Refatore o código conforme necessário para melhorar a qualidade e a eficiência do sistema
Documente o código adequadamente, incluindo instruções de compilação e execução, bem como descrições dos principais componentes e funcionalidades.
Entrega do Projeto

Atenção: somente serão considerados programas que compilem sem erros ou avisos!

A entrega do projeto será realizada através da plataforma Moodle e deve incluir os seguintes itens:

Relatório de Contribuição Comentado: Seguir o modelo disponibilizado na plataforma (anexo a esta tarefa). É importante observar que os percentuais atribuídos a cada integrante devem ser números inteiros e não podem ser repetidos. Caso essas condições sejam violadas, valores arbitrários serão utilizados.
Código-fonte: Deve ser fornecido em um arquivo .zip, contendo os arquivos .h e .cpp. Inclua também um arquivo de script de compilação para Linux. O código deve compilar sem erros ou avisos usando apenas recursos da linguagem C++ (C++ 11) e suas bibliotecas-padrão. Não serão aceitas correções ou alterações no código ou no script após a entrega.
Arquivo PDF com o Código-fonte Completo: Cada arquivo .h e .cpp deve iniciar em uma nova página. Este arquivo será utilizado para a correção geral e avaliação da qualidade do código.
Link para Vídeo Demonstrativo (3 a 5 minutos): O vídeo deve mostrar o programa em funcionamento (desde a compilação). Não é necessário instalar ou ter acesso a um banco de dados relacional remoto. Utilize a implementação DAO em memória para essa demonstração. Use o campo de texto do Moodle, na postagem, para indicar o link e tenha certeza de ter dado permissões suficientes para que o professor e o PED consigam acesso.
Diagrama de Classes UML em PDF: O diagrama deve mostrar os relacionamentos entre as classes, especialmente a herança.
Considerações Finais

Este projeto oferece uma oportunidade para aplicar e aprimorar seus conhecimentos em programação C++ e práticas de desenvolvimento de software. Aproveite ao máximo esta experiência e não hesite em buscar ajuda ou esclarecimentos sempre que necessário.
Um bom modo de aprender é incluir funcionalidades e recursos além do mínimo solicitado. Tente fazer isso.
Boa sorte e bons estudos!