#ifndef EVENTPAYLOAD_HPP
#define EVENTPAYLOAD_HPP
class EventPayload
{
    int status;
    int pause;
  public:
     EventPayload(int w, int nw)
     {
       this->status=w;
       this->pause=nw;
     }
};
#endif