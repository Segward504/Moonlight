//
//  Element.cpp
//  Moonlight
//

#include "Element.hpp"

Element::Element() {
    
}

void Element::Generate() {
    dnn = DNN();
    dnn.Generate();
}

void Element::SetInput(Element b) {
    
    Vec3 lookvector = Vec3(cos(rotation*pi/180), 0, sin(rotation*pi/180));
    
    Vec3 deltapos = b.pos.Sub(pos);
    
    double dotproduct = deltapos.Unit().Dot(lookvector);
    
    dnn.inputarray = {
        deltapos.a[0], deltapos.a[1], deltapos.a[0], dotproduct
    };
    
}

void Element::CalculateFitness(Element b) {
    
    double distance1 = abs(b.pos.Sub(previouspos).Normal());
    double distance2 = abs(b.pos.Sub(pos).Normal());
    
    if (distance2 < distance1) {
        fitness += 1;
    } else if (distance2 > distance1) {
        fitness -= 1;
    }
    
    cout << "fitness: " << fitness << endl;
}

void Element::Update() {
    
    dnn.ForwardFeed();
    
    previouspos = pos;
    
    if (dnn.outputarray[0] > 0.9) {
        Forward();
    }
    
    if (dnn.outputarray[1] > 0.9) {
        RotateLeft();
    }
    
    if (dnn.outputarray[2] > 0.9) {
        RotateRight();
    }
    
}

void Element::Forward() {
    Vec3 lookvector = Vec3(cos(rotation * pi/180), 0, sin(rotation * pi/180));
    pos = pos.Add(lookvector);
}

void Element::RotateLeft() {
    rotation = rotation + 45;
}

void Element::RotateRight() {
    rotation = rotation - 45;
}
