Dans le cadre du [THSF](https://github.com/tetalab/thsf-2013),
J'ai suivi un atelier [Light Painting](http://en.wikipedia.org/wiki/Light_painting).
Le principe est de faire une barre de leds commandée par un arduino pour afficher un texte.
Cet atelier était animé par des personnes du [GRL](http://www.graffitiresearchlab.fr/) que je remercie.
Je ne traiterait pas de la partie prise de vue avec un
appareil photo qui dépasse mes compétences.

Préparation
-----------

Couper une moulure électrique sur 15, centimètres.
Avec un forêt du diamètre des diodes, percez les trous à distance égale
(environ la taille de la petite broche (cathode) de la diode):

![](https://raw.github.com/yazgoo/ledbar/master/ledbar_holes.png)

Ensuite, insérez les leds:

![](https://raw.github.com/yazgoo/ledbar/master/ledbar_one_led.png)

Pliez et soudez les cathodes entre-elles:

![](https://raw.github.com/yazgoo/ledbar/master/ledbar_leds_linked.png)

Enfin, soudez les résistances aux anodes.

![](https://raw.github.com/yazgoo/ledbar/master/ledbar_finished.png)

Vous n'avez plus qu'à tirer un fil entre ces dernières et les pins 3 à 9
de l'arduino UNO.
Enfin, vous pouvez refermer la moulure.
Vous pouvez alimenter votre arduino avec une pile 9 volts.
Il vous est conseillé de bien fixer le tout (avec du ruban adhésif par exemple).

Code utilisé pour le projet
---------------------------

Le code est disponible [sur la page suivante](http://www.graffitiresearchlab.fr/?portfolio=near-tag-quality),
[ici](http://graffitiresearchlab.fr/download/NTQ_Software_v1.0.zip).
Il faudra installer tk pour utiliser l'UI.
Si vous utilisez python 3, il faudra remplacer ``<>`` par ``!=`` et tKinter par tkinter.
Vous entrez votre texte, et le script vous génère un sketch arduino correspondant.
J'ai néanmoins codé une bibliothèque basique que je présente ci-dessous.

Ledbar
------

Tout comme pour mon précédent article, j'utilise mon propre makefile.
J'explique cela sur le [github arduino makefile](https://github.com/yazgoo/arduino-makefile).
Vous pouvez ensuite cloner mon projet github via un:
``github clone https://github.com/yazgoo/ledbar.git``
Il vous suffit alors de modifier ledbar.cpp pour afficher votre texte:

```C++
#include "Arduino.h"
#include "ledbar.c"
void setup() {
        // initialise la bibliothèque
        // initialise la bibliothèque
        ledbar_setup();
}
void loop()
{
        // affiche HELLO WORLD avec un délai de 200ms entre chaque lettre.
        ledbar_write_text(200, "HELLO WORLD");
}
```

Conclusion
----------

Si vous voulez voir ce que cela donne avec le générateur python,
voilà [le résultat](http://www.flickr.com/photos/grlfr/8814833084/in/photostream/lightbox/).
