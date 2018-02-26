//
// Created by Nikolay Yakovets on 2018-02-01.
//

#include "SimpleGraph.h"
#include "SimpleEstimator.h"

#include "Preparation.h"

SimpleEstimator::SimpleEstimator(std::shared_ptr<SimpleGraph> &g){

    // works only with SimpleGraph
    graph = g;
}

//no need
//std::vector<std::vector<std::vector<uint32_t>>> list;

void SimpleEstimator::prepare() {

    std::vector<Preparation> list;

    // do your prep here
    for (int i=0;i<graph->adj.size();i++)
    {
        //look only in the adj list, rev doubles list
        //std::cout << "\nrow " << i << " size: "<< graph->adj[i].size()<< std::endl;
        for(int j=0;j<graph->adj[i].size();j++)
        {
            //std::cout << "from "<< j+1 <<" with "<< graph->adj[i].data()[j].first<<" to "<< graph->adj[i].data()[j].second << std::endl;

            // uint32_t from = j+1;
            // uint32_t to = graph->adj[i].data()[j].second;
            // uint32_t edgeLabel = graph->adj[i].data()[j].first;

            list[graph->adj[i].data()[j].first].emplace_back(Preparation());
        }
    }

    //std::cout << "\nrow " << 0 << " size: "<< list[0][0][1]<< std::endl;
}

cardStat SimpleEstimator::estimate(RPQTree *q) {

    // perform your estimation here
    prepare();

    std::cout << q->data;



    return cardStat {0, 0, 0};
}