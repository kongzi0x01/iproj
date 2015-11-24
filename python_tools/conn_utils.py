#!/usr/bin/python
import sys
sys.path.append("../protocol/python_inc/")
import struct
import header_pb2
from buffer import *
from utils import *
from prompt_pb import *
import socket
import time


class GetConnectedSocket:
	def __init__(self, ip, port, account):
		self.ip = ip
		self.port = port
		self.account = account
		self.conn_utils_sock = Connector(self.ip, self.port)
		self.roleid = long(0)
		
	def connect(self):
		self.request_account_login()
		#time.sleep(5)
		self.request_role_login()
		
	def request_account_login(self):
		print "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
		print "request_account_login"
		self.conn_utils_sock.set_header(123456, 2, "sessionid", 4, "CS.AccountLoginReq")
		account_login_req_pb = login_pb2.AccountLoginReq()
		PromptAccountLogin(account_login_req_pb, self.account)
		self.conn_utils_sock.send(account_login_req_pb)
		
		msg_pb = login_pb2.AccountLoginRsp()
		self.conn_utils_sock.recv(msg_pb)
		self.conn_utils_sock.print_header()
		print "=================="
		print "result: ", msg_pb.result
		print "account: ", msg_pb.account
		print "uid: ", msg_pb.uid
		for rr in msg_pb.role_record:
			print "--------------"
			#print "role_name: ", rr.role_name
			print "roleid: ", rr.roleid
			self.roleid = rr.roleid
		
	def request_role_login(self):
		print "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
		print "request_role_login"
		print "roleid:", self.roleid
		
		self.conn_utils_sock.set_header(self.roleid, 2, "sessionid", 4, "CS.RoleLoginReq")
		role_login_req_pb = login_pb2.RoleLoginReq()
		PromptRoleLogin(role_login_req_pb ,self.roleid)
		
		self.conn_utils_sock.send(role_login_req_pb)
		
		role_login_msg_pb = login_pb2.RoleLoginRsp()
		self.conn_utils_sock.recv(role_login_msg_pb)
		self.conn_utils_sock.print_header()
		print "=================="
		print "result: ", role_login_msg_pb.result
		print "roleid: ", role_login_msg_pb.roleid
		print "roleid: ", role_login_msg_pb.role_data.roleid
		#print "role_name: ", role_login_msg_pb.role_data.role_name
		print "fight_capacity: ", role_login_msg_pb.role_data.fight_capacity
		print "gold: ", role_login_msg_pb.role_data.gold
		print "diamond: ", role_login_msg_pb.role_data.diamond
		print "stamina: ", role_login_msg_pb.role_data.stamina
		print "hero_data size: ", len(role_login_msg_pb.role_data.hero_list)
		for hd in role_login_msg_pb.role_data.hero_list:
			print "--------------------"
			print "hero_data.gid: ", hd.gid
			print "hero_data.heroid: ", hd.heroid
			print "hero_data.level: ", hd.level
			print "hero_data.exp: ", hd.exp
			print "hero_data.position: ", hd.position
			print "skill_slot size:", len(hd.skill_slot)
			
	def get_roleid(self):
		return self.roleid
		
	def request_protocol(self, message_full_name, req_pb, recv_pb):
		print "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
		print "request_protocol"
		self.conn_utils_sock.set_header(self.roleid, 2, "sessionid", 4, message_full_name)
		self.conn_utils_sock.send(req_pb)
		self.conn_utils_sock.recv(recv_pb)
		
	def print_recv_header(self):
		self.conn_utils_sock.print_header()
		
	def set_header(self, roleid, seq, sessionid, re_send_cnt, msg_full_name):
		self.conn_utils_sock.set_header(roleid, seq, sessionid, re_send_cnt, msg_full_name)
		
	def send_packet(self, msg_pb):
		self.conn_utils_sock.send(msg_pb)
		
	def recv_packet(self, msg_pb):
		self.conn_utils_sock.recv(msg_pb)
		
