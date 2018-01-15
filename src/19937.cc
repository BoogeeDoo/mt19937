#include <random>
#include <nan.h>

namespace __NODE_RANDOM__ {

using v8::Function;
using v8::FunctionTemplate;
using v8::Local;
using v8::Persistent;

class NodeMt19937 : public Nan::ObjectWrap {
public:
    static NAN_MODULE_INIT(Init)
    {
        Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
        tpl->SetClassName(Nan::New("Mt19937Generator").ToLocalChecked());
        tpl->InstanceTemplate()->SetInternalFieldCount(1);

        Nan::SetPrototypeMethod(tpl, "next", Next);
        Nan::Set(target, Nan::New("Mt19937").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
    }
 
private:
    explicit NodeMt19937(int seed, int a, int b) :
        dis(a, b)
    {
        gen.seed(seed);
    }

    ~NodeMt19937() {}

    static NAN_METHOD(Next)
    {
        NodeMt19937* rand = Nan::ObjectWrap::Unwrap<NodeMt19937>(info.Holder());

        int ret = rand->dis(rand->gen);

        info.GetReturnValue().Set(ret);
    }

    static NAN_METHOD(New)
    {
        int seed = info[0]->IsUndefined() ? 0 : info[0]->NumberValue();
        int a = info[1]->IsUndefined() ? 0 : info[1]->NumberValue();
        int b = info[2]->IsUndefined() ? std::numeric_limits<int>::max() : info[2]->NumberValue();

        NodeMt19937* obj = new NodeMt19937(seed, a, b);
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    }

    std::mt19937 gen;
    std::uniform_int_distribution<int> dis;
};

NAN_MODULE_INIT(Init)
{
    NodeMt19937::Init(target);
}

}

NODE_MODULE(__mt19937, __NODE_RANDOM__::Init)
