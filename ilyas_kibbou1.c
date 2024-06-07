/*Exercice 1 Dénir une structure struct noeud_s permettant de coder un n÷ud d'un arbre
binaire contenant une valeur entière. Ajouter des typedef pour dénir les nouveaux types
noeud_t et arbre_t (ces types devraient permettre de représenter une feuille, c'est à dire un
arbre vide).*/
typedef struct noeud_s {
int v al e u r ;
struct noeud_s ∗ gauche ;
struct noeud_s ∗ d r o i t ;
} ∗noeud_t ;
typedef noeud_t arbre_t ;
/*Exercice 2 Écrire une fonction cree_arbre() qui prend en argument une valeur entière ainsi
que deux arbres et renvoie un arbre dont la racine contient cette valeur et les deux sous-arbres
sont ceux donnés en paramètre.*/
I Correction
#include < s t d l i b . h>
arbre_t c ree_ a r b re ( int v al e u r , arbre_t gauche , arbre_t d r o i t ) {
arbre_t a r b r e = m all oc ( s i z e o f ( struct noeud_s ) ) ;
a rb re−>v al e u r = v al e u r ;
a rb re−>gauche = gauche ;
a rb re−>d r o i t = d r o i t ;
return a r b r e ;
}
/*Exercice 12  Bonus (diculté : •••) Écrire une fonction supprime() qui supprime une
valeur de l'arbre (on supprimera la première rencontrée) tout en conservant les propriétés
d'ABR. L'algorithme est le suivant (une fois trouvé le n÷ud contenant la valeur en question) :
 si le n÷ud à enlever ne possède aucun ls, on l'enlève,
 si le n÷ud à enlever n'a qu'un ls, on le remplace par ce ls,
 si le noeud à enlever a deux ls, on le remplace par le sommet de plus petite valeur dans le
sous-arbre droit, puis on supprime ce sommet.*/
I Correction
arbre_t supprime ( arbre_t a rb re , int v al e u r ) {
noeud_t noeud = a rb re , ∗ p e r e = &a r b r e ;
noeud_t nouveau_noeud , ∗nouveau_pere ;
while ( noeud != NULL) {
i f ( v al e u r == noeud−>v al e u r )
break ;
i f ( v al e u r < noeud−>v al e u r ) {
p e r e = &noeud−>gauche ;
noeud = noeud−>gauche ;
} e l s e { /∗ v a l e u r >= noeud−>v a l e u r ∗/
p e r e = &noeud−>d r o i t ;
noeud = noeud−>d r o i t ;
}
}
i f ( noeud != NULL) {
i f ( noeud−>gauche == NULL) {
i f ( noeud−>d r o i t == NULL) {
∗ p e r e = NULL;
f r e e ( noeud ) ;
} e l s e { /∗ noeud−>d r o i t != NULL ∗/
∗ p e r e = noeud−>d r o i t ;
f r e e ( noeud ) ;
}
} e l s e { /∗ noeud−>gauche != NULL ∗/
i f ( noeud−>d r o i t == NULL) {
∗ p e r e = noeud−>gauche ;
f r e e ( noeud ) ;
} e l s e { /∗ noeud−>d r o i t != NULL ∗/
/∗ r e c h e r c h e de l a p l u s p e t i t e v a l e u r du sous−a r b r e d r o i t ∗/
nouveau_noeud = noeud−>d r o i t ;
nouveau_pere = &noeud−>d r o i t ;
while ( nouveau_noeud != NULL)
i f ( nouveau_noeud−>gauche != NULL) {
nouveau_pere = &nouveau_noeud−>gauche ;
nouveau_noeud = nouveau_noeud−>gauche ;
}
noeud−>v al e u r = nouveau_noeud−>v al e u r ;
∗nouveau_pere = nouveau_noeud−>d r o i t ;
f r e e ( nouveau_noeud ) ;
}
}
}
return a r b r e ;
}

