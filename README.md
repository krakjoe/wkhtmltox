wkhtmltox
========

This extension wraps libwkhtmltox for PHP 7.

API
===

```
class wkhtmltox\PDF\Converter {
	/**
	* @param array see https://wkhtmltopdf.org/libwkhtmltox/pagesettings.html#pagePdfGlobal
	**/
	public function __construct(array $settings = []);

	public function add(wkhtmltox\PDF\Object $object);

	public function convert() : ?string;
}

class wkhtmltox\PDF\Object {
	/**
	* @param string html
	* @param array see https://wkhtmltopdf.org/libwkhtmltox/pagesettings.html#pagePdfObject
	**/
	public function __construct(string $html, array $settings = []);
}

class wkhtmltox\Image\Converter {
	/**
	* @param string html
	* @param array see https://wkhtmltopdf.org/libwkhtmltox/pagesettings.html#pageImageGlobal
	**/
	public function __construct(string $html, array $settings = []);

	public function convert() ?string;
}
```

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
