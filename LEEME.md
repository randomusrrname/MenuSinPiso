# Menu Sin Piso (5hut.menu-sin-piso)

Mod de Geode que oculta el piso del menú principal y extiende el fondo hacia abajo.

## Cómo compilarlo (igual que tu mod practice-hud)
1. Creá un repo nuevo en GitHub (por ejemplo `MenuSinPiso`) y subí estos archivos:
   `mod.json`, `CMakeLists.txt`, `src/main.cpp`, `.gitignore`.
2. Copiá la carpeta `.github/workflows/` de tu repo de practice-hud (el archivo .yml que ya te
   compila para Android). Así usás el mismo flujo que ya te funciona con Geode v6 beta.
3. Hacé push, esperá que GitHub Actions termine y bajá el archivo `.geode` que genera.
4. Ponelo en la carpeta `mods` de Geode en el celular y reiniciá el juego.

## Ajustes (dentro del juego, en la lista de mods)
- Ocultar piso (activado por defecto)
- Ocultar línea del horizonte (desactivado por defecto)

## Si da error al compilar o al cargar
- Mirá la línea `"geode"` de `mod.json`: debe coincidir con la de tu mod practice-hud.
- Mandame el texto del error y lo corrijo.
