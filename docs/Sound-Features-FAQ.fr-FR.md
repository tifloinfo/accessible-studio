# Fonctions audio : questions et réponses

Complément du [guide d’utilisation](README.fr-FR.html). Aucune clé API n’est nécessaire.

## Quel outil choisir ?

La **console de volume** règle gain, écoute locale et sortie programme. **Audible Meter** avertit et annonce des mesures. **Sound Doctor** réalise une session de mesure et propose des filtres. Ces deux derniers ne peuvent pas fonctionner ensemble.

Tout reste local, sous forme de statistiques de taille limitée en mémoire. Aucun son n’est enregistré ou transmis ; aucun historique de mesures ou rapport n’est sauvegardé. Préférences et exclusions d’entrée sont conservées.

## Que signifient les valeurs ?

Le nombre en dB dans la console est le gain du curseur : 0 dB ne change pas le niveau, une valeur négative le réduit. Ce n’est pas une mesure du volume sonore.

Les crêtes décrivent des pointes brèves. Le RMS représente l’énergie du signal et sert aux niveaux typiques et aux variations. Les mesures en dBFS augmentent en se rapprochant de 0. Pré-fader signifie avant le réglage de volume OBS ; post-fader signifie après. Baisser ce réglage ne répare pas une distorsion déjà présente à l’entrée.

## Pourquoi JAWS lit-il l’ancienne valeur ?

Son traitement des flèches peut annoncer le nombre précédent avant que le module annonce le résultat correct avec « dB ». Dans le test signalé, Insert+3 puis la flèche a supprimé cette annonce périmée. Le réglage lui-même est correct. Le problème est transmis à Vispero ; l’annonce explicite reste prise en charge pour JAWS et NVDA.

## Quand les sons sont-ils émis ?

Les avertissements automatiques de sortie dépendent du temps cumulé au-dessus d’un seuil. Par défaut : 1,5 seconde et la limite rouge OBS, soit −9 dBFS en crête d’échantillon ou −2 dBFS en crête vraie. Une baisse de moins d’une seconde ne remet pas entièrement le compteur à zéro ; une seconde sous le seuil réarme l’avertissement.

Avec Audible Meter actif, la console réagit immédiatement : son moyen en jaune, aigu en rouge. Les limites jaune/rouge sont −20/−9 dBFS en crête d’échantillon et −13/−2 dBFS en crête vraie. Vert, absence de signal ou de source et focus hors des commandes de source restent silencieux.

Le son grave accompagne une correction d’entrée acceptée tant que le signal reste rouge avant le curseur. Les sources Média et vidéo VLC ne déclenchent pas d’avertissement pré-fader.

## Peut-on couper les avertissements et garder les mesures ?

Oui. I bascule les avertissements d’entrée et de sortie lorsque le compteur est actif. Leur réactivation recommence le calcul d’exposition. Les sons de console et H/J/K/L restent disponibles. Ces lettres ne sont jamais interceptées dans les champs de saisie.

H annonce niveau et zone actuels de la source choisie ; J donne la plus forte maintenant. K indique son RMS actif typique sur la session ; L identifie la source ayant le niveau typique le plus élevé. La sélection correspond à la dernière source focalisée dans la console.

## Comment fonctionne la réduction demandée ?

Appuyez sur Maj+I pendant un avertissement de sortie. Pour chaque source responsable, la cible est le seuil moins la marge de sécurité. Le calcul utilise la plus haute crête de l’incident, arrondit la réduction au demi-dB supérieur et respecte le maximum configuré. Il n’augmente jamais le gain et n’agit pas pour un seul avertissement pré-fader.

Valeurs par défaut : marge de 3 dB et réduction maximale de 12 dB. Cela protège les crêtes sans équilibrer à votre place voix, musique et effets.

Ctrl+Maj+I restaure uniquement les curseurs restés à la valeur corrigée. Démarrer ou arrêter le compteur, changer de collection de scènes ou enregistrer ses paramètres efface cette possibilité de restauration unique.

## Pourquoi le guidage d’entrée est-il prioritaire ?

Une distorsion en amont doit être corrigée à la source. La première boîte de dialogue est silencieuse. Oui lance le guidage ; Non ou Échap mémorise une exclusion pour la source inchangée. Un signal actif durablement sain résout l’incident. Une modification d’identité ou de paramètres déclenche une nouvelle évaluation.

Le silence ne constitue pas une réussite. Des annonces surviennent après 2 et 12 secondes sans signal, puis une question après 22 secondes. Continuer attend le signal sans répéter cette séquence. Validez le message de réussite avant la reprise des autres avertissements.

La console suspend le temps d’avertissement de sortie et met les problèmes d’entrée en attente. Un signal actif sain retire un problème devenu caduc ; le silence le conserve. Fermer la console donne la priorité aux problèmes d’entrée encore présents.

## Quels paramètres pour Audible Meter ?

Dans **Outils audio > Paramètres audio avancés > Audible Meter** :

- Seuil de sortie : −30 à 0 dBFS ; valeur initiale selon le mode de crête OBS.
- Durée d’exposition : 0,1–30 secondes ; défaut 1,5 seconde.
- Marge de sécurité : 0–12 dB ; défaut 3 dB.
- Réduction maximale : 0,5–30 dB ; défaut 12 dB.
- Liste d’exclusions pré-fader : retirer une exclusion pour vérifier de nouveau cette entrée.

Ces réglages ne changent ni les zones de console, ni H/J/K/L, ni la limite rouge d’entrée. Il existe un seul mode sans fenêtre. Appliquer enregistre, OK enregistre et ferme, Annuler abandonne depuis le dernier Appliquer.

## Combien de temps faut-il à Sound Doctor ?

Au moins 120 secondes, dont 45 secondes de signal actif par source pour proposer un traitement. Ces durées sont fixes. La mesure peut continuer pendant la diffusion ou l’enregistrement ; les résultats attendent leur arrêt à tous deux. Utilisez des sons représentatifs. Le programme ne comprend pas les paroles et ne distingue pas fiablement musique et voix.

## Quand proposer un compresseur ?

La source doit être probablement une entrée en direct, suffisamment active et inchangée. Aucun compresseur ni limiteur ne doit exister, même désactivé. L’écart dynamique doit atteindre le minimum configuré, 8 dB par défaut.

Cet écart sépare la médiane du RMS actif et son 95e centile. Le RMS est corrigé du gain du curseur OBS. Le nouveau compresseur suit les traitements existants et précède un éventuel nouveau limiteur.

Son seuil est la médiane plus 5 dB, arrondie et limitée entre −24 et −10 dB. Attaque : 6 ms ; relâchement : 100 ms ; gain de sortie : 0 dB. Rapport : 2:1 sous 10 dB d’écart, 2,5:1 entre 10 et moins de 14 dB, puis le maximum configuré. Ne compressez la musique que si vous souhaitez cet effet.

## Quand proposer un limiteur ?

Par défaut, pour une entrée probablement en direct, suffisamment active, inchangée et sans limiteur. Un écrêtage préalable n’est pas requis : la protection est préventive. Le nouveau limiteur termine la chaîne, avec plafond de −3 dBFS et relâchement de 60 ms par défaut. Il ne répare pas la distorsion antérieure et ne garantit pas l’absence de surcharge du mélange total.

La portée peut inclure toutes les sources actives, même si un média déjà maîtrisé peut ne pas en avoir besoin. Les deux types de recommandation sont indépendants. Le rapport décrit aussi les filtres existants, un limiteur non placé en dernier, des crêtes d’entrée proches de l’écrêtage et les données insuffisantes ou périmées.

## Quels paramètres pour Sound Doctor ?

- Écart dynamique minimal : 6–15 dB ; défaut 8 dB.
- Rapport maximal : 2,5:1, 3:1 ou 3,5:1 ; défaut 3:1. Des rapports inférieurs restent possibles.
- Portée du limiteur : entrées probablement en direct ou toutes les sources actives.
- Plafond : −12 à −1 dBFS ; défaut −3 dBFS.

## Peut-il modifier sans mon accord ?

Non. Rien n’est coché au départ. Terminer applique seulement vos choix après vérification de la source, du volume et des filtres. Les sources modifiées sont ignorées. Échap ferme sans changement. Les filtres ajoutés permettent Annuler et Rétablir dans OBS.

Ctrl+Maj+D peut interrompre la mesure et l’abandonner après confirmation. Non ou Échap poursuit. L’option de mémorisation peut désactiver cette confirmation.
