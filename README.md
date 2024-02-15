# INF224 Ronan Lebas
This repository contains the lab work from the 2023-2024 course INF224 of Télécom Paris.  
All mandatory questions have been answered.

## Code
* The C++ server is in `cpp`, the code is memory-leaks proof
* The Java client is in `swing`
* Each of these folders have a Makefile to compile and execute with `make run`

In `cpp/main.cpp`, there are three functions that can be called by the `main` function:
* `test` for testing the management of objects and memory
* `serial` for testing the serialization
* `server` for testing the interaction with the Java client

By default the program will execute these three functions, but one can look for memory leaks using `valgrind` by commenting the call to `server` in `main` (because the server is an infinite loop, so `valgrind` cannot be used).

## Questions
Here are the answers to the questions of the lab:

*  Contrairement à la fonction d'affichage : elle ne peut pas avoir d'implementation au niveau de la classe de base (car chaque type d'objet nécessite un programme différent pour être joué). Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?
    * C'est une méthode abstraite, on les déclare avec `=0`

* Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?
    * La classe de base comporte une méthode abstraite, c'est donc une classe abstraite, qui ne peut donc pas être instanciée

* Cette boucle doit traiter tous les objets dérivant de la classe de base de la même manière. Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?
    * La propriété utile ici est le polymorphisme d'héritage

* Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? 
    * Il faut déclarer `virtual` les méthodes de la classe de base qui seront redéfinies, déclarer `override` les méthodes des sous-classes correspondantes sous peine de ne pas profiter de la liaison dynamique de méthode

* Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java. 
    * Le tableau contient des pointeurs vers des objets qui sont considérés comme appartenant à la classe de base. Ainsi, tous les objets sont traités de la même manière (polymorphisme d'héritage). En Java, le tableau contiendrait des références vers les objets

* Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?
    * Il faut modifier les classes qui utilisent le tas (mémoire dynamique), donc la classe `Movie` (il faut `delete` le tableau de durées)

* La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?
    * Le problème est le problème de *shallow copy* (seul les attributs sont copiés, donc les pointeurs sont copiés mais pas les pointés). La solution est d'implémenter une *deep copy*, en définissant un contructeur de copie ou en redéfinissant l'opérateur d'affectation afin de copier également les pointés

* Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.
    * La liste doit être une liste de pointeurs pour pouvoir traiter uniformément les objets contenus dans le groupe (polymorphisme d'héritage). Java utilise des références

* Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?
    * Il suffit de déclarer les constructeurs comme `private` et d'avoir une méthode pour créer les objets

* Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ?
    * Quand la fenêtre devient trop petite, le texte est masqué, il faut ajouter des ascenseurs pour résoudre ce problème

## Documentation
Doxygen-generated documentation is available by opening `docs/html/index.html` in a web browser.

## Explanations
I chose to use exceptions for C++ step 13, but I think the way inputs are processed remove the need for a lot of exceptions: for instance, if the user wants to search an object which doesn't exist, the server will simply respond with a message indicating the object cannot be found, so using exceptions in such cases is not worth. I implemented exceptions for a few cases that seem necessary to me.