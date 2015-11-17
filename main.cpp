#include "base.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "catalogue.h"
#include <memory>
#include <string>


int main() {

    /*
     * Creating new Base object with name and path attributes
     * Print attributes on console
    */
    if(1){
        cout<<"\n1: Creating Base object:\n " << endl;
        Base * b = new Base();
        b->setName("BaseFile");
        b->setPathname("BasePath");
        b->affichage(cout);
        delete b;
    }

    /*
     * Creates new Photo and Video
     * Prints attributes on console
    */
    if(1){
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

    }
    if(0){

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
        cout << "\nTableau elements: \n";
        for(unsigned int i =0; i<count; i++){
            tableau[i]->affichage(cout);
        }

//        delete tableau;
//        p.reset();
//        v.reset();

    }

    /*
     * Create new film and set attributes. Print on console result
    */
    if(1){
        cout<<"\n4: Creating Film object:\n " << endl;
        shared_ptr<Film> f(new Film());
        f->setName("video1.mp4");
        f->setPathname("media/video1.mp4");
        f->setDuree(5);
        unsigned int d [] = { 5 , 2 , 3 };
        unsigned int num = 3;
        f->setDurees(d, num);
        f->affichage(cout);
        f.reset();
    }
    /*
     * Create new group and assign objects to group. Print on console result
    */
    if(1){
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
    }

    /*
     * Opens photo object
    */
    if(0){
        cout<<"\n6: Opening Photo object:\n " << endl;
        shared_ptr<Photo> p(new Photo());
        p->setName("disney.jpg");
        p->setPathname("media/disney.jpg");
        p->setLatitude(10.0);
        p->setLongitude(15.0);
        p->affichage(cout);
        p->openObject();

        p.reset();
    }

    /*
     * Opens video object
    */
    if(0){
        cout<<"\n7: Opening video object:\n " << endl;
        shared_ptr<Video> v(new Video());
        v->setName("video1.mp4");
        v->setPathname("media/video1.mp4");
        v->setDuree(5);
        v->affichage(cout);
        v->openObject();

        v.reset();

    }

    /*
     * Creates a Catalogue with groups, photos, videos and film and searches for each one and plays them.
     */
    if(1){
        cout<<"\n8: Creating Catalogue object and printing and opening multimedia:\n " << endl;
        shared_ptr<Catalogue> c(new Catalogue());
        c->createPhoto("disney.jpg", "media/disney.jpg", 1.23, 2.34);
        c->createVideo("video1.mp4", "media/video1.mp4", 120);
//        unsigned int d [] = {5, 2, 3};
//        unsigned int num = 3;
//        c->createFilm("film", "media/film", 100, d,num);
        c->createGroup("Disney");
        c->rechercherMultimedia("video1.mp4", cout);
        c->rechercherMultimedia("disney.jpg", cout);
        //c->rechercherMultimedia("film", cout);
        c->jouer("disney.jpg");
        c->jouer("video1.mp4");
        c->supprimerMultimedia("disney.jpg");
        c->supprimerGroup("Disney");

        c.reset();
    }

    /*
     * Creates a catalogue with objects, saves it to the file media/hello.html
     * Deletes objects from multimedia
     * Reloads the objects and adds them to the catalogue
    */

    if(0){
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
    }

    /*
     * Error treatment
    */
    if(1){
        cout<<"\n10: Error Treatment:\n " << endl;
        shared_ptr<Catalogue> c(new Catalogue());
        c->createPhoto("disn!ey.jpg", "media/disney.jpg", 1.23, 2.34);
        c->createVideo("video1.mp4", "media/video1.mp4", 5);
        c->createVideo("video1.mp4", "media/video1.mp4", 5);
        unsigned int d [] = { 5 , 2 , 3 };
        unsigned int num = 0;
        c->createFilm("film", "/sorube/film", 100, d,num);

        c.reset();
    }





}
