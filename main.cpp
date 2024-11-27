#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include "Class.cpp"
#include <thread>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

int countMenu = 0;
int gameCount = 0;
bool infoBoxB = false;
int quiSoigner = 0;

#pragma region Struct
struct CharacterStruct {
    bool isAttacking = false;
    bool SoundAttack = false;
    bool AttackMode = false;
    bool isHealing = false;
    bool SoundHeal = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isDead = false;
    bool SoundDead = false;
    bool printBody = false;
    int countAnimAtk = 0;
    int countAnimHeal = 0;
    int countAnimHit = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; CharacterStruct Char_S;

struct FireWormStruct {
    bool isAttacking = false;
    bool SoundAttack = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isHealing = false;
    bool isDead = false;
    bool SoundDead = false;
    bool printBody = false;
    int countAnimHit = 0;
    int countAnimAtk = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; FireWormStruct Worm_S;

struct EvilWizardStruct {
    bool isAttacking = false;
    bool SoundAttack = false;
    bool isHealing = false;
    bool SoundHeal = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isDead = false;
    bool SoundDead = false;
    bool printBody = false;
    int countAnimAtk = 0;
    int countAnimHeal = 0;
    int countAnimHit = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; EvilWizardStruct Evil_S;

struct BossStruct {
    bool isAttacking = false;
    bool isAttacking2 = false;
    bool SoundAttack = false;
    bool SoundAttack2 = false;
    bool isHit = false;
    bool SoundHit = false;
    bool isHealing = false;
    bool isDead = false;
    bool SoundDead = false;
    bool printBody = false;
    int countAnimAtk = 0;
    int countAnimAtk2 = 0;
    int countAnimHit = 0;
    int countAnimDeath = 0;
    int DeathCount = 0;
}; BossStruct Boss_S;

#pragma endregion Struct

int main()
{
    Wizard wizard;
    EvilWizard evilWizard;
    FireWorm fireWorm;
    Boss boss;

    // Cr�ation de la fen�tre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Fen�tre SFML");
    window.setFramerateLimit(8);

#pragma region Gestion_images
    ////////// Background //////////

    // Charger une texture

    sf::Texture background_texture;
    if (!background_texture.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\decor.png")) {
        return -1; // Erreur si le fichier est introuvable
    }
    background_texture.setSmooth(true);
    // Associer la texture � un sprite

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
    //
    sf::Texture perso_texture_Death;
    sf::Sprite perso_sprite_Death;
    if (!perso_texture_Death.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\free-wizard-sprite-sheets-pixel-art\\Wanderer Magican\\DeadV2.png")) {
        return -1;
    }
    perso_texture_Death.setSmooth(true);

    perso_sprite_Death.setTexture(perso_texture_Death);
    perso_sprite_Death.setPosition(225, 625);
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
    //
    sf::Texture fireWorm_texture_Death;
    sf::Sprite fireWorm_sprite_Death;
    if (!fireWorm_texture_Death.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Fire Worm\\Fire Worm\\Sprites\\Worm\\DeathV2.png")) {
        return -1;
    }
    fireWorm_texture_Death.setSmooth(true);

    fireWorm_sprite_Death.setTexture(fireWorm_texture_Death);
    fireWorm_sprite_Death.setPosition(925, 650);

    // Sorcier de feu m�chant //
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

    evilWizard_sprite_Hit.setTexture(evilWizard_texture_Hit);
    evilWizard_sprite_Hit.setPosition(1125, 444);
    //
    sf::Texture evilWizard_texture_Death;
    sf::Sprite evilWizard_sprite_Death;
    if (!evilWizard_texture_Death.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\Evil Wizard\\Evil Wizard\\Sprites\\DeathV2.png")) {
        return -1;
    }
    evilWizard_texture_Death.setSmooth(true);

    evilWizard_sprite_Death.setTexture(evilWizard_texture_Death);
    evilWizard_sprite_Death.setPosition(1125, 444);

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
    //
    sf::Texture boss_texture_Death;
    sf::Sprite boss_sprite_Death;
    if (!boss_texture_Death.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Tilesheet Projet SFML\\EVil Wizard 2\\EVil Wizard 2\\Sprites\\DeathV2.png")) {
        return -1;
    }
    boss_texture_Death.setSmooth(true);

    boss_sprite_Death.setTexture(boss_texture_Death);
    boss_sprite_Death.setPosition(1400, 333);

    ////////////////////////////////

    ////////// Animation ///////////
    sf::Vector2i c_anim(1, 0);
    sf::Vector2i c_anim_Attack(1, 0);
    sf::Vector2i c_anim_Heal(1, 0);
    sf::Vector2i c_anim_Hit(1, 0);
    sf::Vector2i c_anim_Death(1, 0);

    sf::Vector2i f_anim(1, 0);
    sf::Vector2i f_anim_Attack(1, 0);
    sf::Vector2i f_anim_Hit(1, 0);
    sf::Vector2i f_anim_Death(1, 0);

    sf::Vector2i e_anim(1, 0);
    sf::Vector2i e_anim_Attack(1, 0);
    sf::Vector2i e_anim_Hit(1, 0);
    sf::Vector2i e_anim_Heal(1, 0);
    sf::Vector2i e_anim_Death(1, 0);

    sf::Vector2i b_anim(1, 0);
    sf::Vector2i b_anim_Attack(1, 0);
    sf::Vector2i b_anim_Attack2(1, 0);
    sf::Vector2i b_anim_Hit(1, 0);
    sf::Vector2i b_anim_Death(1, 0);
    ////////////////////////////////
#pragma endregion Gestion_images
#pragma region Gestion_son
    sf::Music fightMusic;
    if (!fightMusic.openFromFile("C:\\Users\\quent\\Music\\MusicLab\\V2 120bpm.wav"))
        return -1;
    fightMusic.setLoop(true);
    if(gameCount >= 1) fightMusic.play();

    sf::SoundBuffer wizardAttack;
    if (!wizardAttack.loadFromFile("C:\\Users\\quent\\Music\\MusicLab\\wizard attack V3.wav"))
        return -1;

    sf::Sound soundWizardAttack;
    soundWizardAttack.setBuffer(wizardAttack);

    sf::SoundBuffer Heal;
    if (!Heal.loadFromFile("C:\\Users\\quent\\Music\\MusicLab\\HealWAV.wav"))
        return -1;

    sf::Sound soundHeal;
    soundHeal.setBuffer(Heal);

    sf::SoundBuffer fireWormAttack;
    if (!fireWormAttack.loadFromFile("C:\\Users\\quent\\Music\\MusicLab\\fireWormAttackWAV.wav"))
        return -1;

    sf::Sound soundFireWormAttack;
    soundFireWormAttack.setBuffer(fireWormAttack);

#pragma endregion Gestion_son

#pragma region Menu principal

    sf::Texture background_texture_Menu;
    if (!background_texture_Menu.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\free-sky-with-clouds-background-pixel-art-set\\Clouds\\Clouds 6\\1.png")) {
        return -1;
    }
    background_texture_Menu.setSmooth(true);

    sf::Sprite sprite_background_Menu;
    sprite_background_Menu.setTexture(background_texture_Menu);
    sprite_background_Menu.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu2;
    if (!background_texture_Menu2.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\free-sky-with-clouds-background-pixel-art-set\\Clouds\\Clouds 6\\2.png")) {
        return -1;
    }
    background_texture_Menu2.setSmooth(true);

    sf::Sprite sprite_background_Menu2;
    sprite_background_Menu2.setTexture(background_texture_Menu2);
    sprite_background_Menu2.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu3;
    if (!background_texture_Menu3.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\free-sky-with-clouds-background-pixel-art-set\\Clouds\\Clouds 6\\3.png")) {
        return -1;
    }
    background_texture_Menu3.setSmooth(true);

    sf::Sprite sprite_background_Menu3;
    sprite_background_Menu3.setTexture(background_texture_Menu3);
    sprite_background_Menu3.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu4;
    if (!background_texture_Menu4.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\free-sky-with-clouds-background-pixel-art-set\\Clouds\\Clouds 6\\4.png")) {
        return -1;
    }
    background_texture_Menu4.setSmooth(true);

    sf::Sprite sprite_background_Menu4;
    sprite_background_Menu4.setTexture(background_texture_Menu4);
    sprite_background_Menu4.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu5;
    if (!background_texture_Menu5.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\free-sky-with-clouds-background-pixel-art-set\\Clouds\\Clouds 6\\5.png")) {
        return -1;
    }
    background_texture_Menu5.setSmooth(true);

    sf::Sprite sprite_background_Menu5;
    sprite_background_Menu5.setTexture(background_texture_Menu5);
    sprite_background_Menu5.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Texture background_texture_Menu6;
    if (!background_texture_Menu6.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\Image Projet\\free-sky-with-clouds-background-pixel-art-set\\Clouds\\Clouds 6\\6.png")) {
        return -1;
    }
    background_texture_Menu6.setSmooth(true);

    sf::Sprite sprite_background_Menu6;
    sprite_background_Menu6.setTexture(background_texture_Menu6);
    sprite_background_Menu6.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    //
    sf::Font fontMenu;
    if (!fontMenu.loadFromFile("C:\\Users\\quent\\source\\repos\\Mini Projet FF\\minecraft\\minecraft.ttf"))
    {
        return -1;
    }
    sf::Text title_Menu;
    title_Menu.setPosition(230, 200);
    title_Menu.setFont(fontMenu);
    title_Menu.setString("SYWAR, THE QUEST OF JAAJ");
    title_Menu.setCharacterSize(90);
    title_Menu.setFillColor(sf::Color::White);
    title_Menu.setOutlineColor(sf::Color::Black);
    title_Menu.setOutlineThickness(10.f);
    title_Menu.setStyle(sf::Text::Bold);
    //
    sf::RectangleShape start_Menuu(sf::Vector2f(250.f, 50.f));
    start_Menuu.setPosition(300, 350);
    start_Menuu.setFillColor(sf::Color(255, 178, 101));
    sf::Text start_Menu;
    start_Menu.setPosition(300, 400);
    start_Menu.setFont(fontMenu);
    start_Menu.setString("START");
    start_Menu.setCharacterSize(50);
    start_Menu.setFillColor(sf::Color::White);
    start_Menu.setOutlineColor(sf::Color::Black);
    start_Menu.setOutlineThickness(8.f);
    start_Menu.setStyle(sf::Text::Bold);



#pragma endregion Menu principal

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
    UI_Character.setPosition(317, 690);
    UI_Character.setFont(font);
    UI_Character.setString("YOU");
    UI_Character.setCharacterSize(20);
    UI_Character.setFillColor(sf::Color::White);
    UI_Character.setOutlineColor(sf::Color::Black);
    UI_Character.setOutlineThickness(3.5f);
    UI_Character.setStyle(sf::Text::Bold);

    sf::Text UI_Character_PV;
    UI_Character_PV.setPosition(305, 720);
    UI_Character_PV.setFont(font);
    UI_Character_PV.setCharacterSize(20);
    UI_Character_PV.setFillColor(sf::Color::Green);
    UI_Character_PV.setOutlineColor(sf::Color::Black);
    UI_Character_PV.setOutlineThickness(3.5f);
    UI_Character_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Character_PV2;
    UI_Character_PV2.setPosition(351, 720);
    UI_Character_PV2.setFont(font);
    UI_Character_PV2.setString(" PV");
    UI_Character_PV2.setCharacterSize(20);
    UI_Character_PV2.setFillColor(sf::Color::Green);
    UI_Character_PV2.setOutlineColor(sf::Color::Black);
    UI_Character_PV2.setOutlineThickness(3.5f);
    UI_Character_PV2.setStyle(sf::Text::Bold);

    sf::Text UI_Worm;
    UI_Worm.setPosition(940, 620);
    UI_Worm.setFont(font);
    UI_Worm.setString("FIRE WORM");
    UI_Worm.setCharacterSize(20);
    UI_Worm.setFillColor(sf::Color::White);
    UI_Worm.setOutlineColor(sf::Color::Black);
    UI_Worm.setOutlineThickness(3.5f);
    UI_Worm.setStyle(sf::Text::Bold);

    sf::Text UI_Worm_PV;
    UI_Worm_PV.setPosition(970, 650);
    UI_Worm_PV.setFont(font);
    UI_Worm_PV.setCharacterSize(20);
    UI_Worm_PV.setFillColor(sf::Color::Green);
    UI_Worm_PV.setOutlineColor(sf::Color::Black);
    UI_Worm_PV.setOutlineThickness(3.5f);
    UI_Worm_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Worm_PV2;
    UI_Worm_PV2.setPosition(1005, 650);
    UI_Worm_PV2.setFont(font);
    UI_Worm_PV2.setString(" PV");
    UI_Worm_PV2.setCharacterSize(20);
    UI_Worm_PV2.setFillColor(sf::Color::Green);
    UI_Worm_PV2.setOutlineColor(sf::Color::Black);
    UI_Worm_PV2.setOutlineThickness(3.5f);
    UI_Worm_PV2.setStyle(sf::Text::Bold);

    sf::Text UI_Evil;
    UI_Evil.setPosition(1280, 520);
    UI_Evil.setFont(font);
    UI_Evil.setString("EVIL WIZARD");
    UI_Evil.setCharacterSize(20);
    UI_Evil.setFillColor(sf::Color::White);
    UI_Evil.setOutlineColor(sf::Color::Black);
    UI_Evil.setOutlineThickness(3.5f);
    UI_Evil.setStyle(sf::Text::Bold);

    sf::Text UI_Evil_PV;
    UI_Evil_PV.setPosition(1310, 550);
    UI_Evil_PV.setFont(font);;
    UI_Evil_PV.setCharacterSize(20);
    UI_Evil_PV.setFillColor(sf::Color::Green);
    UI_Evil_PV.setOutlineColor(sf::Color::Black);
    UI_Evil_PV.setOutlineThickness(3.5f);
    UI_Evil_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Evil_PV2;
    UI_Evil_PV2.setPosition(1356, 550);
    UI_Evil_PV2.setFont(font);
    UI_Evil_PV2.setString(" PV");
    UI_Evil_PV2.setCharacterSize(20);
    UI_Evil_PV2.setFillColor(sf::Color::Green);
    UI_Evil_PV2.setOutlineColor(sf::Color::Black);
    UI_Evil_PV2.setOutlineThickness(3.5f);
    UI_Evil_PV2.setStyle(sf::Text::Bold);

    sf::Text UI_Boss;
    UI_Boss.setPosition(1780, 620);
    UI_Boss.setFont(font);
    UI_Boss.setString("???");
    UI_Boss.setCharacterSize(20);
    UI_Boss.setFillColor(sf::Color::White);
    UI_Boss.setOutlineColor(sf::Color::Black);
    UI_Boss.setOutlineThickness(3.5f);
    UI_Boss.setStyle(sf::Text::Bold);

    sf::Text UI_Boss_PV;
    UI_Boss_PV.setPosition(1750, 650);
    UI_Boss_PV.setFont(font);
    UI_Boss_PV.setCharacterSize(20);
    UI_Boss_PV.setFillColor(sf::Color::Green);
    UI_Boss_PV.setOutlineColor(sf::Color::Black);
    UI_Boss_PV.setOutlineThickness(3.5f);
    UI_Boss_PV.setStyle(sf::Text::Bold);
    sf::Text UI_Boss_PV2;
    UI_Boss_PV2.setPosition(1796, 650);
    UI_Boss_PV2.setFont(font);
    UI_Boss_PV2.setString(" PV");
    UI_Boss_PV2.setCharacterSize(20);
    UI_Boss_PV2.setFillColor(sf::Color::Green);
    UI_Boss_PV2.setOutlineColor(sf::Color::Black);
    UI_Boss_PV2.setOutlineThickness(3.5f);
    UI_Boss_PV2.setStyle(sf::Text::Bold);
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
                window.close(); // Fermer la fen�tre
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
            Char_S.countAnimDeath = 0;
            c_anim.x++;
            if (c_anim.x * 256 >= perso_texture.getSize().x) // boucle qui permet de revenir a la premiere slide de l'anim
                c_anim.x = 0;
            // ici, ce code permet de cr�er l'animation Idle du personnage
            perso_sprite.setTextureRect(sf::IntRect(c_anim.x * 256, 0, 256, 256));
        }
        //////////////////////////////////////////////////////////////////////////////////////
        // Worm
        if (!Worm_S.isHit && !Worm_S.isAttacking && !Worm_S.isHealing && fireWorm.getAlive() == true) {
            f_anim.x++;
            if (f_anim.x * 180 == fireWorm_texture.getSize().x) {
                f_anim.x = 0;
            }
            fireWorm_sprite.setTextureRect(sf::IntRect(f_anim.x * 180, 0, 180, 180));
            Worm_S.countAnimAtk = 0;
            Worm_S.countAnimHit = 0;
            Worm_S.countAnimDeath = 0;
        }

        //////////////////////////////////////////////////////////////////////////////////////
        // EvilWizard
        if (!Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && evilWizard.getAlive() == true) {
            e_anim.x++;
            if (e_anim.x * 450 == evilWizard_texture.getSize().x) {
                e_anim.x = 0;
            }
            evilWizard_sprite.setTextureRect(sf::IntRect(e_anim.x * 450, 0, 450, 450));
            Evil_S.countAnimAtk = 0;
            Evil_S.countAnimHeal = 0;
            Evil_S.countAnimHit = 0;
            Evil_S.countAnimDeath = 0;
        }


        //////////////////////////////////////////////////////////////////////////////////////
        // Boss
        if (!Boss_S.isAttacking && !Boss_S.isAttacking2 && !Boss_S.isHit && !Boss_S.isHealing && boss.getAlive() == true) {
            b_anim.x++;
            if (b_anim.x * 800 == boss_texture.getSize().x)
                b_anim.x = 0;

            boss_sprite.setTextureRect(sf::IntRect(b_anim.x * 800, 0, 800, 800));
            Boss_S.countAnimAtk = 0;
            Boss_S.countAnimAtk2 = 0;
            Boss_S.countAnimDeath = 0;
            Boss_S.countAnimHit = 0;
        }
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
        // S�lection des membres du menu
        // if on fais les fleches haut et bas alors on fait pop un rectangle autour du menu atk ou autre
        // COmpteur qui va de 1 a 3 avec a chaque fois -- dans le down et ++ dans le up ils ont pas le droit de d�passer 3 ou 1

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
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 1 && Char_S.AttackMode && fireWorm.getAlive() == true)
            {
                c_anim_Attack.x = 0;
                Char_S.AttackMode = false;
                Char_S.isAttacking = true;
                Worm_S.isHit = true;
                wizard.attack(fireWorm);
                //Cr�ation du rectangle de ce qui se passe
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au fireWorm !");
                gameCount++;
                countMenu = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 1 && Char_S.AttackMode && fireWorm.getAlive() == false) {
                infoBoxB = true;
                textInfoBox.setString("FireWorm est mort t'es bouch� mec !");
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 2 && Char_S.AttackMode && evilWizard.getAlive() == true)
            {
                Char_S.AttackMode = false;
                Char_S.isAttacking = true;
                Evil_S.isHit = true;
                wizard.attack(evilWizard);
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au Evil Wizard !");
                gameCount++;
                countMenu = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 1 && Char_S.AttackMode && evilWizard.getAlive() == false) {
                infoBoxB = true;
                textInfoBox.setString("EvilWizard est mort t'es bouch� mec !");
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 3 && Char_S.AttackMode && boss.getAlive() == true)
            {
                Char_S.AttackMode = false;
                Char_S.isAttacking = true;
                Boss_S.isHit = true;
                wizard.attack(boss);
                infoBoxB = true;
                textInfoBox.setString("Vous infligez une attaque au ??? !");
                gameCount++;
                countMenu = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 1 && Char_S.AttackMode && boss.getAlive() == false) {
                infoBoxB = true;
                textInfoBox.setString("??? est mort t'es bouch� mec !");
            }
            // Choix Soin
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 2 && wizard.getHealth() < 500)
            {
                c_anim_Heal.x = 0;
                c_anim.x = 0;
                Char_S.isHealing = true;
                wizard.heal();
                infoBoxB = true;
                textInfoBox.setString("Vous vous soignez de 30 PV");
                gameCount++;
                countMenu = 0;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 2 && wizard.getHealth() >= 500)
            {
                infoBoxB = true;
                textInfoBox.setString("T'es full Vie mec");
                wizard.setHealth(500);
            }
            // Choix passe ton tour
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && countMenu == 3)
            {
                infoBoxB = true;
                textInfoBox.setString("Vous passez un tour");
                gameCount++;
                countMenu = 0;
            }
        }
#pragma endregion Gestion Entree
#pragma region Gestion IA
        // FireWorm
        if (gameCount == 2 && fireWorm.getAlive() == false) {
            if (fireWorm.getAlive() == false) {
                Worm_S.isAttacking = false;
                Worm_S.isHit = false;
                gameCount++;
            }
        }
        if (gameCount == 2 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Worm_S.isHit && fireWorm.getAlive() == true) {
            Worm_S.isHit = false;
            Worm_S.isAttacking = true;
            fireWorm.attack(wizard);
            Char_S.isHit = true;
            infoBoxB = true;
            textInfoBox.setString("FireWorm vous inflige 8 points de degats !");
            gameCount++;

        }

        // EvilWizard
        if (gameCount == 3 && evilWizard.getAlive() == false) {
            Evil_S.isAttacking = false;
            Evil_S.isHealing = false;
            Evil_S.isHit = false;
            gameCount++;
        }
        if (gameCount == 3 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && evilWizard.getAlive() == true) {
            int action = rand() % 4;
            switch (action) {
            case 0:
                Evil_S.isHit = false;
                Evil_S.isAttacking = true;
                evilWizard.attack(wizard);
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("Evil Wizard vous inflige 12 points de degats !");
                gameCount++;
                break;

            case 1:
                Evil_S.isHit = false;
                Evil_S.isAttacking = true;
                evilWizard.attack(wizard);
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("Evil Wizard vous inflige 12 points de degats !");
                gameCount++;
                break;

            case 2:
                quiSoigner = rand() % 3;
                if (quiSoigner == 0 && fireWorm.getAlive() == true && fireWorm.getHealth() < 75) {
                    Evil_S.isHealing = true;
                    fireWorm.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne le FireWorm de 30 PV !");
                }
                else if (quiSoigner == 1 && evilWizard.getAlive() == true && evilWizard.getHealth() < 150) {
                    Evil_S.isHealing = true;
                    evilWizard.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard se soigne de 30 PV !");
                }
                else if (quiSoigner == 2 && boss.getAlive() == true < 425) {
                    Evil_S.isHealing = true;
                    boss.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne ??? de 30 PV !");
                }
                else {
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard a rate son incantation c'est vraiment un trou de balle !");
                }
                cout << evilWizard.getName() << " soigne" << endl << endl;

                gameCount++;
                break;

            case 3:
                quiSoigner = rand() % 3;
                quiSoigner += 3;
                if (quiSoigner == 3 && fireWorm.getAlive() == true && fireWorm.getHealth() < 75) {
                    Evil_S.isHealing = true;
                    fireWorm.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne le FireWorm de 30 PV !");
                }
                else if (quiSoigner == 4 && evilWizard.getAlive() == true && evilWizard.getHealth() < 150) {
                    Evil_S.isHealing = true;
                    evilWizard.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard se soigne de 30 PV !");
                }
                else if (quiSoigner == 5 && boss.getAlive() == true < 425) {
                    Evil_S.isHealing = true;
                    boss.heal();
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard soigne ??? de 30 PV !");
                }
                else {
                    infoBoxB = true;
                    textInfoBox.setString("Evil Wizard a rate son incantation c'est vraiment un trou de balle !");
                }

                cout << evilWizard.getName() << " soigne" << endl << endl;

                gameCount++;
                break;

            default:
                break;
            }
        }

        // Boss
        if (gameCount == 4 && boss.getAlive() == false) {
            Boss_S.isAttacking = false;
            Boss_S.isAttacking2 = false;
            Boss_S.isHit = false;
            gameCount++;
        }
        if (gameCount == 4 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && !Boss_S.isHit && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && boss.getAlive() == true) {
            int action = rand() % 5;
            switch (action) {
            case 0:
                Boss_S.isHit = false;
                Boss_S.isAttacking = true;
                boss.attack(wizard);
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 20 points de degats ! (attack1)");
                gameCount++;
                break;

            case 1:
                cout << boss.getName() << " regarde les mouches voler" << endl << endl;
                gameCount++;
                break;

            case 2:
                Boss_S.isHit = false;
                Boss_S.isAttacking = false;
                Boss_S.isAttacking2 = true;
                boss.attack(wizard);
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 20 points de degats ! (attack2)");
                gameCount++;
                break;

            case 3:
                Boss_S.isHit = false;
                Boss_S.isAttacking = true;
                boss.attack(wizard);
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 20 points de degats ! (attack1)");
                gameCount++;
                break;

            case 4:
                Boss_S.isHit = false;
                Boss_S.isAttacking = false;
                Boss_S.isAttacking2 = true;
                boss.attack(wizard);
                Char_S.isHit = true;
                infoBoxB = true;
                textInfoBox.setString("??? vous inflige 20 points de degats ! (attack2)");
                gameCount++;
                break;

            default:
                break;
            }
        }
#pragma endregion Gestion IA
#pragma region atelier dessin

        // Effacer la fen�tre
        window.clear();

        if (gameCount == 0) {
            window.draw(sprite_background_Menu);
            window.draw(sprite_background_Menu2);
            window.draw(sprite_background_Menu3);
            window.draw(sprite_background_Menu4);
            window.draw(sprite_background_Menu5);
            window.draw(sprite_background_Menu6);

            window.draw(title_Menu);
            window.draw(start_Menuu);
            window.draw(start_Menu);
        }
        if (gameCount >= 1) {
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
                if (Char_S.countAnimAtk == 2) {
                    soundWizardAttack.play();
                }
                if (Char_S.countAnimAtk == 7) {
                    Char_S.isAttacking = false;
                }
                // faut vraiment mettre un timeur pour permettre de faire les tours moins rapidement;
                window.draw(perso_sprite_Attack);
                Sleep(25);
            }///////////////////////////////////
            else if (Char_S.isHealing && wizard.getAlive() == true) {
                c_anim_Heal.x++;
                if (c_anim_Heal.x * 256 >= perso_texture_Heal.getSize().x)
                    c_anim_Heal.x = 0;
                perso_sprite_Heal.setTextureRect(sf::IntRect(c_anim_Heal.x * 256, 0, 256, 256));
                perso_sprite_Heal.setColor(sf::Color(0, 255, 0));
                Char_S.countAnimHeal++;
                if (Char_S.countAnimHeal == 7) {
                    soundFireWormAttack.stop();
                    soundWizardAttack.stop();
                    soundHeal.play();
                }
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
                perso_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Char_S.countAnimHit++;
                if (Char_S.countAnimHit == 4) {
                    Char_S.isHit = false;
                }
                window.draw(perso_sprite_Hit);
                Sleep(25);
            }///////////////////////////////////
            else if (Char_S.countAnimDeath == 0) {
                if (wizard.getAlive() == false && !Worm_S.isAttacking && !Evil_S.isAttacking && !Boss_S.isAttacking) {
                    c_anim_Death.x++;
                    if (c_anim_Death.x * 256 >= perso_texture_Death.getSize().x)
                        c_anim_Death.x = 0;
                    perso_sprite_Death.setTextureRect(sf::IntRect(c_anim_Death.x * 256, 0, 256, 256));
                    Char_S.countAnimDeath++;
                    if (Char_S.countAnimDeath == 4) {
                        Char_S.isDead = false;
                        Char_S.printBody = true;
                    }
                    window.draw(perso_sprite_Death);
                    Sleep(25);
                }
            }///////////////////////////////////


            /*else if (!Char_S.isAttacking && !Char_S.isHealing && Char_S.isHit && wizard.getAlive() == true && (Worm_S.isAttacking || Evil_S.isAttacking || Boss_S.isAttacking || Boss_S.isAttacking2)) {
                Char_S.countAnimAtk = 0;
                Char_S.countAnimHeal = 0;
                Char_S.countAnimHit = 0;
                Char_S.countAnimDeath = 0;
                c_anim.x++;
                if (c_anim.x * 256 >= perso_texture.getSize().x) // boucle qui permet de revenir a la premiere slide de l'anim
                    c_anim.x = 0;
                // ici, ce code permet de cr�er l'animation Idle du personnage
                perso_sprite.setTextureRect(sf::IntRect(c_anim.x * 256, 0, 256, 256));
                window.draw(perso_sprite);
            }///////////////////////////////////*/



            ////////// Worm ///////////

            if (!Worm_S.isHit && !Worm_S.isAttacking && !Worm_S.isHealing && fireWorm.getAlive() == true) {
                window.draw(fireWorm_sprite);
            }///////////////////////////////////

            else if (!Worm_S.isHit && !Worm_S.isAttacking && Worm_S.isHealing && fireWorm.getAlive() == true) {
                fireWorm_sprite.setColor(sf::Color(0, 255, 0));
            }///////////////////////////////////


            else if (Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Worm_S.isHit && fireWorm.getAlive() == true) {
                f_anim_Attack.x++;
                if (f_anim_Attack.x * 180 >= fireWorm_texture_Attack.getSize().x)
                    f_anim_Attack.x = 0;
                fireWorm_sprite_Attack.setTextureRect(sf::IntRect(f_anim_Attack.x * 180, 0, 180, 180));
                Worm_S.countAnimAtk++;
                if (Worm_S.countAnimAtk == 2) {
                    soundWizardAttack.stop();
                    soundFireWormAttack.play();
                }
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
                fireWorm_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Worm_S.countAnimHit++;
                if (Worm_S.countAnimHit == 4) {
                    Worm_S.isHit = false;
                }
                window.draw(fireWorm_sprite_Hit);
            }///////////////////////////////////
            else if (Worm_S.DeathCount == 0) {
                if (fireWorm.getAlive() == false) {
                    f_anim_Death.x++;
                    if (f_anim_Death.x * 180 >= fireWorm_texture_Death.getSize().x)
                        f_anim_Death.x = 0;
                    fireWorm_sprite_Death.setTextureRect(sf::IntRect(f_anim_Death.x * 180, 0, 180, 180));
                    Worm_S.countAnimDeath++;
                    if (Worm_S.countAnimDeath == 8) {
                        Worm_S.isDead = false;
                        Worm_S.DeathCount++;
                    }
                    window.draw(fireWorm_sprite_Death);
                }
            }///////////////////////////////////


        ////////// Evil Wizard ///////////

            if (!Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && evilWizard.getAlive() == true) {
                window.draw(evilWizard_sprite);
            }
            else if (Evil_S.isAttacking && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && evilWizard.getAlive() == true) { //&& wormisHit/atk etc pour vraiment mettre de l'ordre dans la boucle
                e_anim_Attack.x++;
                if (e_anim_Attack.x * 450 >= evilWizard_texture_Attack.getSize().x)
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
                if (e_anim_Heal.x * 450 >= evilWizard_texture_Heal.getSize().x)
                    e_anim_Heal.x = 0;
                evilWizard_sprite_Heal.setTextureRect(sf::IntRect(e_anim_Heal.x * 450, 0, 450, 450));
                evilWizard_sprite_Heal.setColor(sf::Color(0, 255, 0));
                Evil_S.countAnimHeal++;
                if (Evil_S.countAnimHeal == 2) {
                    soundWizardAttack.stop();
                    soundFireWormAttack.stop();
                    soundHeal.play();
                }
                if (Evil_S.countAnimHeal == 9) {
                    Evil_S.isHealing = false;
                }
                window.draw(evilWizard_sprite_Heal);
            }
            else if (Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && evilWizard.getAlive() == true) {
                e_anim_Hit.x++;
                if (e_anim_Hit.x * 450 >= evilWizard_texture_Hit.getSize().x)
                    e_anim_Hit.x = 0;
                evilWizard_sprite_Hit.setTextureRect(sf::IntRect(e_anim_Hit.x * 450, 0, 450, 450));
                evilWizard_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Evil_S.countAnimHit++;
                if (Evil_S.countAnimHit == 5) {
                    Evil_S.isHit = false;
                }
                window.draw(evilWizard_sprite_Hit);
            }
            else if (Evil_S.DeathCount == 0) {
                if (evilWizard.getAlive() == false) {
                    e_anim_Death.x++;
                    if (e_anim_Death.x * 450 >= evilWizard_texture_Death.getSize().x)
                        e_anim_Death.x = 0;
                    evilWizard_sprite_Death.setTextureRect(sf::IntRect(e_anim_Death.x * 450, 0, 450, 450));
                    Evil_S.countAnimDeath++;
                    if (Evil_S.countAnimDeath == 5) {
                        Evil_S.isDead = false;
                        Evil_S.DeathCount++;
                    }
                    window.draw(evilWizard_sprite_Hit);
                }
            }

            ////////// Boss ///////////

            if (!Boss_S.isAttacking && !Boss_S.isHit && !Boss_S.isAttacking2 && !Boss_S.isHealing && boss.getAlive() == true) {
                window.draw(boss_sprite);
            }
            else if (!Boss_S.isHit && !Boss_S.isAttacking && Boss_S.isHealing && boss.getAlive() == true) {
                boss_sprite.setColor(sf::Color(0, 255, 0));
            }///////////////////////////////////
            else if (Boss_S.isAttacking && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Worm_S.isDead && !Evil_S.isDead && boss.getAlive() == true) {
                b_anim_Attack.x++;
                if (b_anim_Attack.x * 800 >= boss_texture_Attack.getSize().x)
                    b_anim_Attack.x = 0;
                boss_sprite_Attack.setTextureRect(sf::IntRect(b_anim_Attack.x * 800, 0, 800, 800));
                Boss_S.countAnimAtk++;
                if (Boss_S.countAnimAtk == 8) {
                    Boss_S.isAttacking = false;
                }
                window.draw(boss_sprite_Attack);
            }
            else if (Boss_S.isHit && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && boss.getAlive() == true) {
                b_anim_Hit.x++;
                if (b_anim_Hit.x * 800 >= boss_texture_Hit.getSize().x)
                    b_anim_Hit.x = 0;
                boss_sprite_Hit.setTextureRect(sf::IntRect(b_anim_Hit.x * 800, 0, 800, 800));
                boss_sprite_Hit.setColor(sf::Color(255, 0, 0));
                Boss_S.countAnimHit++;
                if (Boss_S.countAnimHit == 3) {
                    Boss_S.isHit = false;
                }
                window.draw(boss_sprite_Hit);
            }
            else if (Boss_S.isAttacking2 && !Evil_S.isAttacking && !Evil_S.isHealing && !Evil_S.isHit && !Worm_S.isHit && !Worm_S.isAttacking && !Char_S.isAttacking && !Char_S.isHealing && !Worm_S.isDead && !Evil_S.isDead && boss.getAlive() == true) {
                b_anim_Attack2.x++;
                if (b_anim_Attack2.x * 800 >= boss_texture_Attack2.getSize().x)
                    b_anim_Attack2.x = 0;
                boss_sprite_Attack2.setTextureRect(sf::IntRect(b_anim_Attack2.x * 800, 0, 800, 800));
                Boss_S.countAnimAtk2++;
                if (Boss_S.countAnimAtk2 == 8) {
                    Boss_S.isAttacking2 = false;
                }
                window.draw(boss_sprite_Attack2);
            }
            else if (Boss_S.DeathCount == 0) {
                if (boss.getAlive() == false) {
                    b_anim_Death.x++;
                    if (b_anim_Death.x * 800 >= boss_texture_Death.getSize().x)
                        b_anim_Death.x = 0;
                    boss_sprite_Death.setTextureRect(sf::IntRect(b_anim_Death.x * 800, 0, 800, 800));
                    Boss_S.countAnimDeath++;
                    if (Boss_S.countAnimDeath == 7) {
                        Boss_S.isDead = false;
                        Boss_S.DeathCount++;
                    }
                    window.draw(boss_sprite_Attack2);
                }
            }
#pragma endregion animation qui marche la ptn de ta soeur

            //Sleep(100);

            if (gameCount == 1 && !Char_S.isAttacking && !Char_S.isHealing && !Char_S.isHit && wizard.getAlive() == true) {
                window.draw(menuBackground);
                window.draw(menuAtk);
                window.draw(textAtk);
                window.draw(menuHeal);
                window.draw(textHeal);
                window.draw(menuSkip);
                window.draw(textSkip);
                //Sleep(50);
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
                window.draw(UI_Character_PV);
                window.draw(UI_Character_PV2);
                string Vie_Char(to_string(wizard.getHealth()));
                UI_Character_PV.setString(Vie_Char);
            }
            if (fireWorm.getAlive() == true) {
                window.draw(UI_Worm);
                window.draw(UI_Worm_PV);
                window.draw(UI_Worm_PV2);
                string Vie_Worm(to_string(fireWorm.getHealth()));
                UI_Worm_PV.setString(Vie_Worm);
            }
            if (evilWizard.getAlive() == true) {
                window.draw(UI_Evil);
                window.draw(UI_Evil_PV);
                window.draw(UI_Evil_PV2);
                string Vie_Evil(to_string(evilWizard.getHealth()));
                UI_Evil_PV.setString(Vie_Evil);
            }
            if (boss.getAlive() == true) {
                window.draw(UI_Boss);
                window.draw(UI_Boss_PV);
                window.draw(UI_Boss_PV2);
                string Vie_Boss(to_string(boss.getHealth()));
                UI_Boss_PV.setString(Vie_Boss);
            }
        }
        // Afficher le contenu
        window.display();
    }
#pragma endregion atelier dessin
    return 0;
}