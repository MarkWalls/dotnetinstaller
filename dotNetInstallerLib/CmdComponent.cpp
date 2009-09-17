#include "StdAfx.h"
#include "XmlAttribute.h"
#include "CmdComponent.h"
#include "InstallUILevel.h"
#include "InstallerLog.h"
#include "InstallConfiguration.h"
#include "InstallerSession.h"

CmdComponent::CmdComponent()
	: ProcessComponent(cmd)
{

}

void CmdComponent::Exec()
{
	std::wstring l_command = InstallUILevelSetting::Instance->GetCommand(
		command, command_basic, command_silent);

	std::map<std::wstring, std::wstring>::iterator cmdline = InstallerSession::Instance->AdditionalCmdLineArgs.find(description);
    if (cmdline != InstallerSession::Instance->AdditionalCmdLineArgs.end())
    {
		l_command += TEXT(" ");
		l_command += cmdline->second.c_str();
		LOG(L"-- Additional component arguments: " << cmdline->second);
    }

	LOG(L"Executing: " << l_command);
	DVLib::DetachCmd(l_command, & m_process_info);
};

void CmdComponent::Load(TiXmlElement * node)
{
	command = XML_ATTRIBUTE(node->Attribute("command"));
    command_silent = XML_ATTRIBUTE(node->Attribute("command_silent"));
	command_basic = XML_ATTRIBUTE(node->Attribute("command_basic"));	
	Component::Load(node);
	LOG(L"Loaded 'cmd' component '" << description << L"'");
}

void CmdComponent::Wait(DWORD tt)
{
	ProcessComponent::Wait(tt);

	DWORD exitcode = ProcessComponent::GetProcessExitCode();
	// a non-zero error code represents failure
	CHECK_BOOL(exitcode == 0,
		L"Error executing '" << description << "': " << DVLib::FormatMessage(L"0x%x", exitcode));
}
