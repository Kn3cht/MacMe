# MacMe
This project contains a list of useful MacOS scripts that are united by the program "me"

## Installation
To build the executable file execute ``make`` in the root directory of this project.
In order to make the program accessible from all directories it is necessary to copy the binary file to a location defined in the file ``~/.bash_profile.``. This can be done by executing the following command (use ``mv`` to move the file instead of creating a copy):
```
cp ~/MacMe/me ./bin
```