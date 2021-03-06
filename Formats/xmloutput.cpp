//  2006-2008 (c) Viva64.com Team
//  2008-2020 (c) OOO "Program Verification Systems"

#include "xmloutput.h"

namespace PlogConverter
{

XMLOutput::XMLOutput(const ProgramOptions &opt) : IOutput(opt, "xml")
{

}

XMLOutput::~XMLOutput() = default;

void XMLOutput::Start()
{
  m_ostream << "<?xml version=\"1.0\"?>" << std::endl
            << "<NewDataSet>" << std::endl;
}

void XMLOutput::Write(const Warning& msg)
{
  if (msg.IsDocumentationLinkMessage())
  {
    return;
  }

  m_ostream << "  <PVS-Studio_Analysis_Log>" << std::endl
            << "    <Level>" << msg.level << "</Level>" << std::endl
            << "    <ErrorType>" << msg.GetLevelString() << "</ErrorType>" << std::endl
            << "    <ErrorCode>" << msg.code << "</ErrorCode>" << std::endl
            << "    <Message>" << EscapeHtml(msg.message) << "</Message>" << std::endl
            << "    <Line>" << msg.GetLine() << "</Line>" << std::endl
            << "    <File>" << msg.GetFile() << "</File>" << std::endl;

  auto extendedLines = msg.GetExtendedLines();
  if(extendedLines.size() > 1)
  {
    m_ostream << "    <LineExtension>" << Join(extendedLines, [](auto v) { return std::to_string(v); }, ",") << "</LineExtension>" << std::endl;
  }

  if (msg.HasCWE())
  {
    m_ostream << "    <CWECode>" << msg.GetCWEString() << "</CWECode>" << std::endl;
  }

  if (msg.HasMISRA())
  {
    m_ostream << "    <MISRA>" << msg.GetMISRAStringWithLanguagePrefix() << "</MISRA>" << std::endl;
  }

  m_ostream << "  </PVS-Studio_Analysis_Log>" << std::endl;
}

void XMLOutput::Finish()
{
  m_ostream << "</NewDataSet>" << std::endl;
}

}
