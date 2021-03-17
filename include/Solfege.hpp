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
    std::string generated_data = "/* lol */\n"
                                 "#include <stdio.h>\n"
                                 "#include <stdlib.h>\n"
                                 "\n\n"
                                 "int main(int argc, char** argv) {\n"
                                 "unsigned char* ptr = calloc(30000, 1);\n";
};

class Solfege {
    std::vector<std::string> tokens;
public:
    SolfegeData la;

    std::vector<std::string> Split(std::string data);

    SolfegeData ReadSource(std::string file);
};

#endif // SOLFEGE_HPP
