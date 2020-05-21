/** program_forwardL_parser.hpp ---
*
*
* Authors: Misgana <.com> and Elias Tsegaw<tsegawelias@gmail.com>
* Copyright (c) 2020 misgana96
* This program is free software; you can redistribute it and/or modify
* it under the terms of the  MIT License as
* published by the Free Software Foundation
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* MIT License for more details.
*
* You should have received a copy of the MIT License
* along with this program; if not, write to:
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef FORWARDL_PARSER_HPP_INCLUDED
#define FORWARDL_PARSER_HPP_INCLUDED

#include "L_proposition.hpp"
#include "not.hpp"
#include "and.hpp"
#include "or.hpp"
#include "implication.hpp"
#include "bi_implication.hpp"
#include <stack>
namespace Wumpus
{
namespace util
{

class forwardL_parser
{

public:
    bool fParser(vector<cell> propos);
};
}
}
#endif // FORWARDL_PARSER_HPP_INCLUDED
