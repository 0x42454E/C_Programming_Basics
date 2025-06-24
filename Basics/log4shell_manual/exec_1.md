Apache Log4j JNDI features used in configuration, log messages, and parameters do not protect against attacker controlled LDAP and other JNDI related endpoints. An attacker who can control log messages or log message parameters can execute arbitrary code loaded from LDAP servers when message lookup substitution is enabled.

log4j provides a record system for event, logs and etc

in log4j, there is a lookup table that is being processed by JNDI API

JNDI provides an abstraction layer for directory services and can load and process sources from destinations dynamically 
at runtime

JNDI can process LDAP for log4j
and execute them locally

Input sanitation was improperly configured and by recieving tailord input - it can fetch malicous files and arbitary code may execute

this exploit allows the attacker to takeover the explioted system

invoke jndi lookup, its coresponding api resolves it.
contacts a server specified by the attacker and fetches the class to be executed.

![[Pasted image 20250218090042.png]]