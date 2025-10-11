#!/usr/bin/env python3

# To execute this code in linux, create a virtual environment and 
#make a pip install numpy matplotlib


import numpy as np
import matplotlib.pyplot as plt

# Fonction originale
def f(x):
    return 1 / (1 + 25*x**2)

# Polynômes d'approximation par série entière
def P_m(m, x):
    """Polynôme d'approximation pour l'ordre m"""
    result = np.zeros_like(x)
    for k in range(0, m//2 + 1):  # k va de 0 à m/2
        result += (-25 * x**2)**k
    return result

# Intervalle de visualisation
x = np.linspace(-0.5, 0.5, 1000)

# Valeurs de m demandées
m_values = [4, 8, 12, 20]

# Création du graphique
plt.figure(figsize=(14, 9))

# Tracer la fonction originale
plt.plot(x, f(x), 'k-', linewidth=3, label='f(x) = 1/(1+25x²)')

# Tracer les polynômes d'approximation
colors = ['red', 'blue', 'green', 'orange']
line_styles = ['--', '-.', ':', '--']
for i, m in enumerate(m_values):
    y_approx = P_m(m, x)
    plt.plot(x, y_approx, line_styles[i], color=colors[i], linewidth=2, 
             label=f'P_{m}(x) (k=0 à {m//2})')

# Marquer le rayon de convergence
plt.axvline(x=0.2, color='gray', linestyle=':', alpha=0.7, linewidth=2, 
            label='Rayon de convergence (0.2)')
plt.axvline(x=-0.2, color='gray', linestyle=':', alpha=0.7, linewidth=2)

# Zone de convergence
plt.axvspan(-0.2, 0.2, alpha=0.1, color='gray', label='Zone de convergence')

plt.xlabel('x', fontsize=12)
plt.ylabel('y', fontsize=12)
plt.title('Approximation de f(x) = 1/(1+25x²) par développement en série entière', fontsize=14)
plt.legend(fontsize=10)
plt.grid(True, alpha=0.3)
plt.ylim(-2, 4)  # Ajustement des limites pour mieux voir le comportement
plt.xlim(-0.5, 0.5)

# Ajouter un sous-graphique pour zoomer sur la zone de convergence
plt.figure(figsize=(14, 6))

plt.subplot(1, 2, 1)
# Zoom sur la zone de convergence [-0.2, 0.2]
x_zoom = np.linspace(-0.2, 0.2, 500)
plt.plot(x_zoom, f(x_zoom), 'k-', linewidth=3, label='f(x) réelle')
for i, m in enumerate(m_values):
    y_approx_zoom = P_m(m, x_zoom)
    plt.plot(x_zoom, y_approx_zoom, line_styles[i], color=colors[i], linewidth=2, 
             label=f'P_{m}(x)')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Zoom sur la zone de convergence [-0.2, 0.2]')
plt.legend()
plt.grid(True, alpha=0.3)

plt.subplot(1, 2, 2)
# Erreur d'approximation dans la zone de convergence
for i, m in enumerate(m_values):
    y_approx_zoom = P_m(m, x_zoom)
    erreur = np.abs(y_approx_zoom - f(x_zoom))
    plt.plot(x_zoom, erreur, color=colors[i], linewidth=2, label=f'Erreur P_{m}')
plt.xlabel('x')
plt.ylabel('Erreur absolue')
plt.title("Erreur d'approximation dans la zone de convergence")
plt.legend()
plt.grid(True, alpha=0.3)
plt.yscale('log')  # Échelle logarithmique pour mieux voir les variations

plt.tight_layout()
plt.show()

# Affichage des valeurs aux bords du rayon de convergence
print("Valeurs aux limites du rayon de convergence (x = ±0.2):")
print(f"f(0.2) = {f(0.2):.6f}")
for m in m_values:
    print(f"P_{m}(0.2) = {P_m(m, 0.2):.6f}")