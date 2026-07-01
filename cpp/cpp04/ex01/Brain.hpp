#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[93m"
#define BLUE	"\033[34m"
#define PURPLE	"\033[35m"

class Brain {
			private:
					std::string _ideas[100];
			public:
					Brain();
					Brain(const Brain& copy);
					Brain& operator=(const Brain& copy);
					~Brain();
};

#endif