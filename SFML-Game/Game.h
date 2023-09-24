#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();
private:
	void handleEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
	sf::RenderWindow mWindow;
	sf::Texture mTexture;
	sf::Sprite mPlayer;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
private:
	bool mMoveUp, mMoveDown, mMoveLeft, mMoveRight;
};

