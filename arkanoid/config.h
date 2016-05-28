#pragma once
#include <GL/freeglut.h>

#define DEFAULT_GAME_WIDTH  724
#define DEFAULT_GAME_HEIGHT 765

#define SAFE_LINE_BEGIN_X   0
#define SAFE_LINE_BEGIN_Y   (DEFAULT_GAME_HEIGHT - 20)
#define SAFE_LINE_END_X     (DEFAULT_GAME_WIDTH)
#define SAFE_LINE_END_Y     (SAFE_LINE_BEGIN_Y)
#define SAFE_LINE_SEGMENTS  30
#define SAFE_LINE_NOISE     8
#define SAFE_LINE_COLOR     {0, 1, 1}
#define SAFE_LINE_OFFSET    8
#define MAX_SAFE_LINE_COUNT 3

#define BLOCK_HEIGHT 20
#define BLOCK_WIDTH  30

#define BLOCK_ROWS_COUNT 7
#define BLOCK_V_OFFSET   120
#define BLOCK_H_OFFSET   90
#define BETWEEN_BLOCKS_H_OFFSET 5
#define BETWEEN_BLOCKS_V_OFFSET 5

#define START_ROCKET_SIZE     200
#define ROCKET_BOTTOM_OFSET   40
#define START_ROCKET_H_OFFSET 200
#define START_ROCKET_HEIGHT   12
#define ROCKET_SPEED          500
#define MAX_ROCKET_SIZE       500
#define MIN_ROCKET_SIZE       50

#define BALL_RADIUS             10
#define BALL_COLOR              { 0.3, 0.7, 0.4 }
#define START_BALL_SPEED        500
#define START_BALL_DIRECTION    { -1., -1. }
#define MIN_BALL_SPEED          200
#define MAX_BALL_SPEED          900

#define SCORE_STRING_H_OFFFSET  624
#define SCORE_STRING_V_OFFSET   20
#define SCORE_FONT              GLUT_BITMAP_TIMES_ROMAN_24

#define LIVES_STRING_H_OFFSET   730
#define LIVES_STRING_V_OFFSET   20
#define LIVES_FONT              GLUT_BITMAP_TIMES_ROMAN_24

#define BONUS_WIDTH         10
#define BONUS_HEIGHT        15
#define BONUS_FALL_SPEED    80

#define BONUSES_COUNT       7
#define BONUS_PROPABILITY   1.

#define EXTEND_BONUS_COLOR                  {0, 1, 0}
#define EXTEND_BONUS_DESCRIPTION            "Extend rocket"
#define EXTEND_BONUS_VALUE                  30

#define SQUEEZE_BONUS_COLOR                 {1, 0, 0}
#define SQUEEZE_BONUS_DESCRIPTION           "Collapse rocket"
#define SQUEEZE_BONUS_VALUE                 30

#define SPEED_UP_BONUS_COLOR                {1, 1, 0}
#define SPEED_UP_BONUS_DESCRIPTION          "Increase ball speed"
#define SPEED_UP_BONUS_INCREASE_VALUE       50

#define SPEED_DOWN_BONUS_COLOR              {1, 1, 1}
#define SPEED_DOWN_BONUS_DESCRIPTION        "Decrease ball speed"
#define SPEED_DOWN_BONUS_DECREASE_VALUE     50

#define STICK_BONUS_COLOR                   {0, 0, 1}
#define STICK_BONUS_DESCRIPTION             "Make rocket stickly"

#define UNSTICK_BONUS_COLOR                 {0, 1, 1}
#define UNSTICK_DOWN_BONUS_DESCRIPTION      "Make rocket not stickly"

#define CRAZY_BALL_BONUS_COLOR              {0.5, 0.5, 0.5}
#define CRAZY_BALL_BONUS_DESCRIPTION        "Set random ball direction"

#define SAFE_LINE_BONUS_COLOR               {0.3, 0.5, 0.9}
#define SAFE_LINE_BONUS_DESCRIPTION         "Add safe line"

#define LEGEND_X_OFFSET     (DEFAULT_GAME_WIDTH + 10)
#define LEGEND_Y_OFFSET     100
#define LEGEND_NOTE_OFFSET  20
#define LEGEND_COLOR        {0.8, 1, 1}
#define LEGEND_FONT         GLUT_BITMAP_HELVETICA_12