```
			███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗███╗
			██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     ██████╔╝
			██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔══██╗
			██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ║██║
			╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚══╝
				PID: 1337			By: ybounite
			⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰
```
<h1 align="center">
	42cursus' minitalk 
</h1>

<p align="center">
This project is a simple client-server communication system implemented using signals in C.
The client sends a message to the server, and the server receives and displays the message character by character.


### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters
