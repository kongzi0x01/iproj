// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: response_code.proto

#ifndef PROTOBUF_response_5fcode_2eproto__INCLUDED
#define PROTOBUF_response_5fcode_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace line {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_response_5fcode_2eproto();
void protobuf_AssignDesc_response_5fcode_2eproto();
void protobuf_ShutdownFile_response_5fcode_2eproto();


enum RESPONSE_CODE {
  OK = 0,
  ERR_NOT_FOUND_USER = 101,
  ERR_WROND_PASSWORD = 102,
  ERR_SYSTEM = 103,
  ERR_USERNAME_EXISTS = 104
};
bool RESPONSE_CODE_IsValid(int value);
const RESPONSE_CODE RESPONSE_CODE_MIN = OK;
const RESPONSE_CODE RESPONSE_CODE_MAX = ERR_USERNAME_EXISTS;
const int RESPONSE_CODE_ARRAYSIZE = RESPONSE_CODE_MAX + 1;

const ::google::protobuf::EnumDescriptor* RESPONSE_CODE_descriptor();
inline const ::std::string& RESPONSE_CODE_Name(RESPONSE_CODE value) {
  return ::google::protobuf::internal::NameOfEnum(
    RESPONSE_CODE_descriptor(), value);
}
inline bool RESPONSE_CODE_Parse(
    const ::std::string& name, RESPONSE_CODE* value) {
  return ::google::protobuf::internal::ParseNamedEnum<RESPONSE_CODE>(
    RESPONSE_CODE_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

}  // namespace line

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::line::RESPONSE_CODE>() {
  return ::line::RESPONSE_CODE_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_response_5fcode_2eproto__INCLUDED
