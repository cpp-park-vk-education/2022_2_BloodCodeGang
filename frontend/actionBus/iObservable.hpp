#include <iostream>

class IObservable {
public:
    virtual void update(Action action) = 0;
}