# Star System Checker

This program is designed to take in a simple description of a star
system, compute initial positions and velocities for the objects,
and then run a fast n-body simulation to determine the stability
of the system.

Input files consist of a simple comma separate value of the form
<_object name_>,<_mass_>,<_semi-major axis_>[,<_eccentricity_>]

with the star first, followed by all other objects in the simulation
