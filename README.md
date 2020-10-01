# MacMe
This project contains a list of useful and often forgotten MacOS scripts that are united by the program "me". 

## Installation
To build the executable file execute ``make`` in the root directory of this project.
In order to make the program accessible from all directories it is necessary to copy the binary file to a location defined in the file ``~/.bash_profile.``. This can be done by executing the following command (use ``mv`` to move the file instead of creating a copy):
```
$ cp ~/MacMe/me ./bin
```

## Examples

The following command prints the user name of the currently logged in user

```
$ me name
```

This command makes it easy to get the ip address of the en0 (ethernet or WiFi interface of newer hardware). To retreive the ip address of a different interface the suffix ``-i <interface name>`` can be used.

```
$ me ip
```

This command returns the MacOS version
```
$ me os
```