#include <iostream>

#include "gff.h"

#include <cstdio>

int main(int argc, char* argv[]) {

    GffReader reader(argv[1]);
    reader.readAll(true);


    std::cerr << "had count of " << reader.gflst.Count() << "\n";
    size_t nfeat = reader.gflst.Count();
    for (size_t i=0; i < nfeat; ++i) {
       auto f = reader.gflst[i];
       if (f->isTranscript()) {

           std::cout << f->getID() << '\t' << f->getGeneID() << '\t';
           if (f->attrs) {
               for (size_t j=0; j < f->attrs->Count(); ++j) {
                   std::cout << f->getAttrName(j) << "\t" << f->getAttrValue(j) << "\t";
               }
           }
           std::cout << "\n";
       }
    }

}

