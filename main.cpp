#include "base.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "catalogue.h"
#include <memory>
#include <string>


int main() {

    // Please choose an exercise between 1 and 10
    int exercice = 9;

    switch(exercice){
        case 1:{
            cout<<"\n1: Creating Base object:\n " << endl;
            Base * b = new Base();
            b->setName("BaseFile");
            b->setPathname("BasePath");
            b->affichage(cout);
            delete b;
            break;
        }
        case 2:{
            cout<<"\n2: Creating Photo and Video object:\n " << endl;
            Photo * p = new Photo();
            p->setName("disney.jpg");
            p->setPathname("media/disney.jpg");
            p->setLatitude(10.0);
            p->setLongitude(50.36);
            p->affichage(cout);

            Video * v = new Video();
            v->setName("video1.mp4");
            v->setPathname("media/video1.mp4");
            v->setDuree(2);
            v->affichage(cout);

            delete p;
            delete v;
            break;
        }
        case 3:{
            /*
            * Create new Photo and set attributes. Print on console result
            */
            cout<<"\n3: Creating Tableau of objects:\n " << endl;
            shared_ptr<Photo> p(new Photo());
            p->setName("disney.jpg");
            p->setPathname("media/disney.jpg");
            p->setLatitude(10.0);
            p->setLongitude(15.0);

            /*
             * Create new Video and set attributes. Print on console result
            */
            shared_ptr<Video> v(new Video());
            v->setName("video1.mp4");
            v->setPathname("media/video1.mp4");
            v->setDuree(5);

            Base ** tableau = new Base * [2];
            unsigned int count = 0;
            tableau[count++] = p.get();
            tableau[count++] = v.get();
            cout << "\nTableau elements: \n" << endl;
            for(unsigned int i =0; i<count; i++){
                tableau[i]->affichage(cout);
            }

            p.reset();
            v.reset();
            delete tableau;
            break;
        }
        case 4:{
            cout<<"\n4: Creating Film object:\n " << endl;
            shared_ptr<Film> f(new Film());
            f->setName("film");
            f->setPathname("media/film");
            f->setDuree(5);
            unsigned int d [] = { 5 , 2 , 3 };
            unsigned int num = 3;
            f->setDurees(d, num);
            cout << "film created" << endl;
            f->affichage(cout);
            f.reset();
            break;
        }
        case 5:{
            cout<<"\n5: Creating Group object:\n " << endl;
            shared_ptr<Photo> p(new Photo());
            p->setName("disney.jpg");
            p->setPathname("media/disney.jpg");
            p->setLatitude(10.0);
            p->setLongitude(15.0);

            shared_ptr<Video> v(new Video());
            v->setName("video1.mp4");
            v->setPathname("media/video1.mp4");
            v->setDuree(5);

            shared_ptr<Film> f(new Film());
            f->setName("video1.mp4");
            f->setPathname("media/video1.mp4");
            f->setDuree(5);
            unsigned int d [] = { 5 , 2 , 3 };
            unsigned int num = 3;
            f->setDurees(d, num);

            shared_ptr<Group> g(new Group("My Memories"));
            g->push_back(f.get());
            g->push_back(v.get());
            g->push_back(p.get());
            g->affichage(cout);

            g.reset();

            shared_ptr<Group> g1(new Group("Photos"));
            g1->push_back(p.get());
            g1->affichage(cout);

            g1.reset();
            break;
        }
        case 6:{
            cout<<"\n6: Opening Photo object:\n " << endl;
            shared_ptr<Photo> p(new Photo());
            p->setName("disney.jpg");
            p->setPathname("media/disney.jpg");
            p->setLatitude(10.0);
            p->setLongitude(15.0);
            p->affichage(cout);
            p->openObject();

            p.reset();
            break;
        }
        case 7:{
            cout<<"\n7: Opening video object:\n " << endl;
            shared_ptr<Video> v(new Video());
            v->setName("video1.mp4");
            v->setPathname("media/video1.mp4");
            v->setDuree(5);
            v->affichage(cout);
            v->openObject();

            v.reset();
            break;
        }
        case 8:{
            cout<<"\n8: Creating Catalogue object and printing and opening multimedia:\n " << endl;
            shared_ptr<Catalogue> c(new Catalogue());
            c->createPhoto("disney.jpg", "media/disney.jpg", 1.23, 2.34);
            c->createVideo("video1.mp4", "media/video1.mp4", 120);
            unsigned int d [] = {5, 2, 3};
            unsigned int num = 3;
            c->createFilm("film", "media/film", 100, d,num);
            c->createGroup("Disney");
            c->rechercherMultimedia("video1.mp4", cout);
            c->rechercherMultimedia("disney.jpg", cout);
            c->rechercherMultimedia("film", cout);
            c->jouer("disney.jpg");
            c->jouer("video1.mp4");
            c->supprimerMultimedia("disney.jpg");
            c->supprimerGroup("Disney");

            c.reset();
            break;
        }
        case 9:{
            cout<<"\n9: Saves and Loads Catalogue object to/from file:\n " << endl;
            shared_ptr<Catalogue> c(new Catalogue());
            c->createPhoto("disney.jpg", "media/disney.jpg", 1.23, 2.34);
            c->createVideo("video1.mp4", "media/video1.mp4", 5);
            unsigned int d [] = { 5 , 2 , 3 };
            unsigned int num = 3;
            c->createFilm("film", "/sorube/film", 100, d,num);
            if(c->save("media/hello.html"))
                cout<< "Saved file" <<endl;
            c->supprimerMultimedia("video1.mp4");
            c->supprimerMultimedia("disney.jpg");
            c->supprimerMultimedia("film");
            if(c->load("media/hello.html"))
                cout << "Loaded file"<< endl;
            c->rechercherMultimedia("video1.mp4", cout);
            c->rechercherMultimedia("disney.jpg", cout);
            c->rechercherMultimedia("film", cout);
            c.reset();
            break;
        }
        case 10:{
            cout<<"\n10: Error Treatment:\n " << endl;
            shared_ptr<Catalogue> c(new Catalogue());
            c->createPhoto("disn!ey.jpg", "media/disney.jpg", 1.23, 2.34);
            c->createVideo("video1.mp4", "media/video1.mp4", 5);
            c->createVideo("video1.mp4", "media/video1.mp4", 5);
            unsigned int d [] = { 5 , 2 , 3 };
            unsigned int num = 0;
            c->createFilm("film", "/sorube/film", 100, d,num);

            c.reset();
            break;
        }
        default:
            cerr << "Please choose a correct exercise from 1-10" <<endl;
            break;
    }

}
