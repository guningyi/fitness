    #pragma once  
    #include <boost/asio.hpp>   
    #include <boost/array.hpp>   
    #include <boost/bind.hpp>  
    #include <boost/asio/deadline_timer.hpp>  
    #include <boost/enable_shared_from_this.hpp>  
      
      
    class CSession:   
        public boost::enable_shared_from_this<CSession>  
      
      
    {  
    public:  
        CSession(const std::string IP, unsigned short port,int m_heartbeat_timer_minutes,boost::asio::io_service& io_service_);  
        ~CSession(void);  
      
    private:  
        boost::asio::ip::tcp::endpoint m_ep;  
        boost::asio::ip::tcp::socket m_sock;  
        boost::asio::ip::tcp::resolver m_resolver;  
      
      
        boost::array<unsigned char, 4096> read_buffer;  
        boost::array<unsigned char, 4096> write_buffer;  
      
      
        boost::asio::deadline_timer heartbeat_timer;  
        int m_heartbeat_timer_minutes;//心跳间隔 以分为单位  
      
      
        void receive_handler(const boost::system::error_code &ec, std::size_t bytes_transferred);//接收数据处理结果  
        void connect_handler(const boost::system::error_code &ec); //连接处理结果  
        void heartbeat_handler(const boost::system::error_code &ec); //心跳处理结果  
        void login_handler(const boost::system::error_code &ec,std::size_t bytes_transferred);//登录结果的处理  
        void start_receive();//开始接收数据  
        void send_handler(const boost::system::error_code &ec);  
        std::size_t check_frame(const boost::system::error_code &ec, std::size_t bytes_transferred);//校验数据  
        void parse_frame(const boost::system::error_code &ec, std::size_t bytes_transferred);//解析数据  
    public:  
        void start_send();//其他地方调用时 只需要把任务加到任务队列 执行 io_service_.post(boost::bind(&CSession::start_send, this));  
        void start();//启动停止  
        void stop();  
        void login();//登录  
        void heartbeat();//心跳  
        task m_task_queue;//线程安全的任务队列  
    };  
