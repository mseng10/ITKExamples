add_example( CastAnImageToAnotherType )
compare_to_baseline( EXAMPLE_NAME CastAnImageToAnotherType
  BASELINE_PREFIX OutputBaseline
  )

add_example(ApplyKernelToEveryPixel)
compare_to_baseline(EXAMPLE_NAME ApplyKernelToEveryPixel
  BASELINE_PREFIX OutputBaseline
  )

add_example(ApplyKernelToEveryPixelInNonZeroImage)
compare_to_baseline(EXAMPLE_NAME ApplyKernelToEveryPixelInNonZeroImage
  BASELINE_PREFIX OutputBaseline
  )

add_example(CustomOperationToCorrespondingPixelsInTwoImages)

add_example(ComputeLocalNoise)
compare_to_baseline(EXAMPLE_NAME ComputeLocalNoise
  BASELINE_PREFIX OutputBaseline
  TEST_IMAGE output.mhd
  )

# TODO Fix example for clean build
add_example(PredefinedOperationToCorrespondingPixelsInTwoImages)
