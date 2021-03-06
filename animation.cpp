#include "animation.h"

bool Animation::getAnimDead() const
{
    return animDead;
}

Animation::Animation(ForceWork * forceWork)
{

    currentGame = forceWork;

    image1 = new QImage;
    image1->load("../forcework_game/data/Terre.png");

    image2 = new QImage;
    image2->load("../forcework_game/data/Metal.png");

    image3 = new QImage;
    image3->load("../forcework_game/data/Ciel.png");

    image4 = new QImage;
    image4->load("../forcework_game/data/Herbe.png");

    image5 = new QImage;
    image5->load("../forcework_game/data/inTerre.png");

    flag = new QImage;
    flag->load("../forcework_game/data/drapeau1-2.png");

    flag2 = new QImage;
    flag2->load("../forcework_game/data/drapeau2-2.png");

    perso1 = new QImage;
    perso1->load("../forcework_game/data/persoStopHDD.png");

    perso2 = new QImage;
    perso2->load("../forcework_game/data/persoStopHDG.png");

    persoMarcher1_6D = new QImage;
    persoMarcher1_6D->load("../forcework_game/data/persoMarcherHD1-6D.png");

    persoMarcher2_6D = new QImage;
    persoMarcher2_6D->load("../forcework_game/data/persoMarcherHD2-6D.png");

    persoMarcher3_6D = new QImage;
    persoMarcher3_6D->load("../forcework_game/data/persoMarcherHD3-6D.png");

    persoMarcher4_6D = new QImage;
    persoMarcher4_6D->load("../forcework_game/data/persoMarcherHD4-6D.png");

    persoMarcher5_6D = new QImage;
    persoMarcher5_6D->load("../forcework_game/data/persoMarcherHD5-6D.png");

    persoMarcher6_6D = new QImage;
    persoMarcher6_6D->load("../forcework_game/data/persoMarcherHD6-6D.png");

    persoMarcher1_6G = new QImage;
    persoMarcher1_6G->load("../forcework_game/data/persoMarcherHD1-6G.png");

    persoMarcher2_6G = new QImage;
    persoMarcher2_6G->load("../forcework_game/data/persoMarcherHD2-6G.png");

    persoMarcher3_6G = new QImage;
    persoMarcher3_6G->load("../forcework_game/data/persoMarcherHD3-6G.png");

    persoMarcher4_6G = new QImage;
    persoMarcher4_6G->load("../forcework_game/data/persoMarcherHD4-6G.png");

    persoMarcher5_6G = new QImage;
    persoMarcher5_6G->load("../forcework_game/data/persoMarcherHD5-6G.png");

    persoMarcher6_6G = new QImage;
    persoMarcher6_6G->load("../forcework_game/data/persoMarcherHD6-6G.png");

    persoSautHD1_5G = new QImage;
    persoSautHD1_5G->load("../forcework_game/data/persoSautHD1-5G.png");

    persoSautHD2_5G = new QImage;
    persoSautHD2_5G->load("../forcework_game/data/persoSautHD2-5G.png");

    persoSautHD3_5G = new QImage;
    persoSautHD3_5G->load("../forcework_game/data/persoSautHD3-5G.png");

    persoSautHD4_5G = new QImage;
    persoSautHD4_5G->load("../forcework_game/data/persoSautHD4-5G.png");

    persoSautHD5_5G = new QImage;
    persoSautHD5_5G->load("../forcework_game/data/persoSautHD5-5G.png");

    persoSautHD1_5D = new QImage;
    persoSautHD1_5D->load("../forcework_game/data/persoSautHD1-5D.png");

    persoSautHD2_5D = new QImage;
    persoSautHD2_5D->load("../forcework_game/data/persoSautHD2-5D.png");

    persoSautHD3_5D = new QImage;
    persoSautHD3_5D->load("../forcework_game/data/persoSautHD3-5D.png");

    persoSautHD4_5D = new QImage;
    persoSautHD4_5D->load("../forcework_game/data/persoSautHD4-5D.png");

    persoSautHD5_5D = new QImage;
    persoSautHD5_5D->load("../forcework_game/data/persoSautHD5-5D.png");

    persoMort1_9D = new QImage;
    persoMort1_9D->load("../forcework_game/data/persoMort1-9D.png");

    persoMort2_9D = new QImage;
    persoMort2_9D->load("../forcework_game/data/persoMort2-9D.png");

    persoMort3_9D = new QImage;
    persoMort3_9D->load("../forcework_game/data/persoMort3-9D.png");

    persoMort4_9D = new QImage;
    persoMort4_9D->load("../forcework_game/data/persoMort4-9D.png");

    persoMort5_9D = new QImage;
    persoMort5_9D->load("../forcework_game/data/persoMort5-9D.png");

    persoMort6_9D = new QImage;
    persoMort6_9D->load("../forcework_game/data/persoMarche6-9D.png");

    persoMort7_9D = new QImage;
    persoMort7_9D->load("../forcework_game/data/persoMort7-9D.png");

    persoMort8_9D = new QImage;
    persoMort8_9D->load("../forcework_game/data/persoMort8-9D.png");

    persoMort9_9D = new QImage;
    persoMort9_9D->load("../forcework_game/data/persoMort9-9D.png");

    persoMort1_9G = new QImage;
    persoMort1_9G->load("../forcework_game/data/persoMort1-9G.png");

    persoMort2_9G = new QImage;
    persoMort2_9G->load("../forcework_game/data/persoMort2-9G.png");

    persoMort3_9G = new QImage;
    persoMort3_9G->load("../forcework_game/data/persoMort3-9G.png");

    persoMort4_9G = new QImage;
    persoMort4_9G->load("../forcework_game/data/persoMort4-9G.png");

    persoMort5_9G = new QImage;
    persoMort5_9G->load("../forcework_game/data/persoMort5-9G.png");

    persoMort6_9G = new QImage;
    persoMort6_9G->load("../forcework_game/data/persoMarche6-9G.png");

    persoMort7_9G = new QImage;
    persoMort7_9G->load("../forcework_game/data/persoMort7-9G.png");

    persoMort8_9G = new QImage;
    persoMort8_9G->load("../forcework_game/data/persoMort8-9G.png");

    persoMort9_9G = new QImage;
    persoMort9_9G->load("../forcework_game/data/persoMort9-9G.png");
    // image rambo

    rambo1 = new QImage;
    rambo1->load("../forcework_game/data/ramboStopD.png");

    rambo2 = new QImage;
    rambo2->load("../forcework_game/data/ramboStopG.png");

    ramboMarcher1_6D = new QImage;
    ramboMarcher1_6D->load("../forcework_game/data/ramboMarcher1-6D.png");

    ramboMarcher2_6D = new QImage;
    ramboMarcher2_6D->load("../forcework_game/data/ramboMarcher2-6D.png");

    ramboMarcher3_6D = new QImage;
    ramboMarcher3_6D->load("../forcework_game/data/ramboMarcher3-6D.png");

    ramboMarcher4_6D = new QImage;
    ramboMarcher4_6D->load("../forcework_game/data/ramboMarcher4-6D.png");

    ramboMarcher5_6D = new QImage;
    ramboMarcher5_6D->load("../forcework_game/data/ramboMarcher5-6D.png");

    ramboMarcher6_6D = new QImage;
    ramboMarcher6_6D->load("../forcework_game/data/ramboMarcher6-6D.png");

    ramboMarcher1_6G = new QImage;
    ramboMarcher1_6G->load("../forcework_game/data/ramboMarcher1-6G.png");

    ramboMarcher2_6G = new QImage;
    ramboMarcher2_6G->load("../forcework_game/data/ramboMarcher2-6G.png");

    ramboMarcher3_6G = new QImage;
    ramboMarcher3_6G->load("../forcework_game/data/ramboMarcher3-6G.png");

    ramboMarcher4_6G = new QImage;
    ramboMarcher4_6G->load("../forcework_game/data/ramboMarcher4-6G.png");

    ramboMarcher5_6G = new QImage;
    ramboMarcher5_6G->load("../forcework_game/data/ramboMarcher5-6G.png");

    ramboMarcher6_6G = new QImage;
    ramboMarcher6_6G->load("../forcework_game/data/ramboMarcher6-6G.png");

    ramboMort1_9D = new QImage;
    ramboMort1_9D->load("../forcework_game/data/ramboMort1-9D.png");

    ramboMort2_9D = new QImage;
    ramboMort2_9D->load("../forcework_game/data/ramboMort2-9D.png");

    ramboMort3_9D = new QImage;
    ramboMort3_9D->load("../forcework_game/data/ramboMort3-9D.png");

    ramboMort4_9D = new QImage;
    ramboMort4_9D->load("../forcework_game/data/ramboMort4-9D.png");

    ramboMort5_9D = new QImage;
    ramboMort5_9D->load("../forcework_game/data/ramboMort5-9D.png");

    ramboMort6_9D = new QImage;
    ramboMort6_9D->load("../forcework_game/data/ramboMarche6-9D.png");

    ramboMort7_9D = new QImage;
    ramboMort7_9D->load("../forcework_game/data/ramboMort7-9D.png");

    ramboMort8_9D = new QImage;
    ramboMort8_9D->load("../forcework_game/data/ramboMort8-9D.png");

    ramboMort9_9D = new QImage;
    ramboMort9_9D->load("../forcework_game/data/ramboMort9-9D.png");

    ramboMort1_9G = new QImage;
    ramboMort1_9G->load("../forcework_game/data/ramboMort1-9G.png");

    ramboMort2_9G = new QImage;
    ramboMort2_9G->load("../forcework_game/data/ramboMort2-9G.png");

    ramboMort3_9G = new QImage;
    ramboMort3_9G->load("../forcework_game/data/ramboMort3-9G.png");

    ramboMort4_9G = new QImage;
    ramboMort4_9G->load("../forcework_game/data/ramboMort4-9G.png");

    ramboMort5_9G = new QImage;
    ramboMort5_9G->load("../forcework_game/data/ramboMort5-9G.png");

    ramboMort6_9G = new QImage;
    ramboMort6_9G->load("../forcework_game/data/ramboMarche6-9G.png");

    ramboMort7_9G = new QImage;
    ramboMort7_9G->load("../forcework_game/data/ramboMort7-9G.png");

    ramboMort8_9G = new QImage;
    ramboMort8_9G->load("../forcework_game/data/ramboMort8-9G.png");

    ramboMort9_9G = new QImage;
    ramboMort9_9G->load("../forcework_game/data/ramboMort9-9G.png");



    // image costar

    costar1 = new QImage;
    costar1->load("../forcework_game/data/costarStopD.png");

    costar2 = new QImage;
    costar2->load("../forcework_game/data/costarStopG.png");

    costarMarcher1_6D = new QImage;
    costarMarcher1_6D->load("../forcework_game/data/costarMarcherHD1-6D.png");

    costarMarcher2_6D = new QImage;
    costarMarcher2_6D->load("../forcework_game/data/costarMarcherHD2-6D.png");

    costarMarcher3_6D = new QImage;
    costarMarcher3_6D->load("../forcework_game/data/costarMarcherHD3-6D.png");

    costarMarcher4_6D = new QImage;
    costarMarcher4_6D->load("../forcework_game/data/costarMarcherHD4-6D.png");

    costarMarcher5_6D = new QImage;
    costarMarcher5_6D->load("../forcework_game/data/costarMarcherHD5-6D.png");

    costarMarcher6_6D = new QImage;
    costarMarcher6_6D->load("../forcework_game/data/costarMarcherHD6-6D.png");

    costarMarcher1_6G = new QImage;
    costarMarcher1_6G->load("../forcework_game/data/costarMarcherHD1-6G.png");

    costarMarcher2_6G = new QImage;
    costarMarcher2_6G->load("../forcework_game/data/costarMarcherHD2-6G.png");

    costarMarcher3_6G = new QImage;
    costarMarcher3_6G->load("../forcework_game/data/costarMarcherHD3-6G.png");

    costarMarcher4_6G = new QImage;
    costarMarcher4_6G->load("../forcework_game/data/costarMarcherHD4-6G.png");

    costarMarcher5_6G = new QImage;
    costarMarcher5_6G->load("../forcework_game/data/costarMarcherHD5-6G.png");

    costarMarcher6_6G = new QImage;
    costarMarcher6_6G->load("../forcework_game/data/costarMarcherHD6-6G.png");

    costarMort1_9D = new QImage;
    costarMort1_9D->load("../forcework_game/data/costarMort1-9D.png");

    costarMort2_9D = new QImage;
    costarMort2_9D->load("../forcework_game/data/costarMort2-9D.png");

    costarMort3_9D = new QImage;
    costarMort3_9D->load("../forcework_game/data/costarMort3-9D.png");

    costarMort4_9D = new QImage;
    costarMort4_9D->load("../forcework_game/data/costarMort4-9D.png");

    costarMort5_9D = new QImage;
    costarMort5_9D->load("../forcework_game/data/costarMort5-9D.png");

    costarMort6_9D = new QImage;
    costarMort6_9D->load("../forcework_game/data/costarMarche6-9D.png");

    costarMort7_9D = new QImage;
    costarMort7_9D->load("../forcework_game/data/costarMort7-9D.png");

    costarMort8_9D = new QImage;
    costarMort8_9D->load("../forcework_game/data/costarMort8-9D.png");

    costarMort9_9D = new QImage;
    costarMort9_9D->load("../forcework_game/data/costarMort9-9D.png");

    costarMort1_9G = new QImage;
    costarMort1_9G->load("../forcework_game/data/costarMort1-9G.png");

    costarMort2_9G = new QImage;
    costarMort2_9G->load("../forcework_game/data/costarMort2-9G.png");

    costarMort3_9G = new QImage;
    costarMort3_9G->load("../forcework_game/data/costarMort3-9G.png");

    costarMort4_9G = new QImage;
    costarMort4_9G->load("../forcework_game/data/costarMort4-9G.png");

    costarMort5_9G = new QImage;
    costarMort5_9G->load("../forcework_game/data/costarMort5-9G.png");

    costarMort6_9G = new QImage;
    costarMort6_9G->load("../forcework_game/data/costarMarche6-9G.png");

    costarMort7_9G = new QImage;
    costarMort7_9G->load("../forcework_game/data/costarMort7-9G.png");

    costarMort8_9G = new QImage;
    costarMort8_9G->load("../forcework_game/data/costarMort8-9G.png");

    costarMort9_9G = new QImage;
    costarMort9_9G->load("../forcework_game/data/costarMort9-9G.png");

    balleDroite = new QImage;
    balleDroite->load("../forcework_game/data/BalleD.png");

    balleGauche = new QImage;
    balleGauche->load("../forcework_game/data/BalleG.png");


    boom1_6 = new QImage;
    boom1_6->load("../forcework_game/data/boom1-6.png");

    boom2_6 = new QImage;
    boom2_6->load("../forcework_game/data/boom2-6.png");

    boom3_6 = new QImage;
    boom3_6->load("../forcework_game/data/boom3-6.png");

    boom4_6 = new QImage;
    boom4_6->load("../forcework_game/data/boom4-6.png");

    boom5_6 = new QImage;
    boom5_6->load("../forcework_game/data/boom5-6.png");

    boom6_6 = new QImage;
    boom6_6->load("../forcework_game/data/boom6-6.png");


    // dimention des images personnage principal
    *persoSautHD1_5D =  persoSautHD1_5D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD2_5D =  persoSautHD2_5D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD3_5D =  persoSautHD3_5D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD4_5D =  persoSautHD4_5D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD5_5D =  persoSautHD5_5D->scaled(QSize(sizeBlock,sizeBlock*2));

    *persoSautHD1_5G =  persoSautHD1_5G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD2_5G =  persoSautHD2_5G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD3_5G =  persoSautHD3_5G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD4_5G =  persoSautHD4_5G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoSautHD5_5G =  persoSautHD5_5G->scaled(QSize(sizeBlock,sizeBlock*2));

    *persoMarcher1_6D = persoMarcher1_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher2_6D = persoMarcher2_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher3_6D = persoMarcher3_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher4_6D = persoMarcher4_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher5_6D = persoMarcher5_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher6_6D = persoMarcher6_6D->scaled(QSize(sizeBlock,sizeBlock*2));

    *persoMarcher1_6G = persoMarcher1_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher2_6G = persoMarcher2_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher3_6G = persoMarcher3_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher4_6G = persoMarcher4_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher5_6G = persoMarcher5_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMarcher6_6G = persoMarcher6_6G->scaled(QSize(sizeBlock,sizeBlock*2));

    *persoMort1_9D = persoMort1_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort2_9D = persoMort2_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort3_9D = persoMort3_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort4_9D = persoMort4_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort5_9D = persoMort5_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort6_9D = persoMort6_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort7_9D = persoMort7_9D->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *persoMort8_9D = persoMort8_9D->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *persoMort9_9D = persoMort9_9D->scaled(QSize(sizeBlock*2,sizeBlock));

    *persoMort1_9G = persoMort1_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort2_9G = persoMort2_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort3_9G = persoMort3_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort4_9G = persoMort4_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort5_9G = persoMort5_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort6_9G = persoMort6_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *persoMort7_9G = persoMort7_9G->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *persoMort8_9G = persoMort8_9G->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *persoMort9_9G = persoMort9_9G->scaled(QSize(sizeBlock*2,sizeBlock));

    *perso1 = perso1->scaled(QSize(sizeBlock,sizeBlock*2));
    *perso2 = perso2->scaled(QSize(sizeBlock,sizeBlock*2));

    //redimention des images Rambo

    *ramboMarcher1_6D = ramboMarcher1_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher2_6D = ramboMarcher2_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher3_6D = ramboMarcher3_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher4_6D = ramboMarcher4_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher5_6D = ramboMarcher5_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher6_6D = ramboMarcher6_6D->scaled(QSize(sizeBlock,sizeBlock*2));

    *ramboMarcher1_6G = ramboMarcher1_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher2_6G = ramboMarcher2_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher3_6G = ramboMarcher3_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher4_6G = ramboMarcher4_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher5_6G = ramboMarcher5_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMarcher6_6G = ramboMarcher6_6G->scaled(QSize(sizeBlock,sizeBlock*2));

    *ramboMort1_9D = ramboMort1_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort2_9D = ramboMort2_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort3_9D = ramboMort3_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort4_9D = ramboMort4_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort5_9D = ramboMort5_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort6_9D = ramboMort6_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort7_9D = ramboMort7_9D->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *ramboMort8_9D = ramboMort8_9D->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *ramboMort9_9D = ramboMort9_9D->scaled(QSize(sizeBlock*2,sizeBlock));

    *ramboMort1_9G = ramboMort1_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort2_9G = ramboMort2_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort3_9G = ramboMort3_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort4_9G = ramboMort4_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort5_9G = ramboMort5_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort6_9G = ramboMort6_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *ramboMort7_9G = ramboMort7_9G->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *ramboMort8_9G = ramboMort8_9G->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *ramboMort9_9G = ramboMort9_9G->scaled(QSize(sizeBlock*2,sizeBlock));

    *rambo1 = rambo1->scaled(QSize(sizeBlock,sizeBlock*2));
    *rambo2 = rambo2->scaled(QSize(sizeBlock,sizeBlock*2));

    //redimmention des images Costar

    *costarMarcher1_6D = costarMarcher1_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher2_6D = costarMarcher2_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher3_6D = costarMarcher3_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher4_6D = costarMarcher4_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher5_6D = costarMarcher5_6D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher6_6D = costarMarcher6_6D->scaled(QSize(sizeBlock,sizeBlock*2));

    *costarMarcher1_6G = costarMarcher1_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher2_6G = costarMarcher2_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher3_6G = costarMarcher3_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher4_6G = costarMarcher4_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher5_6G = costarMarcher5_6G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMarcher6_6G = costarMarcher6_6G->scaled(QSize(sizeBlock,sizeBlock*2));

    *costarMort1_9D = costarMort1_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort2_9D = costarMort2_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort3_9D = costarMort3_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort4_9D = costarMort4_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort5_9D = costarMort5_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort6_9D = costarMort6_9D->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort7_9D = costarMort7_9D->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *costarMort8_9D = costarMort8_9D->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *costarMort9_9D = costarMort9_9D->scaled(QSize(sizeBlock*2,sizeBlock));

    *costarMort1_9G = costarMort1_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort2_9G = costarMort2_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort3_9G = costarMort3_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort4_9G = costarMort4_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort5_9G = costarMort5_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort6_9G = costarMort6_9G->scaled(QSize(sizeBlock,sizeBlock*2));
    *costarMort7_9G = costarMort7_9G->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *costarMort8_9G = costarMort8_9G->scaled(QSize(sizeBlock*2,sizeBlock*2));
    *costarMort9_9G = costarMort9_9G->scaled(QSize(sizeBlock*2,sizeBlock));

    *costar1 = costar1->scaled(QSize(sizeBlock,sizeBlock*2));
    *costar2 = costar2->scaled(QSize(sizeBlock,sizeBlock*2));



    *flag = flag->scaled(QSize(sizeBlock,sizeBlock*2));
    *flag2 = flag2->scaled(QSize(sizeBlock,sizeBlock*2));


    *image1 = image1->scaled(QSize(sizeBlock,sizeBlock));
    *image2 = image2->scaled(QSize(sizeBlock,sizeBlock));
    *image3 = image3->scaled(QSize(sizeBlock,sizeBlock));
    *image4 = image4->scaled(QSize(sizeBlock,sizeBlock));
    *image5 = image5->scaled(QSize(sizeBlock,sizeBlock));
}

Animation::~Animation()
{
    delete image1;
    delete image2;
    delete image3;
    delete image4;
    delete image5;
    delete flag;
    delete flag2;
    delete perso1;
    delete perso2;
    delete persoMarcher1_6D;
    delete persoMarcher1_6G;
    delete persoMarcher2_6D;
    delete persoMarcher2_6G;
    delete persoMarcher3_6D;
    delete persoMarcher3_6G;
    delete persoMarcher4_6D;
    delete persoMarcher4_6G;
    delete persoMarcher5_6D;
    delete persoMarcher5_6G;
    delete persoMarcher6_6D;
    delete persoMarcher6_6G;

    delete rambo1;
    delete rambo2;
    delete ramboMarcher1_6D;
    delete ramboMarcher1_6G;
    delete ramboMarcher2_6D;
    delete ramboMarcher2_6G;
    delete ramboMarcher3_6D;
    delete ramboMarcher3_6G;
    delete ramboMarcher4_6D;
    delete ramboMarcher4_6G;
    delete ramboMarcher5_6D;
    delete ramboMarcher5_6G;
    delete ramboMarcher6_6D;
    delete ramboMarcher6_6G;



    delete costar1;
    delete costar2;
    delete costarMarcher1_6D;
    delete costarMarcher1_6G;
    delete costarMarcher2_6D;
    delete costarMarcher2_6G;
    delete costarMarcher3_6D;
    delete costarMarcher3_6G;
    delete costarMarcher4_6D;
    delete costarMarcher4_6G;
    delete costarMarcher5_6D;
    delete costarMarcher5_6G;
    delete costarMarcher6_6D;
    delete costarMarcher6_6G;

    delete persoSautHD1_5D;
    delete persoSautHD1_5G;
    delete persoSautHD2_5D;
    delete persoSautHD2_5G;
    delete persoSautHD3_5D;
    delete persoSautHD3_5G;
    delete persoSautHD4_5D;
    delete persoSautHD4_5G;
    delete persoSautHD5_5D;
    delete persoSautHD5_5G;

    delete costarMort1_9D;
    delete costarMort2_9D;
    delete costarMort3_9D;
    delete costarMort4_9D;
    delete costarMort5_9D;
    delete costarMort6_9D;
    delete costarMort7_9D;
    delete costarMort8_9D;
    delete costarMort9_9D;
    delete costarMort1_9G;
    delete costarMort2_9G;
    delete costarMort3_9G;
    delete costarMort4_9G;
    delete costarMort5_9G;
    delete costarMort6_9G;
    delete costarMort7_9G;
    delete costarMort8_9G;
    delete costarMort9_9G;

    delete ramboMort1_9D;
    delete ramboMort2_9D;
    delete ramboMort3_9D;
    delete ramboMort4_9D;
    delete ramboMort5_9D;
    delete ramboMort6_9D;
    delete ramboMort7_9D;
    delete ramboMort8_9D;
    delete ramboMort9_9D;
    delete ramboMort1_9G;
    delete ramboMort2_9G;
    delete ramboMort3_9G;
    delete ramboMort4_9G;
    delete ramboMort5_9G;
    delete ramboMort6_9G;
    delete ramboMort7_9G;
    delete ramboMort8_9G;
    delete ramboMort9_9G;

    delete persoMort1_9D;
    delete persoMort2_9D;
    delete persoMort3_9D;
    delete persoMort4_9D;
    delete persoMort5_9D;
    delete persoMort6_9D;
    delete persoMort7_9D;
    delete persoMort8_9D;
    delete persoMort9_9D;
    delete persoMort1_9G;
    delete persoMort2_9G;
    delete persoMort3_9G;
    delete persoMort4_9G;
    delete persoMort5_9G;
    delete persoMort6_9G;
    delete persoMort7_9G;
    delete persoMort8_9G;
    delete persoMort9_9G;


    delete boom1_6;
    delete boom2_6;
    delete boom3_6;
    delete boom4_6;
    delete boom5_6;
    delete boom6_6;
}

void Animation::updateAnimation()
{
    itsFlagTime++;

    if (itsFlagTime == 40)
    {
        itsFlagBool =! itsFlagBool;
        itsFlagTime = 0;
    }
    itsPersoTimeD++;
    itsPersoTimeG++;
    itsPersoTimeJump++;
}


void Animation::drawAnimation(QPainter *painter)
{
    bool itsPersoSens = currentGame->getPlayer()->getDirection();
    bool fall = false;
    vector<Block> blocks = currentGame->getItsMap().getItsBlocks();
    int offSetX = currentGame->getCamera().getItsOffsetX();
    int offSetY = currentGame->getCamera().getItsOffsetY();

    int locX,locY;
    bool haveDrawSomething = false;
    bool ground = currentGame->getPlayer()->getItsSpeedY()<1 and currentGame->getPlayer()->getItsSpeedY()>-1 ;
    for (int i = 0; i<(int)blocks.size() ;i++ ) {


        locY = blocks[i].getItsBlockY()*sizeBlock+ offSetY;
        locX = blocks[i].getItsBlockX()*sizeBlock+ offSetX;
        if(locX > -50 && locX < 1200)
        {


            if (blocks[i].getItsBlockType() == 2){
                painter->drawImage(locX,locY, *image1);
            }
            if (blocks[i].getItsBlockType() == 5 and currentGame->getPlayer()->getItsBlockY() >=25){
                painter->drawImage(locX,locY, *image5);
            }
            else if(blocks[i].getItsBlockType() == 5)
            {
                painter->drawImage(locX,locY, *image1);
            }
            if (blocks[i].getItsBlockType() == 3){
                painter->drawImage(locX,locY, *image2);
            }
            if (blocks[i].getItsBlockType() == 0 or blocks[i].getItsBlockType() == 1){
                painter->drawImage(locX,locY, *image3);
                if (blocks[i].getItsBlockType() == 1){


                    if (itsFlagBool == false)
                    {

                    painter->drawImage(locX,locY-sizeBlock, *flag);
                    }
                    else
                    {

                    painter->drawImage(locX,locY-sizeBlock, *flag2);
                    }

                }
            }

            if (blocks[i].getItsBlockType() == 4){
                painter->drawImage(locX,locY, *image4);

            }

        }
    }

    if (currentGame->getPlayer()->getIsDead() == false)
    {
    if (currentGame->getPlayer()->getItsAnimationImage() == 0)
    {
        haveDrawSomething = true;
        itsPersoTimeD = 0;
        itsPersoTimeG = 0;

        if (currentGame->getPlayer()->getDirection() == false and ground == true)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *perso1);
        }
        else if (currentGame->getPlayer()->getDirection() == true and ground == true)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *perso2);
        }
        else
        {
            haveDrawSomething = false;
        }
    }
    if (currentGame->getPlayer()->getItsAnimationImage() == 1 and ground == true)
    {
        haveDrawSomething = true;
        itsPersoTimeD = 0;
        if (itsPersoTimeG >= 0 and itsPersoTimeG <15)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6G);
        }
        else if (itsPersoTimeG >= 15 and itsPersoTimeG <30)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher2_6G);
        }
        else if (itsPersoTimeG >= 30 and itsPersoTimeG <45)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher3_6G);
        }
        else if (itsPersoTimeG >= 45 and itsPersoTimeG <60)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher4_6G);
        }
        else if (itsPersoTimeG >= 60 and itsPersoTimeG <75)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher5_6G);
        }
        else if (itsPersoTimeG >= 75 and itsPersoTimeG <90)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher6_6G);

        }
        else if (itsPersoTimeG >= 90)
        {

        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6G);

        itsPersoTimeG = 0;
        }
    }
    if (currentGame->getPlayer()->getItsAnimationImage() == 2 and ground == true)
    {
        haveDrawSomething = true;
        itsPersoTimeG = 0;
        if (itsPersoTimeD >= 0 and itsPersoTimeD <15)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6D);
        }
        else if (itsPersoTimeD >= 15 and itsPersoTimeD <30)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher2_6D);
        }
        else if (itsPersoTimeD >= 30 and itsPersoTimeD <45)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher3_6D);
        }
        else if (itsPersoTimeD >= 45 and itsPersoTimeD <60)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher4_6D);
        }
        else if (itsPersoTimeD >= 60 and itsPersoTimeD <75)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher5_6D);
        }
        else if (itsPersoTimeD >= 75 and itsPersoTimeD <90)
        {
        painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher6_6D);
        }
        else if (itsPersoTimeD >= 90)
        {
        itsPersoTimeD = 0;
         painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoMarcher1_6D);
        }

    }



    // animation saut droit
        if (ground == false and itsPersoSens == false)
        {
            if (currentGame->getPlayer()->getItsImpulsion() == true)
            {
                if (itsPersoTimeJump>= 0 and itsPersoTimeJump <10)
                {
                painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD1_5D);
                }
                else if (itsPersoTimeJump>= 10 and itsPersoTimeJump <20)
                {
                painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD2_5D);
                }
                else if (itsPersoTimeJump>= 20 and itsPersoTimeJump <30)
                {
                painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD3_5D);
                }
                haveDrawSomething = true;
            }
            else
            {
                itsPersoTimeJump = 0;
                fall = true;
            }

        }


    // animation saut gauche
    if (ground == false and itsPersoSens == true)
    {
        if (currentGame->getPlayer()->getItsImpulsion() == true)
        {
            if (itsPersoTimeJump>= 0 and itsPersoTimeJump <10)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD1_5G);
            }
            else if (itsPersoTimeJump>= 10 and itsPersoTimeJump <20)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD2_5G);
            }
            else if (itsPersoTimeJump>= 20 and itsPersoTimeJump <30)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD3_5G);
            }
            haveDrawSomething = true;
        }
        else
        {
            itsPersoTimeJump = 0;
            fall = true;
        }

    }

    if (ground == false and currentGame->getPlayer()->getDirection() == true and currentGame->getPlayer()->getItsImpulsion() == false)


    // animation chute gauche
    if ((ground == false and itsPersoSens == true and currentGame->getPlayer()->getItsImpulsion() == false) or (fall == true and itsPersoSens == true))
    {
            if (itsPersoTimeJump>= 0 and itsPersoTimeJump <10)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD4_5G);
            }
            else if (itsPersoTimeJump >= 10)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD5_5G);
            }

        haveDrawSomething = true;
    }

    if ((ground == false and itsPersoSens == false and currentGame->getPlayer()->getItsImpulsion() == false) or (fall == true and itsPersoSens == false))
    {

            if (itsPersoTimeJump>= 0 and itsPersoTimeJump <10)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD4_5D);
            }
            else if (itsPersoTimeJump >= 10)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD5_5D);
            }
        haveDrawSomething = true;
    }


    if(!haveDrawSomething)
    {
        if (ground == true and currentGame->getPlayer()->getItsAnimationImage() == 2 and itsPersoSens == false)
        {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD5_5D);
        }
        else if (ground == true and currentGame->getPlayer()->getItsAnimationImage() == 1 and itsPersoSens == true)
        {
             painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD5_5G);
        }

        if(!itsPersoSens)
        {
          painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD5_5D);
        }
        else
        {
          painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX,currentGame->getPlayer()->getItsY()+offSetY, *persoSautHD5_5G);
        }
    }
    }
    if (currentGame->getPlayer()->getIsDead() == true)
    {
        if (currentGame->getPlayer()->getDirection() == false)
        {

            itsPersoTimeG=0;
            if (itsPersoTimeD >= 0 and itsPersoTimeD <15)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort1_9D);
            }
            else if (itsPersoTimeD >= 10 and itsPersoTimeD <20)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort2_9D);
            }
            else if (itsPersoTimeD >= 20 and itsPersoTimeD <30)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort3_9D);
            }
            else if (itsPersoTimeD >= 30 and itsPersoTimeD <40)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort4_9D);
            }
            else if (itsPersoTimeD >= 40 and itsPersoTimeD <50)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort5_9D);
            }
            else if (itsPersoTimeD >= 50 and itsPersoTimeD <60)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort6_9D);
            }
            else if (itsPersoTimeD >= 60 and itsPersoTimeD <70)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort7_9D);
            }
            else if (itsPersoTimeD >= 70 and itsPersoTimeD <80)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort8_9D);
            }
            else if (itsPersoTimeD >= 80)
            {
             painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY+sizeBlock+10, *persoMort9_9D);
              if (itsPersoTimeD >= 100)
              {
                  animDead = true;
              }
            }
        }

        if (currentGame->getPlayer()->getDirection() == true)
        {

            itsPersoTimeD=0;
            if (itsPersoTimeG >= 0 and itsPersoTimeG <15)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort1_9G);
            }
            else if (itsPersoTimeG >= 10 and itsPersoTimeG <20)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort2_9G);
            }
            else if (itsPersoTimeG >= 20 and itsPersoTimeG <30)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort3_9G);
            }
            else if (itsPersoTimeG >= 30 and itsPersoTimeG <40)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort4_9G);
            }
            else if (itsPersoTimeG >= 40 and itsPersoTimeG <50)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort5_9G);
            }
            else if (itsPersoTimeG >= 50 and itsPersoTimeG <60)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort6_9G);
            }
            else if (itsPersoTimeG >= 60 and itsPersoTimeG <70)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort7_9G);
            }
            else if (itsPersoTimeG >= 70 and itsPersoTimeG <80)
            {
            painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY, *persoMort8_9G);
            }
            else if (itsPersoTimeG >= 80)
            {
             painter->drawImage(currentGame->getPlayer()->getItsX()+offSetX, currentGame->getPlayer()->getItsY()+offSetY+sizeBlock+10, *persoMort9_9D);
             if (itsPersoTimeG >= 100)
             {
                 animDead = true;
             }
            }
        }

    }

    // IA -------------------------------------------------------------------------------------------------------
    bool first = true;
    for (Personnage* i:currentGame->getItsPersonnages() ) {
        if(!first)
        {
            if(((IA*)i)->getIsDead() == false)
            {


                if (((IA*)i)->getItsAnimationImage() == 4 and ((IA*)i)->getDirection() == false)
                {
                    painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costar1);
                }
                else if (((IA*)i)->getItsAnimationImage() == 4 and ((IA*)i)->getDirection() == true)
                {
                    painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costar2);
                }

                if (((IA*)i)->getItsMoveOrNot() == true)
                {
                    if (((IA*)i)->getItsAnimationImage() == 0 and ((IA*)i)->getDirection() == false)
                    {
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *rambo1);
                    }
                    else if (((IA*)i)->getItsAnimationImage() == 0 and ((IA*)i)->getDirection() == true)
                    {
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *rambo2);
                    }
                    else if (((IA*)i)->getItsAnimationImage() == 2)
                    {
                        ((IA*)i)->setItsTimeG(0);
                        if (((IA*)i)->getItsTimeD() >= 0 and ((IA*)i)->getItsTimeD() <15)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher1_6D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 15 and ((IA*)i)->getItsTimeD() <30)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher2_6D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 30 and ((IA*)i)->getItsTimeD() <45)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher3_6D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 45 and ((IA*)i)->getItsTimeD() <60)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher4_6D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 60 and ((IA*)i)->getItsTimeD() <75)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher5_6D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 75 and ((IA*)i)->getItsTimeD() <90)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher6_6D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 90)
                        {
                        ((IA*)i)->setItsTimeD(0);
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher1_6D);
                        }
                    }

                    else if (((IA*)i)->getItsAnimationImage() == 1)
                    {
                        ((IA*)i)->setItsTimeD(0);
                        if (((IA*)i)->getItsTimeG() >= 0 and ((IA*)i)->getItsTimeG() <15)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher1_6G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 15 and ((IA*)i)->getItsTimeG() <30)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher2_6G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 30 and ((IA*)i)->getItsTimeG() <45)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher3_6G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 45 and ((IA*)i)->getItsTimeG() <60)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher4_6G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 60 and ((IA*)i)->getItsTimeG() <75)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher5_6G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 75 and ((IA*)i)->getItsTimeG() <90)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher6_6G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 90)
                        {
                        ((IA*)i)->setItsTimeG(0);
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMarcher1_6G);
                        }
                    }
                }
            }
            // La mort de l'ia -----------------------------------------------------------------------------------------
            if(((IA*)i)->getIsDead() == true)
            {

                if (((IA*)i)->getItsMoveOrNot() == false)
                {

                    if ( ((IA*)i)->getDirection() == false and ((IA*)i)->getAnimationDead() == false)
                    {
                        ((IA*)i)->setItsTimeG(0);
                        if (((IA*)i)->getItsTimeD() >= 0 and ((IA*)i)->getItsTimeD() <15)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort1_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 10 and ((IA*)i)->getItsTimeD() <20)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort2_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 20 and ((IA*)i)->getItsTimeD() <30)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort3_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 30 and ((IA*)i)->getItsTimeD() <40)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort4_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 40 and ((IA*)i)->getItsTimeD() <50)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort5_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 50 and ((IA*)i)->getItsTimeD() <60)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort6_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 60 and ((IA*)i)->getItsTimeD() <70)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort7_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 70 and ((IA*)i)->getItsTimeD() <80)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort8_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 80)
                        {
                        ((IA*)i)->setItsTimeD(0);
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *costarMort9_9D);
                         ((IA*)i)->setAnimationDead(true);
                        }
                    }
                    else if ( ((IA*)i)->getDirection() == true and ((IA*)i)->getAnimationDead() == false)
                    {
                        ((IA*)i)->setItsTimeD(0);
                        if (((IA*)i)->getItsTimeG() >= 0 and ((IA*)i)->getItsTimeG() <10)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort1_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 10 and ((IA*)i)->getItsTimeG() <20)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort2_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 20 and ((IA*)i)->getItsTimeG() <30)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort3_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 30 and ((IA*)i)->getItsTimeG() <40)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort4_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 40 and ((IA*)i)->getItsTimeG() <50)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort5_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 50 and ((IA*)i)->getItsTimeG() <60)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort6_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 60 and ((IA*)i)->getItsTimeG() <70)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort7_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 70 and ((IA*)i)->getItsTimeG() <80)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *costarMort8_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 80)
                        {
                        ((IA*)i)->setItsTimeG(0);
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *costarMort9_9G);
                         ((IA*)i)->setAnimationDead(true);
                        }
                    }



                    if (((IA*)i)->getDirection() == false and ((IA*)i)->getAnimationDead() == true)
                    {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *costarMort9_9D);
                    }
                    else if (((IA*)i)->getDirection() == true and ((IA*)i)->getAnimationDead() == true)
                    {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *costarMort9_9G);
                    }
                }

                if (((IA*)i)->getItsMoveOrNot() == true)
                {

                    if ((((IA*)i)->getItsAnimationImage() == 0 or ((IA*)i)->getItsAnimationImage() == 2) and ((IA*)i)->getDirection() == false and ((IA*)i)->getAnimationDead() == false)
                    {
                        ((IA*)i)->setItsTimeG(0);
                        if (((IA*)i)->getItsTimeD() >= 0 and ((IA*)i)->getItsTimeD() <15)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort1_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 10 and ((IA*)i)->getItsTimeD() <20)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort2_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 20 and ((IA*)i)->getItsTimeD() <30)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort3_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 30 and ((IA*)i)->getItsTimeD() <40)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort4_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 40 and ((IA*)i)->getItsTimeD() <50)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort5_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 50 and ((IA*)i)->getItsTimeD() <60)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort6_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 60 and ((IA*)i)->getItsTimeD() <70)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort7_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 70 and ((IA*)i)->getItsTimeD() <80)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort8_9D);
                        }
                        else if (((IA*)i)->getItsTimeD() >= 80)
                        {
                        ((IA*)i)->setItsTimeD(0);
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *ramboMort9_9D);
                         ((IA*)i)->setAnimationDead(true);
                        }
                    }
                    else if ((((IA*)i)->getItsAnimationImage() == 0 or ((IA*)i)->getItsAnimationImage() == 1) and ((IA*)i)->getDirection() == true and ((IA*)i)->getAnimationDead() == false)
                    {
                        ((IA*)i)->setItsTimeD(0);
                        if (((IA*)i)->getItsTimeG() >= 0 and ((IA*)i)->getItsTimeG() <10)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort1_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 10 and ((IA*)i)->getItsTimeG() <20)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort2_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 20 and ((IA*)i)->getItsTimeG() <30)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort3_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 30 and ((IA*)i)->getItsTimeG() <40)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort4_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 40 and ((IA*)i)->getItsTimeG() <50)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort5_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 50 and ((IA*)i)->getItsTimeG() <60)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort6_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 60 and ((IA*)i)->getItsTimeG() <70)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort7_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 70 and ((IA*)i)->getItsTimeG() <80)
                        {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY, *ramboMort8_9G);
                        }
                        else if (((IA*)i)->getItsTimeG() >= 80)
                        {
                        ((IA*)i)->setItsTimeG(0);
                         painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *ramboMort9_9G);
                         ((IA*)i)->setAnimationDead(true);
                        }
                    }

                    if (((IA*)i)->getDirection() == true and ((IA*)i)->getAnimationDead() == true)
                    {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *ramboMort9_9G);

                    }
                    else if (((IA*)i)->getDirection() == false and ((IA*)i)->getAnimationDead() == true)
                    {
                        painter->drawImage(((IA*)i)->getItsX()+offSetX, ((IA*)i)->getItsY()+offSetY+sizeBlock+10, *ramboMort9_9D);

                    }

                }
            }


        }
        else
        {
            first = false;
        }

    }









    if (ground == true)
    {

        itsPersoTimeJump =0;
        fall = false;
    }
    // Balle ------------------------------------------------------------------------------------------------------------------------------

    if(currentGame->getItsBullets().size()!=0)
    {
        for(Bullet * bullet : currentGame->getItsBullets())
        {
            if(currentGame->getPlayer()->getDirection() == true and bullet->getIsHit() == false) painter->drawImage(bullet->getItsX()+offSetX, bullet->getItsY()+offSetY, *balleGauche);
            else if(currentGame->getPlayer()->getDirection() == false and bullet->getIsHit() == false) painter->drawImage(bullet->getItsX()+offSetX, bullet->getItsY()+offSetY, *balleDroite);
            else if(bullet->getIsHit() == true)
            { if (bullet->getAnimTime() >= 0 and bullet->getAnimTime() < 10)
                {
                    painter->drawImage(bullet->getItsX()+offSetX-10, bullet->getItsY()+offSetY-6, *boom1_6);
                }
                if (bullet->getAnimTime() >= 10 and bullet->getAnimTime() < 20)
                {
                     painter->drawImage(bullet->getItsX()+offSetX-10, bullet->getItsY()+offSetY-6, *boom2_6);
                }
                if (bullet->getAnimTime() >= 20 and bullet->getAnimTime() < 30)
                {
                     painter->drawImage(bullet->getItsX()+offSetX-10, bullet->getItsY()+offSetY-6, *boom3_6);
                }
                if (bullet->getAnimTime() >= 30 and bullet->getAnimTime() < 40)
                {
                     painter->drawImage(bullet->getItsX()+offSetX-10, bullet->getItsY()+offSetY-6, *boom4_6);
                }
                if (bullet->getAnimTime() >= 40 and bullet->getAnimTime() < 50)
                {
                     painter->drawImage(bullet->getItsX()+offSetX-10, bullet->getItsY()+offSetY-6, *boom5_6);
                }
                if (bullet->getAnimTime() >= 50 and bullet->getAnimTime() < 60)
                {
                     painter->drawImage(bullet->getItsX()+offSetX-10, bullet->getItsY()+offSetY-6, *boom6_6);
                }

            }
        }
     }
}
