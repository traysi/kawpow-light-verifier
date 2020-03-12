#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>
#include "nan.h"

  #include "progpow.hpp"
  #include "ethash.hpp"
  #include "helpers.hpp"


#define THROW_ERROR_EXCEPTION(x) Nan::ThrowError(x)
#define THROW_ERROR_EXCEPTION_WITH_STATUS_CODE(x, y) NanThrowError(x, y)

using namespace node;
using namespace v8;

NAN_METHOD(node_light_verify) {

    if (info.Length() < 1)
        return THROW_ERROR_EXCEPTION("You must provide four arguments.");

    Local<Object> target = Nan::To<Object>(info[0]).ToLocalChecked();
    if(!Buffer::HasInstance(target))
        return THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

    Local<Object> target2 = Nan::To<Object>(info[1]).ToLocalChecked();
    if(!Buffer::HasInstance(target2))
        return THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

    Local<Object> target3 = Nan::To<Object>(info[2]).ToLocalChecked();
    if(!Buffer::HasInstance(target3))
        return THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

    Local<Object> target4 = Nan::To<Object>(info[3]).ToLocalChecked();
    if(!Buffer::HasInstance(target4))
        return THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

    std::string header_hash;
    std::string mix_hash;
    std::string str_nonce;
    std::string boundary;
    header_hash = (std::string) Buffer::Data(target);
    mix_hash = (std::string)  Buffer::Data(target2);
    str_nonce = (std::string)  Buffer::Data(target3);
    boundary = (std::string)  Buffer::Data(target4);
    char *cstr = new char[64 + 1];

    progpow::light_verify(header_hash.c_str(), mix_hash.c_str(), str_nonce.c_str(), boundary.c_str(), cstr);
    info.GetReturnValue().Set(Nan::New(std::string(cstr, 64)).ToLocalChecked());

    delete[] cstr;
}

NAN_MODULE_INIT(init) {
  Nan::Set(target,
    Nan::New<v8::String>("node_light_verify").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(node_light_verify)).ToLocalChecked()
  );
  // Nan::Set(target, Nan::New("light_verify").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(light_verify)).ToLocalChecked());
}

NODE_MODULE(node_light_verify, init)
