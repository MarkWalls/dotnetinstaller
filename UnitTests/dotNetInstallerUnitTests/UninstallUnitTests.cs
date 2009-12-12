using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;
using InstallerLib;
using dotNetUnitTestsRunner;
using System.IO;

namespace dotNetInstallerUnitTests
{
    [TestFixture]
    public class UninstallUnitTests
    {
        [Test]
        public void TestSupportsNone()
        {
            // a configuration with no components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.supports_install = false;
            setupConfiguration.supports_uninstall = false;
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            File.Delete(configFilename);
        }

        [Test]
        public void TestSupportsInstall()
        {
            // a configuration with no components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.supports_install = true;
            setupConfiguration.supports_uninstall = false;
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            // uninstall is not supported
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.uninstall = true;
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestSupportsUninstall()
        {
            // a configuration with no components
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            setupConfiguration.supports_install = false;
            setupConfiguration.supports_uninstall = true;
            // save config file
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute dotNetInstaller
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(configFilename));
            // uninstall is not supported
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.uninstall = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUninstallSwitch()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            setupConfiguration.Children.Add(cmd);
            cmd.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd.uninstall_command = "cmd.exe /C exit /b 0";
            cmd.supports_install = true;
            cmd.supports_uninstall = true;
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // execute uninstall
            dotNetInstallerExeUtils.RunOptions options = new dotNetInstallerExeUtils.RunOptions(configFilename);
            options.uninstall = false;
            Assert.AreNotEqual(0, dotNetInstallerExeUtils.Run(options));
            options.uninstall = true;
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(options));
            File.Delete(configFilename);
        }

        [Test]
        public void TestUninstallAuto()
        {
            // a component that's already installed
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            configFile.Children.Add(setupConfiguration);
            ComponentCmd cmd = new ComponentCmd();
            setupConfiguration.Children.Add(cmd);
            cmd.id = "cmd1";
            cmd.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd.uninstall_command = "cmd.exe /C exit /b 0";
            cmd.supports_install = true;
            cmd.supports_uninstall = true;
            InstalledCheckFile check = new InstalledCheckFile();
            cmd.Children.Add(check);
            check.comparison = installcheck_comparison.exists;
            check.filename = dotNetInstallerExeUtils.Executable;
            // a second component that doesn't support uninstall
            ComponentCmd cmd2 = new ComponentCmd();
            setupConfiguration.Children.Add(cmd2);
            cmd2.id = "cmd2";
            cmd2.command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd2.uninstall_command = "cmd.exe /C exit /b 1"; // would fail if ran
            cmd2.supports_install = true;
            cmd2.supports_uninstall = false;
            cmd2.Children.Add(check);
            string configFilename = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFilename);
            configFile.SaveAs(configFilename);
            // will fallback to uninstall since all components are installed
            Assert.AreEqual(0, dotNetInstallerExeUtils.Run(configFilename));
        }
    }
}