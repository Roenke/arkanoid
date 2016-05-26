#pragma once
struct drawable {
    virtual ~drawable() {}

    virtual void render() = 0;
};
