#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "Class.cpp"
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

int countMenu = 0;
int gameCount = 1;
bool infoBoxB = false;

#pragma region Struct
struct CharacterStruct {
    bool isAttacking = false;
    bool AttackMode = false;
    bool isHealing = false;
    bool isHit = false;
    int countAnimAtk = 0;
    int countAnimHeal = 0;
    int countAnimHit = 0;
}; CharacterStruct Char_S;

struct FireWormStruct {
    bool isAttacking = false;
    bool isHit = false;
    int countAnimHit = 0;
    int countAnimAtk = 0;
}; FireWormStruct Worm_S;

struct EvilWizardStruct {
    bool isAttacking = false;
    bool isHealing = false;
    bool isHit = false;
    int countAnimAtk = 0;
    int countAnimHeal = 0;
    int countAnimHit = 0;
}; EvilWizardStruct Evil_S;

struct BossStruct {
    bool isAttacking = false;
    bool isAttacking2 = false;
    bool isHit = false;
    int countAnimAtk = 0;
    int countAnimAtk2 = 0;
    int countAnimHit = 0;
}; BossStruct Boss_S;
#pragma endregion Struct

int main()
{
    Wizard wizard;
    EvilWizard evilWizard;
    FireWorm fireWorm;
    Boss boss;

    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Fenêtre SFML");

#pragma region Gestion_images
    ////////// Background //////////

    // Charger une texture

    sf::Texture background_texture;
    if (!background_texture.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\decor.png")) {
        return -1; // Erreur si le fichier est introuvable
    }
    background_texture.setSmooth(true);
    // Associer la texture à un sprite

    sf::Sprite sprite_background;
    sprite_background.setTexture(background_texture);
    sprite_background.setTextureRect(sf::IntRect(0, 0, 1920, 1080));


    ////////////////////////////////



    ////////// Personnage //////////
    sf::Texture perso_texture;
    sf::Sprite perso_sprite;
    if (!perso_texture.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\free-wizard-sprite-sheets-pixel-art\\Wanderer Magican\\IdleV2.png")) {
        return -1;
    }
    perso_texture.setSmooth(true);

    perso_sprite.setTexture(perso_texture);
    perso_sprite.setPosition(225, 625);
    //
    sf::Texture perso_texture_Attack;
    sf::Sprite perso_sprite_Attack;
    if (!perso_texture_Attack.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\free-wizard-sprite-sheets-pixel-art\\Wanderer Magican\\Attack_1V2.png")) {
        return -1;
    }
    perso_texture_Attack.setSmooth(true);

    perso_sprite_Attack.setTexture(perso_texture_Attack);
    perso_sprite_Attack.setPosition(225, 625);
    //
    sf::Texture perso_texture_Heal;
    sf::Sprite perso_sprite_Heal;
    if (!perso_texture_Heal.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\free-wizard-sprite-sheets-pixel-art\\Wanderer Magican\\Attack_2V2.png")) {
        return -1;
    }
    perso_texture_Heal.setSmooth(true);

    perso_sprite_Heal.setTexture(perso_texture_Heal);
    perso_sprite_Heal.setPosition(225, 625);
    //
    sf::Texture perso_texture_Hit;
    sf::Sprite perso_sprite_Hit;
    if (!perso_texture_Hit.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\free-wizard-sprite-sheets-pixel-art\\Wanderer Magican\\HurtV2.png")) {
        return -1;
    }
    perso_texture_Hit.setSmooth(true);

    perso_sprite_Hit.setTexture(perso_texture_Hit);
    perso_sprite_Hit.setPosition(225, 625);

    ////////////////////////////////

    ////////// Ennemis //////////

    // Verre de terre de feu nul //
    sf::Texture fireWorm_texture;
    sf::Sprite fireWorm_sprite;
    if (!fireWorm_texture.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Fire Worm\\Fire Worm\\Sprites\\Worm\\IdleV2.png")) {
        return -1;
    }
    fireWorm_texture.setSmooth(true);

    fireWorm_sprite.setTexture(fireWorm_texture);
    fireWorm_sprite.setPosition(925, 650);
    //
    sf::Texture fireWorm_texture_Attack;
    sf::Sprite fireWorm_sprite_Attack;
    if (!fireWorm_texture_Attack.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Fire Worm\\Fire Worm\\Sprites\\Worm\\AttackV2.png")) {
        return -1;
    }
    fireWorm_texture_Attack.setSmooth(true);

    fireWorm_sprite_Attack.setTexture(fireWorm_texture_Attack);
    fireWorm_sprite_Attack.setPosition(925, 650);
    //
    sf::Texture fireWorm_texture_Hit;
    sf::Sprite fireWorm_sprite_Hit;
    if (!fireWorm_texture_Hit.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Fire Worm\\Fire Worm\\Sprites\\Worm\\Get HitV2.png")) {
        return -1;
    }
    fireWorm_texture_Hit.setSmooth(true);

    fireWorm_sprite_Hit.setTexture(fireWorm_texture_Hit);
    fireWorm_sprite_Hit.setPosition(925, 650);

    // Sorcier de feu méchant //
    sf::Texture evilWizard_texture;
    sf::Sprite evilWizard_sprite;
    if (!evilWizard_texture.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Evil Wizard\\Evil Wizard\\Sprites\\IdleV2.png")) {
        return -1;
    }
    evilWizard_texture.setSmooth(true);

    evilWizard_sprite.setTexture(evilWizard_texture);
    evilWizard_sprite.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Attack;
    sf::Sprite evilWizard_sprite_Attack;
    if (!evilWizard_texture_Attack.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Evil Wizard\\Evil Wizard\\Sprites\\AttackV2.png")) {
        return -1;
    }
    evilWizard_texture_Attack.setSmooth(true);

    evilWizard_sprite_Attack.setTexture(evilWizard_texture_Attack);
    evilWizard_sprite_Attack.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Heal;
    sf::Sprite evilWizard_sprite_Heal;
    if (!evilWizard_texture_Heal.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Evil Wizard\\Evil Wizard\\Sprites\\MoveV2.png")) {
        return -1;
    }
    evilWizard_texture_Heal.setSmooth(true);

    evilWizard_sprite_Heal.setTexture(evilWizard_texture_Heal);
    evilWizard_sprite_Heal.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Hit;
    sf::Sprite evilWizard_sprite_Hit;
    if (!evilWizard_texture_Hit.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Evil Wizard\\Evil Wizard\\Sprites\\HitV2.png")) {
        return -1;
    }
    evilWizard_texture_Hit.setSmooth(true);

    evilWizard_sprite_Hit.setTexture(evilWizard_texture_Heal);
    evilWizard_sprite_Hit.setPosition(1125, 444);

    // LE BOSS DE SES MORTS //
    sf::Texture boss_texture;
    sf::Sprite boss_sprite;
    if (!boss_texture.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\EVil Wizard 2\\EVil Wizard 2\\Sprites\\IdleV2.png")) {
        return -1;
    }
    boss_texture.setSmooth(true);

    boss_sprite.setTexture(boss_texture);
    boss_sprite.setPosition(1400, 333);
    //
    sf::Texture boss_texture_Attack;
    sf::Sprite boss_sprite_Attack;
    if (!boss_texture_Attack.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\EVil Wizard 2\\EVil Wizard 2\\Sprites\\Attack1V2.png")) {
        return -1;
    }
    boss_texture_Attack.setSmooth(true);

    boss_sprite_Attack.setTexture(boss_texture_Attack);
    boss_sprite_Attack.setPosition(1400, 333);
    //
    sf::Texture boss_texture_Attack2;
    sf::Sprite boss_sprite_Attack2;
    if (!boss_texture_Attack2.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\EVil Wizard 2\\EVil Wizard 2\\Sprites\\Attack2V2.png")) {
        return -1;
    }
    boss_texture_Attack2.setSmooth(true);

    boss_sprite_Attack2.setTexture(boss_texture_Attack2);
    boss_sprite_Attack2.setPosition(1400, 333);
    //
    sf::Texture boss_texture_Hit;
    sf::Sprite boss_sprite_Hit;
    if (!boss_texture_Hit.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\EVil Wizard 2\\EVil Wizard 2\\Sprites\\HitV2.png")) {
        return -1;
    }
    boss_texture_Hit.setSmooth(true);

    boss_sprite_Hit.setTexture(boss_texture_Hit);
    boss_sprite_Hit.setPosition(1400, 333);

    ////////////////////////////////

    ////////// Animation ///////////
    sf::Vector2i c_anim(1, 0);
    sf::Vector2i c_anim_Attack(1, 0);
    sf::Vector2i c_anim_Heal(1, 0);
    sf::Vector2i c_anim_Hit(1, 0);

    sf::Vector2i f_anim(1, 0);
    sf::Vector2i f_anim_Attack(1, 0);
    sf::Vector2i f_anim_Hit(1, 0);

    sf::Vector2i e_anim(1, 0);
    sf::Vector2i e_anim_Attack(1, 0);
    sf::Vector2i e_anim_Hit(1, 0);
    sf::Vector2i e_anim_Heal(1, 0);

    sf::Vector2i b_anim(1, 0);
    sf::Vector2i b_anim_Attack(1, 0);
    sf::Vector2i b_anim_Attack2(1, 0);
    sf::Vector2i b_anim_Hit(1, 0);


    ////////////////////////////////
#pragma endregion Gestion_images
#pragma region Menu
// Mini menu 
    sf::RectangleShape menuBackground(sf::Vector2f(420.0f, 226.f));
    menuBackground.setPosition(20, 20);
    menuBackground.setFillColor(sf::Color(255, 178, 101));

    sf::RectangleShape menuAtk(sf::Vector2f(420.f, 65.f));
    menuAtk.setPosition(20, 25);
    menuAtk.setFillColor(sf::Color(183, 127, 71));
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\minecraft\\minecraft.ttf"))
    {
        return -1;
    }
    sf::Text textAtk;
    textAtk.setPosition(130, 35);
    textAtk.setFont(font);
    textAtk.setString("ATTAQUER");
    textAtk.setCharacterSize(35);
    textAtk.setFillColor(sf::Color::White);
    textAtk.setOutlineColor(sf::Color::Black);
    textAtk.setOutlineThickness(5.f);
    textAtk.setStyle(sf::Text::Bold);

#pragma region sousMenuAtk
    // apres avoir choisi attaquer
    sf::RectangleShape menuWhoAtk(sf::Vector2f(420.f, 226.f));
    menuWhoAtk.setPosition(20, 20);
    menuWhoAtk.setFillColor(sf::Color(255, 178, 101));

    sf::RectangleShape menuWorm(sf::Vector2f(420.f, 65.f));
    menuWorm.setPosition(20, 25);
    menuWorm.setFillColor(sf::Color(183, 127, 71));
    sf::Text textMenuWorm;
    textMenuWorm.setPosition(120, 35);
    textMenuWorm.setFont(font);
    textMenuWorm.setString("FIRE WORM");
    textMenuWorm.setCharacterSize(35);
    textMenuWorm.setFillColor(sf::Color::White);
    textMenuWorm.setOutlineColor(sf::Color::Black);
    textMenuWorm.setOutlineThickness(5.f);
    textMenuWorm.setStyle(sf::Text::Bold);

    sf::RectangleShape menuEvilWizard(sf::Vector2f(420.f, 65.f));
    menuEvilWizard.setPosition(20, 100);
    menuEvilWizard.setFillColor(sf::Color(183, 127, 71));
    sf::Text textMenuEvilWizard;
    textMenuEvilWizard.setPosition(100, 110);
    textMenuEvilWizard.setFont(font);
    textMenuEvilWizard.setString("EVIL WIZARD");
    textMenuEvilWizard.setCharacterSize(35);
    textMenuEvilWizard.setFillColor(sf::Color::White);
    textMenuEvilWizard.setOutlineColor(sf::Color::Black);
    textMenuEvilWizard.setOutlineThickness(5.f);
    textMenuEvilWizard.setStyle(sf::Text::Bold);

    sf::RectangleShape menuBoss(sf::Vector2f(420.f, 65.f));
    menuBoss.setPosition(20, 175);
    menuBoss.setFillColor(sf::Color(183, 127, 71));
    sf::Text textMenuBoss;
    textMenuBoss.setPosition(180, 185);
    textMenuBoss.setFont(font);
    textMenuBoss.setString("???");
    textMenuBoss.setCharacterSize(35);
    textMenuBoss.setFillColor(sf::Color::White);
    textMenuBoss.setOutlineColor(sf::Color::Black);
    textMenuBoss.setOutlineThickness(5.f);
    textMenuBoss.setStyle(sf::Text::Bold);
#pragma endregion sousMenuAtk

    sf::RectangleShape menuHeal(sf::Vector2f(420.f, 65.f));
    menuHeal.setPosition(20, 100);
    menuHeal.setFillColor(sf::Color(183, 127, 71));
    sf::Text textHeal;
    textHeal.setPosition(180, 110);
    textHeal.setFont(font);
    textHeal.setString("SOIN");
    textHeal.setCharacterSize(35);
    textHeal.setFillColor(sf::Color::White);
    textHeal.setOutlineColor(sf::Color::Black);
    textHeal.setOutlineThickness(5.f);
    textHeal.setStyle(sf::Text::Bold);


    sf::RectangleShape menuSkip(sf::Vector2f(420.f, 65.f));
    menuSkip.setPosition(20, 175);
    menuSkip.setFillColor(sf::Color(183, 127, 71));
    sf::Text textSkip;
    textSkip.setPosition(70, 185);
    textSkip.setFont(font);
    textSkip.setString("PASSER LE TOUR");
    textSkip.setCharacterSize(35);
    textSkip.setFillColor(sf::Color::White);
    textSkip.setOutlineColor(sf::Color::Black);
    textSkip.setOutlineThickness(5.f);
    textSkip.setStyle(sf::Text::Bold);

#pragma region UI des ennemies 
    sf::Text UI_Character;
    UI_Character.setPosition(317, 700);
    UI_Character.setFont(font);
    UI_Character.setString("YOU");
    UI_Character.setCharacterSize(20);
    UI_Character.setFillColor(sf::Color::White);
    UI_Character.setOutlineColor(sf::Color::Black);
    UI_Character.setOutlineThickness(3.5f);
    UI_Character.setStyle(sf::Text::Bold);

    sf::Text UI_Worm;
    UI_Worm.setPosition(940, 650);
    UI_Worm.setFont(font);
    UI_Worm.setString("FIRE WORM");
    UI_Worm.setCharacterSize(20);
    UI_Worm.setFillColor(sf::Color::White);
    UI_Worm.setOutlineColor(sf::Color::Black);
    UI_Worm.setOutlineThickness(3.5f);
    UI_Worm.setStyle(sf::Text::Bold);

    sf::Text UI_Evil;
    UI_Evil.setPosition(1280, 540);
    UI_Evil.setFont(font);
    UI_Evil.setString("EVIL WIZARD");
    UI_Evil.setCharacterSize(20);
    UI_Evil.setFillColor(sf::Color::White);
    UI_Evil.setOutlineColor(sf::Color::Black);
    UI_Evil.setOutlineThickness(3.5f);
    UI_Evil.setStyle(sf::Text::Bold);

    sf::Text UI_Boss;
    UI_Boss.setPosition(1780, 620);
    UI_Boss.setFont(font);
    UI_Boss.setString("???");
    UI_Boss.setCharacterSize(20);
    UI_Boss.setFillColor(sf::Color::White);
    UI_Boss.setOutlineColor(sf::Color::Black);
    UI_Boss.setOutlineThickness(3.5f);
    UI_Boss.setStyle(sf::Text::Bold);
#pragma endregion UI des ennemies

    sf::RectangleShape infoBox(sf::Vector2f(700.f, 180.f));
    infoBox.setPosition(1100, 35);
    infoBox.setFillColor(sf::Color::Black);
    infoBox.setOutlineColor(sf::Color::White);
    infoBox.setOutlineThickness(5.f);

    sf::Text textInfoBox;
    textInfoBox.setPosition(1220, 105);
    textInfoBox.setFont(font);
    textInfoBox.setString("Erreur");
    textInfoBox.setCharacterSize(25);
    textInfoBox.setFillColor(sf::Color::White);
    textInfoBox.setOutlineColor(sf::Color::Black);
    textInfoBox.setOutlineThickness(3.5f);
    textInfoBox.setStyle(sf::Text::Bold);

#pragma endregion Menu

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fenêtre
        }

        if (gameCount >= 5) {
            gameCount = 1;
        }
        if (!infoBoxB) {
            infoBox.setFillColor(sf::Color::Transparent);
            infoBox.setOutlineColor(sf::Color::Transparent);
            textInfoBox.setString("");
        }
        if (infoBoxB) {
            infoBox.setFillColor(sf::Color::Black);
            infoBox.setOutlineColor(sf::Color::White);
            infoBox.setOutlineThickness(5.f);
        }

#pragma region animation
        //ici, on va rajouter 256px a notre image pour la faire changer et donc s'animer ;)
        // Character
        if (!Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && wizard.getAlive() == true) {
            Char_S.countAnimAtk = 0;
            Char_S.countAnimHeal = 0;
            Char_S.countAnimHit = 0;
            c_anim.x++;
            if (c_anim.x * 256 >= perso_texture.getSize().x) // boucle qui permet de revenir a la premiere slide de l'anim
                c_anim.x = 0;
            // ici, ce code permet de créer l'animation Idle du personnage
            perso_sprite.setTextureRect(sf::IntRect(c_anim.x * 256, 0, 256, 256));
        }
        //////////////////////////////////////////////////////////////////////////////////////
        // Worm
        if (!Worm_S.isHit && !Worm_S.isAttacking && fireWorm.getAlive() == true) {
            Worm_S.countAnimAtk = 0;
            Worm_S.countAnimHit = 0;
            f_anim.x++;
            if (f_anim.x * 180 >= fireWorm_texture.getSize().x)
                f_anim.x = 0;
            fireWorm_sprite.setTextureRect(sf::IntRect(f_anim.x * 180, 0, 180, 180));
        }

        //////////////////////////////////////////////////////////////////////////////////////
        // EvilWizard
        if (!Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && evilWizard.getAlive() == true) {
            Evil_S.countAnimAtk = 0;
            Evil_S.countAnimHeal = 0;
            Evil_S.countAnimHit = 0;
            e_anim.x++;
            if (e_anim.x * 450 == evilWizard_texture.getSize().x)
                e_anim.x = 0;

            evilWizard_sprite.setTextureRect(sf::IntRect(e_anim.x * 450, 0, 450, 450));
        }

        //////////////////////////////////////////////////////////////////////////////////////
        // Boss
        if(!Boss_S.isAttacking && !Boss_S.isAttacking2 && !Boss_S.isHit && boss.getAlive() == true)
        b_anim.x++;
        if (b_anim.x * 800 == boss_texture.getSize().x)
            b_anim.x = 0;

        boss_sprite.setTextureRect(sf::IntRect(b_anim.x * 800, 0, 800, 800));


#pragma endregion animation
#pragma region interMenu

        if (countMenu <= 1) {
            countMenu = 1;
        }
        else if (countMenu >= 3) {
            countMenu = 3;
        }

        if (countMenu == 1 && !Char_S.AttackMode) { // pointe sur attaque
            menuAtk.setOutlineColor(sf::Color::Cyan);
            menuAtk.setOutlineThickness(5.f);
        }
        else {
            menuAtk.setOutlineColor(sf::Color::Transparent); // disparait
            menuAtk.setOutlineThickness(0);
        }
        if (countMenu == 2 && !Char_S.AttackMode) { // pointe sur soin
            menuHeal.setOutlineColor(sf::Color::Cyan);
            menuHeal.setOutlineThickness(5.f);
        }
        else {
            menuHeal.setOutlineColor(sf::Color::Transparent);
            menuHeal.setOutlineThickness(0);
        }
        if (countMenu == 3 && !Char_S.AttackMode) { // pointe sur passe tour
            menuSkip.setOutlineColor(sf::Color::Cyan);
            menuSkip.setOutlineThickness(5.f);
        }
        else {
            menuSkip.setOutlineColor(sf::Color::Transparent);
            menuSkip.setOutlineThickness(0);
        }

        if (countMenu == 1 && Char_S.AttackMode) { // fireworm
            menuWorm.setOutlineColor(sf::Color::Cyan);
            menuWorm.setOutlineThickness(5.f);
        }
        else {
            menuWorm.setOutlineColor(sf::Color::Transparent);
            menuWorm.setOutlineThickness(0);
        }
        if (countMenu == 2 && Char_S.AttackMode) { // evilWizard
            menuEvilWizard.setOutlineColor(sf::Color::Cyan);
            menuEvilWizard.setOutlineThickness(5.f);
        }
        else {
            menuEvilWizard.setOutlineColor(sf::Color::Transparent);
            menuEvilWizard.setOutlineThickness(0);
        }
        if (countMenu == 3 && Char_S.AttackMode) { // boss
            menuBoss.setOutlineColor(sf::Color::Cyan);
            menuBoss.setOutlineThickness(5.f);
        }
        else {
            menuBoss.setOutlineColor(sf::Color::Transparent);
            menuBoss.setOutlineThickness(0);
        }

#pragma endregion interMenu
#pragma region Gestion Entree
        if (gameCount == 1) {
            // Keyboard
        // Sélection des membres du menu
        // if on fais les fleches haut et bas alors on fait pop un rectangle autour du menu atk ou autre
        // ensuite on dira que si on appui sur entrée et que le rectangle est sur les bonnes coordonnées alors lets gow
        // COmpteur qui va de 1 a 3 avec a chaque fois -- dans le down et ++ dans le up ils ont pas le droit de dépasser 3 ou 1

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && countMenu <= 3)
            {
                countMenu++;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && countMenu >= 1)
            {
                countMenu--;
            }
            // Choix attaque
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 1 && !Char_S.AttackMode)
            {
                Char_S.AttackMode = true;
                Char_S.isAttacking = false;
                Char_S.isHealing = false;
                Char_S.isHit = false;
            }
            // menu d'atk
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 1 && Char_S.AttackMode)
            {
                c_anim_Attack.x = 0;
                Char_S.isAttacking = true;
                Char_S.AttackMode = false;
                wizard.attack(fireWorm);
                Worm_S.isHit = true;
                //Création du rectangle de ce qui se passe
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au fireWorm !");
                gameCount++;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 2 && Char_S.AttackMode)
            {
                Char_S.isAttacking = true;
                Char_S.AttackMode = false;
                wizard.attack(evilWizard);
                Evil_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au Evil Wizard !");
                gameCount++;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 3 && Char_S.AttackMode)
            {
                Char_S.isAttacking = true;
                Char_S.AttackMode = false;
                wizard.attack(boss);
                Boss_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au ??? !");
                gameCount++;
            }
            // Choix Soin
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 2)
            {
                c_anim_Heal.x = 0;
                c_anim.x = 0;
                Char_S.isHealing = true;
                infoBoxB = true;
                textInfoBox.setString("Vous vous soignez de 15 PV");
                gameCount++;
            }
            // Choix passe ton tour
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 3)
            {
                infoBoxB = true;
                textInfoBox.setString("Vous passez un tour");
                gameCount++;
            }
        }
#pragma endregion Gestion Entree
#pragma region Gestion IA
        // FireWorm
        if ((gameCount == 2 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit) && (!Worm_S.isHit && fireWorm.getAlive() == true)) {
            int action = rand() % 2;
            switch (action) {
            case 0:
                fireWorm.attack(wizard);
                Worm_S.isAttacking = true;
                Worm_S.isHit = false;
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("FireWorm vous inflige 8 points de degats !");
                gameCount++;
                break;

            case 1:
                cout << fireWorm.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                break;

            default:
                break;
            }
        }

        // EvilWizard
        if ((gameCount == 3 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Evil_S.isHit && evilWizard.getAlive() == true) && ((!Worm_S.isHit && !Worm_S.isAttacking) || (fireWorm.getAlive() == false))) {
            int action = rand() % 3;
            switch (action) {
            case 0:
                evilWizard.attack(wizard);
                Evil_S.isAttacking = true;
                Evil_S.isHit = false;
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("Evil Wizard vous inflige 12 points de degats !");
                gameCount++;
                break;

            case 1:
                cout << evilWizard.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                break;

            case 2:
                Evil_S.isHealing = true;
                cout << evilWizard.getName() << " se soigne" << endl << endl;
                infoBoxB = true;
                textInfoBox.setString("Evil Wizard se soigne !");
                gameCount++;
                break;

            default:
                break;
            }
        }

        // Boss
        if (gameCount == 4 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Boss_S.isHit && boss.getAlive() == true && ((!Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit) || (evilWizard.getAlive() == false)) && ((!Worm_S.isHit && !Worm_S.isAttacking) || (fireWorm.getAlive() == false))) {
            int action = rand() % 5;
            switch (action) {
            case 0:
                boss.attack(wizard);
                Boss_S.isAttacking = true;
                Boss_S.isHit = false;
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 20 points de degats !");
                gameCount++;
                break;

            case 1:
                cout << boss.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                break;

            case 2:
                cout << boss.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                break;
            case 3:
                boss.attack(wizard);
                Boss_S.isAttacking = false;
                Boss_S.isAttacking2 = true;
                Boss_S.isHit = false;
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 20 points de degats !");
                gameCount++;
                break;
            case 4:
                cout << boss.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                break;

            default:
                break;
            }
            if (boss.getAlive() == false) gameCount++;
        }
#pragma endregion Gestion IA
#pragma region atelier dessin

        // Effacer la fenêtre
        window.clear();

        // Dessiner la forme
        window.draw(sprite_background);

#pragma region animation qui marche la ptn de ta soeur

        if (!Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && wizard.getAlive() == true) {
            window.draw(perso_sprite);
        }///////////////////////////////////
        else if (Char_S.isAttacking && wizard.getAlive() == true) {
            c_anim_Attack.x++;
            if (c_anim_Attack.x * 256 >= perso_texture_Attack.getSize().x)
                c_anim_Attack.x = 0;
            perso_sprite_Attack.setTextureRect(sf::IntRect(c_anim_Attack.x * 256, 0, 256, 256));
            Char_S.countAnimAtk++;
            if (Char_S.countAnimAtk == 7) {
                Char_S.isAttacking = false;
            }
            window.draw(perso_sprite_Attack);
            Sleep(25);
        }///////////////////////////////////
        else if (Char_S.isHealing && wizard.getAlive() == true) {
            c_anim_Heal.x++;
            if (c_anim_Heal.x * 256 >= perso_texture_Heal.getSize().x)
                c_anim_Heal.x = 0;
            perso_sprite_Heal.setTextureRect(sf::IntRect(c_anim_Heal.x * 256, 0, 256, 256));
            Char_S.countAnimHeal++;
            if (Char_S.countAnimHeal == 10) {
                Char_S.isHealing = false;
            }
            window.draw(perso_sprite_Heal);
            Sleep(25);
        }///////////////////////////////////
        else if (Char_S.isHit && !Char_S.isAttacking && !Char_S.isHealing && wizard.getAlive() == true) {
            c_anim_Hit.x++;
            if (c_anim_Hit.x * 256 >= perso_texture_Hit.getSize().x)
                c_anim_Hit.x = 0;
            perso_sprite_Hit.setTextureRect(sf::IntRect(c_anim_Hit.x * 256, 0, 256, 256));
            Char_S.countAnimHit++;
            if (Char_S.countAnimHit == 4) {
                Char_S.isHit = false;
            }
            window.draw(perso_sprite_Hit);
            Sleep(25);
        }///////////////////////////////////

        ////////// Worm ///////////

        if (!Worm_S.isHit && !Worm_S.isAttacking && fireWorm.getAlive() == true) {
            window.draw(fireWorm_sprite);
        }///////////////////////////////////

        else if (Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Worm_S.isHit && fireWorm.getAlive() == true) {
            f_anim_Attack.x++;
            if (f_anim_Attack.x * 180 >= fireWorm_texture_Attack.getSize().x)
                f_anim_Attack.x = 0;
            fireWorm_sprite_Attack.setTextureRect(sf::IntRect(f_anim_Attack.x * 180, 0, 180, 180));
            Worm_S.countAnimAtk++;
            if (Worm_S.countAnimAtk == 10) {
                Worm_S.isAttacking = false;
            }
            window.draw(fireWorm_sprite_Attack);
        }///////////////////////////////////

        else if (Worm_S.isHit && !Char_S.isHealing && fireWorm.getAlive() == true) {

            f_anim_Hit.x++;
            if (f_anim_Hit.x * 180 >= fireWorm_texture_Hit.getSize().x)
                f_anim_Hit.x = 0;
            fireWorm_sprite_Hit.setTextureRect(sf::IntRect(f_anim_Hit.x * 180, 0, 180, 180));
            Worm_S.countAnimHit++;
            if (Worm_S.countAnimHit == 4) {
                Worm_S.isHit = false;
            }
            window.draw(fireWorm_sprite_Hit);
        }///////////////////////////////////



        ////////// Evil Wizard ///////////

        if (!Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && evilWizard.getAlive() == true) {
            window.draw(evilWizard_sprite);
        }
        else if (Evil_S.isAttacking && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && evilWizard.getAlive() == true) { //&& wormisHit/atk etc pour vraiment mettre de l'ordre dans la boucle
            e_anim_Attack.x++;
            if (e_anim_Attack.x * 450 == evilWizard_texture_Attack.getSize().x)
                e_anim_Attack.x = 0;
            evilWizard_sprite_Attack.setTextureRect(sf::IntRect(e_anim_Attack.x * 450, 0, 450, 450));
            Evil_S.countAnimAtk++;
            if (Evil_S.countAnimAtk == 9) {
                Evil_S.isAttacking = false;
            }
            window.draw(evilWizard_sprite_Attack);
        }
        else if (Evil_S.isHealing && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && evilWizard.getAlive() == true) {
            e_anim_Heal.x++;
            if (e_anim_Heal.x * 450 == evilWizard_texture_Heal.getSize().x)
                e_anim_Heal.x = 0;
            evilWizard_sprite_Heal.setTextureRect(sf::IntRect(e_anim_Heal.x * 450, 0, 450, 450));
            Evil_S.countAnimHeal++;
            if (Evil_S.countAnimHeal == 9) {
                Evil_S.isHealing = false;
            }
            window.draw(evilWizard_sprite_Heal);
        }
        else if (Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && evilWizard.getAlive() == true) {
            e_anim_Hit.x++;
            if (e_anim_Hit.x * 450 == evilWizard_texture_Hit.getSize().x)
                e_anim_Hit.x = 0;
            evilWizard_sprite_Hit.setTextureRect(sf::IntRect(e_anim_Hit.x * 450, 0, 450, 450));
            Evil_S.countAnimHit++;
            if (Evil_S.countAnimHit == 5) {
                Evil_S.isHit = false;
            }
            window.draw(evilWizard_sprite_Hit);
        }

        ////////// Boss ///////////

        if (!Boss_S.isAttacking && !Boss_S.isHit && !Boss_S.isAttacking2 && boss.getAlive() == true) {
            window.draw(boss_sprite);
        }
        else if (Boss_S.isAttacking && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && boss.getAlive() == true) {
            b_anim_Attack.x++;
            if (b_anim_Attack.x * 800 == boss_texture_Attack.getSize().x)
                b_anim_Attack.x = 0;
            boss_sprite_Attack.setTextureRect(sf::IntRect(b_anim_Attack.x * 800, 0, 800, 800));
            Boss_S.countAnimAtk++;
            if (Boss_S.countAnimAtk == 9) {
                Boss_S.isAttacking = false;
            }
            window.draw(boss_sprite_Attack);
        }
        else if (Boss_S.isHit && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && boss.getAlive() == true) {
            b_anim_Hit.x++;
            if (b_anim_Hit.x * 800 == boss_texture_Hit.getSize().x)
                b_anim_Hit.x = 0;
            boss_sprite_Hit.setTextureRect(sf::IntRect(b_anim_Hit.x * 800, 0, 800, 800));
            Boss_S.countAnimHit++;
            if (Boss_S.countAnimHit == 9) {
                Boss_S.isHit = false;
            }
            window.draw(boss_sprite_Hit);
        }
        else if (Boss_S.isAttacking2 && !Boss_S.isAttacking && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && boss.getAlive() == true) {
            b_anim_Attack2.x++;
            if (b_anim_Attack2.x * 800 == boss_texture_Attack2.getSize().x)
                b_anim_Attack2.x = 0;
            boss_sprite_Attack.setTextureRect(sf::IntRect(b_anim_Attack2.x * 800, 0, 800, 800));
            Boss_S.countAnimAtk2++;
            if (Boss_S.countAnimAtk2 == 9) {
                Boss_S.isAttacking2 = false;
            }
            window.draw(boss_sprite_Attack2);
        }
#pragma endregion animation qui marche la ptn de ta soeur

        Sleep(100);

        if (gameCount == 1 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && wizard.getAlive() == true) {
            window.draw(menuBackground);
            window.draw(menuAtk);
            window.draw(textAtk);
            window.draw(menuHeal);
            window.draw(textHeal);
            window.draw(menuSkip);
            window.draw(textSkip);
            Sleep(50);
        }

        if (Char_S.AttackMode && gameCount == 1 && wizard.getAlive() == true) {
            window.draw(menuWhoAtk);
            window.draw(menuWorm);
            window.draw(textMenuWorm);
            window.draw(menuEvilWizard);
            window.draw(textMenuEvilWizard);
            window.draw(menuBoss);
            window.draw(textMenuBoss);
        }

        window.draw(infoBox);
        window.draw(textInfoBox);

        if (wizard.getAlive() == true) {
            window.draw(UI_Character);
        }
        if (fireWorm.getAlive() == true) {
            window.draw(UI_Worm);
        }
        if (evilWizard.getAlive() == true) {
            window.draw(UI_Evil);
        }
        if (boss.getAlive() == true) {
            window.draw(UI_Boss);
        }
        // Afficher le contenu
        window.display();
    }
#pragma endregion atelier dessin
    return 0;
}