# Module 03

Le module 03 du C++ est composé de 4 exercices. le dernier exercice est facultatif

[L'énoncé du sujet version 9](./document/fr.subject_cpp_03.pdf).

[l'introducion](./../Intro.md) et [les consignes générales](./../ConsigneGeneral.md)

## Exercise 00: Aaaaand... OPEN!

| nom de l'exercice    |      Aaaaand... OPEN!           |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex00/](./rendu/ex00/)  |
| Fichier à rendre     | Makefile, main.cpp, ClapTrap.{h, hpp}, ClapTrap.cpp |
| Fonctions interdites | Aucune                  |

Classe ClapTrap init priv et les valeur specifier entre parenthese:

- Name en parametre du constructeur
- Les points de vie (10), représentent la santé du ClapTrap
- Points d'énergie (10)
- Degats d'attaque (0)

Fonction public :

- ```void attack(const std::string& target);```
- ``` void takeDamage(unsigned int amount);```
- ```void beRepaired(unsigned int amount);```

Lorsque ClapTrack attaque, sa cible perd des points de vie < dégâts d'attaque>.
Lorsque ClapTrap se répare, il récupère < montant> points de vie.
Bien sûr, ClapTrap ne peut rien faire s’il ne lui reste plus de points de vie ni de points d’énergie.

Dans toutes ces fonctions membres, vous devez imprimer un message pour décrire ce qui se passe. pour les constructeur et destructeur aussi. Faire mes propre test.

## Exercise 01: Serena, my love!

| nom de l'exercice    |      Serena, my love!           |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex01/](./rendu/ex01/)  |
| Fichier à rendre     | Fichier du precent exercice + ScavTrap.{h, hpp}, ScavTrap.cpp |
| Fonctions interdites | Aucune                  |

Crée une classe qui herite de ClapTrap, Il s'appellera ScavTrap et héritera des constructeurs et du destructeur de ClapTrap.

Cependant, ses constructeurs, son destructeur et son attaque() imprimeront des messages différents.

Après tout, les ClapTraps sont conscients de leur individualité

Je vqis devoir faire mes propre test, Lorsqu'un ScavTrap est créé, le programme commence par construire un ClapTrap.

La destruction s'effectue dans l'ordre inverse. Pourquoi?

ScavTrap utilisera les attributs de ClapTrap (mettre à jour ClapTrap en conséquence) et devra les initialiser pour :

- Name en parametre du constructeur
- Les points de vie (100), représentent la santé du ClapTrap
- Points d'énergie (50)
- Degats d'attaque (20)

ScavTrap aura également sa propre capacité spéciale :
```void guardGate();```

Cette fonction membre affichera un message informant que ScavTrap est maintenant en mode Gate keeper.

## Exercise 02: Repetitive work

| nom de l'exercice    |      Repetitive work            |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex02/](./rendu/ex02/)          |
| Fichier à rendre     | Fichier du precent exercice + FragTrap.{h, hpp}, FragTrap.cpp |
| Fonctions interdites | Aucune                          |

Maintenant, implémentez une classe FragTrap qui hérite de ClapTrap.

C'est très similaire à ScavTrap. Cependant, ses messages de construction et de destruction doivent être différents.

Un enchaînement de construction/destruction approprié doit être démontré dans vos tests.

Lorsqu'un FragTrap est créé, le programme commence par construire un ClapTrap.

La destruction est dans l'ordre inverse.

Même chose pour les attributs, mais avec des valeurs différentes cette fois :

- Name en parametre du constructeur
- Les points de vie (100), représentent la santé du ClapTrap
- Points d'énergie (100)
- Degats d'attaque (30)

FragTrap aura également sa propre capacité spéciale :
```void highFivesGuys(void);```

Cette fonction membre affiche une demande positive de cinq sur la sortie standard.

## Exercise 03: Now it’s weird!

| nom de l'exercice    |      Now it’s weird!            |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex03/](./rendu/ex03/)          |
| Fichier à rendre     | Fichier du precent exercice + DiamondTrap.{h, hpp}, DiamondTrap.cpp |
| Fonctions interdites | Aucune                          |

Dans cet exercice, vous allez créer un monstre :
un ClapTrap moitié FragTrap, moitié Piège Scav.
Il s'appellera DiamondTrap et héritera à la fois du FragTrap et le ScavTrap.

La classe DiamondTrap aura un attribut privé de nom.

Donnez à cet attribut exactement le même nom de variable (je ne parle pas ici du nom du robot) que celui de la classe de base ClapTrap.

Pour être plus clair, voici deux exemples:

- Si La variable de ClapTrap est name, donnez le nom à celui du DiamondTrap.

- Si La variable de ClapTrap est _name, donnez le nom _name à celle du DiamondTrap.

Ses attributs et fonctions membres seront sélectionnés dans l'une de ses classes parentes :
- Name en parametre du constructeur
- ClapTrap::name (paramètre du constructeur + suffixe "_clap_name")
- Les points de vie (FragTrap)
- Points d'énergie (ScavTrap)
- Degats d'attaque (FragTrap)
- attack (Scavtrap)

En plus des fonctions spéciales de ses deux classes parentes, DiamondTrap aura sa propre capacité particulière :

```void whoAmI();```

Cette fonction membre affichera à la fois son nom et son nom ClapTrap.

Bien entendu, le sous-objet ClapTrap du DiamondTrap sera créé une seule fois, et seulement
une fois. Oui, il y a une astuce.
Encore une fois, ajoutez plus de tests à votre programme.

>> Do you know the **-Wshadow** and **-Wno-shadow** compiler flags?
