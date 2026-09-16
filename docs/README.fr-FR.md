# Accessible Studio : guide d’utilisation

Accessible Studio ajoute à OBS Studio sous Windows des commandes au clavier, des annonces vocales, des outils audio et une analyse d’image facultative. Il s’adresse aux personnes aveugles utilisant JAWS ou NVDA. Les [questions sur les fonctions audio](Sound-Features-FAQ.fr-FR.html) expliquent les mesures et les filtres.

## Installation et suppression

Il faut Windows 10 ou 11 et OBS Studio 32.x, tous deux en 64 bits. Seules les analyses d’image et de compatibilité nécessitent une clé API OpenAI. Les outils audio et les commandes au clavier fonctionnent sans clé.

1. Installez OBS depuis son [site officiel](https://obsproject.com/download).
2. Fermez OBS, puis lancez le programme d’installation de la version d’Accessible Studio reçue.
3. Suivez les instructions. Une connexion Internet est nécessaire si le programme doit télécharger Microsoft WebView2 ou le runtime Visual C++ manquant.
4. Relancez OBS et ouvrez **Outils > Accessible Studio**.

L’installation s’arrête si OBS est absent, endommagé ou antérieur à 32.0. À partir d’OBS 33, un avertissement propose la [dernière version du module](https://github.com/tifloinfo/accessible-studio/releases/latest). Continuer malgré cet avertissement ne garantit pas la compatibilité. Le programme vous demande de fermer OBS ; il ne le ferme jamais de force.

Le module est installé dans `C:\ProgramData\obs-studio\plugins\accessible-studio`, sans remplacer les fichiers OBS ou Qt ni créer de raccourci sur le Bureau. La dernière page peut ouvrir le manuel.

**Migration depuis Accessible OBS Studio 1.0 :** l’ancien module, ses paramètres propres, ses raccourcis, son cache et sa clé API sont supprimés. Les autres réglages et contenus OBS sont conservés. Les mises à jour au sein d’Accessible Studio 1.1.x conservent paramètres et clé.

Pour désinstaller, fermez OBS puis utilisez les applications installées de Windows. La désinstallation conserve les paramètres et la clé. Supprimez d’abord celle-ci dans la gestion des clés API si vous ne souhaitez plus la garder.

## Menus et aide

Dans **Outils > Accessible Studio**, les outils audio regroupent la console de volume, Audible Meter, Sound Doctor et les paramètres audio avancés. Les outils vidéo regroupent les descriptions, la lecture de texte, les personnes et arrière-plans, la vérification visuelle et les clés API.

Le menu contient aussi l’éditeur de raccourcis et le manuel. Celui-ci s’ouvre dans le navigateur, dans la langue d’OBS si elle est disponible, sinon en anglais.

## Raccourcis par défaut

Les conflits existants ou vos propres affectations peuvent modifier ces raccourcis.

### Navigation

- F6 / Maj+F6 : zone principale suivante / précédente.
- Ctrl+0 : aperçu vidéo.
- Ctrl+1 : scènes.
- Ctrl+2 : sources.
- Ctrl+3 : mélangeur audio.
- Ctrl+4 : transitions de scènes.
- Ctrl+5 : commandes.
- Ctrl+M : commandes multimédias visibles.
- Alt+1 à Alt+9 : neuf premières scènes dans l’ordre affiché ; Alt+0 : dixième scène.

Si NVDA est le seul lecteur d’écran détecté, le nom de la zone est annoncé en complément. Le mélangeur natif conserve son fonctionnement OBS habituel.

### Sorties et audio

- F5 : démarrer ou arrêter la diffusion.
- F7 : démarrer ou arrêter l’enregistrement, même en pause.
- Alt+F7 : mettre en pause ou reprendre, si la configuration OBS le permet.
- F8 : démarrer ou arrêter la caméra virtuelle.
- Alt+F2 : état des sorties et du mode Studio ; Entrée ou Échap ferme la fenêtre.
- Ctrl+Grave : console de volume. Il s’agit de la touche physique juste sous Échap, quel que soit le caractère imprimé.
- Ctrl+I : activer ou désactiver Audible Meter.
- Ctrl+Maj+D : lancer ou interrompre Sound Doctor.

Les changements d’état terminés sont annoncés, ainsi que la perte puis le rétablissement de la connexion de diffusion.

### Image

Ces commandes nécessitent Internet et une clé API ; il n’est pas nécessaire de placer le focus sur l’aperçu.

- F3 : description courte, limitée à 80 caractères.
- Maj+F3 : description détaillée.
- Alt+F3 : texte visible, sans traduction ni commentaire.
- Ctrl+F3 : personnes visibles et leur environnement immédiat.
- F4 : vérification de la composition et de la qualité de l’image.

## Modifier les raccourcis

Dans l’éditeur, recherchez une commande et sélectionnez-la avec les flèches. Entrée ou Ajouter ou modifier ouvre son affectation. Saisissez la combinaison, ajoutez-en d’autres si nécessaire, puis validez. **OK dans l’éditeur principal** enregistre les changements.

Un conflit déclenche une demande de réaffectation. Suppr ou Supprimer dans la liste principale efface toutes les affectations de la commande sélectionnée. Fermer avec des modifications propose de les enregistrer, les abandonner ou revenir. Les touches de navigation et les combinaisons système réservées ne sont pas capturées.

Si le profil, la collection de scènes ou des affectations concernées changent pendant la saisie, l’enregistrement peut être refusé. Rouvrez alors l’éditeur.

Par défaut, les raccourcis OBS ne fonctionnent que lorsque l’application est active. Pour laisser OBS gérer leur portée, cochez l’option correspondante dans l’éditeur et enregistrez. Le réglage de focus des raccourcis d’OBS reprend alors effet.

Au démarrage ou après un changement de profil, vous pouvez conserver les affectations existantes ou remplacer uniquement les combinaisons en conflit. Les raccourcis par défaut concernés restent non affectés si vous conservez l’existant. Le choix mémorisé vaut pour cette version dans tous les profils. Les affectations personnalisées non vides sont conservées lors de la migration des valeurs par défaut. La commande ouvrant directement le menu du module n’a pas de raccourci par défaut.

## Régler le volume

Ctrl+Grave ouvre la console accessible. Les changements sont immédiats.

- Gauche / Droite : source précédente / suivante.
- Haut / Bas : augmenter / réduire le gain de 1 dB.
- Origine : régler le gain à 0 dB.
- 1 à 9, puis 0 : sélectionner les sources 1 à 10.
- Espace : basculer ensemble l’écoute locale et la sortie programme.
- Ctrl+Espace : basculer seulement l’écoute locale.
- Maj+Espace : basculer seulement la sortie programme.
- Échap : fermer et retrouver la commande OBS précédente.

L’écoute locale, ou monitoring, est le son que vous entendez. La sortie programme alimente la diffusion ou l’enregistrement. Chaque fonction dispose aussi d’un bouton.

La liste contient d’abord les sources actives du programme, pas celles présentes uniquement dans l’aperçu du mode Studio. Activez **Afficher toutes les sources** avec Entrée, pas Espace, pour inclure les sources inactives. Gauche et Droite atteignent toutes les sources, même au-delà de dix. La liste et les valeurs sont actualisées deux fois par seconde.

Le gain ne dépasse normalement pas 0 dB. Une valeur positive déjà réglée ailleurs dans OBS reste accessible. OBS 32.2 permet de gérer indépendamment le silence et le monitoring ; les versions prises en charge antérieures utilisent les anciens états de monitoring.

Après Haut ou Bas, le module annonce le résultat en dB, même en butée. Les frappes rapides regroupent les annonces en attente ; quitter la source annule les annonces restantes.

**JAWS :** une ancienne valeur peut être prononcée avant la bonne valeur suivie de « dB ». Le volume change pourtant dans le bon sens. Lors du test signalé, Insert+3 suivi de la flèche a supprimé l’annonce périmée. Le problème est transmis à Vispero. L’annonce explicite reste disponible pour JAWS et NVDA.

## Audible Meter

Ctrl+I active un seul mode sans fenêtre. Il suit les sources actives même hors diffusion ou enregistrement. Les avertissements sont activés au départ. Il n’ouvre pas la console automatiquement et ne modifie aucun filtre.

- I : activer ou couper les avertissements automatiques d’entrée et de sortie.
- H : niveau et zone actuels de la dernière source choisie dans la console.
- J : source actuellement la plus forte et son niveau.
- K : niveau actif typique de la source choisie pour cette session.
- L : source dont le niveau actif typique est le plus élevé.
- Maj+I : pendant un avertissement de sortie, demander une réduction prudente des sources responsables.
- Ctrl+Maj+I : rétablir la dernière réduction, sauf sur les sources réglées depuis.

Ces lettres ne sont pas interceptées dans une zone de saisie. H et K indiquent si aucune source n’a été choisie.

### Comprendre les sons

Le **son grave** accompagne une correction d’entrée acceptée : le signal reste trop fort avant le réglage OBS. Réduisez le gain du périphérique, de l’entrée Windows ou de l’application source. Le **son moyen** indique la zone jaune de la source sélectionnée dans la console. Le **son aigu** indique sa zone rouge ou un avertissement automatique de sortie. La zone verte, l’absence de signal ou de source et le focus hors des commandes de source restent silencieux.

Les sons de la console sont immédiats. Les avertissements exigent une durée d’exposition. I ne coupe pas les sons de mesure de la console.

Un avertissement d’entrée ouvre d’abord une boîte de dialogue silencieuse. Oui lance le guidage ; Non ou Échap mémorise une exclusion pour cette source inchangée. Le silence ne prouve pas que le problème est résolu : des annonces précèdent une question sur la poursuite du contrôle. Un signal actif durablement sain termine le guidage. Validez le message de réussite pour reprendre les autres avertissements.

Dans la console, le chronométrage des avertissements de sortie est suspendu ; les problèmes d’entrée attendent sa fermeture. Ouvrir la console pendant un guidage demande si vous souhaitez poursuivre ; Non mémorise l’exclusion et ouvre la console.

Les paramètres audio avancés règlent seuil, durée d’exposition, marge, réduction maximale et exclusions. Ils ne changent ni les zones de la console ni H/J/K/L. Aucun mode séparé, historique ou fichier de rapport n’est créé.

## Sound Doctor

Sound Doctor et Audible Meter ne peuvent pas fonctionner simultanément.

1. Appuyez sur Ctrl+Maj+D et confirmez le démarrage.
2. Produisez des sons représentatifs pendant au moins deux minutes. Chaque source doit fournir 45 secondes de signal actif pour recevoir des propositions de filtres.
3. Arrêtez diffusion et enregistrement pour afficher les résultats ; jusque-là, les mesures peuvent continuer.
4. Lisez les recommandations et cochez celles voulues. Rien n’est coché au départ.
5. Terminer applique les choix ; Échap ferme sans modification.

La compression peut réduire de fortes variations d’un signal probablement capté en direct. Un limiteur protège contre des pointes futures. Le programme n’identifie pas les paroles et ne distingue pas fiablement la musique : ne sélectionnez sa compression que si vous souhaitez cet effet.

Sources et filtres sont vérifiés avant application ; les sources modifiées sont ignorées. Les traitements existants ne sont pas dupliqués. Un nouveau compresseur suit les filtres existants et précède le nouveau limiteur final. Les filtres portent le nom Sound Doctor et permettent Annuler et Rétablir dans OBS.

Ctrl+Maj+D interrompt une session après confirmation et abandonne ses mesures. Non ou Échap poursuit. L’option de mémorisation peut supprimer cette confirmation. Si le rapport est déjà ouvert, la commande lui rend le focus. Il est masqué pendant une diffusion ou un enregistrement.

Les paramètres Sound Doctor définissent la politique de recommandation. Appliquer enregistre ; OK enregistre et ferme ; Annuler abandonne les modifications depuis le dernier Appliquer. Consultez la [FAQ audio](Sound-Features-FAQ.fr-FR.html) pour les valeurs.

## Commandes multimédias

Avec Ctrl+M, placez le focus sur les commandes visibles d’une source lisible. Gauche/Droite recule/avance de 5 secondes ; Maj+Gauche/Droite d’une minute ; Page précédente/suivante de 5 minutes. Ces commandes ne changent pas le comportement des autres zones.

## Description et correction d’image

Enregistrez une clé dans les outils vidéo. Après validation, elle est stockée dans le Gestionnaire d’identification Windows pour votre compte. Elle n’est jamais affichée ; un remplacement raté conserve l’ancienne clé. Sa suppression demande confirmation.

Une commande d’image capture le rendu OBS et un clic confirme la demande. Une fenêtre WebView2 accessible présente les résultats. Chaque nouvelle réponse est annoncée une fois ; Copier le dernier résultat ne copie que celle-ci. À la fermeture, le focus est rétabli lorsque cela convient.

Les questions liées à l’image et les descriptions proposées réutilisent la conversation. La fermer ou lancer une nouvelle capture la termine. Vérifier à nouveau envoie une nouvelle image pour comparaison.

La vérification visuelle examine éclairage, cadrage, taille, flou, bruit, captures vides et obstructions. Elle ne juge ni sens, ni opinions, ni orthographe. Le texte n’est évalué que pour sa présentation. Des commandes ou bordures Zoom ordinaires ne suffisent pas à conclure à un affichage en fenêtre.

Les corrections proposées permettent de choisir une source vidéo, puis une transformation et son risque. Avec une seule source, sa sélection est automatique. Vous approuvez une correction à la fois. L’étirement à l’écran, les commandes arbitraires, l’audio, les sorties, les identifiants et la suppression de scènes sont exclus.

Après un ajustement au canevas, un contrôle supplémentaire peut évaluer la qualité. Si elle est mauvaise ou incertaine, les transformations enregistrées sont restaurées et la source recentrée uniquement si l’état de la scène correspond toujours. Aucune commande Annuler générale n’écrase les modifications faites pendant l’attente. Ce contrôle en ligne est désactivé en mode Studio, où aperçu et programme peuvent différer.

## Confidentialité et compatibilité

L’analyse d’image envoie à OpenAI l’image, la langue OBS, les instructions et les questions. L’analyse de compatibilité envoie versions, dépendances et description des fonctions. La clé sert à l’authentification, pas de contenu à analyser. Son propriétaire assume les frais API.

Pour une version majeure OBS plus récente que celles testées, vous pouvez annuler, continuer ou analyser la compatibilité. L’analyse associe vérifications locales en lecture seule et sources OBS officielles consultées via OpenAI. Elle estime le risque sans garantie. Un rapport réussi est conservé pour cette combinaison exacte de versions et d’architecture et copié dans le Presse-papiers.

Les outils audio restent locaux, sans enregistrement sonore, transmission audio ou historique des mesures. Préférences et exclusions sont conservées. Le module n’intègre ni publicité ni télémétrie.

## Dépannage et licence

Si le module manque, vérifiez OBS 64 bits et fermez-le avant de réinstaller. Pour les raccourcis, vérifiez affectations, conflits et réglage de focus. Les commandes multimédias nécessitent une source lisible. Réparez WebView2 ou relancez l’installation avec Internet si les résultats ne s’ouvrent pas.

Accessible Studio est indépendant : il n’est ni développé, ni parrainé, ni approuvé par le projet OBS ou ses contributeurs. OBS et OBS Studio sont des marques déposées de Wizards of OBS LLC.

© 2026 [Tiflo.Info](https://tiflo.info). GNU GPL version 2 ou ultérieure ; voir la [licence](../LICENSE.txt). Les noms et logos restent protégés séparément. [English](README.en-US.html).
