//  2006-2008 (c) Viva64.com Team
//  2008-2020 (c) OOO "Program Verification Systems"

#ifndef TASKLISTOUTPUT_H
#define TASKLISTOUTPUT_H
#include "ioutput.h"

namespace PlogConverter
{

class TaskListOutput : public IOutput
{
public:
  explicit TaskListOutput(const ProgramOptions &);
  ~TaskListOutput() override;
  void Write(const Warning &msg) override;
};

}

#endif // TASKLISTOUTPUT_H
