# Chromatography
* resolution dependencies
    - flow rate, column width, plate height, etc.

### Asymmetric Bandshapes
* ideally, $K = \frac{1[S]~stationary~}{1[S]~mobile~}$ (gaussian distribution)
* but...
    - overloading
    - tailing: H-bonding of analyte to column

## EXAM II
* know equations - van Deemter Equation
    $H = A + \frac{B}{u_x} + Cu_x$
* graph of height of theoretical plate vs. mobile phase velocity
* know class excercise
* convert base width to width at half mast

## Gas Chromatography vs Liquid
* mobile phase = gas | liquid
* analyte = volatile | soluble (peptides, proteins in life sciences)
* optimize mobile phase = temperature | solvent composition/mixtures
* GC is cheaper and less messy, less expensive
* disadvantages in LC outweigh those in GC

#### mobile phase   
* inert gas: H~2~, He, N~2~, Ar   
* longer retention time = broader peak

#### analyte  
* volatile  
* must have some affinity with stationary phase

#### stationary phase  
* liquid or solid, polarity adjusted by functional groups  
    - solid: adsorption chromatography
    - liquid: partition chromatography (preferred)
* low volatility
* thermal stability
* chemical inertness
* reasonable k values based on solute identity
* compatibility (affinity b/w stationary phase and different analytes to get
  separation)
* polysiloxanes = popular choice

## Column Type
open tubular        packed
-----------         ------
A=0 (good)          A>0
B doesn't care      B doesn't care
big C               small C (good)

### GC open tubular types
* wall coated
* support coated
* porous layer
* factors:
    - column diameter, length
    - thickness of stationary phase

### GC injection types
* split (most common)
    - analytes > 0.1% sample
    - bad for quantitation
    - 350 degrees C
* splitless
    - low concentration / trace analysis
    - 220 degrees C
* on-column
    - samples that decompose w/ high T

## Detector
* LOD is important
* linear detection for quantitative analysis

### Thermal conductivity detector
* He as mobile phase
* analyte addition lowers thermal conductivity of He
* analyte + He eludes -> filament gets hotter -> voltage changes in resistor

### Flame ionization detector
* hydrocarbons in eluate burned w/ H~2~ and air
* CH+ radicals produced
* presence of e- produces detectable *current*

### Electron capture
* detected current decreases upon passing of compound that captures e-

### Mass spectrometry
* $\frac{mass_of_molucules}{charge}$ ratio
* coupled to e- impact ionization
    - M + e- -> M+ + 2e-
* e- impact creates fragments
* measures isotopes, fragments - very specific

## external vs internal standards


# Liquid Chromatography
* volatility of stationary and mobile phases
* slow diffusion coefficients
* large travel distance to get to stationary phase
    - packed column used
    - small beads to minimize "A" and "C" terms
    - smaller beads -> smaller plate size
    - require higher pressure

### Column Pressure
* linearly prop to flow rate
* inversely prop to particle diameter

### Column
* degraded by dust/particles
    - centrifuge/filter sample
* guard columns
* heating
* length (shorter than GC)
* diameter
* small particle size/narrow column = higher sensitivity

### Stationary phase
* silica particles common
* partition vs adsorption 
* polarity is important for functional groups on silica particle

### Mobile phase
* unlike GC, must consider mobile phase in LC
* attraction/displacement of solute vs. stationary phase
* strong solvent = good at displacing solute from stationary phase, similar to
  stationary phase

### Normal vs Reverse Phase LC
Column property determins normal vs reverse phase operation
Normal                                      Reverse
-----------                                 ----------------
polar stationary phase, nonpolar solvent    nonpolar stationary phase (C~18~)
but still somewhat polar                    more commonly used in HPLC

### Reverse phase
* increasing aqueous of solvent will increase run time of reverse phase
* polar compounds will elute first
* use gradient solvent for elution

### Designing & Optimizing HPLC experiment
* good resolution and separation for quantitation (well resolved peaks)
* reasonable run time  

* Attributes of a good separation
    - Retention Factor: 0.5 < k < 20
    - Resolution = 1.5 b/w closest peaks
    - Operating pressure: <15 Mps (150 bar)
    - Symmetric peaks
    - good baseline

* optimizing solvent system 
    - using a solvent triangle
    - designing a gradient

### HPLC Detectors
* Refractive Index Sensing
    - not specific, low sensitivity, not good for gradient elutions

* UV Absorption
    - universal (detects a lot of molecules), good sensitivity, can be used for
      quantification, good for gradient elution
    - mobile phase can interfere when using low wavelengths

* Fluorescence
    - high sensitivity, gradient elution 
    - not universal (only certain molecules fluorese)
    - derivitizing sample?

* Mass Spectrometry
    - LC coupled with ElectroSpray ionization
    - good selectivity, compatible with gradient elution
    - salts in buffers interfere
    - need compatible flow rates

* choosing detector systems:
    - LOD and LOQ
    - using a decision tree

# Equilibrium
* quasi-equilibrium 

# EXAM II
* Ch 22, 23, 24
* Extractions
* Theoretical Plates
