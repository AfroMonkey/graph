#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <list>

#include "link.h"

class Vertex
{
public:
    std::string name_;
    std::list<Link> links_;
    bool visited_;

    Vertex(const std::string name = "uname") : name_(name), visited_(false) {}

    int set_link(Vertex *to, const int weight);
};

int Vertex::set_link(Vertex *to, const int weight)
{
    if(!to) return 0;

    for (std::list<Link>::iterator i = links_.begin(); i != links_.end(); i++)
    {
        if (i->to_ == to)
        {
            i->weight_ = weight;
            return 1;
        }
    }

    Link link(this, to, weight);
    links_.push_back(link);
    return 2;
}

#endif
