#pragma once
#include <SFML/Graphics.hpp>
#include <Shape.hpp>

class Triangle : public Shape
{
private:
	float t_r;
	float t_alfa_shape;
	sf::CircleShape shape;
public:
	Triangle(float x, float y, float r, float v, float alfa, float alfa_shape) : Shape(x, y, v, alfa)
	{
		t_r = r;
		t_alfa_shape = alfa_shape;
		setBorders(r * sin(alfa_shape), r * cos(alfa_shape), r * cos(alfa_shape - pi / 6), r * sin(alfa_shape + pi / 6));
		shape.setPointCount(3);
		shape.setRadius(r);
		shape.setOrigin(r, r);
		shape.setPosition(x, y);
		shape.setRotation(alfa_shape * (180 / pi));
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