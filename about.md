# Better Gameplay

## English

**Better Gameplay** is a performance and input enhancement mod for Geometry Dash.  
It focuses on providing a smoother and more customizable experience, especially on lower-end devices or setups with irregular refresh rates.

### What It Does

This mod replaces the original frame rendering system with a smarter method that only draws frames at a stable target rate. This can help reduce CPU and GPU load while still keeping the game logic running properly. If your phone or PC has overheating, inconsistent framerates, or performance issues, this mod may improve the experience.

### Key Features

- **FPS Bypass (Visual FPS Override)**  
  Allows you to override the game's default framerate limit. If disabled, the mod uses your screen's refresh rate. If enabled, you can manually set any FPS value you want (1 to 1,000,000).  

- **No Particles**  
  Disables particle effects like explosions, speed change particles, etc. This reduces GPU usage and can make the game run smoother on Android devices with low power.  

- **No Glow**  
  Disables glow rendering on objects. Helps reduce lag on levels with too many glowing blocks or complex visual effects.  

- **Modular Settings**  
  You can turn each option on or off independently in the mod menu. No restart required for changes to take effect.  

- **Cross-platform**  
  Fully compatible with Android, Windows, macOS, and iOS. Does not rely on platform-specific code.

### Technical Note

This mod alters how the `drawScene` method is called, improving rendering timing stability without skipping logic updates. It accumulates real delta time and draws only when a certain threshold is reached, reducing redundant draws and making the gameplay smoother.

> Be careful with high FPS values. They may cause input desync or physics glitches on levels not designed for them.

---

## Espanol

**Better Gameplay** es un mod de mejora de rendimiento y entradas para Geometry Dash.  
Esta creado para ofrecer una experiencia mas fluida y personalizable, especialmente en dispositivos de gama baja o con tasas de refresco irregulares.

### Como Funciona

Este mod reemplaza el sistema de renderizado de frames original con uno mas inteligente que solo dibuja frames cuando es necesario. Esto ayuda a reducir el uso del CPU y GPU mientras mantiene el juego funcionando correctamente. Si tu telefono o PC tiene problemas de temperatura, lag o rendimiento, este mod puede ayudarte.

### Caracteristicas Principales

- **Bypass de FPS (Override Visual)**  
  Te permite cambiar el limite de FPS del juego. Si esta desactivado, usa la tasa de refresco de tu pantalla. Si esta activado, puedes poner cualquier valor (de 1 hasta 1,000,000).  

- **Sin Particulas**  
  Desactiva efectos como explosiones o efectos de velocidad. Reduce el uso de GPU y hace el juego mas fluido en telefonos Android con poca potencia.  

- **Sin Glow**  
  Desactiva el brillo de los objetos. Mejora el rendimiento en niveles con muchos efectos visuales o bloques brillantes.  

- **Configuracion Modular**  
  Puedes activar o desactivar cada opcion desde el menu del mod. No necesitas reiniciar el juego.  

- **Multiplataforma**  
  Compatible con Android, Windows, macOS e iOS. No usa codigo especifico de una sola plataforma.

### Nota Tecnica

Este mod cambia la funcion `drawScene` para mejorar la estabilidad del renderizado. Acumula el tiempo real y solo dibuja cuando se alcanza un umbral, lo que reduce el dibujo de frames innecesarios y hace que el juego se vea mas fluido.

> Ten cuidado al usar valores muy altos de FPS. Pueden causar errores en los inputs o en la fisica de algunos niveles.

