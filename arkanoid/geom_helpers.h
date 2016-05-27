#pragma once
#include <glm/glm.hpp>
#include <utility>

float distance_to_segment(glm::vec2 point, std::pair<glm::vec2, glm::vec2> segment);
float distance_to_point(glm::vec2 p1, glm::vec2 p2);