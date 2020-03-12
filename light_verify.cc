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

    char *header_hash = Buffer::Data(target);
    char *mix_hash = Buffer::Data(target2);
    char *str_nonce = Buffer::Data(target3);
    char *boundary = Buffer::Data(target4);
    char *final_hash = (char*) malloc(sizeof(char) * 32);

    progpow::light_verify(header_hash, mix_hash, str_nonce, boundary, final_hash);

    info.GetReturnValue().Set(Nan::NewBuffer(final_hash, 32).ToLocalChecked());
}

NAN_MODULE_INIT(init) {
  Nan::Set(target,
    Nan::New<v8::String>("node_light_verify").ToLocalChecked(),
    Nan::GetFunction(Nan::New<v8::FunctionTemplate>(node_light_verify)).ToLocalChecked()
  );
  // Nan::Set(target, Nan::New("light_verify").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(light_verify)).ToLocalChecked());
}

NODE_MODULE(node_light_verify, init)
