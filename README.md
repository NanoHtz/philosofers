<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="assets/banner.svg" alt="Banner de TODO_TITULO" width="100%" />
</p>

<p align="center"><i>PHILOSOPHERS — Creación y manejo de hilos, gestion de deadlocks y mutexes.</i></p>

---

## Índice
- [Resumen](#resumen)
- [Capturas / Demo](#capturas--demo)
- [Stack / Dependencias](#stack--dependencias)
- [Estructura](#estructura)
- [Instalación y uso](#instalación-y-uso)
- [Tests](#tests)
---

## Resumen
- **Qué**: Philosophers, es un proyecto en el que aprendes a manejar hilos de un mismo proceso, que comparten recursos, memoria, variables... etc
- **Para qué**: valor que aporta (p. ej., “aprendizaje de X”, “utilidad Y”).
- **Estado**: `alpha` / `estable` / `en progreso`.
- **Highlights**: 3 bullets de funciones o decisiones técnicas clave.
Puedes usar : https://github.com/dantonik/42-philosophers-tester Para probar

---

## Capturas / Demo
<!-- Deja una o varias imágenes / GIFs; guarda en assets/ -->
<p align="center">
  <!-- <img src="assets/demo_1.png" width="85%" alt="Demo"> -->
  <!-- <img src="assets/demo.gif" width="85%" alt="Animación"> -->
  <i>Incluye aquí una imagen o GIF corto si aporta valor.</i>
</p>

---

## Stack / Dependencias
<!-- Elige la variante que aplique y elimina la otra -->

<!-- ===== Variante C / 42 ===== -->
- **Lenguaje**: C (C99/gnu11)
- **Build**: Makefile (`cc -Wall -Wextra -Werror`)
- **POSIX**: `unistd.h`, `fcntl.h`, `signal.h`, etc.
- **Opcional**: MiniLibX / pthreads / readline

<!-- ===== Variante Python / Datos ===== -->
<!--
- **Lenguaje**: Python 3.10+
- **Entorno**: venv / conda
- **Paquetes**: numpy, pandas, matplotlib, scipy, scikit-learn, jupyter
-->

---

## Estructura
```text
TODO_REPO/
├─ src/              # código fuente
├─ include/          # headers (si C)
├─ notebooks/        # *.ipynb (si Python)
├─ tests/            # mains de prueba o pytest
├─ assets/           # banner.svg, capturas
├─ Makefile          # si C/42
├─ requirements.txt  # si Python
└─ README.md
