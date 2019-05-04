/**
 * Simple C++ class for representing a Cube.
 * 
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

// All header (.h) files start with "#pragma once":
#pragma once

class Cube {
  // Public members:
  public:
    /**
     * Returns the volume of the cube.
     * 
     * @return
     *   Volume of the cube.
     */
    double getVolume();

    /**
     * Returns the surface area of the cube.
     * 
     * @return
     *   Surface area of the cube.
     */
    double getSurfaceArea();

    /**
     * Sets the length of the side of the cube.
     * 
     * @param length
     *   The new length of the side of the cube.
     */ 
    void setLength(double length);


  // Private members:
  private:
    double length_;  //< Length of the side of the cube.
};
