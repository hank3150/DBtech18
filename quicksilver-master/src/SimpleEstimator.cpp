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

std::vector< std::vector<uint32_t> > list0;
std::vector< std::vector<uint32_t> > list1;
std::vector< std::vector<uint32_t> > list2;
std::vector< std::vector<uint32_t> > list3;

void SimpleEstimator::prepare() {

    // do your prep here

    //execute prepare() once
    if(list0.size()==0) {

        for (int i = 0; i < graph->adj.size(); i++) {
            //look only in the adj list, rev doubles list

            for (int j = 0; j < graph->adj[i].size(); j++) {

                //std::cout << "from "<< j+1 <<" with "<< graph->adj[i].data()[j].first<<" to "<< graph->adj[i].data()[j].second << std::endl;

                uint32_t edge = graph->adj[i].data()[j].first;
                uint32_t to = graph->adj[i].data()[j].second;

                switch (edge) {
                    case 0:
                        list0.resize(j+1);
                        list0[j].emplace_back(to);
                    case 1:

                        list1.resize(j+1);
                        list1[j].emplace_back(to);
                    case 2:

                        list2.resize(j+1);
                        list2[j].emplace_back(to);
                    case 3:

                        list3.resize(j+1);
                        list3[j].emplace_back(to);
                }
            }
        }

//tests
//        for (int i = 0; i < list0.size(); i++) {
//            std::cout << "\nSize " << list0[i].size() << std::endl;
//
//            for (int j = 0; j < list0[i].size(); j++) {
//                std::cout << "\nFrom " << j+1 << " to " << list0[i][j] << std::endl;
//
//            }
//        }

//        for (int i = 0; i < list1.size(); i++) {
//            std::cout << "\nSize " << list1[i].size() << std::endl;
//
//            for (int j = 0; j < list1[i].size(); j++) {
//                std::cout << "\nFrom " << j+1 << " to " << list1[i][j] << std::endl;
//
//            }
//        }

//        for (int i = 0; i < list2.size(); i++) {
//            std::cout << "\nSize " << list2[i].size() << std::endl;
//
//            for (int j = 0; j < list2[i].size(); j++) {
//                std::cout << "\nFrom " << j+1 << " to " << list2[i][j] << std::endl;
//
//            }
//        }

//        for (int i = 0; i < list3.size(); i++) {
//            std::cout << "\nSize " << list3[i].size() << std::endl;
//
//            for (int j = 0; j < list3[i].size(); j++) {
//                std::cout << "\nFrom " << j+1 << " to " << list3[i][j] << std::endl;
//
//            }
//        }
    }

}

cardStat SimpleEstimator::estimate(RPQTree *q) {

    // perform your estimation here;

    return cardStat {0, 0, 0};
}


