// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: line.proto

#ifndef PROTOBUF_line_2eproto__INCLUDED
#define PROTOBUF_line_2eproto__INCLUDED

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

namespace line {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_line_2eproto();
void protobuf_AssignDesc_line_2eproto();
void protobuf_ShutdownFile_line_2eproto();

class LoginReq;

// ===================================================================

class LoginReq : public ::google::protobuf::Message {
 public:
  LoginReq();
  virtual ~LoginReq();

  LoginReq(const LoginReq& from);

  inline LoginReq& operator=(const LoginReq& from) {
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
  static const LoginReq& default_instance();

  void Swap(LoginReq* other);

  // implements Message ----------------------------------------------

  LoginReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const LoginReq& from);
  void MergeFrom(const LoginReq& from);
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

  // optional string user_name = 1;
  inline bool has_user_name() const;
  inline void clear_user_name();
  static const int kUserNameFieldNumber = 1;
  inline const ::std::string& user_name() const;
  inline void set_user_name(const ::std::string& value);
  inline void set_user_name(const char* value);
  inline void set_user_name(const char* value, size_t size);
  inline ::std::string* mutable_user_name();
  inline ::std::string* release_user_name();
  inline void set_allocated_user_name(::std::string* user_name);

  // optional string encrypted_psw = 2;
  inline bool has_encrypted_psw() const;
  inline void clear_encrypted_psw();
  static const int kEncryptedPswFieldNumber = 2;
  inline const ::std::string& encrypted_psw() const;
  inline void set_encrypted_psw(const ::std::string& value);
  inline void set_encrypted_psw(const char* value);
  inline void set_encrypted_psw(const char* value, size_t size);
  inline ::std::string* mutable_encrypted_psw();
  inline ::std::string* release_encrypted_psw();
  inline void set_allocated_encrypted_psw(::std::string* encrypted_psw);

  // @@protoc_insertion_point(class_scope:line.LoginReq)
 private:
  inline void set_has_user_name();
  inline void clear_has_user_name();
  inline void set_has_encrypted_psw();
  inline void clear_has_encrypted_psw();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* user_name_;
  ::std::string* encrypted_psw_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_line_2eproto();
  friend void protobuf_AssignDesc_line_2eproto();
  friend void protobuf_ShutdownFile_line_2eproto();

  void InitAsDefaultInstance();
  static LoginReq* default_instance_;
};
// ===================================================================


// ===================================================================

// LoginReq

// optional string user_name = 1;
inline bool LoginReq::has_user_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LoginReq::set_has_user_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LoginReq::clear_has_user_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LoginReq::clear_user_name() {
  if (user_name_ != &::google::protobuf::internal::kEmptyString) {
    user_name_->clear();
  }
  clear_has_user_name();
}
inline const ::std::string& LoginReq::user_name() const {
  return *user_name_;
}
inline void LoginReq::set_user_name(const ::std::string& value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
}
inline void LoginReq::set_user_name(const char* value) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(value);
}
inline void LoginReq::set_user_name(const char* value, size_t size) {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  user_name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* LoginReq::mutable_user_name() {
  set_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    user_name_ = new ::std::string;
  }
  return user_name_;
}
inline ::std::string* LoginReq::release_user_name() {
  clear_has_user_name();
  if (user_name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = user_name_;
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void LoginReq::set_allocated_user_name(::std::string* user_name) {
  if (user_name_ != &::google::protobuf::internal::kEmptyString) {
    delete user_name_;
  }
  if (user_name) {
    set_has_user_name();
    user_name_ = user_name;
  } else {
    clear_has_user_name();
    user_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string encrypted_psw = 2;
inline bool LoginReq::has_encrypted_psw() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LoginReq::set_has_encrypted_psw() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LoginReq::clear_has_encrypted_psw() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LoginReq::clear_encrypted_psw() {
  if (encrypted_psw_ != &::google::protobuf::internal::kEmptyString) {
    encrypted_psw_->clear();
  }
  clear_has_encrypted_psw();
}
inline const ::std::string& LoginReq::encrypted_psw() const {
  return *encrypted_psw_;
}
inline void LoginReq::set_encrypted_psw(const ::std::string& value) {
  set_has_encrypted_psw();
  if (encrypted_psw_ == &::google::protobuf::internal::kEmptyString) {
    encrypted_psw_ = new ::std::string;
  }
  encrypted_psw_->assign(value);
}
inline void LoginReq::set_encrypted_psw(const char* value) {
  set_has_encrypted_psw();
  if (encrypted_psw_ == &::google::protobuf::internal::kEmptyString) {
    encrypted_psw_ = new ::std::string;
  }
  encrypted_psw_->assign(value);
}
inline void LoginReq::set_encrypted_psw(const char* value, size_t size) {
  set_has_encrypted_psw();
  if (encrypted_psw_ == &::google::protobuf::internal::kEmptyString) {
    encrypted_psw_ = new ::std::string;
  }
  encrypted_psw_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* LoginReq::mutable_encrypted_psw() {
  set_has_encrypted_psw();
  if (encrypted_psw_ == &::google::protobuf::internal::kEmptyString) {
    encrypted_psw_ = new ::std::string;
  }
  return encrypted_psw_;
}
inline ::std::string* LoginReq::release_encrypted_psw() {
  clear_has_encrypted_psw();
  if (encrypted_psw_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = encrypted_psw_;
    encrypted_psw_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void LoginReq::set_allocated_encrypted_psw(::std::string* encrypted_psw) {
  if (encrypted_psw_ != &::google::protobuf::internal::kEmptyString) {
    delete encrypted_psw_;
  }
  if (encrypted_psw) {
    set_has_encrypted_psw();
    encrypted_psw_ = encrypted_psw;
  } else {
    clear_has_encrypted_psw();
    encrypted_psw_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace line

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_line_2eproto__INCLUDED
