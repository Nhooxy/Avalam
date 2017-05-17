Pour compiler : make
Pour demarrer le jeu : make run

Ce programe utilise des librairie externe si vous ne lancer pas via la commande indiquer le programme ne fonctionnera pas . (librairie non installable sur les pc de la fac ce qui implique l'utilisation d'un bash contenant "LD_LIBRARY_PATH=LIB: avalam.run" lancable via le makefile avec la commande "make run" (rappel)


J'utilise pour mon projet en structure de donnée les objet :
joueur : qui contient le nom du joueur et sa couleur;
plateau : qui contient le plateau avec ces dimension;
pion : qui contient la position du pion, sa hauteur et à qui il appartient 

Suite à vos commentaire :
je n'ai pas modifié la classe Joueur, car pour ma logique du code, je n'en est pas l'utilité.

J'ai modifié la difficulté en constante, malgré la perte du choix du niveau que cela implique ... (plus de facile / moyen / difficile) .
