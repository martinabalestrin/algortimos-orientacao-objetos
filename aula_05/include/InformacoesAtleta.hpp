#pragma once
#include "Atleta.hpp"
#include "Nadador.hpp"
#include "Corredor.hpp"
#include <string>

using namespace std;

class InformacoesAtleta
{
    public:
        // Construtor
        InformacoesAtleta();
        // Destrutor
        ~InformacoesAtleta();
        // M�todos
        void imprime_exclusivos_atleta(Atleta *a);
        void imprime_informacoes_atleta(Atleta *a);
};
