#pragma once
#include <gl/freeglut.h>
#include "drawable.h"

class game_border : public drawable {
public:
    game_border(GLint width, GLint height);

    ~game_border() override;
    void render() override;

private:
    GLint width_;
    GLint height_;
};
