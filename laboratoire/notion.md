# Notion

ce fichier a pour objectif de repertoirier toute les notion de c++ que j'apprend.

pour compiller :
```bash
c++ -Wall -Wextra -Werror
```

| Index | Notion                              | compris |
|-------|-------------------------------------|---------|
| 0     | Name space                          | OUI     |
| 1     | Flux de stream entrée sortie        | OUI     |
| 2     | Classe Instance                     | OUI     |
| 3     | Attribut membre et fonction membre  | OUI     |
| 4     | This / self                         | OUI     |
| 5     | Initialisation list                 | OUI     |
| 6     | Const                               | OUI     |
| 7     | Encapsulation                       | OUI     |
| 8     | Class vs Struct                     | OUI     |
| 9     | Accessors                           | OUI     |
| 10    | Comparaison                         | OUI     |
| 11    | les attribut et fonction non membre | OUI     |
| 12    | Pointeur sur Membre                 | OUI     |
| 13    | New Delete                          | OUI     |
| 14    | Reference                           | OUI     |
| 15    | FileStream                          | BOF     |
| 16    | Adhoc polymorphims                  | NON     |

## Name space

c'est un ensemble qui va regroupper plusieur element dans elle meme.
```cpp
namesapce	<nom>
{
	...
}
```

je vais bcp l'utiliser pour la biblitheque standar.

### Nouveaux oppereteur

l'operateur de resolution de portée (aussi appelé Paamayim Nekudotayim en Indien) qui ressemble a :
```::```

qui permet d'apeller lelement aux sein d'un namespace
[exemple](./00_namespace/main.cpp).

## Flux de stream entrée sortie

C GRAVE UTILE OMG c'est pour lire ou ecrire dans des sortie ou entrée de fichier ou autre style mieux qu'utilise read ou write hihihi. [exemple](./01_stdio_streams/main.cpp).
et voici de la [documentation](https://cplusplus.com/reference/iostream/)

utilise le site cplusplus.com comme reference pour la doc.

## Classe Instance

La classe est comment on creee les objet avec sa propre syntaxe avec les destructeur constructeur, et les instance c'est ce qu'on crée.

## Attribut membre et fonction membre

Attribut membre == variable ou autre assignée a la classe

fonction membre dite methode est une fonction qui est assignée a une classe.

## This / self


this est un mot clée (self dans dautre langage), permet de pointer sur linstance meme donc utilise des flecher pour pointer.

## Initialisation list

C' le fais qu'on puisse directement initiliaser les attrbut membre aux constructeur on respectante cette syntaxe :

```c++
Sample2::Sample2(char p1, int p2, float p3 ) : a1(p1), a2(p2), a3(p3)
{
	...
}
```

sa permet de faire plein daute chose que je verrais au fur et a mesure.

## Const

Const on c on est etais obliger initiliaser pour donner une valeur car assigner n'etais possible.

en c++ on peut initiliaser aux moment du constructeur grace a la l'initialisation de list.

important on peut metre const apres une methode pour dire que j'ammais on ne va faire d'assignation dans cette instance !!

## Encapsulation

C'est le fais de rendre accessible ou non certaine infroamtion.

>> L'encapsulation permet d'ajouter aisément des règles de validation et des contraintes d'intégrité, par exemple limiter le domaine des valeurs qu'une variable peut prendre (validité) ou vérifier que cette valeur n'entre pas en conflit avec les valeurs d'autres variables (intégrité).

nous avons vu public et private.

private : on peut y acceder seulement dans la classe

public : accessible a peut pres partout

## Class vs Struct

Pareil juste par defaut les class encapsule par defaut tout en privée et les structure encapsule tout en public par defaut

## Accessors

c'est des fonction qui servent d'interface pour les attribut privée.

par convention y a les set qui modifie l'atribut et les get qui recuperer en retour l'atribut.

## Comparaison

bah on peut faire des fonction qui compare structureleent les instance aux lieu de le faire physiquement.

## les attribut et fonction non 

avec static elle permet de rendre des atribut et ft non membre en gros elles font partie de la classe mais pas des instance.

## Pointeur sur Membre

en gros on vois comment utiliser des pointeur de fonction et atribut membre.

## New Dellete

Notre nouveaux malloc free se sont des mauvaise idée car sa napelle pas le constructeur et destructeur.

Et c'est avec sa qu'on peut faire des tableaux / list.

## Reference

sa ressmeble a un pointeur c'est tjr constant sur la meme chose et est souvent defference genre pas besoin de remetre des symbole ou autre pour modifier est assigner mais on ne peut pas changer l'adresse.

au lieux de metre un * on mets un &.

En gros c pour se simplifier la vie mais les pointeur sa permet de faire + de chose.

## file stream

ouais pas trop compris cette notion mais en gros c'est la nouvelle manierre d'interagire avec des fichier en precisent le flux entrée sortie ou autre etc.

## Adhoc polymorphims

aussi appeler surcharge de fonction, permet davoir different fonction ayant la meme fonction et ayant des entrée différente

## Surcharge d'operrateur

la surcharge d'operrateur aussi qui permet de redefinir les opperateur logic.

Partie complexe mais on peut faire des super truc avec. MAis attention il y a a de grand risque de foutre le bordel donc voici des regles a suivre :
1. La surcharge d'un operateur doit etre naturelle
2. Est un rapport avec la scémenthique de l'operrateur
3. Eviter de faire des surcharge d'opperateur.

### Vocabulaire

operation arithémthique :

```bash
+ 1 1 == Notation prefixe / notation fonctionelle
1 + 1 == Notation infixe
1 1 + == Notation postfixe / pour calculer les piles
```

## Forme Canonique

et les forme canonique d'une classe.
C'est la convention a suivre pour faire une bonne classe.

pour qu'une forme soi canonique voici ce qu'il faut au minimum :

```hpp
Sample {
	Sample();									// CANON
	Sample( Sample const & src);				// CANON
	~Sample();									// CANON
	Sample	&operator=( Sample const & rhs);	// CANON
}
```
Si il y a ces 4 ellement alors sa sera une forme canonique de coplien :
1. Constructeur par defaut
2. Constructeur par copie
3. un Destructeur (virtuel mais a voir plus tard)
4. UN operateur egal

## L'héritage

Crée une classe parent qui peut avoir un enfant.
Nouvelle encapsulation -> protected qui peut etre accessible aus enfant.

Pas d'exemple a executer.

A voir le multiple heritage et aussi il y aussi le probléme de l'heritage diamant

## Polymorphisme

avec le mot clée virtuel rendre une fonction dynmaic == methode.

## Abstraction

en gros de ce que j'ai compris c'est le faire davoir des methode pour pouvoir se faire heriter.

## Nested Class

ou classe imbriquer permet de declarer une classe dans une autre classe

## Exceptions

permet danticiper des erreur prevue. avec trhow catch et exception est une classe


