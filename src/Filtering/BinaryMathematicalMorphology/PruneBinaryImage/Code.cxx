/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkImage.h"
#include "itkBinaryPruningImageFilter.h"
#include "itkImageFileReader.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkImageFileWriter.h"

#ifdef ENABLE_QUICKVIEW
#  include "QuickView.h"
#endif

template <typename TImage>
void
CreateImage(TImage * const image);

int
main(int argc, char * argv[])
{
  if (argc < 4)
  {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " <inputImage> <outputImage> <iterations>";
    std::cerr << std::endl;
    return EXIT_FAILURE;
  }

  const char *       inputImage = argv[1];
  const char *       outputImage = argv[2];
  const unsigned int iterationValue = std::stoi(argv[3]);

  using PixelType = unsigned char;
  constexpr unsigned int Dimension = 2;

  using ImageType = itk::Image<PixelType , Dimension>;
  using ReaderType = itk::ImageFileReader<ImageType>;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(inputImage);
  reader->Update();

  std::cout << "Iterations: " << iterationValue << std::endl;

  using BinaryPruningImageFilterType = itk::BinaryPruningImageFilter<ImageType, ImageType>;
  BinaryPruningImageFilterType::Pointer pruneFilter = BinaryPruningImageFilterType::New();
  pruneFilter->SetInput(reader->GetOutput());
  pruneFilter->SetIteration(iterationValue);

#ifdef ENABLE_QUICKVIEW
  QuickView viewer;
  viewer.AddImage(image.GetPointer());
  viewer.AddImage(pruneFilter->GetOutput());
  viewer.Visualize();
#endif

  itk::WriteImage(pruneFilter->GetOutput(), outputImage);

  return EXIT_SUCCESS;
}
