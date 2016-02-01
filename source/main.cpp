//#define BOOST_ASIO_SEPARATE_COMPILATION 
 
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio;
io_service service;
ip::tcp::socket sock(service);





char buff_read[1024], buff_write[1024] = "ok";
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
}



/*
����� ���������� service.run(), �� � �������� ��������� ���� �� ���� ����������� ��������. 
����� ����� ������������ � �������, ���������� on_connect, ������� ��������� ��� ���� ����������� ��������. 
����� ��������� ������ on_connect � ��� �������� ���� ��������������� �������� (read). ����� ����������� 
�������� on_read, ����� �����, ����������� ��� ���� ��������������� ��������(write). ����� ���������� 
������� on_write, �� ������ ��������� ��������� �� �������, ������� ����� ��������� ��� ���� ��������������� 
��������. ����� ����������� ������� on_write � ��� ���� ���� ��������������� �������� (read). � ��� ���� 
������������, ���� �� �� ����� ������� ����������.
*/
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::cout << "��� ����� CLIENT" << endl;
	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
	sock.async_connect(ep, on_connect);
	service.run();
}






//��������� ��� ��� ������� ����������� ������ :
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

 /*��������, ��������� ��������� �� ������ �������� ������ ������ � ��� ����� 100 �����������:

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
�
read = false;
char data[512];
sock.async_read_some(buffer(data, 512));
deadline_timer t(service, boost::posix_time::milliseconds(100));
t.async_wait(&deadline_handler);
service.run();
*/


/*
.run() ������ ����� ��������, ���� ������ ��� �������� ��� ��������
���� �� ������, ����� service.run() ��������� ��������, �� ������ ������������ ��� ������ ������. 
������� ������ ��������.  �������� ���������� �������� �� connect_handler, �������� ��� ���� ����������� ��������.
������ ������ ����������� � �������� ��������� ��� ������, ��������� ��������� ���:
typedef boost::shared_ptr<io_service::work> work_ptr;
work_ptr dummy_work(new io_service::work(service_));

����������� ���� ��� ��������� ���������� ������ service_.run() �� ��� ��� ���� �� �� �������� 
useservice_.stop() ��� dummy_work.reset(0); // destroy dummy_work.
*/