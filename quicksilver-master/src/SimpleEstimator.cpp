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
    //std::cout << "\nPREPARE!" << graph->adj[1].size()<< std::endl;
    for (int i=0;i<graph->adj.size();i++)
    {
        std::cout << "\nPREPARE!" << graph->adj[i].data()<< std::endl;
    }
}

cardStat SimpleEstimator::estimate(RPQTree *q) {

    // perform your estimation here
    prepare();



    return cardStat {0, 0, 0};
}