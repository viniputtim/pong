# ifndef SCENE_HPP
# define SCENE_HPP


class Game;


class Scene
{
protected:
    Game *game;

public:
    Scene(Game *game) : game(game) {};
    virtual ~Scene() {};
    virtual void check_events() {};
    virtual void update() {};
    virtual void draw() {};
};


# endif
