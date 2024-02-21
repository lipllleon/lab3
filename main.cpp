#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Rectangle.hpp>
#include <Triangle.hpp>
#include <chrono>
#include <thread>

int main()
{
	sf::RenderWindow m_window;
	int width = 1000;
	int height = 600;
	m_window.create(sf::VideoMode(width, height), "game");

	Circle cir(150, 300, 60, 100, pi/4);
	Rectangle rec(400, 300, 150, 100, 100, 5*pi/6, pi/4);
	Triangle tri(700, 300, 90, 100, -pi/3, pi/4);

	m_window.clear(sf::Color::White);
	m_window.draw(cir.Get());
	m_window.draw(rec.Get());
	m_window.draw(tri.Get());
	m_window.display();

	std::this_thread::sleep_for(std::chrono::seconds(2));
	sf::Clock clock;

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		float dt = clock.getElapsedTime().asSeconds();
		clock.restart();

		cir.Move(dt, width, height);
		rec.Move(dt, width, height);
		tri.Move(dt, width, height);

		cir.TouchBorder(width, height);		
		rec.TouchBorder(width, height);
		tri.TouchBorder(width, height);

		m_window.clear(sf::Color::White);
		m_window.draw(cir.Get());
		m_window.draw(rec.Get());
		m_window.draw(tri.Get());
		m_window.display();
	}
	return 0;
}


