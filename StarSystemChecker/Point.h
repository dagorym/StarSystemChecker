/*
 * Point.h
 *
 *  Created on: Feb 28, 2018
 *      Author: Tom Stephens
 */

#ifndef POINT_H_
#define POINT_H_

/**
 * @brief Class to hold 3D point
 *
 * @author Tom Stephens
 * @date Create: FEb 28, 2018
 */
class Point {
public:
	Point();
	Point(double x, double y, double z):m_x(x),m_y(y),m_z(z) {};
	virtual ~Point();

	double getX() const { return m_x; }
	double getY() const { return m_y; }
	double getZ() const { return m_z; }
	void setX(double x) { m_x = x; }
	void setY(double y) { m_y = y; }
	void setZ(double z) { m_z = z; }

	/**
	 * @brief Return distance to a given point
	 *
	 * This method simply computes the Cartesian distance
	 * between the object and the point provided.
	 *
	 * @author Tom Stephens
	 * @date Create: Feb 28, 2018
	 */
	double getDistance( Point p ) const;

private:
	double m_x;
	double m_y;
	double m_z;
};

#endif /* POINT_H_ */
