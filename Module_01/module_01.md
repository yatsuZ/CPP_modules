# Module 01

Le module 01 du C++ est composé de 7 exercices. le dernier exercice est facultatif

[L'énoncé du sujet version 9](./document/fr.subject_cpp_01.pdf).

[l'introducion](./../Intro.md) et [les consignes générales](./../ConsigneGeneral.md)

## Exercice 00 : BraiiiiiiinnnzzzZ

| nom de l'exercice    |      BraiiiiiiinnnzzzZ          |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex00/](./rendu/ex00/)  |
| Fichier à rendre     | Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
newZombie.cpp, randomChump.cpp |
| Fonctions interdites | Aucune                  |

Pour commencer, implémentez une classe Zombie.
Elle possède un attribut **privé name** (nom) de **type string**.
Ajoutez-lui une fonction membre : ```void announce( void );```.

Les zombies se présentent (s’annoncent) ainsi :
```bash
<nom>: BraiiiiiiinnnzzzZ...
```
exemple si le zombie sapelle Bob :
```bash
Bob: BraiiiiiiinnnzzzZ...
```

Ensuite, implémentez les fonctions suivantes :

- ```Zombie* newZombie( std::string name );```
Crée un zombie, lui donne un nom et le retourne afin qu’il puisse être utilisé en
dehors de la portée de la fonction.

- ```void randomChump( std::string name );```
Crée un zombie, lui donne un nom et le fait se présenter.

Je dois déterminer dans quel cas il est plus judicieux d’allouer les zombies sur le tas, et dans quel autre sur la pile.

**Les zombies doivent être détruits lorsque vous n’en avez plus besoin. Le destructeur doit afficher un message de débug comportant le nom du zombie.**

## Exercice 01 : Encore plus de cerveaux !

| nom de l'exercice    |      Encore plus de cerveaux !          |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex01/](./rendu/ex01/)  |
| Fichier à rendre     | Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, newZombie.cpp, randomChump.cpp, zombieHorde.cpp |
| Fonctions interdites | Aucune                  |

Implémentez la fonction suivante dans le fichier correspondant :

```Zombie* zombieHorde( int N, std::string name );```

Cette fonction doit allouer N objets Zombie en une seule allocation. Ensuite, elle doit initialiser les zombies en donnant à chacun le nom passé en paramètre.

Elle retourne un pointeur sur le premier zombie.

Écrivez vos propres tests afin de vous assurer que votre fonction ```zombieHorde()``` se comporte comme demandé. Essayez d’appeler ```announce()``` pour chacun des zombies.

N’oubliez pas de tous les delete et de vérifiez que vous n’avez pas de fuites de mémoire

## Exercice 02 : BONJOUR ICI LE CERVEAU

| nom de l'exercice    |      BONJOUR ICI LE CERVEAU     |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex02/](./rendu/ex02/)          |
| Fichier à rendre     | Makefile, main.cpp              |
| Fonctions interdites | Aucune                          |

Créez un programme comportant :

- Une variable de type string initialisée à "HI THIS IS BRAIN".
- stringPTR : Un pointeur sur la string.
- stringREF : Une référence sur la string.

Votre programme doit afficher :

- L’adresse de la string en mémoire.
- L’adresse stockée dans stringPTR.
- L’adresse stockée dans stringREF.

Puis :

- La valeur de la string.
- La valeur pointée par stringPTR.
- La valeur pointée par stringREF.

C’est tout. Il n’y a pas de pièges.

Le but de cet exercice est de vous faire démystifier les références qui ne sont pas un concept totalement nouveau.

Bien qu’il y ait de légères différences, il s’agit seulement d’une autre syntaxe pour représenter quelque chose que vous faites déjà : manipuler des adresses.

## Exercice 03 : Violence inutile

| nom de l'exercice    |      Violence inutile     |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex03/](./rendu/ex03/)          |
| Fichier à rendre     | Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h, hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp|
| Fonctions interdites | Aucune                          |

Implémentez une classe Weapon (arme) qui possède :
- Un attribut privé type de type string.
- Une fonction membre getType() retournant une référence constante sur type.
- Une fonction membre setType() qui attribue à type la nouvelle valeur passée en paramètre.

Maintenant, créez deux classes HumanA et HumanB. Toutes deux possèdent une Weapon et un name, ainsi qu’une fonction membre attack() affichant (sans les chevrons bien sûr) :
```
<name> attacks with their <weapon type>
```

HumanA et HumanB sont presque identiques, à l’exception de deux petits détails :
- Alors que le constructeur de HumanA prend une Weapon comme paramètre, ce n’est pas le cas de celui de HumanB.
- HumanB n’aura pas toujours une Weapon, tandis que HumanA en aura forcément une.

Si votre implémentation est correcte, l’exécution du code suivant affichera une attaque avec "crude spiked club", puis une attaque avec "some other type of club", pour les deux tests (main d'exemple):

```cpp
int main()
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
```

**N’oubliez pas de vérifier que vous n’avez pas de fuites de mémoire.**

>> Dans quel cas pensez-vous plus judicieux d’utiliser un pointeur sur Weapon ? Et une référence sur Weapon ? Pourquoi ? Prenez le temps d’y réfléchir avant de commencer.

## Exercice 04 : Sed, c’est pour les perdant(e)s

| nom de l'exercice    |    Sed, c’est pour les perdant(e)s    |
|----------------------|---------------------------------------|
| Dossier de rendu     | [ex04/](./rendu/ex04/)                |
| Fichier à rendre     | Makefile, main.cpp, *.cpp, *.{h, hpp} |
| Fonctions interdites | std::string::replace                  |

Concevez un programme prenant trois paramètres dans l’ordre suivant :
1. un nom de fichier
2. une string
3. une seconde string

Le fichier < filename > sera ouvert et son contenu copié dans un nouveau fichier < filename >.replace, où chaque occurrence de s1 sera remplacée par s2.

Bien entendu, vous devez gérer les entrées inattendues et les erreurs possibles. Créez
et rendez vos propres tests afin de prouver que votre programme fonctionne.

>> **Avoir recours aux fonctions C de manipulation de fichiers est interdit et sera considéré comme de la triche. Toutes les fonctions membres de la classe std::string sont autorisées sauf replace. Utilisez-les intelligemment !**

## Exercice 05 : Harl 2.0

| nom de l'exercice    |    Harl 2.0                                 |
|----------------------|---------------------------------------------|
| Dossier de rendu     | [ex05/](./rendu/ex05/)                      |
| Fichier à rendre     | Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp |
| Fonctions interdites | Aucune                                      |

Vous devez créer une classe Harl avec les fonctions membres privées suivantes :

- ```void debug( void );```
- ```void info( void );```
- ```void warning( void );```
- ```void error( void );```

Harl a également une fonction membre publique qui, selon le niveau passé en para-
mètre, fait appel à l’une des quatre fonctions membres ci-dessus :

```void	complain( std::string level );```

- Niveau "DEBUG" : Les messages de débug contiennent des informations contextuelles. On les utilise principalement pour établir des diagnostics.

exemple : **I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !**

- Niveau "INFO" : Ces messages contiennent des informations détaillées. On les utilise pour tracer l’exécution d’un programme en production.

exemple : **I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !**

- Niveau "WARNING" : Les messages d’avertissement indiquent un problème potentiel dans le système. Toutefois, on est en mesure de le gérer ou de l’ignorer.

exemple : **I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.**

- Niveau "ERROR" : Ces messages indiquent qu’une erreur irrécupérable s’est produite. Il s’agit généralement d’un problème critique qui nécessite une intervention manuelle.

exemple : **This is unacceptable ! I want to speak to the manager now.**

Le but de l’exercice est de vous faire utiliser des pointeurs sur fonctions membres.

Ce n’est pas qu’une suggestion. 

**Harl doit pouvoir se plaindre sans avoir recours à une forêt de if/else if/else.**
Il n’y réfléchit pas à deux fois !

Créer et rendre des tests pour montrer que Harl se plaint beaucoup. Vous pouvez utiliser les exemples de commentaires indiqué au dessus dans le sujet ou choisir d’utiliser des commentaires de votre choix.

## Exercice 06 : Harl filter

| nom de l'exercice    |    Harl filter                              |
|----------------------|---------------------------------------------|
| Dossier de rendu     | [ex06/](./rendu/ex06/)                      |
| Fichier à rendre     | Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp |
| Fonctions interdites | Aucune                                      |

Il arrive que vous n’ayiez pas envie de prêter attention à chacun des commentaires
de Harl. Implémentez un système permettant de filtrer ce qu’il dit selon les niveaux que
vous acceptez d’entendre.

Concevez un programme prenant en paramètre un des quatre niveaux de gravité. Il
affichera le message de ce niveau et tous ceux des niveaux supérieurs.

Exemple : 

```bash
$> ./HarlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I've been coming for years whereas you started working here since last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./HarlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

Bien qu’il y ait plusieurs moyens de gérer Harl, l’un des plus efficaces est de le SWITCH off.

Appelez votre exécutable HarlFilter.

Vous devez utiliser, et peut-être découvrir, l’instruction switch dans cet exercice.