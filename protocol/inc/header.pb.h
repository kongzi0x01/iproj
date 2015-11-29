// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

#ifndef PROTOBUF_header_2eproto__INCLUDED
#define PROTOBUF_header_2eproto__INCLUDED

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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_header_2eproto();
void protobuf_AssignDesc_header_2eproto();
void protobuf_ShutdownFile_header_2eproto();

class Header;
class Msg;

// ===================================================================

class Header : public ::google::protobuf::Message {
 public:
  Header();
  virtual ~Header();

  Header(const Header& from);

  inline Header& operator=(const Header& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Header& default_instance();

  void Swap(Header* other);

  // implements Message ----------------------------------------------

  Header* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Header& from);
  void MergeFrom(const Header& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint64 id = 1;
  inline bool has_id() const;
  inline void clear_id();
  static const int kIdFieldNumber = 1;
  inline ::google::protobuf::uint64 id() const;
  inline void set_id(::google::protobuf::uint64 value);

  // optional string msg_full_name = 2;
  inline bool has_msg_full_name() const;
  inline void clear_msg_full_name();
  static const int kMsgFullNameFieldNumber = 2;
  inline const ::std::string& msg_full_name() const;
  inline void set_msg_full_name(const ::std::string& value);
  inline void set_msg_full_name(const char* value);
  inline void set_msg_full_name(const char* value, size_t size);
  inline ::std::string* mutable_msg_full_name();
  inline ::std::string* release_msg_full_name();
  inline void set_allocated_msg_full_name(::std::string* msg_full_name);

  // optional uint64 client_session_ident = 3;
  inline bool has_client_session_ident() const;
  inline void clear_client_session_ident();
  static const int kClientSessionIdentFieldNumber = 3;
  inline ::google::protobuf::uint64 client_session_ident() const;
  inline void set_client_session_ident(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:protocol.Header)
 private:
  inline void set_has_id();
  inline void clear_has_id();
  inline void set_has_msg_full_name();
  inline void clear_has_msg_full_name();
  inline void set_has_client_session_ident();
  inline void clear_has_client_session_ident();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 id_;
  ::std::string* msg_full_name_;
  ::google::protobuf::uint64 client_session_ident_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_header_2eproto();
  friend void protobuf_AssignDesc_header_2eproto();
  friend void protobuf_ShutdownFile_header_2eproto();

  void InitAsDefaultInstance();
  static Header* default_instance_;
};
// -------------------------------------------------------------------

class Msg : public ::google::protobuf::Message {
 public:
  Msg();
  virtual ~Msg();

  Msg(const Msg& from);

  inline Msg& operator=(const Msg& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Msg& default_instance();

  void Swap(Msg* other);

  // implements Message ----------------------------------------------

  Msg* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Msg& from);
  void MergeFrom(const Msg& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .protocol.Header header = 1;
  inline bool has_header() const;
  inline void clear_header();
  static const int kHeaderFieldNumber = 1;
  inline const ::protocol::Header& header() const;
  inline ::protocol::Header* mutable_header();
  inline ::protocol::Header* release_header();
  inline void set_allocated_header(::protocol::Header* header);

  // optional string serialized_msg = 2;
  inline bool has_serialized_msg() const;
  inline void clear_serialized_msg();
  static const int kSerializedMsgFieldNumber = 2;
  inline const ::std::string& serialized_msg() const;
  inline void set_serialized_msg(const ::std::string& value);
  inline void set_serialized_msg(const char* value);
  inline void set_serialized_msg(const char* value, size_t size);
  inline ::std::string* mutable_serialized_msg();
  inline ::std::string* release_serialized_msg();
  inline void set_allocated_serialized_msg(::std::string* serialized_msg);

  // @@protoc_insertion_point(class_scope:protocol.Msg)
 private:
  inline void set_has_header();
  inline void clear_has_header();
  inline void set_has_serialized_msg();
  inline void clear_has_serialized_msg();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::protocol::Header* header_;
  ::std::string* serialized_msg_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_header_2eproto();
  friend void protobuf_AssignDesc_header_2eproto();
  friend void protobuf_ShutdownFile_header_2eproto();

  void InitAsDefaultInstance();
  static Msg* default_instance_;
};
// ===================================================================


// ===================================================================

// Header

// optional uint64 id = 1;
inline bool Header::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Header::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Header::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Header::clear_id() {
  id_ = GOOGLE_ULONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::uint64 Header::id() const {
  return id_;
}
inline void Header::set_id(::google::protobuf::uint64 value) {
  set_has_id();
  id_ = value;
}

// optional string msg_full_name = 2;
inline bool Header::has_msg_full_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Header::set_has_msg_full_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Header::clear_has_msg_full_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Header::clear_msg_full_name() {
  if (msg_full_name_ != &::google::protobuf::internal::kEmptyString) {
    msg_full_name_->clear();
  }
  clear_has_msg_full_name();
}
inline const ::std::string& Header::msg_full_name() const {
  return *msg_full_name_;
}
inline void Header::set_msg_full_name(const ::std::string& value) {
  set_has_msg_full_name();
  if (msg_full_name_ == &::google::protobuf::internal::kEmptyString) {
    msg_full_name_ = new ::std::string;
  }
  msg_full_name_->assign(value);
}
inline void Header::set_msg_full_name(const char* value) {
  set_has_msg_full_name();
  if (msg_full_name_ == &::google::protobuf::internal::kEmptyString) {
    msg_full_name_ = new ::std::string;
  }
  msg_full_name_->assign(value);
}
inline void Header::set_msg_full_name(const char* value, size_t size) {
  set_has_msg_full_name();
  if (msg_full_name_ == &::google::protobuf::internal::kEmptyString) {
    msg_full_name_ = new ::std::string;
  }
  msg_full_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Header::mutable_msg_full_name() {
  set_has_msg_full_name();
  if (msg_full_name_ == &::google::protobuf::internal::kEmptyString) {
    msg_full_name_ = new ::std::string;
  }
  return msg_full_name_;
}
inline ::std::string* Header::release_msg_full_name() {
  clear_has_msg_full_name();
  if (msg_full_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = msg_full_name_;
    msg_full_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Header::set_allocated_msg_full_name(::std::string* msg_full_name) {
  if (msg_full_name_ != &::google::protobuf::internal::kEmptyString) {
    delete msg_full_name_;
  }
  if (msg_full_name) {
    set_has_msg_full_name();
    msg_full_name_ = msg_full_name;
  } else {
    clear_has_msg_full_name();
    msg_full_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional uint64 client_session_ident = 3;
inline bool Header::has_client_session_ident() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Header::set_has_client_session_ident() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Header::clear_has_client_session_ident() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Header::clear_client_session_ident() {
  client_session_ident_ = GOOGLE_ULONGLONG(0);
  clear_has_client_session_ident();
}
inline ::google::protobuf::uint64 Header::client_session_ident() const {
  return client_session_ident_;
}
inline void Header::set_client_session_ident(::google::protobuf::uint64 value) {
  set_has_client_session_ident();
  client_session_ident_ = value;
}

// -------------------------------------------------------------------

// Msg

// optional .protocol.Header header = 1;
inline bool Msg::has_header() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Msg::set_has_header() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Msg::clear_has_header() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Msg::clear_header() {
  if (header_ != NULL) header_->::protocol::Header::Clear();
  clear_has_header();
}
inline const ::protocol::Header& Msg::header() const {
  return header_ != NULL ? *header_ : *default_instance_->header_;
}
inline ::protocol::Header* Msg::mutable_header() {
  set_has_header();
  if (header_ == NULL) header_ = new ::protocol::Header;
  return header_;
}
inline ::protocol::Header* Msg::release_header() {
  clear_has_header();
  ::protocol::Header* temp = header_;
  header_ = NULL;
  return temp;
}
inline void Msg::set_allocated_header(::protocol::Header* header) {
  delete header_;
  header_ = header;
  if (header) {
    set_has_header();
  } else {
    clear_has_header();
  }
}

// optional string serialized_msg = 2;
inline bool Msg::has_serialized_msg() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Msg::set_has_serialized_msg() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Msg::clear_has_serialized_msg() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Msg::clear_serialized_msg() {
  if (serialized_msg_ != &::google::protobuf::internal::kEmptyString) {
    serialized_msg_->clear();
  }
  clear_has_serialized_msg();
}
inline const ::std::string& Msg::serialized_msg() const {
  return *serialized_msg_;
}
inline void Msg::set_serialized_msg(const ::std::string& value) {
  set_has_serialized_msg();
  if (serialized_msg_ == &::google::protobuf::internal::kEmptyString) {
    serialized_msg_ = new ::std::string;
  }
  serialized_msg_->assign(value);
}
inline void Msg::set_serialized_msg(const char* value) {
  set_has_serialized_msg();
  if (serialized_msg_ == &::google::protobuf::internal::kEmptyString) {
    serialized_msg_ = new ::std::string;
  }
  serialized_msg_->assign(value);
}
inline void Msg::set_serialized_msg(const char* value, size_t size) {
  set_has_serialized_msg();
  if (serialized_msg_ == &::google::protobuf::internal::kEmptyString) {
    serialized_msg_ = new ::std::string;
  }
  serialized_msg_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Msg::mutable_serialized_msg() {
  set_has_serialized_msg();
  if (serialized_msg_ == &::google::protobuf::internal::kEmptyString) {
    serialized_msg_ = new ::std::string;
  }
  return serialized_msg_;
}
inline ::std::string* Msg::release_serialized_msg() {
  clear_has_serialized_msg();
  if (serialized_msg_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = serialized_msg_;
    serialized_msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Msg::set_allocated_serialized_msg(::std::string* serialized_msg) {
  if (serialized_msg_ != &::google::protobuf::internal::kEmptyString) {
    delete serialized_msg_;
  }
  if (serialized_msg) {
    set_has_serialized_msg();
    serialized_msg_ = serialized_msg;
  } else {
    clear_has_serialized_msg();
    serialized_msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_header_2eproto__INCLUDED
