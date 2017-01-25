#!/bin/bash

#SBATCH -J STC_matmultime              	# Job name
#SBATCH -o normal_job.%j.out       		# Name of stdout output file (%j expands to jobId)
#SBATCH -p normal   	      			# Queue name
#SBATCH -N 1                  			# Total number of nodes requested
#SBATCH -n 1                            # Total number of mpi tasks requested
#SBATCH -t 00:30:00          			# Run time (hh:mm:ss) - 1.5 hours


# Launch the executables time_2000.sh and time_2048.sh
./time_2000.sh
./time_2048.sh
