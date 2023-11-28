#include <utility>
#include <vector>
#include <string>
#include <map>
#include "json11.hpp"
#include "jsonlib.hpp"
#include <iostream>
namespace jsonlib {
    class Json;
}

enum variant_type { Symbol, Number, List, Proc, Lambda, Cadena };

struct Entorno;

class Variant {
public:
    typedef Variant(*proc_type) ( const std::vector<Variant>& );
    typedef std::vector<Variant>::const_iterator iter;
    typedef std::map<std::string, Variant> map;

    variant_type type;
    std::string val;
    std::vector<Variant> list;
    proc_type proc;
    Entorno* env;

    explicit Variant(variant_type type = Symbol) : type(type) , env(nullptr), proc(nullptr) { }
    Variant(variant_type type, std::string  val) : type(type), val(std::move(val)) , env(nullptr) , proc(nullptr) { }
    explicit Variant(proc_type proc) : type(Proc), proc(proc) , env(nullptr) { }

};
int main(){

}