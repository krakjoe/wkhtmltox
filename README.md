wkhtmltox
========

[![Build Status](https://travis-ci.org/krakjoe/wkhtmltox.svg?branch=master)](https://travis-ci.org/krakjoe/wkhtmltox)
[![Build status](https://ci.appveyor.com/api/projects/status/vejunb25q1p9q5um?svg=true)](https://ci.appveyor.com/project/krakjoe/wkhtmltox/branch/master)


This extension wraps libwkhtmltox for PHP 7.

Documentation
============

Documentation can be found in the [PHP Manual](http://docs.php.net/wkhtmltox)

Hello World (PDF)
===============

```
use wkhtmltox\PDF\Converter as PDFConverter;
use wkhtmltox\PDF\Object as PDFObject;

$converter = new PDFConverter([
	"out" => "test.pdf"
]);

$converter->add(new PDFObject(
	file_get_contents("http://www.google.co.uk")));

$converter->convert();
```

Hello World (Image)
=================

```
use wkhtmltox\Image\Converter as ImageConverter;

$converter = new ImageConverter(null, [
	"fmt" => "png",
	"in" => "https://www.google.co.uk",
	"out" => "test.png"
]);

$converter->convert();
```

Notes
=====

  * Warnings from libwkhtmltox raise ZE warnings
  * Errors from libwkhtmltox raise ZE exceptions (RuntimeException)
  * Settings are accessible read only as properties or dimensions after construction
  * It is not possible to change settings after object construction
  * Validation of the possible values for settings is not good

