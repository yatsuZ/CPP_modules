# Module 04

Le module 04  du C++ est composé de 4 exercices. le dernier exercice est facultatif

[L'énoncé du sujet version 9](./document/fr.subject_cpp_04.pdf).

[l'introducion](./../Intro.md) et [les consignes générales](./../ConsigneGeneral.md)

## Exercice 00 : Polymorphisme

| nom de l'exercice    |      Polymorphisme                    |
|----------------------|---------------------------------------|
| Dossier de rendu     | [ex00/](./rendu/ex00/)                |
| Fichier à rendre     | Makefile, main.cpp, *.cpp, *.{h, hpp} |
| Fonctions interdites | Aucune                                |

Pour chaque exercice, veuillez fournir les tests les plus complets possible!!!!

Les constructeurs et les destructeurs de chaque classe doivent afficher des messages qui leur sont propres et different pour chaque class!!!

Commencez par implémenter une classe simple de base Animal. Elle possède un attribut protégé :
- std::string type;

Implémentez une classe Dog (chien) qui hérite de Animal.
Implémentez une classe Cat (chat) qui hérite de Animal.

Ces deux classes dérivées doivent initialiser leur type en fonction de leur nom.

Ainsi, le type de Dog sera “Dog”, et celui de Cat sera “Cat”.

Le type de la classe Animal peut être laissé vide ou initialisé avec la valeur de votre choix.

Chaque animal doit être capable d’utiliser la fonction membre :
makeSound()

Elle affichera un son cohérent (les chats n’aboient pas).

code de test :
```cpp
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	...

	return 0;
}
```

Afin de vous assurer d’avoir compris, implémentez une classe WrongCat héritant d’une classe WrongAnimal. 

Dans le code ci-dessus, si vous remplacez l’Animal et le Cat par le WrongAnimal et le WrongCat, le WrongCat devrait afficher le son du WrongAnimal.

Écrivez et rendez plus de tests que ceux donnés ci-dessus.

## Exercice 01 : Je ne veux pas brûler le monde

| nom de l'exercice    |   Je ne veux pas brûler le monde      |
|----------------------|---------------------------------------|
| Dossier de rendu     | [ex01/](./rendu/ex01/)                |
| Fichier à rendre     | Fichiers de l’exercice précédent + *.cpp, *.{h, hpp} |
| Fonctions interdites | Aucune                                |

Les constructeurs et les destructeurs de chaque classe doivent afficher des messages qui leur sont propres.

Implémentez une classe **Brain** (cerveau) contenant :
- un tableau de 100 std::string appelé ideas (idées).

Ainsi, les classes Dog et Cat auront un attribut privé **Brain\***.
À la construction, les classes Dog et Cat créeront leur Brain avec ````new Brain();```
À la destruction, les classes Dog et Cat devront delete leur Brain.

Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont la moitié est composée d’objets Dog et l’autre moitié d’objets Cat.

À la fin de l’exécution du programme, parcourez ce tableau afin de delete chaque Animal.

Vous devez delete directement les chiens et les chats en tant qu’Animal.

Les destructeurs correspondants doivent être appelés dans le bon ordre.

N’oubliez pas de vérifier que vous n’avez pas de fuites de mémoire!!!!

La copie d’un objet Dog ou d’un objet Cat ne doit pas être superficielle. Par conséquent, vous devez vous assurer que vos copies sont bien des copies profondes.(verifier les pointeur)

code de test :
```cpp
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	...

	return 0;
}
```

## Exercice 02 : Classe abstraite

| nom de l'exercice    |   Classe abstraite                    |
|----------------------|---------------------------------------|
| Dossier de rendu     | [ex02/](./rendu/ex02/)                |
| Fichier à rendre     | Fichiers de l’exercice précédent + *.cpp, *.{h, hpp} |
| Fonctions interdites | Aucune                                |

Créer des objets Animal ne sert pas à grand-chose au final. Ils ne font aucun bruit !

Afin d’éviter les erreurs potentielles, la classe Animal de base ne doit pas être instanciable.

Modifiez-la afin que personne ne puisse l’instancier. Votre code doit fonctionner comme avant.

Si vous le souhaitez, vous pouvez ajouter la lettre A pour préfixer le nom Animal.

## Exercice 03 : Interface & recap

| nom de l'exercice    |   Interface & recap                   |
|----------------------|---------------------------------------|
| Dossier de rendu     | [ex03/](./rendu/ex03/)                |
| Fichier à rendre     | Makefile, main.cpp, *.cpp, *.{h, hpp} |
| Fonctions interdites | Aucune                                |

Les classes purement abstraites sont communément appelées des interfaces.
Donc dans ce dernier exercice, afin de s’assurer que ce module est maîtrisé, vous implémenterez des interfaces.

Complétez la définition de la classe AMateria suivante et implémentez les fonctions membres nécessaires :

```cpp
class AMateria
{
	protected:
		[...]
	public:
		AMateria(std::string const & type);
		[...]

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
```

Implémentez les Materias Ice (glace) et Cure (soin) sous forme de classes concrètes.

Utilisez leur noms en minuscules ("ice" pour Ice, "cure" pour Cure) comme types.

Bien sûr, leur fonction membre clone() retournera une nouvelle instance de même type (en clonant une Materia Ice, on obtient une autre Materia Ice).


Pour ce qui est de la fonction membre **use(ICharacter&)**, elle affichera :
- Ice : "* shoots an ice bolt at < name > *"
- Cure : "* heals < name >’s wounds *

< name > est le nom du Character (personnage) passé en paramètre. N’affichez pas les chevrons (< et >).

>> Quand on assigne une Materia à une autre, copier son type n’a pas
grand intérêt.

Créez la classe concrète Character qui implémentera l’interface suivante :
```cpp
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
```

Le Character a un inventaire de 4 items, soit 4 Materias maximum.

À la construction, l’inventaire est vide.

Les Materias sont équipées au premier emplacement vide trouvé, soit dans l’ordre suivant : de l’emplacement 0 au 3.

Dans le cas où on essaie d’ajouter une Materia à un inventaire plein, ou d’utiliser/retirer une Materia qui n’existe pas, ne faites rien (cela n’autorise pas les bugs pour autant).

La fonction membre unequip() ne doit PAS delete la Materia !

>> Occupez-vous des Materias laissées au sol par votre personnage comme vous le sentez. Vous pouvez enregistrer l’adresse avant d’appeler unequip(), ou autre, du moment que vous n’avez pas de fuites de mémoire

La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement\[idx], et passera la cible en paramètre à la fonction AMateria::use.

>> L’inventaire de votre personnage devra pouvoir contenir n’importe
quel type d’objet AMateria.

Votre Character doit comporter un constructeur prenant son nom en paramètre.

Toute copie (avec le constructeur par recopie ou l’opérateur d’affectation) d’un Character doit être profonde.

Ainsi, lors d’une copie, les Materias du Character doivent être delete avant que les nouvelles ne les remplacent dans l’inventaire.

Bien évidemment, les Materias doivent aussi être supprimées à la destruction d’un Character.

Créez la classe concrète MateriaSource qui implémentera l’interface suivante :

```cpp
class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
```

- learnMateria(AMateria*) :
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias maximum. Ces dernières ne sont pas forcément uniques.

- createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédemment par la MateriaSource et dont le type est le même que celui passé en paramètre. Retourne 0 si le type est inconnu.

MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté.
Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.

Exécuter ce code :
```cpp
int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
```

Devrait afficher :
```bash
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
```

Comme d’habitude, écrivez et rendez plus de tests que ceux donnés ci-dessus.
