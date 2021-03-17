// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#ifndef SOLFEGE_CODEGEN_HPP
#define SOLFEGE_CODEGEN_HPP

#include <vector>
#include "Solfege.hpp"

enum SolfegeTokens {
    Do      = 0,
    DoSharp = 1,
    Di,
    Re,
    ReSharp,
    Ri,
    Mi,
    MiSharp,
    Fa,
    FaSharp,
    Fi,
    Sol,
    SolSharp,
    Si,
    SiSharp,
    La,
    LaSharp,
    Li,
    Ti,
    // Do
    // Ti
    Te,
    // La
    Le,
    // Sol
    Se,
    // Fa
    // Mi
    Me,
    // Re
    Ra,

    Undefined
};

class SolfegeCodegen {
    const std::vector<std::string> keywords = {
            "Do",
            "Do#",
            "Di",
            "Re",
            "Re#",
            "Ri",
            "Mi",
            "Mi#",
            "Fa",
            "Fa#",
            "Fi",
            "Sol",
            "Sol#",
            "Si",
            "Si#",
            "La",
            "La#",
            "Li",
            "Ti",
            "Te",
            "Le",
            "Se",
            "Me",
            "Ra",
            "Lol"
    };
public:
    bool is_statement = false;
    bool is_print     = false;
    bool is_put       = false;

    std::string print_data,
                put_data;

    SolfegeTokens Tokenize(std::string re);

    void Codegen(SolfegeTokens re, SolfegeData &ti, std::string si);
};

#endif // SOLFEGE_CODEGEN_HPP
