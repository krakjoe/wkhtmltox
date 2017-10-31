wkhtmltox
========

This WIP extension wraps libwkhtmltox for PHP 7; Currently the PDF converter API is complete.

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
```

Hello World
==========

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
