#include "safe_line.h"
#include "gl_helpers.h"
#include "config.h"
void safe_line::render(GLint num) {
    draw_line_with_noise({ SAFE_LINE_BEGIN_X, SAFE_LINE_BEGIN_Y + num * SAFE_LINE_OFFSET }, 
            { SAFE_LINE_END_X, SAFE_LINE_END_Y + num * SAFE_LINE_OFFSET },
            SAFE_LINE_NOISE, SAFE_LINE_SEGMENTS, SAFE_LINE_COLOR);
}
