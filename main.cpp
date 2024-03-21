#include <iostream>

#include "antlr4-runtime.h"
#include "woditextLexer.h"
#include "woditextParser.h"
#include "commongen.hpp"

using namespace antlr4;

int main(int argc, const char* argv[])
{
	if (argc != 2 && argc != 3) {
		std::cout << "Usage:" << std::endl;
		std::cout << argv[0] << " <inputfile>" << std::endl;
		std::cout << argv[0] << " <inputfile> <outputfile>" << std::endl;
		return 1;
	}
	
	std::ifstream stream;
	stream.open(argv[1]);

	ANTLRInputStream input(stream);
	woditextLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	woditextParser parser(&tokens);

	//tree::ParseTree* tree = parser.commonlist();
	CommonGen visitor;
	//tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
	woditextParser::CommonlistContext* tree = parser.commonlist();
	visitor.visitCommonlist(tree);

	if (argc == 3) {
		visitor.cf.generate(argv[2]);
	} else {
		visitor.cf.generate("out.common");
	}

	return 0;
}
