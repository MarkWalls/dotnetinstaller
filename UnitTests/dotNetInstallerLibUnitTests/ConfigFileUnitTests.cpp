#include "StdAfx.h"
#include "ConfigFileUnitTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DVLib::UnitTests::ConfigFileUnitTests);

using namespace DVLib::UnitTests;

void ConfigFileUnitTests::testLoadPackagedSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\PackagedSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.1");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 4);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"Standalone setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	ComponentPtr component = configuration->components[0];
	CPPUNIT_ASSERT(component->type == component_type_msi);
}

void ConfigFileUnitTests::testLoadInstallCheckProductSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\InstallCheckProduct\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 1);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"InstallCheckProduct setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 2);
	// \todo: verify that product checks are correct
}

void ConfigFileUnitTests::testLoadInstallCheckOperators()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\InstallCheckOperators\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 1);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"InstallCheckOperators setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 4);
	CPPUNIT_ASSERT(configuration->components[0]->type == component_type_cmd);
	CPPUNIT_ASSERT(configuration->components[1]->type == component_type_cmd);
	CPPUNIT_ASSERT(configuration->components[2]->type == component_type_cmd);
	CPPUNIT_ASSERT(configuration->components[3]->type == component_type_cmd);
	// \todo: verify that operators tree is correct
}

void ConfigFileUnitTests::testLoadStandaloneSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\StandaloneSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 0);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 2);
	// \todo: verify that lcid's are different
}

void ConfigFileUnitTests::testLoadDownloadSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\DownloadSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 0);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	ComponentPtr component = configuration->components[0];
	CPPUNIT_ASSERT(component->type == component_type_cmd);
	// the component has a download dialog with one file
	CPPUNIT_ASSERT(get(component->downloaddialog) != NULL);
	CPPUNIT_ASSERT(component->downloaddialog->downloadfiles.size() == 1);
}

void ConfigFileUnitTests::testLoadReferenceSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\ReferenceSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.0");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 0);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const ReferenceConfiguration * configuration = reinterpret_cast<ReferenceConfiguration *>(get(config[0]));
	// the reference has a download dialog
	CPPUNIT_ASSERT(get(configuration->downloaddialog) != NULL);
	CPPUNIT_ASSERT(configuration->downloaddialog->downloadfiles.size() == 1);
}

void ConfigFileUnitTests::testLoadResource()
{
	ConfigFile config;
	config.LoadResource(NULL, L"RES_CONFIGURATION");
	// configurations properties
	CPPUNIT_ASSERT(! config.schema.generator.empty());
	CPPUNIT_ASSERT(! config.schema.version.empty());
	CPPUNIT_ASSERT(config.lcidtype == DVLib::LcidUserExe);
	CPPUNIT_ASSERT(config.uilevel == InstallUILevelFull);
	CPPUNIT_ASSERT(config.fileversion == L"1.0.0.1");
	CPPUNIT_ASSERT(config.productversion == L"1.0.0.0");
	// file attributes
	CPPUNIT_ASSERT(config.fileattributes.size() == 4);
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->name == L"FileDescription");
	CPPUNIT_ASSERT(config.fileattributes[L"FileDescription"]->value == L"Standalone setup sample");
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	ComponentPtr component = configuration->components[0];
	CPPUNIT_ASSERT(component->type == component_type_msi);
}

void ConfigFileUnitTests::testGetSupportedConfigurations()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\StandaloneSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there're two configurations in this sample, opposite of each other
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(0, SequenceInstall).size() == 1);
}

void ConfigFileUnitTests::testLoadOsFiltersSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\OsFilters\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there're three components in this sample, but only 1 will show because the os filters don't overlap
	CPPUNIT_ASSERT(config.size() == 1);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(0, SequenceInstall).size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 3);	
}


void ConfigFileUnitTests::testLoadMultipleSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\MultipleConfig\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations properties
	CPPUNIT_ASSERT(config.size() == 2);	
	// install sequence
	std::vector<ConfigurationPtr> install_configurations = config.GetSupportedConfigurations(LcidUser, SequenceInstall);
	CPPUNIT_ASSERT(configuration_reference == install_configurations[0]->type);
	CPPUNIT_ASSERT(configuration_install == install_configurations[1]->type);
	InstallConfiguration * p_configuration_install = reinterpret_cast<InstallConfiguration *>(get(install_configurations[1]));
	Components install_components = p_configuration_install->GetSupportedComponents(LcidUser, SequenceInstall);
	CPPUNIT_ASSERT(install_components.size() == 2);
	CPPUNIT_ASSERT(install_components[0]->id == L"setup1");
	CPPUNIT_ASSERT(install_components[1]->id == L"setup2");
	Components uninstall_components = p_configuration_install->GetSupportedComponents(LcidUser, SequenceUninstall);
	CPPUNIT_ASSERT(uninstall_components.size() == 2);
	CPPUNIT_ASSERT(uninstall_components[0]->id == L"setup2");
	CPPUNIT_ASSERT(uninstall_components[1]->id == L"setup1");
	std::vector<ConfigurationPtr> uninstall_configurations = config.GetSupportedConfigurations(LcidUser, SequenceUninstall);
	CPPUNIT_ASSERT(configuration_install == uninstall_configurations[0]->type);
	CPPUNIT_ASSERT(configuration_reference == uninstall_configurations[1]->type);	
}

void ConfigFileUnitTests::testLoadMultilingualSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\MultilingualSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there're two configurations in this sample, but only 1 will show because the lcids don't overlap
	CPPUNIT_ASSERT(config.size() == 2);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(0, SequenceInstall).size() == 1);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(1040, SequenceInstall).size() == 1);
	CPPUNIT_ASSERT(config.GetSupportedConfigurations(1040, SequenceInstall)[0]->lcid_filter == L"1040");
}

void ConfigFileUnitTests::testLoadLicenseAgreement()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\LicenseAgreement\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there's one configuration in this sample
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	CPPUNIT_ASSERT(configuration->controls.size() == 2);
	CPPUNIT_ASSERT(configuration->controls[0]->type == control_type_license);
	CPPUNIT_ASSERT(configuration->controls[1]->type == control_type_image);
}

void ConfigFileUnitTests::testLoadCustomInputSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\CustomInputSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// there's one configuration in this sample
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	CPPUNIT_ASSERT(configuration->controls.size() == 6);
	CPPUNIT_ASSERT(configuration->controls[0]->type == control_type_label);
	CPPUNIT_ASSERT(configuration->controls[1]->type == control_type_label);
	CPPUNIT_ASSERT(configuration->controls[2]->type == control_type_checkbox);
	CPPUNIT_ASSERT(configuration->controls[3]->type == control_type_browse);
	CPPUNIT_ASSERT(configuration->controls[4]->type == control_type_browse);
	CPPUNIT_ASSERT(configuration->controls[5]->type == control_type_hyperlink);
}

void ConfigFileUnitTests::testLoadPatchSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\PatchSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 2);
	ComponentPtr component_msi = configuration->components[0];
	CPPUNIT_ASSERT(component_msi->type == component_type_msi);
	ComponentPtr component_msp = configuration->components[1];
	CPPUNIT_ASSERT(component_msp->type == component_type_msp);
}

void ConfigFileUnitTests::testLoadExeSetup()
{
	std::wstring configxml = DVLib::DirectoryCombine(DVLib::GetModuleDirectoryW(), 
		L"..\\..\\..\\Samples\\ExeSetup\\Configuration.xml");
	CPPUNIT_ASSERT(DVLib::FileExists(configxml));
	ConfigFile config;
	config.LoadFile(configxml);
	// configurations with components
	CPPUNIT_ASSERT(config.size() == 1);
	const InstallConfiguration * configuration = reinterpret_cast<InstallConfiguration *>(get(config[0]));
	CPPUNIT_ASSERT(configuration->components.size() == 1);
	ComponentPtr component_exe = configuration->components[0];
	CPPUNIT_ASSERT(component_exe->type == component_type_exe);	
}
