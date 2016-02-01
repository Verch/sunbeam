// Client
#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <stdio.h>
#endif

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
using namespace boost::asio;
io_service service;

ip::udp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);

void sync_echo(std::string msg) {
	ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), 0));
	sock.send_to(buffer(msg), ep);
	char buff[1024];
	ip::udp::endpoint sender_ep;
	int bytes = sock.receive_from(buffer(buff), sender_ep);
	std::string copy(buff, bytes);
	std::cout << "server echoed our " << msg << ": "
		<< (copy == msg ? "OK" : "FAIL") << std::endl;
	sock.close();
}

int main(int argc, char* argv[]) {
	// connect several clients
	char* messages[] = { "John says hi", "so does James", "Lucy just got home", 0 };
	boost::thread_group threads;
	for (char ** message = messages; *message; ++message) {
		threads.create_thread(boost::bind(sync_echo, *message));
		boost::this_thread::sleep(boost::posix_time::millisec(100));
	}
	
	threads.join_all();
	//system("pause");
	//return 1;
}




















/*#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <stdio.h>
#endif


#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
using namespace boost::asio;
io_service service;

ip::udp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);

void sync_echo(std::string msg) {
	ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), 0));
	sock.send_to(buffer(msg), ep);
	char buff[1024];
	ip::udp::endpoint sender_ep;
	int bytes = sock.receive_from(buffer(buff), sender_ep);
	std::string copy(buff, bytes);
	std::cout << "server echoed our " << msg << ": "
		<< (copy == msg ? "OK" : "FAIL") << std::endl;
	sock.close();
}

int main(int argc, char* argv[]) {
	// connect several clients
	char* messages[] = { "John says hi", "so does James", "Lucy just got home", 0 };
	boost::thread_group threads;
	for (char ** message = messages; *message; ++message) {
		threads.create_thread(boost::bind(sync_echo, *message));
		boost::this_thread::sleep(boost::posix_time::millisec(100));
	}
	threads.join_all();
}*/















//#define BOOST_ASIO_SEPARATE_COMPILATION 


 







///-------------------------------------


/*

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio;
io_service service; 
 


void handle_connections()
{
	char buff[1024];
	ip::udp::socket sock(service, ip::udp::endpoint(ip::udp::v4(), 8001));
	while (true)
	{
		ip::udp::endpoint sender_ep;
		int bytes = sock.receive_from(buffer(buff), sender_ep);
		std::string msg(buff, bytes);
		sock.send_to(buffer(msg), sender_ep);
	}
}
int main(int argc, char* argv[])
{
	std::cout << "UDP Server is start" << endl;
	handle_connections();
	return 0;
}
  
*/


/*
///-------------------------------------///-------------------------------------
struct connection : boost::enable_shared_from_this<connection>
{
	typedef boost::system::error_code error_code;
	typedef boost::shared_ptr<connection> ptr;
	connection() : sock_(service), started_(true) {}
	void start(ip::tcp::endpoint ep)
	{
		sock_.async_connect(ep,
			boost::bind(&connection::on_connect, shared_from_this(), _1));
	}
	void stop()
	{
		if (!started_) return;
		started_ = false;
		sock_.close();
	}
	bool started() { return started_; }
private:
	void on_connect(const error_code & err)
	{
		// here you decide what to do with the connection: read or write
		if (!err) do_read();
		else stop();
	}
	void on_read(const error_code & err, size_t bytes)
	{
		if (!started()) return;
		std::string msg(read_buffer_, bytes);
		if (msg == "can_login")               do_write("access_data");
		else if (msg.find("data ") == 0)    process_data(msg);
		else if (msg == "login_fail")         stop();
	}
	void on_write(const error_code & err, size_t bytes)
	{
		do_read();
	}
	void do_read()
	{
		sock_.async_read_some(buffer(read_buffer_),
			boost::bind(&connection::on_read, shared_from_this(), _1, _2));
	}
	void do_write(const std::string & msg)
	{
		if (!started()) return;
		// note: in case you want to send several messages before 
		// doing another async_read, you'll need several write buffers!
		std::copy(msg.begin(), msg.end(), write_buffer_);
		sock_.async_write_some(buffer(write_buffer_, msg.size()),
			boost::bind(&connection::on_write, shared_from_this(), _1, _2));
	}
	void process_data(const std::string & msg)
	{
		// process what comes from server, and then perform another write
	}
private:
	ip::tcp::socket sock_;
	enum { max_msg = 1024 };
	char read_buffer_[max_msg];
	char write_buffer_[max_msg];
	bool started_;
};

int main(int argc, char* argv[])
{
	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);
	connection::ptr(new connection)->start(ep);
	system("pause");
}*/













///-------------------------------------///-------------------------------------


/*char buff_read[1024], buff_write[1024] = "ok";
void on_read(const boost::system::error_code &err, std::size_t bytes);
void on_write(const boost::system::error_code &err, std::size_t bytes)
{
	sock.async_read_some(buffer(buff_read), on_read);
}
void on_read(const boost::system::error_code &err, std::size_t bytes)
{
	// ... process the read ...
	sock.async_write_some(buffer(buff_write, 3), on_write);
}
void on_connect(const boost::system::error_code &err)
{
	sock.async_read_some(buffer(buff_read), on_read);
}*/



/*
 огда вызываетс€ service.run(), то в ожидании находитс€ хот€ бы одна асинхронна€ операци€. 
 огда сокет подключаетс€ к серверу, вызываетс€ on_connect, котора€ добавл€ет еще одну асинхронную операцию. 
ѕосле окончани€ работы on_connect у нас остаетс€ одна запланированна€ операци€ (read).  огда завершаетс€ 
операци€ on_read, пишем ответ, добавл€етс€ еще одна запланированна€ операци€(write).  огда вызываетс€ 
функци€ on_write, мы читаем следующее сообщение от сервера, который будет добавл€ть еще одну запланированную 
операцию.  огда завершаетс€ функци€ on_write у нас есть одна запланированна€ операци€ (read). » так цикл 
продолжаетс€, пока мы не решим закрыть приложение.
*/
/*int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "тут будет CLIENT" << endl;
	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
	sock.async_connect(ep, on_connect);
	service.run();
}*/






//—ледующий код это простой асинхронный сервер :
/*using boost::asio;
typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
io_service service;
ip::tcp::endpoint ep(ip::tcp::v4(), 2001)); // listen on 2001
ip::tcp::acceptor acc(service, ep);
socket_ptr sock(new ip::tcp::socket(service));
start_accept(sock);
service.run();
void start_accept(socket_ptr sock)
{
	acc.async_accept(*sock, boost::bind(handle_accept, sock, _1));
}
void handle_accept(socket_ptr sock, const boost::system::error_code & err)
{
	if (err) return;
	// at this point, you can read/write to the socket
	socket_ptr sock(new ip::tcp::socket(service));
	start_accept(sock);
}*/


//-------------------------------------

 /*Ќапример, следующее сообщение от вашего партнера должно прийти к вам через 100 миллисекунд:

bool read = false;
void deadline_handler(const boost::system::error_code &) 
{
    std::cout << (read ? "read successfully" : "read failed") << std::endl;
}
void read_handler(const boost::system::error_code &) 
{
    read = true;
}
ip::tcp::socket sock(service);
Е
read = false;
char data[512];
sock.async_read_some(buffer(data, 512));
deadline_timer t(service, boost::posix_time::milliseconds(100));
t.async_wait(&deadline_handler);
service.run();
*/


/*
.run() всегда будет закончен, если больше нет операций дл€ контрол€
≈сли вы хотите, чтобы service.run() продолжил работать, вы должны предоставить ему больше работы. 
решени€ данной проблемы.  €вл€етс€ увеличение нагрузки на connect_handler, запустив еще одну асинхронную операцию.
¬торой способ заключаетс€ в имитации некоторой его работы, использу€ следующий код:
typedef boost::shared_ptr<io_service::work> work_ptr;
work_ptr dummy_work(new io_service::work(service_));

ѕриведенный выше код обеспечит посто€нную работу service_.run() до тех пор пока вы не вызовете 
useservice_.stop() или dummy_work.reset(0); // destroy dummy_work.
*/