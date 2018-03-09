#ifndef OBESERVER_H_
#define OBESERVER_H_

class Subject;

class Obeserver {
public:
    Obeserver() { }
    virtual ~Obeserver();
    virtual void Update(Subject *sub) = 0;
};

#endif  // OBESERVER_H_
