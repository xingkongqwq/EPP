/*
This is E++, a brand new scripting language.

Copyright(C) 2022 xingkongqwq

This program is free software : you can redistribute itand /or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.If not, see < https://www.gnu.org/licenses/>.
*/

#pragma once
#include "epptypes.hpp"
#include <string>
#include <map>
#include <iostream>
class Val
{
public:
	int INT_VAL;
	double DOUBLE_VAL;
	std::string STRING_VAL;
	std::map<Val, Val>MAP_VAL;
	int type;
	void del() {
		INT_VAL = NULL; DOUBLE_VAL = NULL;
		STRING_VAL.clear(), MAP_VAL.clear();
	};
	Val() {};
	Val(int x) {
		INT_VAL = x; type = INT;
	}
	Val(double x) {
		DOUBLE_VAL = x; type = DOUBLE;
	}
	Val(std::string x) {
		STRING_VAL = x; type = STRING;
	}
	Val operator+ (Val& a) {
		if (type == DOUBLE) {
			if (a.type == INT) {
				return DOUBLE_VAL + (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return DOUBLE_VAL + a.DOUBLE_VAL;
			}
		}
		if (type == INT) {
			if (a.type == INT) {
				return (double)INT_VAL + (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return (double)INT_VAL + a.DOUBLE_VAL;
			}
		}
		if (type == STRING) {
			if (a.type == INT) {
				return STRING_VAL + std::to_string(a.INT_VAL);
			}
			if (a.type == DOUBLE) {

			}
			if (a.type == STRING) {
				return STRING_VAL + a.STRING_VAL;
			}
		}
		return Val();
	}

	Val operator- (Val &a) {
		if (type == DOUBLE) {
			if (a.type == INT) {
				return DOUBLE_VAL - (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return DOUBLE_VAL - a.DOUBLE_VAL;
			}
		}
		if (type == INT) {
			if (a.type == INT) {
				return (double)INT_VAL - (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return (double)INT_VAL - a.DOUBLE_VAL;
			}
		}
		if (type == STRING) {
			throw "Cannot perform this operation on string type";
		}
		return Val();
	}

	Val operator* (Val& a) {
		if (type == DOUBLE) {
			if (a.type == INT) {
				return DOUBLE_VAL * (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return DOUBLE_VAL * a.DOUBLE_VAL;
			}
		}
		if (type == INT) {
			if (a.type == INT) {
				return (double)INT_VAL * (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return (double)INT_VAL * a.DOUBLE_VAL;
			}
		}
		if (type == STRING) {
			throw "Cannot perform this operation on string type";
		}
		return Val();
	}

	Val operator/ (Val& a) {
		if (type == DOUBLE) {
			if (a.type == INT) {
				return DOUBLE_VAL / (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return DOUBLE_VAL / a.DOUBLE_VAL;
			}
		}
		if (type == INT) {
			if (a.type == INT) {
				return (double)INT_VAL / (double)a.INT_VAL;
			}
			if (a.type == DOUBLE) {
				return (double)INT_VAL / a.DOUBLE_VAL;
			}
		}
		if (type == STRING) {
			throw "Cannot perform this operation on string type";
		}
		return Val();
	}

	friend std::ostream& operator<< (std::ostream& out, const Val& v) {
		if (v.type == INT) { out << v.INT_VAL; }
		if (v.type == DOUBLE) { out << v.DOUBLE_VAL; }
		if (v.type == STRING) { out << v.STRING_VAL; }
		return out;
	}
};