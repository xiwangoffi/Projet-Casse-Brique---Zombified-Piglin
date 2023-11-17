#pragma once

namespace Mathematics {

    float Magnitude(const sf::Vector2f& vec);
    void Normalize(sf::Vector2f* vec);
    float Angle(sf::Vector2f vec);
    sf::Vector2f AngleToVector(float angle);

}
