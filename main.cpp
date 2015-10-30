#include "base.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "catalogue.cpp"
#include <memory>


int main() {
//    /*
//     * Create new base and set attributes. Print on console result
//    */
//    shared_ptr<Base> b(new Base());
//    b->setName("This file is cool");
//    b->setPathname("cool/fichier/jqjqj");
//   // b->affichage(cout);

//    /*
//     * Create new Photo and set attributes. Print on console result
//    */
//    shared_ptr<Photo> p(new Photo());
//    p->setName("disney.jpg");
//    p->setPathname("/cal/homes/sorube/Desktop/disney.jpg");
//    p->setLatitude(10.0);
//    p->setLongitude(15.0);
//    //p->affichage(cout);
//    //p->openObject();

//    /*
//     * Create new Video and set attributes. Print on console result
//    */
//    shared_ptr<Video> v(new Video());
//    v->setName("sample_video.mp4");
//    v->setPathname("/cal/homes/sorube/Desktop/sample_video.mp4");
//    v->setDuree(5);
//    //v->affichage(cout);
//    //v->openObject();

//    Base ** tableau = new Base * [2];
//    unsigned int count = 0;
//    tableau[count++] = p;
//    tableau[count++] = v;
//    for(unsigned int i =0; i<count; i++){
//        tableau[i]->affichage(cout);
//    }

//    shared_ptr<Film> f(new Film());
//    f->setName("sample_video.mp4");
//    f->setPathname("/cal/homes/sorube/Desktop/sample_video.mp4");
//    f->setDuree(5);
//    unsigned int d [] = { 5 , 2 , 3 };
//    unsigned int num = 3;
//    f->setDurees(d, num);
//    f->affichage(cout);

//    shared_ptr<Group> g(new Group("My Memories"));
//    g->push_back(f.get());
//    g->push_back(v.get());
//    g->push_back(p.get());
//    g->push_back(f.get());
//    g->affichage(cout);

//    g.reset();

//    //delete g;


//    shared_ptr<Group> g1(new Group("Photos"));
//    g1->push_back(p.get());
//    g1->affichage(cout);

//    g1.reset();
//    //delete g1;



//    /*
//     * Delete created objects
//    */
//    delete b;
//    delete p;
//    delete v;
//    delete f;
//    b.reset();
//    p.reset();
//    v.reset();
//    f.reset();

    shared_ptr<Catalogue> c(new Catalogue());
    //Catalogue * c = new Catalogue();
    c->createPhoto("Photo 1", "/sorube/photo", 1.23, 2.34);
    c->createVideo("video 1", "/sorube/video", 120);
    unsigned int d [] = { 5 , 2 , 3 };
    unsigned int num = 3;
    c->createFilm("film", "/sorube/film", 100, d,num);
    c->createGroup("Disney");
    c->rechercher("jeje");
    c->rechercher("Photo 1");
//    c->rechercher("Disney");
    c->supprimer("Photo 1");
    c->supprimer("Disney");
    //c->addToGroup("Photo 1", "Disney");




}
