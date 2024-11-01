#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>

#include "chatbot.h"

using std::unique_ptr;
using std::move;

class GraphEdge;

class GraphNode
{
private:

    std::vector<unique_ptr<GraphEdge>> _childEdges;

    std::vector<GraphEdge *> _parentEdges; 
    ChatBot _chatBot;

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(unique_ptr<GraphEdge> edge);

    void MoveChatbotHere(ChatBot chatbot);

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */