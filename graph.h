#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <queue>
#include <stack>

#include "vertex.h"

#include <iostream>

class Graph
{
public:
    std::list<Vertex> vertices_;

    bool add_vertex(const std::string name);
    bool add_vertex(Vertex &vertex);
    bool set_link(Vertex *start, Vertex *end, int weight);
    Vertex* get_vertex(const std::string name);
    void prim(Vertex* start);
private:
    void unvisit();
};

bool Graph::add_vertex(const std::string name)
{
    for (auto i = vertices_.begin(); i != vertices_.end(); i++)
    {
        if (i->name_ == name) return false;
    }
    vertices_.push_back(Vertex(name));
    return true;
}

bool Graph::add_vertex(Vertex &vertex)
{
    vertices_.push_back(vertex);
    return true;
}

bool Graph::set_link(Vertex *start, Vertex *end, int weight)
{
    if (!(start && end)) return false;

    start->set_link(end, weight);
    end->set_link(start, weight);
    return true;
}

Vertex* Graph::get_vertex(const std::string name)
{
    for (auto i = vertices_.begin(); i != vertices_.end(); i++)
    {
        if (i->name_ == name) return &*i;
    }
    return nullptr;
}

void Graph::unvisit()
{
    for (auto i = vertices_.begin(); i != vertices_.end(); i++)
    {
        i->visited_ = false;
    }
}

void Graph::prim(Vertex* actual)
{
    if (vertices_.empty() || !actual) return;
    std::priority_queue<Link, std::vector<Link>, std::greater<Link> > queue;
    int total = 0;
    Vertex* next;

    for (auto link = actual->links_.begin(); link != actual->links_.end(); link++)
    {
        queue.push(*link);
    }
    actual->visited_ = true;

    do
    {
        next = queue.top().to_;
        if (!next->visited_)
        {
            next->visited_ = true;
            actual = queue.top().from_;
            std::cout << actual->name_ << "->" << queue.top().weight_ << "->" << next->name_ << std::endl;
            total += queue.top().weight_;
            queue.pop();
            for (auto link = next->links_.begin(); link != next->links_.end(); link++)
            {
                if (!link->to_->visited_)
                    queue.push(*link);
            }
        }
        else
        {
            queue.pop();
        }
    } while (!queue.empty());
    std::cout << "Total = " << total << std::endl;
    unvisit();
}

#endif
