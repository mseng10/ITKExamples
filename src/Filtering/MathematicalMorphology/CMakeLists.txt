add_example( CreateABinaryBallStructuringElement )

add_example( DilateAGrayscaleImage )
compare_to_baseline( EXAMPLE_NAME DilateAGrayscaleImage BASELINE_PREFIX OutputBaseline )

add_example( ErodeAGrayscaleImage )
compare_to_baseline( EXAMPLE_NAME ErodeAGrayscaleImage BASELINE_PREFIX OutputBaseline )

add_example(RegionalMinimal)
compare_to_baseline(EXAMPLE_NAME RegionalMinimal
  BASELINE_PREFIX OutputBaseline
  )

add_example(RegionalMaximal)
compare_to_baseline(EXAMPLE_NAME RegionalMaximal
  BASELINE_PREFIX intensityblobs maximal
  )

add_example(ValuedRegionalMaximaImage)
compare_to_baseline(EXAMPLE_NAME ValuedRegionalMaximaImage
        TEST_NAME ValuedRegionalMaximaImageIntensityBlobsOutputBaseline
        BASELINE_PREFIX IntensityBlobsOutputBaseline
        TEST_IMAGE intensityblobs.png
  )
compare_to_baseline(EXAMPLE_NAME ValuedRegionalMaximaImage
        TEST_NAME ValuedRegionalMaximaImageMaximalOutputBaseline
        BASELINE_PREFIX MaximalOutputBaseline
        TEST_IMAGE maximal.png
        )

add_example(ValuedRegionalMinimalImage)
compare_to_baseline(EXAMPLE_NAME ValuedRegionalMinimalImage
  BASELINE_PREFIX OutputBaseline
  )

add_example(GenerateStructureElementsWithAccurateArea)

add_example(ErodeBinaryImageUsingFlatStruct)
compare_to_baseline(EXAMPLE_NAME ErodeBinaryImageUsingFlatStruct
        BASELINE_PREFIX ErodeBinaryImageUsingFlatStruct
        )
