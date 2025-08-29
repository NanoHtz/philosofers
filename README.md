<!-- ===================== BANNER ===================== -->
<p align="center">
  <img src="assets/banner.svg" alt="Banner de TODO_TITULO" width="100%" />
</p>

<p align="center"><i>🧠 Philosophers (42 Cursus) — Solución al clásico "Dining Philosophers Problem" con threads y mutexes, evitando deadlocks race conditions y starvation.</i></p>

---

## Índice
- [Resumen](#resumen)
- [Capturas / Demo](#capturas--demo)
- [Stack / Dependencias](#stack--dependencias)
- [Estructura](#estructura)
- [Instalación y uso](#instalación-y-uso)
- [Tests](#tests)
---

✅ Resumen del proyecto<br>
Philosophers simula a N filósofos sentados alrededor de una mesa. Cada filósofo alterna entre pensar, comer y dormir. Para comer, necesita dos tenedores (izquierdo y derecho). Los tenedores son recursos compartidos, modelados con mutexes. El objetivo es que la simulación no entre en deadlock (todos esperando indefinidamente), evite starvation (nadie se queda sin comer indefinidamente), y mantenga la precisión de tiempos dada por los parámetros.

Para qué<br>
** Que se aprende ??
** Que valor aporta??
<br>
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
