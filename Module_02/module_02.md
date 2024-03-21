# Module 02

Le module 02 du C++ est composé de 4 exercices. le dernier exercice est facultatif

[L'énoncé du sujet version 9](./document/fr.subject_cpp_02.pdf).

[l'introducion](./../Intro.md) et [les consignes générales](./../ConsigneGeneral.md)

## NOUVELLE CONSIGNE !!

À partir de maintenant, vos classes devront impérativement se conformer à la forme canonique de Coplien, sauf en cas d’indication contraire.

Cela signifie qu’elles devront comporter les quatre fonctions membres suivantes :
- Constructeur par défaut
- Constructeur de recopie
- Opérateur d’affectation
- Destructeur

Séparer le code de vos classes dans deux fichiers.
Le fichier d’en-tête (.hpp/.h) contient la définition de la classe, tandis que le fichier source (.cpp) contient son implémentation.

## Exercice 00 : Mon premier canon

| nom de l'exercice    |      Mon premier canon          |
|----------------------|---------------------------------|
| Dossier de rendu     | [ex00/](./rendu/ex00/)  |
| Fichier à rendre     | Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp |
| Fonctions interdites | Aucune                  |

source sur les entier et flottants : [1](http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html), [2](http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html), [3](http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)

Étant donné que le C++ ne possède pas de nombres à virgule fixe, vous allez les ajouter. 

[Cet article](http://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) de Berkeley est un bon point de départ.

Si vous ne savez pas ce qu’est l’Université de Berkeley, lisez [cette partie](http://en.wikipedia.org/wiki/University_of_California,_Berkeley#Notable_alumni.2C_faculty.2C_and_staff) de sa page Wikipédia.

Créez une classe sous forme canonique pour représenter un nombre à virgule fixe.

- Membres privés :
	- Un entier pour stocker la valeur du nombre en virgule fixe.
	- Un entier constant statique pour stocker le nombre de bits de la partie fractionnaire, et dont la valeur sera toujours le littéral entier 8.
- Membres publics :
	- Un constructeur par défaut qui initialisera la valeur du nombre à virgule fixe à 0.
	- Un constructeur de recopie.
	- Une surcharge de l’opérateur d’affectation.
	- Un destructeur.
	- Une fonction membre ```int getRawBits( void ) const;``` qui retourne la valeur du nombre à virgule fixe sans la convertir.
	- Une fonction membre ```void setRawBits( int const raw );``` qui initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.

code à executer :
```cpp
#include <iostream>
int	main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
```
Resultat :
```bash
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

## Exercice 01 : Premiers pas vers une classe utile

| nom de l'exercice    | Premiers pas vers une classe utile |
|----------------------|------------------------------------|
| Dossier de rendu     | [ex01/](./rendu/ex01/)  |
| Fichier à rendre     | Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp |
| Fonctions interdites | roundf (from <cmath>)              |

L’exercice précédent était un bon point de départ mais notre classe n’a pour l’instant pas beaucoup d’intérêt.

Elle peut seulement représenter la valeur 0.0.


Ajoutez à votre classe les constructeurs et les fonctions membres suivants en public :

- Un constructeur prenant un entier constant en paramètre et qui convertit celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8 comme dans l’exercice 00.
- Un constructeur prenant un flottant constant en paramètre et qui convertit celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8 comme dans l’exercice 00.
- Une fonction membre ```float toFloat( void ) const;``` qui convertit la valeur en virgule fixe en nombre à virgule flottante.
- Une fonction membre ```int toInt( void ) const;``` qui convertit la valeur en virgule fixe en nombre entier.

Ajoutez également la fonction suivante à vos fichiers de la classe **Fixed** :
- Une surcharge de l’opérateur d’insertion («) qui insère une représentation en virgule flottante du nombre à virgule fixe dans le flux de sortie (objet output stream) passé en paramètre.

Exécuter ce code :
```cpp
#include <iostream>

int	main( void ) {
	Fixed	a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
```
Resultat :
```bash
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
```

## Exercice 02 : Maintenant, on peut parler

| nom de l'exercice    | Maintenant, on peut parler |
|----------------------|------------------------------------|
| Dossier de rendu     | [ex02/](./rendu/ex02/)  |
| Fichier à rendre     | Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp |
| Fonctions interdites | roundf (from <cmath>)              |

Ajoutez à votre classe des fonctions membres publiques afin de surcharger les opérateurs suivants :
- Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
- Les 4 opérateurs de arithmétiques : +, -, *, et /.
- Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.

Ajoutez à votre classe ces quatre fonctions membres publiques surchargées :

- Une fonction membre statique min prenant en paramètres deux références sur des nombres à virgule fixe et qui retourne le plus petit d’entre eux.
- Une fonction membre statique min prenant en paramètres deux références sur des nombres à virgule fixe constants et qui retourne le plus petit d’entre eux.
- Une fonction membre statique max prenant en paramètres deux références sur des nombres à virgule fixe et qui retourne le plus grand d’entre eux.
- Une fonction membre statique max prenant en paramètres deux références sur des nombres à virgule fixe constants et qui retourne le plus grand d’entre eux.

C’est à moi de tester chaque fonctionnalité de votre code. Mais exécuter ce code :

```cpp
#include <iostream>

int	main( void ) {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
```

Devra afficher ce résultat (pour plus de lisibilité, les messages du constructeur et du destructeur ont été retirés) :
```bash
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

>> Si vous effectuez une division par 0, il est acceptable que le programme crash.

## Exercice 03 : BSP

| nom de l'exercice    | BSP |
|----------------------|------------------------------------|
| Dossier de rendu     | [ex03/](./rendu/ex03/)  |
| Fichier à rendre     | Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp, Point.{h, hpp}, Point.cpp, bsp.cpp |
| Fonctions interdites | roundf (from <cmath>)              |

Maintenant que vous avez une classe Fixed fonctionnelle, ce serait sympa de l’utiliser non ?

Implémentez une fonction qui indique si un point donné est à l’intérieur d’un triangle.

Super utile, n’est-ce pas ?

BSP signifie Binary Space Partitioning. Ne me remerciez pas. :)

Premièrement, créez une classe Point sous forme canonique pour représenter un point 2D :
- Membres privés :
	- Un attribut Fixed constant x.
	- Un attribut Fixed constant y.
	- Et tout ce qui peut vous être utile.
- Membres publics :
	- Un constructeur par défaut qui initialise x et y à 0.
	- Un constructeur prenant deux flottants constants en paramètres et initialisant x et y avec ces derniers.
	- Un constructeur de recopie.
	- Une surcharge de l’opérateur d’affectation.
	- Un destructeur.
	- Et tout ce qui peut vous être utile.

Pour conclure, implémentez la fonction suivante dans le fichier correspondant :

```bool bsp( Point const a, Point const b, Point const c, Point const point);```

- a, b, c : Les sommets de notre cher triangle.
- point : Le point à évaluer.
- Retourne : True si le point est à l’intérieur du triangle. False dans le cas contraire. Cela veut dire que, si le point est un sommet ou placé sur une arrête, la fonction
retournera False.

Écrivez et rendez vos propres tests afin de démontrer que votre classe fonctionne comme demandé.