if(VTK_DIR)
add_example(ClusterPixelsInGrayscaleImage)
compare_to_baseline(EXAMPLE_NAME ClusterPixelsInGrayscaleImage
  BASELINE_PREFIX ClusterPixelsInGrayscaleImage
  )
endif()
# TODO: Fix build examples for examples
#add_example(KMeansClusterOfPixelsInImage)
#compare_to_baseline(EXAMPLE_NAME KMeansClusterOfPixelsInImage
#  BASELINE_PREFIX OutputBaseline
#  )

#add_example(KMeansClustering)
#compare_to_baseline(EXAMPLE_NAME KMeansClustering
#  BASELINE_PREFIX OutputBaseline
#  )
#===========================================