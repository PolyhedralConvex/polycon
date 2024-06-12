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
  

  sps: [ 5.768159, -34.095425, 45.631744, 5.768159 ]
  vertex_corr: [ 0, 1, 0, 0 ]
  sps: [ 3.414737, -0.011982, -0.011982, -44.559331 ]
  vertex_corr: [ 0, 1, 1, 1 ]
  sps: [ 27.186673, 27.305893, 27.305893, -6.789532, 27.186673, -6.789532 ]
  vertex_corr: [ 0, 0, 0, 1, 0, 1 ]
  sps: [ 4.100924, -0.700000, -0.700000, 4.100924, 4.100924, 4.100924 ]
  vertex_corr: [ 0, 1, 1, 0, 0, 0 ]
  sps: [ -8.650000, -0.000000, -0.000000, 11.533333, 11.533333, -8.650000 ]
  vertex_corr: [ 1, 1, 1, 0, 0, 1 ]
  sps: [ -185.239600, -0.000000, -185.239600, 4.942857, -0.000000, -0.000000, -183.173928, -185.239600 ]
  vertex_corr: [ 1, 1, 1, 0, 1, 1, 1, 1 ]
  sps: [ 8.650000, 0.000000, 0.000000, -11.533333, -11.533333, 8.650000 ]
  vertex_corr: [ 0, 0, 0, 1, 1, 0 ]
  sps: [ 4.942857, -0.000000, -185.239600, -0.000000, -191.953033, -183.173928 ]
  vertex_corr: [ 0, 1, 1, 1, 1, 1 ]
  sps: [ 185.239600, 0.000000, 185.239600, -11.533333, 180.419699, 0.000000 ]
  vertex_corr: [ 0, 0, 0, 1, 0, 0 ]
  sps: [ -8.650000, 0.000000, 11.533333, 0.000000 ]
  vertex_corr: [ 1, 0, 0, 0 ]
  sps: [ -52.095715, -0.011982, -0.011982, 3.994459 ]
  vertex_corr: [ 1, 1, 1, 0 ]
  sps: [ 5.768159, -34.095425, 45.631744, 45.512523, 5.768159, -33.976204 ]
  vertex_corr: [ 0, 1, 0, 0, 0, 1 ]
  sps: [ -19.923881, 4.100924, 4.100924, -20.008182, 4.100924, 4.100924 ]
  vertex_corr: [ 1, 0, 0, 1, 0, 0 ]
  sps: [ 27.186673, 27.186673, -0.989949, 27.305893, 27.305893, -0.989949 ]
  vertex_corr: [ 0, 0, 1, 0, 0, 1 ]
  sps: [ 185.239600, 176.589600, 191.953033, -8.650000, -0.000000, -0.000000 ]
  vertex_corr: [ 0, 0, 0, 1, 1, 1 ]
  sps: [ -11.533333, 8.650000, -0.000000, -0.000000, -0.000000, -11.533333 ]
  vertex_corr: [ 1, 0, 1, 1, 1, 1 ]
  sps: [ -185.239600, -176.589600, -191.953033, 8.650000, 0.000000, 0.000000 ]
  vertex_corr: [ 1, 1, 1, 0, 0, 0 ]
  sps: [ 0.000000, 8.650000, -11.533333, -11.533333, 8.650000, -0.000000 ]
  vertex_corr: [ 0, 0, 1, 1, 0, 1 ]
  sps: [ -185.239600, -185.239600, -180.419699, 0.000000, 0.000000, 11.533333 ]
  vertex_corr: [ 1, 1, 1, 0, 0, 0 ]
  sps: [ -0.000000, -8.650000, 11.533333, 11.533333, -8.650000, 0.000000 ]
  vertex_corr: [ 1, 1, 0, 0, 1, 0 ]



  sps: [ 5.768159, -34.095425, 45.631744, 5.768159 ]
  vertex_corr: [ 0, 1, 0, 0 ]
  sps: [ 3.414737, -0.011982, -0.011982, -44.559331 ]
  vertex_corr: [ 0, 1, 1, 1 ]
  sps: [ 27.186673, 27.305893, 27.305893, -6.789532, 27.186673, -6.789532 ]
  vertex_corr: [ 0, 0, 0, 1, 0, 1 ]
  sps: [ 4.100924, -0.700000, -0.700000, 4.100924, 4.100924, 4.100924 ]
  vertex_corr: [ 0, 1, 1, 0, 0, 0 ]
  sps: [ -8.650000, -0.000000, -0.000000, 11.533333, 11.533333, -8.650000 ]
  vertex_corr: [ 1, 1, 1, 0, 0, 1 ]
  sps: [ -185.239600, -0.000000, -185.239600, 4.942857, 0.000000, -0.000000, -183.173928, -185.239600 ]
  vertex_corr: [ 1, 1, 1, 0, 0, 1, 1, 1 ]
  sps: [ 8.650000, 0.000000, 0.000000, -11.533333, -11.533333, 8.650000 ]
  vertex_corr: [ 0, 0, 0, 1, 1, 0 ]
  sps: [ 4.942857, 0.000000, -185.239600, 0.000000, -191.953033, -183.173928 ]
  vertex_corr: [ 0, 0, 1, 0, 1, 1 ]
  sps: [ 185.239600, 0.000000, 185.239600, -11.533333, 180.419699, 0.000000 ]
  vertex_corr: [ 0, 0, 0, 1, 0, 0 ]
  sps: [ -8.650000, -0.000000, 11.533333, -0.000000 ]
  vertex_corr: [ 1, 1, 0, 1 ]
  sps: [ -52.095715, -0.011982, -0.011982, 3.994459 ]
  vertex_corr: [ 1, 1, 1, 0 ]
  sps: [ 5.768159, -34.095425, 45.631744, 45.512523, 5.768159, -33.976204 ]
  vertex_corr: [ 0, 1, 0, 0, 0, 1 ]
  sps: [ -19.923881, 4.100924, 4.100924, -20.008182, 4.100924, 4.100924 ]
  vertex_corr: [ 1, 0, 0, 1, 0, 0 ]
  sps: [ 27.186673, 27.186673, -0.989949, 27.305893, 27.305893, -0.989949 ]
  vertex_corr: [ 0, 0, 1, 0, 0, 1 ]
  sps: [ 185.239600, 176.589600, 191.953033, -8.650000, -0.000000, -0.000000 ]
  vertex_corr: [ 0, 0, 0, 1, 1, 1 ]
  sps: [ -11.533333, 8.650000, 0.000000, 0.000000, 0.000000, -11.533333 ]
  vertex_corr: [ 1, 0, 0, 0, 0, 1 ]
  sps: [ -185.239600, -176.589600, -191.953033, 8.650000, 0.000000, 0.000000 ]
  vertex_corr: [ 1, 1, 1, 0, 0, 0 ]
  sps: [ 0.000000, 8.650000, -11.533333, -11.533333, 8.650000, 0.000000 ]
  vertex_corr: [ 0, 0, 1, 1, 0, 0 ]
  sps: [ -185.239600, -185.239600, -180.419699, -0.000000, -0.000000, 11.533333 ]
  vertex_corr: [ 1, 1, 1, 1, 1, 0 ]
  sps: [ -0.000000, -8.650000, 11.533333, -8.650000, -0.000000, 11.533333, 0.000000, -8.650000 ]
  vertex_corr: [ 1, 1, 0, 1, 1, 0, 0, 1 ]
