#include "cli.h"
#include "graph.h"

void set_vertices(Graph &graph);
void print_vertices(Graph &graph);
void print_links(Graph &graph);

void opt_add_link(Graph &graph);
void opt_prim(Graph &graph);
void opt_print(Graph &graph);


int main()
{
    Graph graph;

    set_vertices(graph);

    int opt;
    do {
        show_menu();
        opt = get_int();
        switch(opt) {
            case OPT_ADD_LINK:
                opt_add_link(graph);
                break;
            case OPT_PRIM:
                opt_prim(graph);
                break;
            case OPT_PRINT:
                print_links(graph);
                break;
            case OPT_EXIT:
                return 0;
                break;
            default:
                msg(INVALID_OPTION);
                break;
        }
        pause();
        clear_screen();
    } while(opt != OPT_EXIT);
    return 0;
}

void set_vertices(Graph &graph)
{
    for (int i = get_int("Numero de vertices>"); i > 0; i--)
    {
        graph.add_vertex(get_string("Vertice>"));
    }
}

void print_vertices(Graph &graph)
{
    for (std::list<Vertex>::iterator i = graph.vertices_.begin(); i != graph.vertices_.end(); i++)
    {
        std::cout << i->name_ << "\n";
    }
}

void print_links(Graph &graph)
{
    for (std::list<Vertex>::iterator i = graph.vertices_.begin(); i != graph.vertices_.end(); i++)
    {
        for(std::list<Link>::iterator j = i->links_.begin(); j != i->links_.end(); j++)
        {
            std::cout << i->name_ << "-" << j->weight_ << "->" << j->to_->name_ <<  "\n";
        }
    }
}

void opt_add_link(Graph &graph)
{
    string start = get_string("Inicio>");
    string end = get_string("Final>");
    int weight = get_int ("Peso>");
    if(graph.set_link(graph.get_vertex(start), graph.get_vertex(end), weight)) {
        msg(DONE);
    } else {
        msg(ERROR);
    }
}

void opt_prim(Graph &graph)
{
    Vertex* start = graph.get_vertex(get_string("Inicio>"));
    if (start)
    {
        graph.prim(start);
    }
    else
    {
        msg("No encontrado");
    }
}
