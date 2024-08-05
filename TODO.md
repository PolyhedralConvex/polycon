* valeur en 1 point
* gestion des bords infinis
  => faire les points "représentatifs" des InfCells (les items genre surface qui ne donne pas forcément de vertex)
* dérivées de la transformée de Legendre
  => prop: pour la phase backward, on donne 

Pb: les InfCells peuvent produire des items qui ne se traduisent pas forcément par des points, par exemple 2 cuts en 3D
  On pourrait peut être vérifier si des cuts disparaissent des InfCells si on ajoute les propositions
  Autre prop: on regarde si la coupe dans l'autre sens est "inutile". C'est ce qu'on veut vérifier pour s'assurer que la coupe ne va pas faire disparaître des items.

  Cependant, il nous faut des points "représentatifs" pour les mxx_box_pos.

  On pourrait par exemple dire que pour chaque item, on veut un point contraint sur la "surface", le plus proche possible de tous les enfants
    Rq: pour un coin avec des edges infinis, ça va donner un point
    Prop: on vérifie pour l'exemple qu'il y a bien des items sans point

En fait... le problème de la transformée de Legendre en 3D venait de la précision machine. Ça fonctionne même avec `min_box_pos` calculé avec les InfCells.
  
Rq: on pourrait supprimer les tests de dimensionalité par des tests sur les items infinis
  => les items infinis sont crées par la coupe de cellules et ne contiennent que des points infinis
  => il y aura un critère "faible" à surveiller pour déterminer s'il y a une coupe à l'infini ou avant... 
  => on pourra avoir des items de différentes dimensions. Un edge en 3D veut dire qu'on enlève une dimension

Prop: on commence par raisonner avec des cellules infinies. On gérera ensuite les cas des cellules coupées.
  En 2D, on peut avoir
  * une cellule infinie de tous les côtés => les bords contraignent à 1 point. On peut ensuite trouver l'offset avec ce point
  * une cellule qui délimite un demi-espace => on va avoir des 2 bords pour créer une égalité puis 1 bord pour un inégalité.
    La nouvelle cellule va définir une ligne au sein de l'espace délimité par une égalité
  * une cellule avec

  De base, on pourrait dire qu'une cellule infinie représente un point de bord
    => s'il y a des voisines infinies, 

Basiquement, les edges infinis donnent des boundaries.
  On ne considères que les edges qui ont au moins une coupe qui vient d'une cellule ext : on garde les points qui ont une référence de coupe + 
  Lorsqu'il n'y a pas 

Dans l'exemple 2D qui revient à du 1D, on n'a pas de point d'intersection qui va créer de nouvelle cellule
  Cependant, on a une cellule 

Prop: on fait un cas particulier pour les contraintes d'égalité.
  
  (PI)rb_base.leaf: 110965444466448 n0: 0
    (PI)rb.leaf: 110965444466448 n1: 1
    (PI)rb.leaf: 110965444466608 n1: 0
    (PI)rb.leaf: 110965444466608 n1: 1
    (PI)rb.leaf: 110965444466608 n1: 2
  (PI)rb_base.leaf: 110965444466448 n0: 1
    (PI)rb.leaf: 110965444466448 n1: 0
    (PI)rb.leaf: 110965444466608 n1: 0
    (PI)rb.leaf: 110965444466608 n1: 1
    (PI)rb.leaf: 110965444466608 n1: 2
  (PI)rb_base.leaf: 110965444466608 n0: 0
    (PI)rb.leaf: 110965444466608 n1: 1
    (PI)rb.leaf: 110965444466608 n1: 2
  (PI)rb_base.leaf: 110965444466608 n0: 1
    (PI)rb.leaf: 110965444466608 n1: 0
    (PI)rb.leaf: 110965444466608 n1: 2
  (PI)rb_base.leaf: 110965444466608 n0: 2
    (PI)rb.leaf: 110965444466608 n1: 0
    (PI)rb.leaf: 110965444466608 n1: 1
