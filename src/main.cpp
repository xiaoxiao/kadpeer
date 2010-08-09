#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <cassert>
#include <cstring>
#include "TThreadPool.hh"
#include <sstream>
#include <unistd.h>

class Server:public TThreadPool::TJob
{
    
    ServerSocket *server;
    
public:
    Server(ServerSocket *ser)
	{
	    server=ser;
	}
    ~Server()
	{
	    delete server;
	}
    virtual void run(void *)
	{
	    ServerSocket new_sock;
	    server->accept ( new_sock );
	    try
	    {
		while ( true )
		{
		    std::string data;
		    new_sock >> data;
		    std::cout<<"Receive Data: "<<data<<std::endl;
		    new_sock << data;
		}
	    }
	    catch ( SocketException &  ) {}
	}
};

class Client:public TThreadPool::TJob
{
    ClientSocket *client_socket;
public:
    Client()
	{
	    client_socket= new ClientSocket("localhost",30000);
	}
    ~Client()
	{
	    delete client_socket;
	}
    virtual void  run(void * args){
	try
	{
	    std::string reply;
	    int num=*(int *)args;
	    try
	    {
		std::stringstream request;
		request<<"Test message from client "<<num;
		(*client_socket) << request.str();
		usleep(100);
		(*client_socket) >> reply;
		std::cout << "We received this response from the server:\n\"" << reply <<"\"\n";
	    }
	    catch ( SocketException& ) {}
	}
	catch ( SocketException& e )
	{
	    std::cout << "Exception was caught:" << e.description() << "\n";
	}
    }
};

int main(int argc, char * argv[])
{
    assert( argc > 1 );
    std::cout<<"running....."<<std::endl;
    if ( strcmp( argv[1] ,"Server") == 0 )
    {
	tp_init(25);
	ServerSocket server(30000);
	while(1)
	{
	    Server *ser = new Server(&server);
	    tp_run(ser, NULL, false);
	} 
	tp_sync_all();
	tp_done();
    }
    else if ( strcmp(argv[1] ,"Client") == 0 )
    {
	tp_init(25);

	for( int i =0 ;i <100;i++)
	{
	    Client client;
	    tp_run(&client,&i,false);
	    tp_sync(&client);
	}
	tp_done();
    }
}

