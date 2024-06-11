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
  