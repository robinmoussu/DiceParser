#include "helpnode.h"

HelpNode::HelpNode()
    : m_path("https://github.com/obiwankennedy/DiceParser/blob/master/HelpMe.md")
{
    m_result = new StringResult();
}
void HelpNode::run(ExecutionNode* previous)
{
	m_previousNode = previous;
    StringResult* txtResult = dynamic_cast<StringResult*>(m_result);
    txtResult->setHighLight(false);

    if(NULL != previous)
    {
        if(previous->getResult() == NULL)
        {
            txtResult->setText(toString());

        }
        else
        {
            txtResult->setText(previous->getHelp());
        }
        m_result->setPrevious(previous->getResult());
    }

    if(NULL!=m_nextNode)
    {
        m_nextNode->run(this);
    }
}
QString HelpNode::toString() const
{
    return QObject::tr("Rolisteam Dice Parser:\nFull documentation at: %1 \n").arg(m_path);
}

qint64 HelpNode::getPriority() const
{
    return 0;
}
void HelpNode::setHelpPath(QString path)
{
    m_path = path;
}
