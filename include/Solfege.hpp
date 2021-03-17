// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#ifndef SOLFEGE_HPP
#define SOLFEGE_HPP

#include <iostream>
#include <vector>

class SolfegeData {
public:
    std::string generated_data;
};

class Solfege {
    std::vector<std::string> tokens;
public:
    SolfegeData la;

    std::vector<std::string> Split(std::string data);

    SolfegeData ReadSource(std::string file, bool is_brainfuck);
};

#endif // SOLFEGE_HPP
