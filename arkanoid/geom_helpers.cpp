#include "geom_helpers.h"
#define norm(v)    sqrt(dot(v,v))
#define d(u,v)     norm(u-v)

glm::vec2 get_nearest_point(glm::vec2 point, std::pair<glm::vec2, glm::vec2> segment) {
    glm::vec2 v = segment.second - segment.first;
    glm::vec2 w = point - segment.first;
    double c1 = dot(w, v);
    if (c1 <= 0) {
        return segment.first;
    }
    double c2 = dot(v, v);
    if (c2 <= c1) {
        return segment.second;
    }

    double b = c1 / c2;
    glm::vec2 pb = { segment.first.x + b * v.x, segment.first.y + b * v.y };
    return pb;
}

float distance_to_segment(glm::vec2 point, std::pair<glm::vec2, glm::vec2> segment) {
    auto nearest = get_nearest_point(point, segment);
    return d(point, nearest);
}

float distance_to_point(glm::vec2 p1, glm::vec2 p2) {
    return d(p1, p2);
}