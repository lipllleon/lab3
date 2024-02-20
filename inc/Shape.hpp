#pragma once
#include <SFML/Graphics.hpp>

const float pi = acos(-1);

class Shape
{
private:
	float p_x, p_y;
	float p_v;
	float p_alfa;
	float p_top;
	float p_right;
	float p_bottom;
	float p_left;

public:

	Shape() = default;

	Shape(float x, float y, float v, float alfa) {
		p_x = x;
		p_y = y;
		p_v = v;
		p_alfa = alfa;
	}

	void setBorders(float top, float right, float bottom, float left)
	{
		p_top = top;
		p_right = right;
		p_bottom = bottom;
		p_left = left;
	}
	void setBorders(float a, float b)
	{
		p_top = b;
		p_right = a;
		p_bottom = b;
		p_left = a;
	}
	void setBorders(float r)
	{
		p_top = r;
		p_right = r;
		p_bottom = r;
		p_left = r;
	}

	std::pair<float, float> move(float dt, int width, int height)
	{
		float vx = p_v * cos(p_alfa);
		float vy = p_v * sin(p_alfa);
		if (vx * dt > width - p_x - p_right)
			p_x = width - p_right;
		else if (vx * dt < -p_x + p_left)
			p_x = p_left;
		else {
			p_x += vx * dt;
		}
		if (vy * dt > height - p_y - p_bottom)
			p_y = height - p_bottom;
		else if (vy * dt < -p_y + p_top)
			p_y = p_top;
		else {
			p_y += vy * dt;
		}
		return std::pair<float, float>(p_x, p_y);
	}
	bool touchBorder(int width, int height)
	{

		if (p_x + p_right >= width || p_x - p_left <= 0)
		{
			p_alfa = pi - p_alfa;
			return true;
		}

		if (p_y + p_bottom >= height || p_y - p_top <= 0)
		{
			p_alfa = 2 * pi - p_alfa;
			return true;
		}
		return false;
	}
};