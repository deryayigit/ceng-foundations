# Computer Graphics  

This repository covers the **fundamentals of computer graphics**, including lighting models, intersection tests, and hardware-accelerated applications.  

---

<img width="712" height="449" alt="image" src="https://github.com/user-attachments/assets/e3c850c0-cf5c-49f3-8ba2-bbb29ea1f97d" />


## 💡 Lighting and Illumination  

- **Light Source Position**  
- **Diffuse Component**: Brightness varies depending on the angle of incidence of the light source.  
- **Specular Component**: Reflection of the light source on the object’s surface.  
- **Ambient Component**: Background light that ensures even shaded areas are illuminated.  

> **Note:** The viewpoint is usually taken as *(0,0,0)*.  

---

## 📐 Basic Mathematics  

- **Dot Product**  
- **Cross Product**  

---

## Ray Tracing  

- Pixel coordinate calculation on the image plane:  

\[
GD(X,Y,Z) = \Big(16 \cdot \frac{x}{799} - 8,\ 4.5 - \frac{y \cdot 9}{449},\ 10\Big)
\]  

- **Ray-Triangle Intersection Test**  
- **Ray-Sphere Intersection Test**  

---

## Shading Models  

- **Phong Shading Model**  
  - Diffuse Color Component  
  - Specular Color Component  
  - Ambient Color Component  

---

## Hardware and DirectX  

- **DirectX**: A hardware-accelerated API designed for high-performance applications.  
- **Primitive Topology** (point, line, triangle definitions)  
- **Object Space** (object’s own coordinate system)  

---

## Example Applications  

- Drawing a Triangle  
- Drawing a Cube  

---

## References  

- Foley, van Dam, Feiner, Hughes – *Computer Graphics: Principles and Practice*  
- Official OpenGL & DirectX documentation  
- Lecture notes  

