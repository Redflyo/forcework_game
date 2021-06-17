#ifndef ANIMATION_H
#define ANIMATION_H
#include <QImage>
#include <QPainter>
#include "forcework.h"
class Animation
{

private:

    QImage *image1;
    QImage *image2;
    QImage *image3;
    QImage *image4;
    QImage *flag;
    QImage *flag2;

    bool itsFlagBool = false;
    int itsFlagTime = 0;

    // Image du personage principal
    QImage *perso1;
    QImage *perso2;
    QImage *persoMarcher1_6D;
    QImage *persoMarcher2_6D;
    QImage *persoMarcher3_6D;
    QImage *persoMarcher4_6D;
    QImage *persoMarcher5_6D;
    QImage *persoMarcher6_6D;
    QImage *persoMarcher1_6G;
    QImage *persoMarcher2_6G;
    QImage *persoMarcher3_6G;
    QImage *persoMarcher4_6G;
    QImage *persoMarcher5_6G;
    QImage *persoMarcher6_6G;
    QImage *persoSautHD1_5D;
    QImage *persoSautHD2_5D;
    QImage *persoSautHD3_5D;
    QImage *persoSautHD4_5D;
    QImage *persoSautHD5_5D;
    QImage *persoSautHD1_5G;
    QImage *persoSautHD2_5G;
    QImage *persoSautHD3_5G;
    QImage *persoSautHD4_5G;
    QImage *persoSautHD5_5G;
    QImage *persoMort1_9D;
    QImage *persoMort2_9D;
    QImage *persoMort3_9D;
    QImage *persoMort4_9D;
    QImage *persoMort5_9D;
    QImage *persoMort6_9D;
    QImage *persoMort7_9D;
    QImage *persoMort8_9D;
    QImage *persoMort9_9D;
    QImage *persoMort1_9G;
    QImage *persoMort2_9G;
    QImage *persoMort3_9G;
    QImage *persoMort4_9G;
    QImage *persoMort5_9G;
    QImage *persoMort6_9G;
    QImage *persoMort7_9G;
    QImage *persoMort8_9G;
    QImage *persoMort9_9G;

    // image de Rambo

    QImage *rambo1;
    QImage *rambo2;
    QImage *ramboMarcher1_6D;
    QImage *ramboMarcher2_6D;
    QImage *ramboMarcher3_6D;
    QImage *ramboMarcher4_6D;
    QImage *ramboMarcher5_6D;
    QImage *ramboMarcher6_6D;
    QImage *ramboMarcher1_6G;
    QImage *ramboMarcher2_6G;
    QImage *ramboMarcher3_6G;
    QImage *ramboMarcher4_6G;
    QImage *ramboMarcher5_6G;
    QImage *ramboMarcher6_6G;

    QImage *ramboMort1_9D;
    QImage *ramboMort2_9D;
    QImage *ramboMort3_9D;
    QImage *ramboMort4_9D;
    QImage *ramboMort5_9D;
    QImage *ramboMort6_9D;
    QImage *ramboMort7_9D;
    QImage *ramboMort8_9D;
    QImage *ramboMort9_9D;
    QImage *ramboMort1_9G;
    QImage *ramboMort2_9G;
    QImage *ramboMort3_9G;
    QImage *ramboMort4_9G;
    QImage *ramboMort5_9G;
    QImage *ramboMort6_9G;
    QImage *ramboMort7_9G;
    QImage *ramboMort8_9G;
    QImage *ramboMort9_9G;


    // image de Costar

    QImage *costar1;
    QImage *costar2;
    QImage *costarMarcher1_6D;
    QImage *costarMarcher2_6D;
    QImage *costarMarcher3_6D;
    QImage *costarMarcher4_6D;
    QImage *costarMarcher5_6D;
    QImage *costarMarcher6_6D;
    QImage *costarMarcher1_6G;
    QImage *costarMarcher2_6G;
    QImage *costarMarcher3_6G;
    QImage *costarMarcher4_6G;
    QImage *costarMarcher5_6G;
    QImage *costarMarcher6_6G;

    QImage *costarMort1_9D;
    QImage *costarMort2_9D;
    QImage *costarMort3_9D;
    QImage *costarMort4_9D;
    QImage *costarMort5_9D;
    QImage *costarMort6_9D;
    QImage *costarMort7_9D;
    QImage *costarMort8_9D;
    QImage *costarMort9_9D;
    QImage *costarMort1_9G;
    QImage *costarMort2_9G;
    QImage *costarMort3_9G;
    QImage *costarMort4_9G;
    QImage *costarMort5_9G;
    QImage *costarMort6_9G;
    QImage *costarMort7_9G;
    QImage *costarMort8_9G;
    QImage *costarMort9_9G;

    // image coeur balle et explosion

    QImage *balleGauche;
    QImage *balleDroite;
    QImage *boom1_6;
    QImage *boom2_6;
    QImage *boom3_6;
    QImage *boom4_6;
    QImage *boom5_6;
    QImage *boom6_6;

    int itsPersoTimeD = 0;
    int itsPersoTimeG = 0;
    int itsPersoTimeJump = 0;
    bool sauterG = false;
    bool sauterD = false;
    bool animDead = false;
    ForceWork * currentGame;
public:
    ///
    /// \brief Animation Constructeur de l'objet d'animation
    /// \param forceWork parti en cours
    ///
    Animation(ForceWork * forceWork);
    ~Animation();
    ///
    /// \brief updateAnimation actualise les timers d'animation
    ///
    void updateAnimation();
    ///
    /// \brief drawAnimation dessinne le jeu en gérant les animation
    /// \param painter QPainter créer dans un PaintEvent
    ///
    void drawAnimation(QPainter * painter);
    bool getAnimDead() const;
};

#endif // ANIMATION_H
