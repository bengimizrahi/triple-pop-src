#ifndef HEXAGRID_H
#define HEXAGRID_H

#include <SMFL/Graphics.hpp>
#include <memory>
#include <array>

constexpr float hexagrid_radius = 10.0f;
constexpr float ball_radius = hexagrid_radius * 0.9;
enum Direction {NE, N, NW, SW, S, SE};

constexpr int num_of_hexagrids(int level)
{
    return (3 * level * level) - (3 * level) + 1
}


class Hexagrid {
private:
    std::unique_ptr<Ball> ball_{};
    std::array<Hexagrid*, 6> neighbors_{{}};
};

template <int Level>
class Hexamesh {
    Hexamesh();
private:
    std::array<Hexagrid, num_of_hexagrids(Level)> hexagrids_;
};

#endif // HEXAGRID_H
