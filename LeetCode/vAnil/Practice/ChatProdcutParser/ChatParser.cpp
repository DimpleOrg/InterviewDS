#include "MaxProductCountInChat.h"

int main(int argc, char *argv[])
{
	ProductCatalogue productCatalogue;
	productCatalogue.AddProduct("CAR");
	productCatalogue.AddProduct("BUS");
	productCatalogue.AddProduct("TRAIN");
	productCatalogue.AddProduct("CUP");
	productCatalogue.AddProduct("GLASS");

	FileParser fParser;
	auto parseResult = fParser.Parse("chat.txt", productCatalogue);

	ProductFequencyAnalyzer fAnalyzer;
	auto result = fAnalyzer.AnalyzeParseResult(parseResult, productCatalogue);


	return 0;
}