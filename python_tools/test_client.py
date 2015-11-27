import sys
sys.path.append("../protocol/python_inc")
import line_pb2
from utils import *

ip = "192.168.1.120"
port = 8989

conn = Connector(ip, port)
conn.set_header(10001, "line.LoginReq")

login_req = line_pb2.LoginReq()
login_req.user_name = "jack"
login_req.encrypted_psw = "ASDF"

conn.send(login_req)

#rsp = line_pb2.LoginRsp()
#conn.recv(rsp)
#print "rsp.result :",rsp.result
