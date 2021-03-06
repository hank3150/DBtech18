//
// Created by Nikolay Yakovets on 2018-02-01.
//

#include "SimpleGraph.h"
#include "SimpleEstimator.h"
#include "SimpleEvaluator.h"

SimpleEstimator::SimpleEstimator(std::shared_ptr<SimpleGraph> &g){

    // works only with SimpleGraph
    graph = g;
}

std::unordered_set <uint32_t> x;
std::vector< std::unordered_set <uint32_t> > inNode={x,x,x,x};
std::vector< std::unordered_set <uint32_t> > outNode={x,x,x,x};
std::vector <uint32_t> y;
std::vector< std::vector <uint32_t> > inNodeTotal={y,y,y,y};
std::vector< std::vector <uint32_t> > outNodeTotal={y,y,y,y};

uint32_t pass=0;

void SimpleEstimator::prepare() {

    // do your prep here
    if(pass==0) {
        for (int i = 0; i < graph->adj.size(); i++) {
            for (int j = 0; j < graph->adj[i].size(); j++) {

                int edge = graph->adj[i].data()[j].first;
                int to = graph->adj[i].data()[j].second;
                int from = j + 1;

                inNode[edge].insert(to);
                outNode[edge].insert(from);

                inNodeTotal[edge].emplace_back(to);
                outNodeTotal[edge].emplace_back(from);
            }
        }
        pass=1;
    }
}

uint32_t TR=0;
uint32_t TS=0;
uint32_t VR=0;
uint32_t VS=0;
uint32_t nrPases=0;
uint32_t noOut=0;
uint32_t noIn=0;

void initialize()
{
    TR=0;
    TS=0;
    VR=0;
    VS=0;
    nrPases=0;
    noOut=0;
    noIn=0;
}

std::shared_ptr<SimpleGraph> SimpleEstimator::estimate_aux(RPQTree *q) {

    // estimate according to the AST bottom-up



    if(q->isLeaf()) {
        // project out the label in the AST
        std::regex directLabel (R"((\d+)\+)");
        std::regex inverseLabel (R"((\d+)\-)");

        std::smatch matches;

        uint32_t label;
        bool inverse;

        if(std::regex_search(q->data, matches, directLabel)) {
            label = (uint32_t) std::stoul(matches[1]);
            inverse = false;
        } else if(std::regex_search(q->data, matches, inverseLabel)) {
            label = (uint32_t) std::stoul(matches[1]);
            inverse = true;
        } else {
            std::cerr << "Label parsing failed!" << std::endl;
            return nullptr;
        }

        SimpleEstimator::calculate(label, inverse);

    }

    if(q->isConcat()) {

        // estimate the children

        auto leftGraph = SimpleEstimator::estimate_aux(q->left);
        auto rightGraph = SimpleEstimator::estimate_aux(q->right);


    }

    return nullptr;
}

void SimpleEstimator::calculate(uint32_t labell, bool inverse) {

    if(TR == 0) {
        //first pass
        TR=inNodeTotal[labell].size();
        VR=inNode[labell].size();
        noOut=VR;
        TS=outNodeTotal[labell].size();
        VS=outNode[labell].size();
        noIn=VS;

        nrPases=std::min(TR*(TS/VS), TS*(TR/VR));
    }
    else {
        TR=TS;
        VR=VS;
        noOut=VS;

        TS=inNodeTotal[labell].size();
        VS=inNode[labell].size();
        noIn=VS;

        nrPases=std::min(TR*(TS/VS), TS*(TR/VR));
    }
}

cardStat SimpleEstimator::estimate(RPQTree *q) {

    // perform your estimation here;
    initialize();
    auto res = estimate_aux(q);
    //return SimpleEstimator::computeStats(res);

    return cardStat {noOut, nrPases, noIn};
}






