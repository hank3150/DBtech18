//
// Created by Nikolay Yakovets on 2018-02-01.
//

#include "SimpleGraph.h"
#include "SimpleEstimator.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <regex>
#include <fstream>

SimpleEstimator::SimpleEstimator(std::shared_ptr<SimpleGraph> &g){

    // works only with SimpleGraph
    graph = g;
}

std::map< uint32_t, std::vector<uint32_t> > map0;
std::map< uint32_t, std::vector<uint32_t> > map1;
std::map< uint32_t, std::vector<uint32_t> > map2;
std::map< uint32_t, std::vector<uint32_t> > map3;

void SimpleEstimator::prepare() {

    // do your prep here

    //to execute prepare() once
    if(map0.size()==0) {

        for (int i = 0; i < graph->adj.size(); i++) {
            //look only in the adj list, rev doubles list

            for (int j = 0; j < graph->adj[i].size(); j++) {

                //std::cout << "from "<< j+1 <<" with "<< graph->adj[i].data()[j].first<<" to "<< graph->adj[i].data()[j].second << std::endl;

                uint32_t edge = graph->adj[i].data()[j].first;
                uint32_t to = graph->adj[i].data()[j].second;

                //use to update for each data point in dictionary
                std::vector<uint32_t> list;

                switch (edge) {
                    case 0:
                        //check if in map
                        if(map0.find(j+1)==map0.end())
                        {
                            list.emplace_back(to);
                            map0.insert(std::pair<uint32_t, std::vector<uint32_t>>(j+1, list));
                        }else {
                            map0[j+1].emplace_back(to);
                        }
                    case 1:
                        //check if in map
                        if(map1.find(j+1)==map1.end())
                        {
                            list.emplace_back(to);
                            map1.insert(std::pair<uint32_t, std::vector<uint32_t>>(j+1, list));
                        }else {
                            map1[j+1].emplace_back(to);
                        }
                    case 2:
                        //check if in map
                        if(map2.find(j+1)==map2.end())
                        {
                            list.emplace_back(to);
                            map2.insert(std::pair<uint32_t, std::vector<uint32_t>>(j+1, list));
                        }else {
                            map2[j+1].emplace_back(to);
                        }
                    case 3:
                        //check if in map
                        if(map3.find(j+1)==map3.end()) {
                            list.emplace_back(to);
                            map3.insert(std::pair<uint32_t, std::vector<uint32_t>>(j+1, list));
                        }else {
                            map3[j+1].emplace_back(to);
                        }
                }
            }
        }
    }

}

cardStat SimpleEstimator::estimate(RPQTree *q) {

    // perform your estimation here;

    RPQTree current = *q;


    return cardStat {nullptr, nullptr, nullptr};
}


