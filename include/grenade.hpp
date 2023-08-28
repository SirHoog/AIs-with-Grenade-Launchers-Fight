#pragma once

int explosionRadius = 200;

struct grenade
{
    sf::Vector2f pos = {0, 0};
    sf::Vector2f vel = {0, 0};
    sf::Time timeLeftMS;

    grenade(sf::Vector2f _pos = {0, 0}, sf::Vector2f _vel = {0, 0})
    {
        pos = _pos;
        vel = _vel;
    }
};