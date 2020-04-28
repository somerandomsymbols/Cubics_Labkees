#pragma once
#include "database.h"

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};
enum class LogicalOperation {
    And,
    Or,
};

enum class NodeType
{
    Node,
    EmptyNode,
    DateComparisonNode,
    EventComparisonNode,
    LogicalOperationNode,
};

class Node
{
    public:
    Node();

    virtual NodeType Type();

    virtual bool Evaluate(Date x, string y)=0;
};

class EmptyNode : public Node
{
    public:
    EmptyNode();

    NodeType Type();

    bool Evaluate(Date x, string y);
};

class DateComparisonNode : public Node
{
    public:
    Comparison comparison;
    Date date;

    DateComparisonNode(Comparison x, Date y);

    NodeType Type();

    bool Evaluate(Date x, string y);
};

class EventComparisonNode : public Node
{
    public:
    Comparison comparison;
    string event;

    EventComparisonNode(Comparison x, string y);

    NodeType Type();

    bool Evaluate(Date x, string y);
};

class LogicalOperationNode : public Node
{
    public:
    LogicalOperation operation;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    LogicalOperationNode(const LogicalOperation &x, shared_ptr<Node> y, shared_ptr<Node> z);

    NodeType Type();

    bool Evaluate(Date x, string y);
};
