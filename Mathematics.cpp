#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mathematics.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Mathematics {

    float Magnitude(const sf::Vector2f& vec) {
        return std::sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    void Normalize(sf::Vector2f* vec) {
        float magnitude = Magnitude(*vec);
        std::cout << "magnitude: " << magnitude << std::endl;
            if (magnitude == 0) return;
        *vec /= magnitude;
    }

	float Angle(sf::Vector2f vec) {
		return std::atan2(vec.y, vec.x) * (180.0 / M_PI);
	}
}