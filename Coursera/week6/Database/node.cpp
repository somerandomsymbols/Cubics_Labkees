#include "node.h"

Node::Node() {}

NodeType Node::Type()
{
    return NodeType::Node;
}

EmptyNode::EmptyNode() {}

NodeType EmptyNode::Type()
{
    return NodeType::EmptyNode;
}

bool EmptyNode::Evaluate(Date x, string y)
{
    return 1;
}


DateComparisonNode::DateComparisonNode(Comparison x, Date y)
{
    DateComparisonNode::date = y;
    DateComparisonNode::comparison = x;
}

NodeType DateComparisonNode::Type()
{
    return NodeType::DateComparisonNode;
}

bool DateComparisonNode::Evaluate(Date x, string y)
{
    switch (DateComparisonNode::comparison)
    {
    case Comparison::Equal:
        return x.date == DateComparisonNode::date.date;
    case Comparison::NotEqual:
        return x.date != DateComparisonNode::date.date;
    case Comparison::Greater:
        return x.date > DateComparisonNode::date.date;
    case Comparison::GreaterOrEqual:
        return x.date >= DateComparisonNode::date.date;
    case Comparison::Less:
        return x.date < DateComparisonNode::date.date;
    case Comparison::LessOrEqual:
        return x.date <= DateComparisonNode::date.date;
    }
}

EventComparisonNode::EventComparisonNode(Comparison x, string y)
{
    EventComparisonNode::comparison = x;
    EventComparisonNode::event = y;
}

NodeType EventComparisonNode::Type()
{
    return NodeType::EventComparisonNode;
}

bool EventComparisonNode::Evaluate(Date x, string y)
{
    /*cout << "+++" << y << "+++" << endl;
    if (y[0] == y[y.length() - 1]
    &&
    y[0] == '"')
    y = y.substr(1, y.length() - 2);*/
    while (y[0] == ' ')
        y = y.substr(1, y.length() - 1);
    while (y[y.length() - 1] == ' ')
        y = y.substr(0, y.length() - 1);
    switch (EventComparisonNode::comparison)
    {
    case Comparison::Equal:
        return y == EventComparisonNode::event;
    case Comparison::NotEqual:
        return y != EventComparisonNode::event;
    case Comparison::Greater:
        return y > EventComparisonNode::event;
    case Comparison::GreaterOrEqual:
        return y >= EventComparisonNode::event;
    case Comparison::Less:
        return y < EventComparisonNode::event;
    case Comparison::LessOrEqual:
        return y <= EventComparisonNode::event;
    }
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &x, shared_ptr<Node> y, shared_ptr<Node> z)
{
    LogicalOperationNode::operation = x;
    LogicalOperationNode::left = y;
    LogicalOperationNode::right = z;
}

NodeType LogicalOperationNode::Type()
{
    return NodeType::LogicalOperationNode;
}

bool LogicalOperationNode::Evaluate(Date x, string y)
{
    switch (LogicalOperationNode::operation)
    {
    case LogicalOperation::And:
        return LogicalOperationNode::left->Evaluate(x, y) && LogicalOperationNode::right->Evaluate(x, y);
    case LogicalOperation::Or:
        return LogicalOperationNode::left->Evaluate(x, y) || LogicalOperationNode::right->Evaluate(x, y);
    }
}
