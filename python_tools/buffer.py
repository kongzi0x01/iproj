#!/usr/bin/python
import struct

class Xlbuf:

	def __init__(self, param = ''):
		self.buf = param 

	def put_string(self, str):
		# padstr = struct.pack('=I', len(str))
		# padstr += str
		self.buf += str
		#self.buf += str

	def get_string(self, start, end):
		ret = self.buf[start:end]
		return ret

	def put_char(self, str):
		self.buf += struct.pack("=B", str)

	def get_char(self):
		ret = struct.unpack("=B", self.buf[:1])[0]
		self.buf = self.buf[1:]
		return ret

	def put_short(self, short):
		self.buf += struct.pack('=H', short)

	def get_short(self):
		ret = struct.unpack('=H', self.buf[:2])[0]
		self.buf = self.buf[2:]
		return ret

	def put_int(self, integer):
		self.buf += struct.pack('=I', integer)

	def get_int(self):
		ret = struct.unpack('=I', self.buf[:4])[0]
		self.buf = self.buf[4:]
		return ret

	def put_long(self, long):
		self.buf += struct.pack('=Q', long)

	def get_long(self):
		ret = struct.unpack('=Q', self.buf[:8])[0]
		self.buf = self.buf[8:]
		return ret

	def get_byte_from_pos(self, pos):
		ret = struct.unpack('=B', self.buf[pos:pos+1])[0]
		return ret

	def get_short_from_pos(self, pos):
		ret = struct.unpack('=H', self.buf[pos:pos+2])[0]
		return ret

	def get_int_from_pos(self, pos):
		ret = struct.unpack('=I', self.buf[pos:pos+4])[0]
		return ret

	def put_int_from_pos(self, pos, value):
		if pos + 4 > len(self.buf):
			print "invalid pos, pos: %d, buf_len: %d" % (pos, len(self.buf))
			return -1
		self.buf = self.buf[:pos] + struct.pack('=I', value) + self.buf[pos+4:]

	def get_long_from_pos(self, pos):
		return struct.unpack('=Q', self.buf[pos:pos+8])[0]


if __name__=="__main__":
	print "this is buffer test"

