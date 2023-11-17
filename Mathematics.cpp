#include <iostream>
#include <SFML/Graphics.hpp>
#include "Mathematics.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Mathematics {

    float Magnitude(const sf::Vector2f& vec) {
        return std::sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    void Normalize(sf::Vector2f* vec) {
        float magnitude = Magnitude(*vec);
            if (magnitude == 0) return;
        *vec /= magnitude;
    }

	float Angle(sf::Vector2f vec) {
		return std::atan2(vec.y, vec.x) * (180.0 / M_PI);
	}

    sf::Vector2f AngleToVector(float angle) {
        return sf::Vector2f(std::cos(angle), std::sin(angle));
    }
}