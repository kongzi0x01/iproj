# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: line.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='line.proto',
  package='line',
  serialized_pb='\n\nline.proto\x12\x04line\"@\n\x08UserData\x12\x0f\n\x07user_id\x18\x01 \x01(\x04\x12\x11\n\tuser_name\x18\x02 \x01(\t\x12\x10\n\x08lover_id\x18\x03 \x01(\x04\"4\n\x08LoginReq\x12\x11\n\tuser_name\x18\x01 \x01(\t\x12\x15\n\rencrypted_psw\x18\x02 \x01(\t\"\x1a\n\x08LoginRsp\x12\x0e\n\x06result\x18\x01 \x01(\r\"9\n\rRegistUserReq\x12\x11\n\tuser_name\x18\x01 \x01(\t\x12\x15\n\rencrypted_psw\x18\x02 \x01(\t\"\x1f\n\rRegistUserRsp\x12\x0e\n\x06result\x18\x01 \x01(\r')




_USERDATA = _descriptor.Descriptor(
  name='UserData',
  full_name='line.UserData',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_id', full_name='line.UserData.user_id', index=0,
      number=1, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_name', full_name='line.UserData.user_name', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='lover_id', full_name='line.UserData.lover_id', index=2,
      number=3, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=20,
  serialized_end=84,
)


_LOGINREQ = _descriptor.Descriptor(
  name='LoginReq',
  full_name='line.LoginReq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_name', full_name='line.LoginReq.user_name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='encrypted_psw', full_name='line.LoginReq.encrypted_psw', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=86,
  serialized_end=138,
)


_LOGINRSP = _descriptor.Descriptor(
  name='LoginRsp',
  full_name='line.LoginRsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='line.LoginRsp.result', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=140,
  serialized_end=166,
)


_REGISTUSERREQ = _descriptor.Descriptor(
  name='RegistUserReq',
  full_name='line.RegistUserReq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_name', full_name='line.RegistUserReq.user_name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='encrypted_psw', full_name='line.RegistUserReq.encrypted_psw', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=168,
  serialized_end=225,
)


_REGISTUSERRSP = _descriptor.Descriptor(
  name='RegistUserRsp',
  full_name='line.RegistUserRsp',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='result', full_name='line.RegistUserRsp.result', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=227,
  serialized_end=258,
)

DESCRIPTOR.message_types_by_name['UserData'] = _USERDATA
DESCRIPTOR.message_types_by_name['LoginReq'] = _LOGINREQ
DESCRIPTOR.message_types_by_name['LoginRsp'] = _LOGINRSP
DESCRIPTOR.message_types_by_name['RegistUserReq'] = _REGISTUSERREQ
DESCRIPTOR.message_types_by_name['RegistUserRsp'] = _REGISTUSERRSP

class UserData(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _USERDATA

  # @@protoc_insertion_point(class_scope:line.UserData)

class LoginReq(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LOGINREQ

  # @@protoc_insertion_point(class_scope:line.LoginReq)

class LoginRsp(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LOGINRSP

  # @@protoc_insertion_point(class_scope:line.LoginRsp)

class RegistUserReq(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _REGISTUSERREQ

  # @@protoc_insertion_point(class_scope:line.RegistUserReq)

class RegistUserRsp(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _REGISTUSERRSP

  # @@protoc_insertion_point(class_scope:line.RegistUserRsp)


# @@protoc_insertion_point(module_scope)
