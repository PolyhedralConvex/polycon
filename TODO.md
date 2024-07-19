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
  
v.pos: [-10, -10, -10 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [ -10, -10, 0 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, -10, 0 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, -10, 50 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [ -10, 1/10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, 1/10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ -10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ -10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ -10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ -10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ -10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ -10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ -10, 1/10, 399/10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, 1/10, 399/10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, 40, 0 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, 40, 0 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ -10, 50, -10 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [ 299/10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 299/10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 299/10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 299/10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 299/10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 299/10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 299/10, 1/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 399/10, 1/10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 399/10, 1/10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 40, -10, 0 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 40, -10, 0 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 50, -10, -10 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [ 9/10, -10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 9/10, -10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 9/10, -10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, -10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, -10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, -10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, -10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, -10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, -10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, -10, 391/10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 9/10, -10, 391/10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 9/10, 1/10, -10 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, -10 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, -10 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, -10 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, -10 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, -10 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, -10 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1

v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 9/10, 1/10, 0 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0

v.pos: [ 9/10, 1/10, 29 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, 29 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, 29 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, 29 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, 29 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, 29 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 1/10, 29 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 291/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 291/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 291/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 291/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 291/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 291/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 291/10, 0 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 9/10, 391/10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 9/10, 391/10, -10 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2




v.pos: [ 0.900000 , 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000,-2.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000,-0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000,-0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000,-0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000,-6.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000,-0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000,-0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0

v.pos: [ 0.900000,-7.306667, 0.000000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 4.142857 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 23.200000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0
v.pos: [ 0.900000, 0.100000, 8.700000 ], cct.nb_ints: 3, cct.nb_bnds: 0, cct.nb_infs: 0

v.pos: [-10.000000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [-10.000000,-10.000000, 0.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000,-10.000000,-10.000000 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [ 0.900000, 0.100000,-10.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000,-10.000000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000,-10.000000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000, 0.100000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000,-10.000000, 0.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000,-10.000000, 50.000000 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [ 0.900000,-10.000000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [-10.000000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [-10.000000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [-10.000000, 0.100000, 39.900000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 0.900000,-10.000000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000,-10.000000, 39.100000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 0.900000, 0.100000, 29.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000, 29.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [-10.000000, 0.100000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000, 50.000000,-10.000000 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [-10.000000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [-10.000000, 40.000000, 0.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000,-10.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000,-10.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 29.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 39.100000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [-10.000000, 0.100000, 39.900000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [-10.000000, 40.000000, 0.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 0.900000, 29.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000, 29.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 50.000000,-10.000000,-10.000000 ], cct.nb_ints: 0, cct.nb_bnds: 0, cct.nb_infs: 3
v.pos: [ 0.900000,-10.000000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 29.900000, 0.100000,-0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000,-10.000000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000,-10.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 39.900000, 0.100000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 40.000000,-10.000000,-0.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 0.900000,-10.000000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 29.900000, 0.100000,-0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000, 29.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000,-10.000000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000,-10.000000, 39.100000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 29.900000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000,-10.000000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 40.000000,-10.000000, 0.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 0.900000, 0.100000, 29.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 29.900000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 29.900000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000,-10.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 39.900000, 0.100000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 0.900000, 29.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 39.100000,-10.000000 ], cct.nb_ints: 1, cct.nb_bnds: 0, cct.nb_infs: 2
v.pos: [ 29.900000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 29.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 29.900000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 29.900000, 0.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 0.100000, 29.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 29.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
v.pos: [ 0.900000, 29.100000, 0.000000 ], cct.nb_ints: 2, cct.nb_bnds: 0, cct.nb_infs: 1
