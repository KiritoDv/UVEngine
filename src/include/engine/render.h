#ifndef RENDER_H
#define RENDER_H

class Display;

class Render {
    public:
        Render(Display * game){
            this->game = game;
        }
        virtual void create();
        virtual void update();
        virtual void draw();
        virtual void dispose();
    private:
        Display * game;
};

#endif
