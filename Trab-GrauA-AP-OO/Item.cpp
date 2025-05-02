#include "Item.hpp"

// Construtores
Item::Item() {

}

Item::Item(const std::string& n) : nome(n) {

}

// Getters
std::string Item::getNome() const{
	return nome;
}
