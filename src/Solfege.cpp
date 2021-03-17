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

SolfegeData Solfege::ReadSource(std::string file) {
    std::ifstream sol(file);
    std::string   la;

    SolfegeCodegen si;
    SolfegeData    ra;

    while(std::getline(sol, la)) {
        tokens = Split(la);

        for(unsigned i = 0; i < tokens.size(); i++) {
            si.Codegen(si.Tokenize(tokens[i]), ra, tokens[i]);
        }
    }

    ra.generated_data.append("}\n");

    return ra;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Solfege - An esoteric language\n" << "Use with file\n";

        return 1;
    }

    std::string re(argv[1]);
    std::ofstream create(re + "_solfege.c", std::ofstream::trunc);

    Solfege mi;

    create << mi.ReadSource(re).generated_data;

    create.close();

    if(std::filesystem::exists(re + "_solfege.c")) {
        system(std::string("cc " + re + "_solfege.c -o solfege_data && ./solfege_data && rm -f solfege_data").c_str());
    }

    return 0;
}
