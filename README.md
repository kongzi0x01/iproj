# iproj
  
autor:夫子  
各功能服务器介绍:
service_svr和db_svr都是基于epoll机制，而http_svr基于libevent的http库。  
service_svr:主要处理socket连接的业务相关，包括但不限于处理客户端日常操作。  
db_svr:需要执行数据库的操作由其他服务器转发到db_svr， 由db_svr执行,并将结果返回。 
http_svr:处理Http连接的业务相关。 
