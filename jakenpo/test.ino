#include <Joint.h>

int moves[] = [200,800,200,800];

Joint r;
Joint s_1;
Joint s_2;
Joint e_1;
Joint e_2;
Joint w_v;
Joint w_v;
w = 0

void setup()
{
    r.initialize(12,5);
    s_1.initialize(13,5);
    s_2.initialize(14,5);
    e_1.initialize(15,5);
    e_2.initialize(16,5);
    w_v.initialize(17,5);
    w_h.initialize(18,5);

    w_h.move(moves[w]);

}

void hand_shake()
{
     
}

void loop()
{
  if(!w_h.moving)
    if(w!=4)
      w_h.moves(++w);
  w_h.update();
  
}
