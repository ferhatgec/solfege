// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#include <sstream>
#include <filesystem>
#include <fstream>

#include "../include/Solfege.hpp"
#include "../include/Solfege_Codegen.hpp"

std::vector<std::string> Solfege::Split(std::string data) {
    std::istringstream si(data);

    std::vector<std::string> re;

    for(std::string mi; std::getline(si, mi, ' ');) {
        re.push_back(mi);
    }

    return re;
}

SolfegeData Solfege::ReadSource(std::string file, bool is_brainfuck) {
    std::ifstream sol(file);
    std::string   la;

    SolfegeCodegen si;
    SolfegeData    ra;

    if(!is_brainfuck) {
        ra.generated_data =    "/* lol */\n"
                               "#include <stdio.h>\n"
                               "#include <stdlib.h>\n"
                               "\n\n"
                               "int main(int argc, char** argv) {\n"
                               "unsigned char* ptr = calloc(30000, 1);\n";

        while(std::getline(sol, la)) {
            tokens = Split(la);

            for(unsigned i = 0; i < tokens.size(); i++) {
                si.Codegen(si.Tokenize(tokens[i]), ra, tokens[i]);
            }
        }
    }
    else {
        while(std::getline(sol, la)) {
            for(unsigned i = 0; i < la.length(); i++) {
                si.BrainfuckToSolfege(la[i], ra);
            }
        }
    }

    if(!is_brainfuck) {
        ra.generated_data.append("}\n");
    }

    return ra;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Solfege - An esoteric language\n" << "Use with file\n";

        return 1;
    }

    bool is_brainfuck = false;
    std::string re(argv[1]);
    std::string generated_re;

    std::cout << re << argc << "\n";

    if(re == "--bf" && argc == 3) {
        is_brainfuck = true;
        re.erase();

        re.append(argv[2]);
    }

    if(is_brainfuck) {
        generated_re.append(re + "_lol.solfege");
    }
    else {
        generated_re.append(re + "_solfege.c");
    }

    std::ofstream create(generated_re, std::ofstream::trunc);

    Solfege mi;

    create << mi.ReadSource(re, is_brainfuck).generated_data;

    create.close();

    if(!is_brainfuck) {
        if (std::filesystem::exists(generated_re)) {
            system(std::string("cc " + generated_re +
            " -o solfege_data && ./solfege_data && rm -f solfege_data").c_str());
        }
    }

    return 0;
}
