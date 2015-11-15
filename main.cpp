#include "base.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "catalogue.h"
#include <memory>
#include <string>


int main() {
    if(0){
        /*
         * Create new base and set attributes. Print on console result
        */
        shared_ptr<Base> b(new Base());
        b->setName("This file is cool");
        b->setPathname("cool/fichier/jqjqj");
        b->affichage(cout);

        /*
        * Create new Photo and set attributes. Print on console result
        */
        shared_ptr<Photo> p(new Photo());
        p->setName("disney.jpg");
        p->setPathname("/home/sorube/Documents/INF224/disney.jpg");
        p->setLatitude(10.0);
        p->setLongitude(15.0);
        p->affichage(cout);
        p->openObject();

        /*
         * Create new Video and set attributes. Print on console result
        */
        shared_ptr<Video> v(new Video());
        v->setName("video1.mp4");
        v->setPathname("/home/sorube/Documents/INF224/video1.mp4");
        v->setDuree(5);
        //v->affichage(cout);
        //v->openObject();

        Base ** tableau = new Base * [2];
        unsigned int count = 0;
        tableau[count++] = p.get();
        tableau[count++] = v.get();
        for(unsigned int i =0; i<count; i++){
            tableau[i]->affichage(cout);
        }

        if(0){
            shared_ptr<Film> f(new Film());
            f->setName("sample_video.mp4");
            f->setPathname("/cal/homes/sorube/Desktop/sample_video.mp4");
            f->setDuree(5);
            unsigned int d [] = { 5 , 2 , 3 };
            unsigned int num = 3;
            f->setDurees(d, num);
            f->affichage(cout);

            shared_ptr<Group> g(new Group("My Memories"));
            g->push_back(f.get());
            g->push_back(v.get());
            g->push_back(p.get());
            g->push_back(f.get());
            g->affichage(cout);

            g.reset();

            //delete g;


            shared_ptr<Group> g1(new Group("Photos"));
            g1->push_back(p.get());
            g1->affichage(cout);

            g1.reset();
            //delete g1;
        }



        /*
         * Delete created objects
        */
//        delete b;
//        delete p;
//        delete v;
//        delete f;
        b.reset();
        p.reset();
        v.reset();
        //f.reset();
    }

    if(0){
        shared_ptr<Photo> p(new Photo());
        p->setName("disney.jpg");
        p->setPathname("/home/sorube/Documents/INF224/disney.jpg");
        p->setLatitude(10.0);
        p->setLongitude(15.0);
        p->affichage(cout);
        p->openObject();

    }

    if(1){
        shared_ptr<Video> v(new Video());
        v->setName("video1.mp4");
        v->setPathname("/home/sorube/Documents/INF224/video1.mp4");
        v->setDuree(5);
        v->affichage(cout);
        v->openObject();

    }

    if(0){
        shared_ptr<Catalogue> c(new Catalogue());
        c->createPhoto("dis¡ney.jpg", "/cal/homes/sorube/Desktop/disney.jpg", 1.23, 2.34);
        c->createPhoto("disney.jpg", "/cal/homes/sorube/Desktop/disney.jpg", 1.23, 2.34);
        c->createVideo("video1", "/sorube/video", 120);
        unsigned int d [] = {5, 2, 3};
        unsigned int num = 3;
        c->createFilm("film", "/sorube/film", 100, d,num);
        cout << "1. created all" <<endl;
        c->createGroup("Disney");
        c->createGroup("Disney");
        cout << "double disney group" << endl;
        c->rechercherMultimedia("jeje", cout);
        c->rechercherMultimedia("video1", cout);
        c->rechercherMultimedia("disney.jpg", cout);
        //c->jouer("disney.jpg");
        c->supprimerMultimedia("Photo 1.jpeg");
        c->supprimerMultimedia("jejej");
        c->supprimerGroup("Disney");
        c->supprimerGroup("tralala");

    }

    if(0){
        shared_ptr<Catalogue> c(new Catalogue());
        c->createPhoto("disney.jpg", "/cal/homes/sorube/Desktop/disney.jpg", 1.23, 2.34);
        c->createVideo("sample_video.mp4", "/cal/homes/sorube/Desktop/sample_video.mp4", 5);
        c->save("/cal/homes/sorube/Desktop/hello.html");
        c->supprimerMultimedia("sample_video.mp4");
        c->supprimerMultimedia("disney.jpg");
        c->load("/cal/homes/sorube/Desktop/hello.html");
        c->rechercherMultimedia("sample_video.mp4", cout);
        c->rechercherMultimedia("disney.jpg", cout);
    }

    if(0){
        shared_ptr<Catalogue> c(new Catalogue());
        unsigned int d [] = { 5 , 2 , 3 };
        unsigned int num = 3;
        c->createFilm("film", "/sorube/film", 100, d,num);
        c->save("/cal/homes/sorube/Desktop/hello.html");
        c->supprimerMultimedia("film");
        c->load("/cal/homes/sorube/Desktop/hello.html");
        c->rechercherMultimedia("film", cout);
    }





}
