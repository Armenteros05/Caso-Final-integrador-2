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

    static std::string to_string();
};
std::string Variant::to_string() {
    std::string Variant::to_string(){
            )
        switch (type) {
            case variant_type::Symbol:
                return val;
            case variant_type::Number:
                return std::to_string(std::stoi(val));  // Convierte la cadena a entero antes de convertirla a cadena nuevamente
            case variant_type::List: {
                std::string result = "[";
                for (const auto& element : list) {
                    result += element.to_string() + ", ";
                }
                if (!list.empty()) {
                    result.pop_back(); // Elimina la última coma
                    result.pop_back(); // Elimina el espacio después de la coma
                }
                result += "]";
                return result;
            }
            case variant_type::Proc:
                return "Procedure";
            case variant_type::Lambda:
                return "Lambda";
            case variant_type::Cadena:
                return "Cadena";
            default:
                return "UnknownType";
        }

}
    return {};
}

int main(){

}