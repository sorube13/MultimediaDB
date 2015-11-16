#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include "TCPServer.h"
#include "catalogue.h"

using namespace std;

const int DEFAULT_PORT = 3331;

class MyApp {
public:


    MyApp(){
        shared_ptr<Catalogue> c(new Catalogue());
        c->createPhoto("disney.jpg", "/cal/homes/sorube/Desktop/disney.jpg", 1.23, 2.34);
        c->createVideo("video 1", "/sorube/video", 120);
        unsigned int d [] = { 5 , 2 , 3 };
        unsigned int num = 3;
        c->createFilm("film", "/sorube/film", 100, d,num);
    }

  /// Cette fonction est appelée chaque fois qu'il y a une requête à traiter.
  /// - 'request' contient la requête
  /// - 'response' sert à indiquer la réponse qui sera renvoyée au client
  /// - si la fonction renvoie false la connexion est close.
  //
  // Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
  // un thread par client).
  // Si le verrou 'lock' est bloqué en mode WRITE, les autres appels sont bloqués
  // jusqu'à la fin l'appel qui a bloqué le verrou.
  //
  bool processRequest(TCPServer::Cnx& cnx, const string& request, string& response)
  {

    // mettre cette variable à true si la commande modifie les donnees du programme
    bool changeData = false;

    shared_ptr<Catalogue> c(new Catalogue());
    c->createPhoto("disney.jpg", "/home/sorube/Documents/INF224/disney.jpg", 1.23, 2.34);
    c->createVideo("video1.mp4", "/home/sorube/Documents/INF224/video1.mp4", 5);
    unsigned int d [] = { 5 , 2 , 3 };
    unsigned int num = 3;
    c->createFilm("film", "/sorube/film", 100, d,num);

    stringstream r;
    string method, args;
    stringstream recherche;
    string type;

    r<<request;
    r >> method >> args;

    if(method == "rechercher" || method =="1"){
        recherche << c->rechercherMultimedia(args, cout);
        cout << "recherche has: " << recherche.str()<< endl;
        getline(recherche, type);
        getline(recherche, response);
        string a;
        while(getline(recherche, a)){
            cout << recherche.str() << endl;
            //getLine(recherche, a);
            response = response + " " + a;
         }

    }else if(method=="jouer" || method =="2"){
        response = "Multimedia being played in server";
        c->jouer(args);
    }else{
        response = "NOT FOUND";
    }

    // suivant le cas on bloque le verrou en mode WRITE ou en mode READ
    TCPServer::Lock lock(cnx, changeData);

    cerr << "request: '" << request << "'" << endl;

    // simule un traitement long (décommenter pour tester le verrou)
    // if (changeData) sleep(10); else sleep(5);





    //response = "OK: " + request;
    cerr << "response: '" << response << "'" << endl;

    // renvoyer false pour clore la connexion avec le client
    return true;
  }
};


int main(int argc, char* argv[])
{
  TCPServer * server = new TCPServer();
  MyApp * app = new MyApp();
  server->setCallback(app, &MyApp::processRequest);

  int port = (argc >= 2) ? atoi(argv[1]) : DEFAULT_PORT;
  cout << "Starting Server on port " << port << endl;
  int status = server->run(port);

  if (status < 0) {
    cerr << "Could not start Server on port " << port << endl;
    return 1;
  }
  else return 0;
}
