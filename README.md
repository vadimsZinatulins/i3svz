# i3svz

Custom i3status made in C++. It follows [i3bar input protocol](https://i3wm.org/docs/i3bar-protocol.html) to communicate with [i3bar](i3wm.org). The configuration file must be written in TOML and its path must be specified with `-c` followed by a the path. Example: `i3svz -c path/to/config.toml`.

At this points all it does is reading the config file and printing a static string (which is useless for now).

# Config file example

```toml
[my_module]
full_text = "Hello World"
color = "#e2e01d"
background = "#221ee1"
```

# Instalation

```bash
mkdir build bin
cmake -B build/ -S .
cmake --build build/
```

The executable will be inside projects *bin/* directory .

# Usage

In your *i3 config file* `status_command` to something like:

```bash
# ...
bar {
    status_command path/to/i3svz -c path/to/config.toml
    # ...
}
```
