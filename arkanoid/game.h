#pragma once
#include <gl/freeglut.h>
#include "drawable.h"
#include "rocket.h"
#include "game_field.h"
#include "game_border.h"
#include "legend.h"

class safe_line_bonus;

class game : public drawable {
public:
    game(GLint width, GLint height);
    ~game() override;
    void render() override;
    void process(float elapsed_time);
    void apply_bonus(bonus* bonus);
    rocket& get_rocket();
    void release_ball();

    friend safe_line_bonus;
private:
    void render_score_and_lifes() const;

    bool is_game_over;

    rocket player_;
    game_field field_;
    game_border border_;
    legend legend_;

    int score_;
    int lives_;

    int save_line_count;
};
