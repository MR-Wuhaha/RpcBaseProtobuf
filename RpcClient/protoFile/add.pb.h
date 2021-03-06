// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: add.proto

#ifndef PROTOBUF_INCLUDED_add_2eproto
#define PROTOBUF_INCLUDED_add_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_add_2eproto 

namespace protobuf_add_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_add_2eproto
class AddRequest;
class AddRequestDefaultTypeInternal;
extern AddRequestDefaultTypeInternal _AddRequest_default_instance_;
class AddRespone;
class AddResponeDefaultTypeInternal;
extern AddResponeDefaultTypeInternal _AddRespone_default_instance_;
namespace google {
namespace protobuf {
template<> ::AddRequest* Arena::CreateMaybeMessage<::AddRequest>(Arena*);
template<> ::AddRespone* Arena::CreateMaybeMessage<::AddRespone>(Arena*);
}  // namespace protobuf
}  // namespace google

// ===================================================================

class AddRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:AddRequest) */ {
 public:
  AddRequest();
  virtual ~AddRequest();

  AddRequest(const AddRequest& from);

  inline AddRequest& operator=(const AddRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AddRequest(AddRequest&& from) noexcept
    : AddRequest() {
    *this = ::std::move(from);
  }

  inline AddRequest& operator=(AddRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const AddRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AddRequest* internal_default_instance() {
    return reinterpret_cast<const AddRequest*>(
               &_AddRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(AddRequest* other);
  friend void swap(AddRequest& a, AddRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AddRequest* New() const final {
    return CreateMaybeMessage<AddRequest>(NULL);
  }

  AddRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<AddRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const AddRequest& from);
  void MergeFrom(const AddRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AddRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double num1 = 2;
  bool has_num1() const;
  void clear_num1();
  static const int kNum1FieldNumber = 2;
  double num1() const;
  void set_num1(double value);

  // optional double num2 = 3;
  bool has_num2() const;
  void clear_num2();
  static const int kNum2FieldNumber = 3;
  double num2() const;
  void set_num2(double value);

  // optional bool KeepAlive = 1 [default = false];
  bool has_keepalive() const;
  void clear_keepalive();
  static const int kKeepAliveFieldNumber = 1;
  bool keepalive() const;
  void set_keepalive(bool value);

  // @@protoc_insertion_point(class_scope:AddRequest)
 private:
  void set_has_keepalive();
  void clear_has_keepalive();
  void set_has_num1();
  void clear_has_num1();
  void set_has_num2();
  void clear_has_num2();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  double num1_;
  double num2_;
  bool keepalive_;
  friend struct ::protobuf_add_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class AddRespone : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:AddRespone) */ {
 public:
  AddRespone();
  virtual ~AddRespone();

  AddRespone(const AddRespone& from);

  inline AddRespone& operator=(const AddRespone& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AddRespone(AddRespone&& from) noexcept
    : AddRespone() {
    *this = ::std::move(from);
  }

  inline AddRespone& operator=(AddRespone&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const AddRespone& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AddRespone* internal_default_instance() {
    return reinterpret_cast<const AddRespone*>(
               &_AddRespone_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(AddRespone* other);
  friend void swap(AddRespone& a, AddRespone& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AddRespone* New() const final {
    return CreateMaybeMessage<AddRespone>(NULL);
  }

  AddRespone* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<AddRespone>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const AddRespone& from);
  void MergeFrom(const AddRespone& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AddRespone* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double resule = 1;
  bool has_resule() const;
  void clear_resule();
  static const int kResuleFieldNumber = 1;
  double resule() const;
  void set_resule(double value);

  // @@protoc_insertion_point(class_scope:AddRespone)
 private:
  void set_has_resule();
  void clear_has_resule();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  double resule_;
  friend struct ::protobuf_add_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// AddRequest

// optional bool KeepAlive = 1 [default = false];
inline bool AddRequest::has_keepalive() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void AddRequest::set_has_keepalive() {
  _has_bits_[0] |= 0x00000004u;
}
inline void AddRequest::clear_has_keepalive() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void AddRequest::clear_keepalive() {
  keepalive_ = false;
  clear_has_keepalive();
}
inline bool AddRequest::keepalive() const {
  // @@protoc_insertion_point(field_get:AddRequest.KeepAlive)
  return keepalive_;
}
inline void AddRequest::set_keepalive(bool value) {
  set_has_keepalive();
  keepalive_ = value;
  // @@protoc_insertion_point(field_set:AddRequest.KeepAlive)
}

// optional double num1 = 2;
inline bool AddRequest::has_num1() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AddRequest::set_has_num1() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AddRequest::clear_has_num1() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AddRequest::clear_num1() {
  num1_ = 0;
  clear_has_num1();
}
inline double AddRequest::num1() const {
  // @@protoc_insertion_point(field_get:AddRequest.num1)
  return num1_;
}
inline void AddRequest::set_num1(double value) {
  set_has_num1();
  num1_ = value;
  // @@protoc_insertion_point(field_set:AddRequest.num1)
}

// optional double num2 = 3;
inline bool AddRequest::has_num2() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void AddRequest::set_has_num2() {
  _has_bits_[0] |= 0x00000002u;
}
inline void AddRequest::clear_has_num2() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void AddRequest::clear_num2() {
  num2_ = 0;
  clear_has_num2();
}
inline double AddRequest::num2() const {
  // @@protoc_insertion_point(field_get:AddRequest.num2)
  return num2_;
}
inline void AddRequest::set_num2(double value) {
  set_has_num2();
  num2_ = value;
  // @@protoc_insertion_point(field_set:AddRequest.num2)
}

// -------------------------------------------------------------------

// AddRespone

// optional double resule = 1;
inline bool AddRespone::has_resule() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AddRespone::set_has_resule() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AddRespone::clear_has_resule() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AddRespone::clear_resule() {
  resule_ = 0;
  clear_has_resule();
}
inline double AddRespone::resule() const {
  // @@protoc_insertion_point(field_get:AddRespone.resule)
  return resule_;
}
inline void AddRespone::set_resule(double value) {
  set_has_resule();
  resule_ = value;
  // @@protoc_insertion_point(field_set:AddRespone.resule)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_add_2eproto
