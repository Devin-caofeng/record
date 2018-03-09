#include <iostream>
#include "subject.h"
#include "obeserver.h"
#include "concrete_obeserver.h"
#include "concrete_subject.h"
using namespace std;

int main() {

    Subject *subject = new ConcreteSubject();

    return 0;
}
