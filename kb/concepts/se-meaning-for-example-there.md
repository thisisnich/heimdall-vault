---
id: "0683fec8-6c86-49f9-aace-dc598342f0a6"
title: "Se Meaning For Example There"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:78fd0650991f4cb6"
source: heimdall/auto
---

# Se Meaning For Example There

- se (meaning, for example,
there is one debian package for each ROS package), respectively.
ROS Package
ROS packages tend to follow a common structure. Here are some of the directories and files you may notice.
●
include/package_name: C++ include headers (make sure to export in the CMakeLists.txt)
● msg/: Folder containing Message (msg) types
●
●
●
src/package_name/: Source files, especially Python source that are exported to other packages.
srv/: Folder containing Service (srv) types
scripts/: executable scripts
● CMakeLists.txt: CMake build file (see catkin/CMakeLists.txt)
● package.xml: Package catkin/package.xml
● CHANGELOG.rst: Many packages will define a changelog which can be automatically injected into binary
packaging and into the wiki page for the package
ROS Package
ROS Package
ROS Package
A package is the basic unit of ROS. The ROS application is developed on a package basis, and the
package contains either a configuration file to launch other packages or nodes. The package also
contains all the files necessary for running the package, including ROS dependency libraries for
running various processes, datasets, and configuration file.
The number of official packages is about 2,500 for ROS Indigo as of July 2017
(http://repositories.ros.org/status_page/ ros_indigo_default.html) and about 1,600 packages for ROS Kinetic
(http://repositories.ros.org/status_page/ros_kinetic_default.html). <!-- id:0683fec8-6c86-49f9-aace-dc598342f0a6 ts:2026-05-17 07:49 -->
- se (meaning, for example,
there is one debian package for each ROS package), respectively.
ROS Package
ROS packages tend to follow a common structure. Here are some of the directories and files you may notice.
●
include/package_name: C++ include headers (make sure to export in the CMakeLists.txt)
● msg/: Folder containing Message (msg) types
●
●
●
src/package_name/: Source files, especially Python source that are exported to other packages.
srv/: Folder containing Service (srv) types
scripts/: executable scripts
● CMakeLists.txt: CMake build file (see catkin/CMakeLists.txt)
● package.xml: Package catkin/package.xml
● CHANGELOG.rst: Many packages will define a changelog which can be automatically injected into binary
packaging and into the wiki page for the package
ROS Package
ROS Package
ROS Package
A package is the basic unit of ROS. The ROS application is developed on a package basis, and the
package contains either a configuration file to launch other packages or nodes. The package also
contains all the files necessary for running the package, including ROS dependency libraries for
running various processes, datasets, and configuration file.
The number of official packages is about 2,500 for ROS Indigo as of July 2017
(http://repositories.ros.org/status_page/ ros_indigo_default.html) and about 1,600 packages for ROS Kinetic
(http://repositories.ros.org/status_page/ros_kinetic_default.html). <!-- id:0683fec8-6c86-49f9-aace-dc598342f0a6 ts:2026-05-17 07:49 -->
