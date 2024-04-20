#include <iostream>

#include "server.h"

using namespace std;

int main() {
	Server s;
	s.listen("127.0.0.1", 9999);
	return 0;
}
