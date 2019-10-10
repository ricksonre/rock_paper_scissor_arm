#include <ax12.h>

class Joint
{
    int id;
    double velocity;
    int goal;
    int min_rotation, max_rotation;
    bool moving;
    Timer timer;

public:

    void initialize(int id, double vel)
    {
        set_joint(id,vel,200,800);
    }

    void initialize(int id, double vel, int min, int max)
    {
        this->id = id;
        velocity = vel;
        max_rotation = max;
        min_rotation = min;
        moving = false;
        goal = GetPosition(id);

        SetPosition(id,512);
        delay(200);
    }

    void move(int pos)
    {
        if (pos > max_rotation)         goal = 800;
        else if (pos < min_rotation)    goal = 200;
        else                            goal = pos;
        
        timer.restart();
        moving = true;
    }

    void update()
    {
        int pos = GetPosition(id);
        if(goal != pos)
        {
            if(timer.get_millis() > 1000/velocity)
            {
                if(goal < pos)
                    SetPosition(id, pos - 1);
                else
                    SetPosition(id, pos + 1);

                timer.restart();
            }
        }
        else
        {
            moving = false;
        }
        
    }

    void center()
    {
        move(512);
    }

    void relax()
    {
        Relax(id);
    }
}
