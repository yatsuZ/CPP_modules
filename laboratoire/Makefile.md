# Makefile

Rapelle des makefile

## Documentation

- [video](https://youtu.be/-riHEHGP2DU?si=i5SAdzKg8BHN91Hf)
- [manuel ecris](https://www.gnu.org/software/make/manual/make.html)
- mes ancien makefile et mes connaissance de pratique 

## C'est quoi

C'est un fichier qui permet de facilité la compilation.
Comment en permetant de crée des variables, des regles et condition pour compiler plusieur fichier.

juste en effectuant la commande ```make``` est peut metre des otpions.

sans makefile on peut faire
```
[compilation] [option] [fichier source]
```

si on modifie un fichier source le makfile metra a jour seulement les fichier modifier.

## Norme de 42

```txt
Les Makefile ne sont pas vérifiés pas La Norminette. Ils doivent être vérifiés par un humain pendant l’évaluation.

1. Les règles $(NAME), clean, fclean, re et all sont obligatoires.
2. Le projet est considéré comme non fonctionnel si le Makefile "relink".
3. Dans le cas d’un projet multibinaire, en plus des règles précédentes, vous devez avoir une règle all compilant les deux binaires ainsi qu’une règle spécifique à chaque binaire compilé.
4. Dans le cas d’un projet faisant appel à une bibliothèque de fonctions (par exemple une libft), votre makefile doit compiler automatiquement cette bibliothèque.
5. Les sources nécessaires à la compilation de votre programme doivent être explicitement citées dans votre Makefile.
```

pour la regle 1 on exepliquera chaqu'une des regles citée.
la 2 on ne dois pas relink voici [une explication de relink](https://stackoverflow.com/questions/52502399/what-does-it-mean-for-a-makefile-to-relink#:~:text=In%20this%20context%2C%20%E2%80%9Crelink%E2%80%9D,objects%20into%20an%20executable%20again.) :

>> Dans ce contexte, « relink » signifie simplement que make exécutera à nouveau la commande pour lier les objets dans un exécutable.

en bref c'est refaire une compilation de fichier .o alors qu'il na pas eu de modifaction or ce n'est pas neccessaire !!

la regle 3 dis que il y a different executable .out que le regle all compile les different fichier binaire.

La regles 4 c'est simple un makefile doit compiler les autre makefile interieur si il y en a exemple libft.

La regles 5 est claire c'est que les source doivent etre explicitement citer.

## Comment en faire un ?


### version 0

```makefile
<cible>: <dependance>
	<commande>
```

et si il y a plusieur cible alors execute par ordre la premiere cible

generalement la premiere cible ````all``` est une cible special que l'on met la depandance final et ce qui permetra de ne pas faire attentione a lordre des cible.

il y a aussi la cible ```clean``` qui ne depant de rien et cette cible permet de suprimer tout les fichier objet.
Et la cible mrproper aussi apeller ```fclean``` qui depdant de clean et surpimer le programme aussi a noter que les 2 cible sont placer en dernier.

[exemple](./00_namespace/Makefile)

## version 1

Mais si on as plusieur fichier on peut les stocker dans des varible comme certaine information etc pour crée des variable il sufit d'ecrire en majuscule et coller et faire =

```makefile
SRC = main.cpp
```

il y a des varible spéciaux :
```makefile
$@ nom cible
$< nom de la premiere dépendance
$^ liste dépendance
$? liste dépendance plus récentes que la cible
$* nom fichier, sans exentsion
```

[exemple](./02_Classe_Instance/Makefile)

## version 2

On mettre aussi des condtion.

Voici la syntaxe
```makefile
UBUNTU = yes

ifeq ($(UBUNTU), yes)
	echo nous somme sur UBUNTU
else
	echo nous ne somme pqs sur UBUNUT
```

## version 3

l'objectif est de compiler different fichier ensemble et j'aimerais aussi avoir une bonne arborecence pour le rangement de mes fichier objet.

DONC je veux crée un dossier obj ou ranger mes .o exemple :

```txt
|
|- Makefile
|- [...].cpp
-
```

faire make qui fais :

```txt
|
|- Makefile
|- [...].cpp
|
|---- obj
    |- [...].o
-
```

[exemple](./04_this_self/Makefile)

## version 4

j'aimerais rajouter de l'esthethisme comme des couleur barre de chargement ou autre et la libre a mois 