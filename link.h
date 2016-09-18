#ifndef LINK_H
#define LINK_H

class Vertex;

class Link
{
public:
    Vertex* from_;
    Vertex *to_;
    int weight_;

    Link(Vertex* from, Vertex *to, const int weight = 0) : from_(from), to_(to), weight_(weight) {}
    const bool operator<(const Link &other) const {return weight_ < other.weight_;}
    const bool operator>(const Link &other) const {return weight_ > other.weight_;}
};

#endif
