#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <cassert>
#include <cstring>
int main ( int argc, char* argv[] )
{
    std::cout << "running....\n";
    assert ( argc >1 );
    if ( strcmp( argv[1], "Server")==0)
    {
	try
	{
	    ServerSocket server ( 30000 );

	    while ( true )
	    {

		ServerSocket new_sock;
		server.accept ( new_sock );

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
		catch ( SocketException& ) {}
	    }
	}
	catch ( SocketException& e )
	{
	    std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}
    }
    else if ( strcmp(argv[1] ,"Client") == 0 )
    {
	try
	{

	    ClientSocket client_socket ( "localhost", 30000 );

	    std::string reply;

	    try
	    {
		while(1){
		    std::string request;
		    std::cin>>request;
		    //client_socket << "Test message.";
		    client_socket<<request;
		    client_socket >> reply;
		    std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;
		}
	    }
	    catch ( SocketException& ) {}
	}
	catch ( SocketException& e )
	{
	    std::cout << "Exception was caught:" << e.description() << "\n";
	}

	return 0;
    }
    return 0;
}



// #include <iostream>
// using namespace std;

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #include <strings.h>
// #include <errno.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <netdb.h>
// #include <unistd.h>
// #include <sys/ioctl.h>
// #include <sys/select.h>
// #include <sys/time.h>

// #include "TThreadPool.hh"


// int count(char * data)
// {
//     int cc=0;
//     for ( int i=0;data[i]!=0;i++)
//     {
// 	if( isalpha( data[i] ) ) 
// 	{
// 	    cc++;
// 	}
//     }
//     return cc; 
// }


// void _ERROR(const char * s)
// {
//     printf("%s,%s \n",s,strerror(errno));
// }

// class Server:public TThreadPool::TJob
// {
//     int cs;
// public:
//     Server(int ls)
// 	{
// 	    struct sockaddr_in cip;
// 	    int len = sizeof(cip);
// 	    printf("MutilThreadTCPServer is wating on port 9999.....\n");
// 	    cs = accept(ls,(struct sockaddr *)&cip,(socklen_t*)&len);
// 	    if (cs<0) 
// 	    {
// 		_ERROR("accept()");
// 		close(ls);
// 	    }
// 	    printf("Client IP:%s  Port：%d connected！\n",inet_ntoa(cip.sin_addr),ntohs(cip.sin_port));
	    
// 	}
//     ~Server()
// 	{
// 	    close(cs);
// 	}
    
//     virtual void run(void *args )
// 	{
// 	    //int cs = (int)args;
// 	    char data[254];
// 	    do {
// 		int n = recv(cs,data,253,0);
// 		data[n]='\0';
// 		printf("[Pthread ID：%d] msg for clinet is：%s\n",pthread_self(),data);
// 		int cc=count(data);
// 		char rdata[254];
// 		sprintf(rdata,"[Pthread ID：%d]The number of alphabet:%d",pthread_self(),cc);
// 		send(cs,rdata,strlen(rdata),0);
// 	    } while (memcmp(data,"quit",4)!=0);
// 	    printf("See you ![Pthread ID：%d]ended！\n",pthread_self());
// 	    close(cs);
// 	}
// };

// int main()
// {
//     int ls = socket(AF_INET,SOCK_STREAM,0);
//     if (ls<0) 
//     {
// 	_ERROR("socket()");
// 	exit(-1);	
//     }
//     struct sockaddr_in sip;
    
//     memset((void*)&sip,0,sizeof(sip));	
//     sip.sin_family = AF_INET;
//     sip.sin_port = htons(9999);
//     sip.sin_addr.s_addr = htonl(INADDR_ANY);
    
    
//     if ( bind(ls,(struct sockaddr*)&sip,sizeof(sip) )) 
//     {
// 	_ERROR("bind()");
// 	close(ls);
// 	return -1;
//     }
//     if (listen(ls,2)<0) 
//     {
// 	_ERROR("listen()");
// 	close(ls);
// 	return -1;
//     }
//     tp_init(512);
//     while(1)
//     {
// 	Server *ser=new Server(ls);
// 	tp_run(ser,NULL,false);
// 	delete ser;
//     }
//     tp_sync_all();
//     tp_done();
// }
