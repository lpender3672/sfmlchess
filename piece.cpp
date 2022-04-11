
#include <iostream>
#include <list>
#include <map>
#include <SFML\Graphics.hpp>

#include "piece.h"

piece::piece() {
	id = 0;
}

piece::piece(int const& _id) {
	std::string piecenames[6] = {"king", "queen", "bishop", "knight", "rook", "pawn" };
	id = _id;
	
	if (id == 0) {
		colour = "none";
		name = "none";
	}
	else {
		name = piecenames[(_id - 1) % 6];

		if (id <= 6) {
			colour = "white";
		}
		else {
			colour = "black";
		}
	}

	
}

int piece::getID() {
	return id;
}


sf::Sprite piece::getSprite(sf::Sprite const& pieceSprites) {

	int unitHeight = pieceSprites.getGlobalBounds().height / 2;
	int unitWidth = pieceSprites.getGlobalBounds().width / 6;

	sf::Sprite pieceSprite = pieceSprites;


	int x = (id - 1) % 6;
	int y = (id - 1) / 6;

	pieceSprite.setTextureRect(sf::IntRect(x * unitWidth, y * unitHeight, unitWidth, unitHeight));

	return pieceSprite;
}