//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                     Loosely Coupled GPS Model Header                             //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  // 
// Author:      Parker Barrett                                                                      //
// Overview:    Header file for the Loosely Coupled GPS Model class                                 //           
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Headers
#pragma once
#include <iostream>
#include <queue>
#include <random>
#include <Eigen/Dense>
#include <Rotations.hpp>
#include <dataTypes.hpp>

// Loosely Coupled GPS Sensor Model Class
class looselyCoupledGpsSensor {

    // Public Class Members/Functions
    public:

	/* @init
            Inputs:
                gpsConfig: looselyCoupledGpsSensorSimData_t struct containing GPS model parameters
            Outputs:
            Description:
                Function which initializes the GPS sensor model.
        */
        bool init(looselyCoupledGpsSensorSimData_t gpsConfig);
        
        /* @generateGpsMeasurements
            Inputs:
	        nedTraj: nedTrajSensorSimData_t containing NED truth trajectory
            Outputs:
                gpsTov: std::queue<int64_t> FIFO queue containing GPS measurement UTC timestamps
                gpsData: std::queue<Eigen::Vector3d> FIFO queue containing GPS LLA measurements
            Description:
                Function which takes in the GPS model parameters and trajectory and generates
                a time history of measurements at the specified rate.
        */
        bool generateGpsMeasurements(nedTrajSensorSimData_t nedTraj,
			             std::queue<int64_t> &gpsTov,
				     std::queue<Eigen::Vector3d> &gpsData);

    // Private Class Members/Function
    private:

        // GPS Sensor Sim Model Parameters
	double rate_;
	double level_pos_sigma_;
	double vertical_pos_sigma_;

	// NavUtils Rotations
	Rotations rot_;
        
};
