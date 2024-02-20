#pragma once
#include <SFML/Graphics.hpp>
#include <Shape.hpp>

class Rectangle : public Shape
{
private:
	float r_a;
	float r_b;
	float r_alfa_shape;
	sf::RectangleShape shape;
public:
	Rectangle(float x, float y, float a, float b, float v, float alfa, float alfa_shape) :Shape(x, y, v, alfa)
	{
		r_a = a;
		r_b = b;
		r_alfa_shape = alfa_shape;
		setBorders((a * cos(alfa_shape) + b * sin(alfa_shape)) / 2, (a * sin(alfa_shape) + b * cos(alfa_shape)) / 2);
		shape.setSize(sf::Vector2f(r_a, r_b));
		shape.setOrigin(a / 2, b / 2);
		shape.setPosition(x, y);
		shape.setRotation(alfa_shape * (180 / pi));
		shape.setFillColor(sf::Color::Color(rand() % 256, rand() % 256, rand() % 256, 255));
	}
	sf::RectangleShape Get()
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