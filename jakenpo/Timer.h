//timer to keep time and regulate internal actions
class Timer
{
    long start;
    long curr;

public:
    Timer()
    {
        restart();
    }

    double get_millis()
    {
        curr = millis();
        long diff = curr - start;

        return diff;
    }

    void restart()
    {
        start = millis();
        curr = start;
    }
};