Macro_func = "Macro add_num\nload N1\nadd N2\nstore N1\nMend\nStart\nMOV
A,00H\nrepeat: add N1 dec N2 JNZ repeat\nadd_num\nMOV A,23H\nadd_num\nEnd "
print("ORIGINAL CODE\n-------------")
print(Macro_func)
print("-------------\n")

# Macro found at index, storing the name & code.
Macro_name = Macro_func[Macro_func.find("Macro") + 6 : Macro_func.find("\n")]
Macro_string = Macro_func[
Macro_func.find(Macro_name) + len(Macro_name) : Macro_func.find("Mend")
]
print(Macro_name)
print(Macro_string)
# finding macro name and replacing the item.
driver_code = Macro_func[Macro_func.find("Start") : Macro_func.find("End") + 3]
driver_code = driver_code.replace(Macro_name, Macro_string)
print(driver_code)