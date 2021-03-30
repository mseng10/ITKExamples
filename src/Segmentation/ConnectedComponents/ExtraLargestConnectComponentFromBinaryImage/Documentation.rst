Extra Largest Connect Component From Binary Image
=================================================

.. index::
   single: ConnectedComponentImageFilter
   pair: binary; image

Synopsis
--------

Extract the largest connected component from a Binary Image.


Results
-------
.. figure:: Yinyang.png
  :scale: 70%
  :alt: input image

  Input image.

.. figure:: OutputBaseline.png
  :scale: 70%
  :alt: output image

  Output image.

Output::

  Number of objects: 3


Code
----

C++
...

.. literalinclude:: Code.cxx
   :lines: 18-

Classes demonstrated
--------------------

.. breathelink:: itk::ConnectedComponentImageFilter
