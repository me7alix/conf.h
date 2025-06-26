## C Configuration File Parser Library (`conf.h`)

This is a simple, lightweight C library for parsing plain-text configuration files with a custom format. The library reads a configuration file line by line, extracts key-value pairs, and stores them in a dynamic structure for later use.

### Features:

* Parses configuration files line by line.
* Supports line comments (lines starting with `#` are ignored).
* Stores configuration data as key-value string pairs.

### Configuration File Format:

* Each configuration entry must start with a **key**, followed by one or more **values** separated by spaces.
* Lines starting with `#` are treated as comments and ignored.
* Lines containing only a key without a value will trigger a parsing error.

**Example:**

```conf
# Sample config file

PORT 8080
HOST localhost
LOG_PATH /var/log/myapp.log
```

### API Overview:

```c
typedef struct {
	char **keys;    // Array of configuration keys
	char **values;  // Array of corresponding values
	size_t count;   // Number of configuration entries
} Conf;
```

#### Functions:

* `Conf conf_parse(const char *filename);`

  * Parses the given configuration file and returns a `Conf` structure containing keys and values.
  * Exits with an error message if the file can't be opened or if it encounters a line with a key but no value.

* `void conf_free(Conf conf);`

  * Frees all memory allocated by `conf_parse`.

### Try the demo
```
cc demo/main.c && ./a.out
```
