# MacMe
This project contains a list of useful and often forgotten MacOS scripts that are united by the program "me". 

## Installation
To build the executable file execute ``make`` in the root directory of this project.
In order to make the program accessible from all directories it is necessary to copy the binary file to a location defined in the file ``~/.bash_profile.``. This can be done by executing the following command (use ``mv`` to move the file instead of creating a copy):
```
$ cp ./me ./bin
```

## List of functionalities

| Name     | Description                                                                                                                                                 |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ``finder``   | Opens a finder window in the current directory. |
| ``interface``| Returns the interface information of the interface ``en0`` (default). With the suffix [-i] <interface name> the interface can be changed.|
| ``ip``       | Returns the ip address of the network interface ``en0`` (default). With the suffix [-i] <interface name> the ip address of a specific interface can be queried. |
| ``ipv6``     | Returns the ip v6 address of the network interface ``en0`` (default). With the suffix [-i] <interface name> the ip v6 address of a specific interface can be queried. |
| ``mac``      | Returns the mac address of the network interface ``en0`` (default). With the suffix [-i] <interface name> the mac address of a specific interface can be queried.|
| ``name``     | Returns the user name of the currently logged in user. |
| ``os``       | Returns the MacOS version. |
| ``path``     | Prints the path of the current directory. |                                                                                                                         
| ``settings`` | Opens the settings window. |

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