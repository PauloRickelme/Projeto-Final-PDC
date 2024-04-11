# PGC 3
Este codigo simula um delivery online, com 2 acessos possiveis

Usuario e Admin

A main se divide em 2 execuções de programa:
-Usuario, o controlador estara apto a fazer um pedido
-Admin, o controlador estara apto a modificar informações de estoque

Temos 4 Arquivos de suporte para execução:

-appUser.cpp(funções de pedidos e cardapio)
  ºappUser.h(declaração das funções de appUser.cpp)
  
-appAdmin.cpp(funções de mudança de estoque)
  ºappAdmin.h(declaração das funções de appAdmin.cpp)

Bibliotecas como <iostream> e <fstream> estão adicionadas em
Main.h, assim como a declaração do struct de produtos.

Main.h está adicionado em todos os cps para encurtamento de includes.
