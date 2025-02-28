
#ifndef GESTORENOTELAB_OBSERVER_H
#define GESTORENOTELAB_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;
};


#endif //GESTORENOTELAB_OBSERVER_H
