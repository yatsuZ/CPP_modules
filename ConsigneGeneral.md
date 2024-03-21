# Consigne Générales

>> Voici la synthese des Consigne Générales de chaque sujet du module cpp.

## Compiliation

- On compile avec **C++** et les flags -Wall -Wextra -Werror et -std=c++98 .

exemple :
```bash
c++ -Wall -Wextra -Werror -std=c++98 fichier.cpp
```

Explication :

- c++ est la commande qui compile le code demande

les flags son des parametre mis.

- Wall : Ce flag active la plupart des avertissements (warnings) standards du compilateur. Cela inclut des avertissements sur des constructions potentiellement dangereuses ou non portables dans le code.

- Wextra : Ce flag active des avertissements supplémentaires par rapport à -Wall. Il inclut généralement des avertissements pour des cas plus subtils ou moins courants.

- Werror : Ce flag indique au compilateur de traiter tous les avertissements comme des erreurs. Cela signifie que si le compilateur émet un avertissement lors de la compilation, il sera traité comme une erreur et le processus de compilation échouera.

En résumé, ces flags sont utiles pour détecter les problèmes potentiels dans le code pendant la compilation et pour s'assurer que le code est écrit de manière robuste et sans avertissements. L'utilisation de -Werror est particulièrement utile dans les environnements où il est important d'avoir un code exempt d'erreurs ou d'avertissements.

- std=c++98 : Le flag -std=c++98 est utilisé pour spécifier la version du standard C++ à utiliser lors de la compilation. Dans ce cas précis, -std=c++98 indique au compilateur de se conformer strictement à la norme C++98, qui est une version plus ancienne du standard C++.

Ce flag est souvent utilisé pour des projets où il est nécessaire de garantir une compatibilité avec des anciennes versions du compilateur ou des systèmes qui ne prennent pas en charge les dernières fonctionnalités du standard C++.

## Format et conventions de nommage

- Les dossiers des exercices seront nommés ainsi : ex00, ex01, ... , exn.
- Nommez vos fichiers, vos classes, vos fonctions, vos fonctions membres et vos attributs comme spécifié dans les consignes.
- Rédigez vos noms de classe au format [UpperCamelCase](https://fr.wikipedia.org/wiki/Camel_case), c'est une convention de comment on ecris des fonction variable methode et fichier.
- Les fichiers contenant le code d’une classe porteront le nom de cette dernière et pour les ficchier dén tete aussi les .hpp
- Sauf si spécifié autrement, tous les messages doivent être terminés par un retour à la ligne et être affichés sur la sortie standard.
- PAS DE NROMINETTE YOUPI. mais je dois garder un code lisible !!

## Ce qui est autorisé et ce qui ne l’est pas

- Essayez d’utiliser le plus possible les versions C++ des fonctions C dont vous avec l’habitude.
- aucune autre bibliothèque externe. Aussi, certaines fonctions demeurent interdites. Utiliser les fonctions suivantes résultera en la note de 0 : **\*printf()**, **\*alloc()** et **\*free()**.
- Sauf si explicitement indiqué autrement, les mots-clés using namespace <ns_name> et friend sont interdits. Leur usage résultera en la note de -42.
- **Vous n’avez le droit à la STL (standar librarie) que dans les Modules 08 et 09**. D’ici là, l’usage des **Containers** (vector/list/map/etc.) et des **Algorithmes** (tout ce qui requiert d’inclure <algorithm>) est interdit. **Dans le cas contraire, vous obtiendrez la note de -42.**

## Quelques obligations côté conception

- Quand vous allouez de la mémoire (en utilisant le mot-clé new), **vous ne devez pas avoir de memory leaks**.
- Du Module 02 au Module 09, vos classes devront se conformer à la forme canonique, dite de Coplien, sauf si explicitement spécifié autrement.
- Une fonction implémentée dans un fichier d’en-tête (hormis dans le cas de fonction template) équivaudra à la note de 0.
- Vous devez pouvoir utiliser vos fichiers d’en-tête séparément les uns des autres. C’est pourquoi ils devront inclure toutes les dépendances qui leur seront nécessaires. Cependant, vous devez éviter le problème de la double inclusion en les protégeant avec **des include guards**. Dans le cas contraire, votre note sera de 0.

## Read me

- Je peux rendre des fichier supplémentaires pour séparer mon code si trop lourd. Vu que mon travaille ne sera pas évalué par un programme je suis libre de gerer le rendu a ma guise tant que je respecte les condition dis plus tot.
- Les consignes d’un exercice peuvent avoir l’air simple mais les exemples contiennent parfois des indications supplémentaires qui ne sont pas explicitement demandées.
- LIRE CHAQUE MODULE !!! est je dois utiliser mon cerveau :).

>> Vous aurez à implémenter un bon nombre de classes, ce qui pourrait s’avérer ardu... ou pas ! Il y a peut-être moyen de vous simplifier la vie grâce à votre éditeur de texte préféré.

donc je peux rendre avec des md pour maider decrire / comprendre les enoncer / exercice. ou meme des umls.

>> Vous êtes assez libre quant à la manière de résoudre les exercices. Toutefois, respectez les consignes et ne vous en tenez pas au strict minimum, vous pourriez passer à côté de notions intéressantes. N’hésitez pas à lire un peu de théorie.