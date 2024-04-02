# Module 00

Le module 00 du C++ est composé de 3 exercices. le dernier exercice est facultatif

[L'énoncé du sujet version 9](./document/fr.subject_cpp_00.pdf).

[l'introducion](./../Intro.md) et [les consignes générales](./../ConsigneGeneral.md)

## Exercice 00 : Mégaphone

| nom de l'exercice    |      Mégaphone          |
|----------------------|-------------------------|
| Dossier de rendu     | [ex00/](./rendu/ex00/)  |
| Fichier à rendre     | Makefile, megaphone.cpp |
| Fonctions interdites | Aucune                  |

>> Faire les exercices d’une "façon" C++.

Afin de s’assurer que tout le monde est bien réveillé, écrivez un programme qui se
comporte comme suit :

```bash
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

En gros je fais un pogramme qui mets toute les chaine de charactere en majuscule. (il doit avoir des fonction en c++ qui fais le taffe de tout metre en majuscule).
Si rien na etais donnée en arguement alors retourne : ```* LOUD AND UNBEARABLE FEEDBACK NOISE *```.

## Exercice 01 :

| nom de l'exercice    |      My Awesome PhoneBook          |
|----------------------|------------------------------------|
| Dossier de rendu     | [ex01/](./rendu/ex01/)             |
| Fichier à rendre     | Makefile, *.cpp, *.{h, hpp}        |
| Fonctions interdites | Aucune                             |

Vous devez implémenter deux classes :

PhoneBook :
- Représente le répertoire.
- Contient un tableau de contacts.
- Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème contact, remplacez le plus ancien par celui-ci.
- Notez que l’allocation dynamique est interdite

Contact
- Représente un contact dans le répertoire.

Dans votre code, l’objet répertoire doit être une instance de la classe PhoneBook. Même chose pour les objets contacts, qui doivent être chacun une instance de la classe Contact.

(Jeter un coup doeil aux video de l'intra).

Au lancement du programme, le répertoire est vide et l’utilisateur peut entrer une
commande. Le programme accepte les entrées suivantes : ADD, SEARCH et EXIT.

Une fois la commande correctement exécutée, le programme attend à nouveau une
entrée. Il prend fin lorsque l’utilisateur entre EXIT.
Donnez un nom cohérent à votre exécutable.

### Les différente commande

| ADD : enregistrer un nouveau contact |
|--------------------------------------|
|Si l’utilisateur entre cette commande, le programme lui demande de remplir une par une les informations du nouveau contact. Une fois tous les champs complétés, le nouveau contact est ajouté au répertoire. |
| Un contact possède les champs suivants : first name (prénom), last name (nom de famille), nickname (surnom), phone number (numéro de téléphone), et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne peuvent être vides.|

| SEARCH : affiche le contact demandé     |
|-----------------------------------------|
|Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index, first name, last name et nickname. |
| Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées par un pipe \|. Leur texte est aligné à droite. Si le texte dépasse la largeur de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par un point (’.’). |
| Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à afficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente. Sinon, affichez les informations du contact, une par ligne. |

| EXIT                                                       |
|------------------------------------------------------------|
| Le programme quitte et les contacts sont perdus à jamais ! |

**Toute autre entrée est ignorée.**

## Exercice 02 : L’emploi de vos rêves

| nom de l'exercice    |      L’emploi de vos rêves         |
|----------------------|------------------------------------|
| Dossier de rendu     | [ex02/](./rendu/ex02/)             |
| Fichier à rendre     | Makefile, Account.cpp, Account.hpp, tests.cpp |
| Fonctions interdites | Aucune                             |

en gros test.cpp possede le main.c Account.hpp me montre les instance methode de la strucutre je dois juste cree la classe enfaite et ce qui manque c'est tout est sa resembler aux log donnée.