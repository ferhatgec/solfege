// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//

#include "../include/Solfege_Codegen.hpp"

SolfegeTokens SolfegeCodegen::Tokenize(std::string re) {
    unsigned i = 0;

    for(auto& mi : keywords) {
        if(mi == re) {
            return static_cast<SolfegeTokens>(i);
        }

        ++i;
    }

    return Undefined;
}


void SolfegeCodegen::Codegen(SolfegeTokens re, SolfegeData &ti, std::string si) {
    switch(re) {
        case Do: {
            ti.generated_data.append("++ptr;\n");
            break;
        }

        case DoSharp: {
            if(is_statement) {
                ti.generated_data.append("*ptr ");
            }

            break;
        }

        case Di: {
            ti.generated_data.append(";\n");

            break;
        }

        case Re: {
            ti.generated_data.append("--ptr;\n");
            break;
        }

        case ReSharp: {
            ti.generated_data.append("}\n");

            break;
        }

        case Ri: {
            ti.generated_data.append("*ti = 0;\n");
            break;
        }

        case Mi: {
            ti.generated_data.append("++*ptr;\n");
            break;
        }

        case MiSharp: {
            ti.generated_data.append("{\n\n");

            break;
        }

        case Fa: {
            ti.generated_data.append("--*ptr;\n");
            break;
        }

        case FaSharp: {
            ti.generated_data.append("(");

            break;
        }

        case Fi: {
            ti.generated_data.append("printf(\"%s\", \"");
            is_print = true;

            break;
        }

        case Sol: {
            ti.generated_data.append("putchar(*ptr);\n");

            break;
        }

        case SolSharp: {
            ti.generated_data.append(")");

            break;
        }

        case Si: {
            ti.generated_data.append(print_data + "\");\n");
            is_print = false;
            print_data.erase();

            break;
        }

        case SiSharp: {
            // Si# ... La#
            is_put = true;

            break;
        }

        case La: {
            ti.generated_data.append("*ptr = getchar();\n");

            break;
        }

        case LaSharp: {
            ti.generated_data.append(put_data);
            put_data.erase();

            break;
        }

        case Li: {
            if(is_statement) {
                ti.generated_data.append("}\n");
                is_statement = false;
                break;
            }

            is_statement = true;

            ti.generated_data.append("if");

            break;
        }

        case Ti: {
            ti.generated_data.append("break;\n");

            break;
        }

        case Te: {
            if(is_statement) {
                ti.generated_data.append("=");
            }

            break;
        }

        case Le: {
            if(is_statement) {
                ti.generated_data.append(">");
            }

            break;
        }

        case Se: {
            if(is_statement) {
                ti.generated_data.append("<");
            }

            break;
        }

        case Me: {
            if(is_statement) {
                ti.generated_data.append("!");
            }

            break;
        }

        case Ra: {
            is_statement = true;

            ti.generated_data.append("while");

            break;
        }

        default: {
            if(is_print) {
                print_data.append(si);
                print_data.append(" ");
            }

            break;
        }
    }
}

void SolfegeCodegen::BrainfuckToSolfege(char re, SolfegeData &ti) {
    switch(re) {
        case '>': {
            ti.generated_data.append("Do\n");

            break;
        }
        
        case '<': {
            ti.generated_data.append("Re\n");

            break;
        }

        case '+': {
            ti.generated_data.append("Mi\n");

            break;
        }

        case '-': {
            ti.generated_data.append("Fa\n");

            break;
        }

        case '.': {
            ti.generated_data.append("Sol\n");

            break;
        }

        case ',': {
            ti.generated_data.append("La\n");

            break;
        }

        case '[': {
            ti.generated_data.append("Ra Fa# Do# Sol# Mi#\n");

            break;
        }

        case ']': {
            ti.generated_data.append("Re#\n");

            break;
        }
    }
}