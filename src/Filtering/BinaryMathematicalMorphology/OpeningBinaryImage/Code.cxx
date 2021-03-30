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
#include "itkBinaryMorphologicalOpeningImageFilter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkBinaryBallStructuringElement.h"
#include "itkSubtractImageFilter.h"

#ifdef ENABLE_QUICKVIEW
#  include "QuickView.h"
#endif

namespace
{
using ImageType = itk::Image<unsigned char, 2>;
}

static void
CreateImage(ImageType * const image);

int
main(int argc, char * argv[])
{
  if (argc < 4)
  {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " <inputImage> <outputImage> <radius>";
    std::cerr << std::endl;
    return EXIT_FAILURE;
  }

  const char *       inputImage = argv[1];
  const char *       outputImage = argv[2];
  const unsigned int radiusValue = std::stoi(argv[3]);

  using PixelType = unsigned char;
  constexpr unsigned int Dimension = 2;

  using ImageType = itk::Image<PixelType , Dimension>;
  using ReaderType = itk::ImageFileReader<ImageType>;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(inputImage);
  reader->Update();

  std::cout << "Radius: " << radiusValue << std::endl;
  using StructuringElementType = itk::BinaryBallStructuringElement<unsigned char, 2>;
  StructuringElementType           structuringElement;
  structuringElement.SetRadius(radiusValue);
  structuringElement.CreateStructuringElement();

  using BinaryMorphologicalOpeningImageFilterType =
    itk::BinaryMorphologicalOpeningImageFilter<ImageType, ImageType, StructuringElementType>;
  BinaryMorphologicalOpeningImageFilterType::Pointer openingFilter = BinaryMorphologicalOpeningImageFilterType::New();
  openingFilter->SetInput(reader->GetOutput());
  openingFilter->SetKernel(structuringElement);
  openingFilter->Update();

  using SubtractType = itk::SubtractImageFilter<ImageType>;
  SubtractType::Pointer diff = SubtractType::New();
  diff->SetInput1(reader->GetOutput());
  diff->SetInput2(openingFilter->GetOutput());

#ifdef ENABLE_QUICKVIEW
  QuickView         viewer;
  std::stringstream desc;
  desc << "Original ";
  viewer.AddImage(image.GetPointer(), true, desc.str());

  std::stringstream desc2;
  desc2 << "BinaryOpening, radius = " << radius;
  viewer.AddImage(openingFilter->GetOutput(), true, desc2.str());

  std::stringstream desc3;
  desc3 << "Original - BinaryOpening";
  viewer.AddImage(diff->GetOutput(), true, desc3.str());
  viewer.Visualize();
#endif

  itk::WriteImage(openingFilter->GetOutput(), outputImage);

  return EXIT_SUCCESS;
}
