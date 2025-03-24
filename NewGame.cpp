#include "NewGame.hpp"

void Game::initAll() {

    //auto Boss = make_unique<Entities>();
    //Boss->sprite.setPosition(200, 200);
    //vector_Entities.push_back(move(Boss));

    auto Character = make_unique<Entities>("William l'intervenant", 500, 25);
    if (!Character->texture.loadFromFile("Extra\\TileSheets\\Wanderer Magican\\IdleV2.png")) {
        cout << "error load file IdlePerso.png" << endl;
    }
    Character->texture.setSmooth(true);

    Character->sprite.setTexture(Character->texture);
    Character->sprite.setPosition(225, 625);
    vector_Entities.push_back(move(Character));

}

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SYWAR, THE QUEST OF JAAJ");
    window.setFramerateLimit(frameLimit);

    auto startTime = chrono::steady_clock::now();
    auto waitTime = chrono::seconds(1);

    auto startSetTime = chrono::steady_clock::now();
    auto waitSetTime = chrono::seconds(1);

    initAll();

    Clock clock;

    // Boucle principale
    while (window.isOpen()) {
        Time deltaT = clock.restart();
        float deltaTime = deltaT.asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fenetre
        }




        window.clear();

        for (auto& Character : vector_Entities) {
            Character->update(deltaTime);
            Character->draw(window);
        }

        window.display();
    }
}