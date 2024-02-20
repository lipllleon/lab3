#pragma once
#include <SFML/Graphics.hpp>
#include <Shape.hpp>


class Circle : public Shape
{
private:
	float c_r;
	sf::CircleShape shape;

public:
	Circle() = default;

	Circle(float x, float y, float r, float v, float alfa) :Shape(x, y, v, alfa)
	{
		c_r = r;
		setBorders(r);
		shape.setOrigin(c_r, c_r);
		shape.setRadius(c_r);
		shape.setPosition(x, y);
		shape.setFillColor(sf::Color::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	}

	sf::CircleShape Get()
	{
		return shape;
	}

	void Move(float dt, int width, int height) {
		std::pair<float, float> m = move(dt, width, height);
		shape.setPosition(m.first, m.second);
	}

	void TouchBorder(int width, int height)
	{
		if (touchBorder(width, height))
			shape.setFillColor(sf::Color::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	}
};

