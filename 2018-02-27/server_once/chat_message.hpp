//
// chat_message.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2017 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include "md5.h"
#ifdef QT_CORE_LIB
#include <QObject>
#endif

#define MAX_TOTAL_STAGE 255

struct header_t {
    uint8_t total : 8;
    uint8_t stage : 8;
    uint16_t body_length : 16; 
};

#ifdef QT_CORE_LIB
class chat_message : public QObject
{
    Q_OBJECT
#else
class chat_message
{
#endif
public:
  enum { header_length = 4 };
  enum { md5_length = MD5_DIGEST_LENGTH + 1};
  enum { max_total_stage = MAX_TOTAL_STAGE };
  enum { max_body_length = 128 };
  chat_message(){}
  chat_message(uint8_t new_total, uint8_t new_stage, uint16_t new_body_length)
  {
    setTotal(new_total);
    setStage(new_stage);
    setBody_length(new_body_length);
    data_ = new char[header_length + md5_length + body_length_];
  }

  chat_message(uint8_t new_total, uint8_t new_stage, const std::string& md5, const std::string& s)
      :chat_message(new_total, new_stage, s.length() + 1)
  {
    setMd5(md5);
    setBody(s.c_str());
    encode_header();
  }
  
  chat_message(const chat_message& rhs)
  {
    total_ = rhs.total_;
    stage_ = rhs.stage_;
    data_  = new char[rhs.length()];
    memcpy(data_, rhs.data_, rhs.length());
    decode_header();
  }

  chat_message(const char* raw_data, size_t len)
  {
      data_ = new char[len];
      memcpy(data_, raw_data, len);
      decode_header();
  }
  const char* data() const
  {
    return data_;
  }

  void setData(const char* new_data)
  {
    memcpy(data_, new_data, header_length + body_length_);
  }

  uint16_t length() const
  {
    return header_length + md5_length + body_length_;
  }

  const char* md5() const
  {
    return data_ + header_length;
  }

  void setMd5(const std::string& new_md5)
  {
    if(new_md5.length() != MD5_DIGEST_LENGTH)
        throw(std::runtime_error("Illegal MD5"));
    memcpy(data_ + header_length, new_md5.c_str(), md5_length);
  }


  const char* body() const
  {
    return data_ + header_length + md5_length;
  }

  void setBody(const char* new_body)
  {
    memcpy(data_ + header_length + md5_length, new_body, body_length_);
  }

  uint8_t total() const
  {
    return total_;
  }

  uint8_t stage() const  
  {
    return stage_;
  }

  uint16_t body_length() const
  {
    return body_length_;
  }

  void setTotal(uint16_t new_total)
  {
    total_= new_total;
    if (total_ > max_total_stage)
        total_ = max_total_stage;
  }

  void setStage(uint16_t new_stage)
  {
    stage_ = new_stage;
    if (stage_ >= total_)
      stage_ = total_;
  }

  void setBody_length(uint16_t new_length)
  {
    body_length_ = new_length;
    if (body_length_ > max_body_length)
      body_length_ = max_body_length;
  }

private:
  bool decode_header()
  {
    header_t header;    
    memcpy(&header, data_, sizeof(header_t));
    total_ = header.total;
    stage_ = header.stage;
    body_length_ = header.body_length;
    if (body_length_ > max_body_length)
    {
      body_length_ = 0;
      return false;
    }
    return true;
  }

  void encode_header()
  {
    header_t header{total_,stage_,body_length_};
    std::memcpy(data_, &header, header_length);
  }

  char* data_ = nullptr;
  uint8_t total_ = 0;
  uint8_t stage_ = 0;
  uint16_t body_length_ = 0;
};

#ifdef QT_CORE_LIB
Q_DECLARE_METATYPE(chat_message)
#endif

#define MYDEFINE(CLASS,TYPE,NAME)                                 \
    struct _##CLASS_##TYPE_##NAME {                             \
        _##CLASS_##TYPE_##NAME() :                              \
        w(#CLASS, #TYPE, #NAME){}                               \
        _##CLASS_##TYPE_##NAME& operator=(const TYPE& rhs) {    \
            m_##NAME = rhs;                                     \
            w.update(m_##NAME);                                 \
            return *this;                                       \
        }                                                       \
        TYPE& operator*() {                                     \
            return m_##NAME;                                    \
        }                                                       \
        TYPE* operator->() {                                    \
            return & this->operator*();                         \
        }                                                       \
        void update() {                                         \
            w.update(m_##NAME);                                 \
        }                                                       \
        private:                                                \
            TYPE m_##NAME;                                      \
            Watcher<TYPE> w;                                    \
    } NAME;                                                     \

struct is_WatcherObject_tag{};

struct AbstractWatcherObject {
    using values_type = std::vector<std::string>;
    virtual values_type watcher_property_value() const = 0;
    using info_type = std::vector<std::pair<std::string, std::string>> ;
};

struct WatcherObject {
    using values_type = std::vector<std::string>;
    using info_type = std::vector<std::pair<std::string, std::string>> ;
    using is_WatcherObject = is_WatcherObject_tag;
};

#define MYDECLARE(CLASS,TYPE,NAME)                                 \
    struct _##CLASS_##TYPE_##NAME {                             \
        _##CLASS_##TYPE_##NAME() :                              \
        w(#CLASS, #TYPE, #NAME){}                               \
        _##CLASS_##TYPE_##NAME& operator=(const TYPE& rhs) {    \
            m_##NAME = rhs;                                     \
            w.update(m_##NAME);                                 \
            return *this;                                       \
        }                                                       \
        const TYPE& operator*() {                               \
            return m_##NAME;                                    \
        }                                                       \
        private:                                                \
            TYPE m_##NAME;                                      \
            Watcher<TYPE> w;                                    \
    };                                                     

template<typename T>
struct _TYPE_TO_NAME{
};



#define MY_REGISTER_WATCHER_TYPE(CLASS)                                 \
    class CLASS;                                                        \
    template<>                                                          \
    struct _TYPE_TO_NAME<CLASS> {                                       \
        static constexpr const char* name = #CLASS;                     \
    };                                                                  \
    class CLASS : public AbstractWatcherObject

#define MY_REGISTER_WATCHER_INFO(CLASS)                                 \
    auto ref = getRegisteredClassInfo();                                \
    (*ref)[#CLASS] =

#endif // CHAT_MESSAGE_HPP
