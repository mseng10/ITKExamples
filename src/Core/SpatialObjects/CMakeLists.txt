add_example(ConvertSpatialObjectToImage)
compare_to_baseline(EXAMPLE_NAME ConvertSpatialObjectToImage
  BASELINE_PREFIX OutputBaseline
  )

add_example(Ellipse)
compare_to_baseline(EXAMPLE_NAME Ellipse
  BASELINE_PREFIX OutputBaseline
  )

add_example(CreateALineSpatialObject)
compare_to_baseline(EXAMPLE_NAME CreateALineSpatialObject
  BASELINE_PREFIX OutputBaseline
  TEST_IMAGE line.png
  )

add_example(Blob)
add_example(ContourSpatialObject)
compare_to_baseline(EXAMPLE_NAME ContourSpatialObject
  BASELINE_PREFIX OutputBaseline
  TEST_IMAGE contour.png
  )