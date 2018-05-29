# CarSharing
C++ Advanced Project

# project dependencies:
Boost version 1.66

if boost library is not under your C: or E: you need to modify lines in CMakeLists.txt in src path

set(BOOST_ROOT E:/boost_1_66_0)
set(Header E:/boost_1_66_0/stage/lib)

# How to run?
build project with cmake

server side:
in terminal navigate to /CarSharing/bin
execute: Server.exe <port>

client side: 
in terminal navigate to /CarSharing/bin
run: Client.exe 127.0.0.1 <port>
