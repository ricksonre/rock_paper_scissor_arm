class Joint
{
    int id;
    double velocity;
    int goal;
    int min_rotation, max_rotation;
    Timer timer;

public:
    Joint(int id, double vel, int min, int max)
    {
        this->id = id;
        velocity = vel;
        max_rotation = max;
        min_rotation = min;
    }

    void update()
    {
        if (timer.get_millis() > 1 / velocity)
        {
            int curr = GetPosition(id);

            if (goal < curr)
                SetPosition(id, curr + 1);
            if (goal > curr)
                SetPosition(id, curr - 1);

            timer.restart();
        }
    }
    void move(int pos)
    {
        if (pos < max_rotation && pos > min_rotation)
        {
            goal = pos;
        }
    }
    void relax()
    {
        Relax(id);
    }
}
