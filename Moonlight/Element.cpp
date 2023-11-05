//
//  Element.cpp
//  Moonlight
//

#include "Element.hpp"

Element::Element() {
    
}

void Element::Generate() {
    
}

void Element::SetInput(Element b) {
    
    Vec3 lookvector = Vec3(cos(rotation*pi/180), 0, sin(rotation*pi/180));
    
    Vec3 deltapos = b.pos.Sub(pos).Unit();
    
    double dotproduct = deltapos.Dot(lookvector);
    
    cout << dotproduct << "\n";

}

void Element::CalculateFitness(Element b) {
    
}

void Element::Update() {
    
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
