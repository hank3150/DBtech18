//
// Created by Nikolay Yakovets on 2018-02-01.
//

#include "SimpleGraph.h"
#include "SimpleEstimator.h"

SimpleEstimator::SimpleEstimator(std::shared_ptr<SimpleGraph> &g){

    // works only with SimpleGraph
    graph = g;
}

void SimpleEstimator::prepare() {

    // do your prep here
    std::cout << "\nPREPARE!" << graph->adj.data()<< std::endl;

}

cardStat SimpleEstimator::estimate(RPQTree *q) {

    // perform your estimation here
    prepare();



    return cardStat {0, 0, 0};
}