#include <node.h>
#include <math.h>

using namespace v8;

void Quadratic(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  
  if (args.Length() < 3) {
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Wrong num of args")));
    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  double a = args[0]->NumberValue();
  double b = args[1]->NumberValue();
  double c = args[2]->NumberValue();
  double root1 = (-b - sqrt(b*b - (4 * a * c)) ) / (2 * a);
  double root2 = (-b + sqrt(b*b - (4 * a * c)) ) / (2 * a);

  Handle<Array> array = Array::New(isolate, 2);
  array->Set(0, Number::New(isolate, root1));
  array->Set(1, Number::New(isolate, root2));
  args.GetReturnValue().Set(array);
}

void Init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "solve", Quadratic);
}

NODE_MODULE(addon, Init)
