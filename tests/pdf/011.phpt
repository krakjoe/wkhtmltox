--TEST--
wkhtmltopdf converter reading dimensions
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
$converter = new wkhtmltox\PDF\Converter([
	"out" => "test.pdf"
]);

var_dump($converter["out"]);
?>
--EXPECTF--
string(%d) "test.pdf"




