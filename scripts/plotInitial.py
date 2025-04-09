import matplotlib.pyplot as plt
import numpy as np


def plot_particles_as_spheres(positions):
   
   
    # Prepare figure
    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')

    # Create a parameterized sphere of resolution 'res'
    res = 20
    u = np.linspace(0, 2*np.pi, res)
    v = np.linspace(0, np.pi, res)
    
    # For each particle, draw a sphere
    for (cx, cy, cz)in positions:
        # Parametric equations for a sphere of radius r:
        x = cx + 0.01*np.outer(np.cos(u), np.sin(v))
        y = cy + 0.01*np.outer(np.sin(u), np.sin(v))
        z = cz + 0.01*np.outer(np.ones_like(u), np.cos(v))

        # Plot the surface
        ax.plot_surface(x, y, z, alpha=0.4)  # alpha for slight transparency

    # Give the plot equal aspect so spheres look spherical
    max_range = (positions.max(axis=0) - positions.min(axis=0)).max()
    mid = positions.mean(axis=0)
    ax.set_xlim(mid[0] - max_range/2, mid[0] + max_range/2)
    ax.set_ylim(mid[1] - max_range/2, mid[1] + max_range/2)
    ax.set_zlim(mid[2] - max_range/2, mid[2] + max_range/2)

    plt.show()

positions = np.loadtxt("out.txt")

plot_particles_as_spheres(positions)
