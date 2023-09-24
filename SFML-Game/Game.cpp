#include "Game.h"

Game::Game() 
: mWindow(sf::VideoMode(640, 480), "SFML Application"), mPlayer(), mTexture()
{
	if (!mTexture.loadFromFile("../gfx/Textures/Player.png")) {

	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) {
		handleEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			handleEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::handleEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		default:
			break;
		}

	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::W) {
		mMoveUp = isPressed;
	}
	if (key == sf::Keyboard::S) {
		mMoveDown = isPressed;
	}
	if (key == sf::Keyboard::A) {
		mMoveLeft = isPressed;
	}
	if (key == sf::Keyboard::D) {
		mMoveRight = isPressed;
	}
}

void Game::update(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	if (mMoveUp) {
		movement.y -= 1.f;
	}
	if (mMoveDown) {
		movement.y += 1.f;
	}
	if (mMoveLeft) {
		movement.x -= 1.f;
	}
	if (mMoveRight) {
		movement.x += 1.f;
	}

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}