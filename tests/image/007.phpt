--TEST--
wkhtmltoimage converter reading dimensions
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
$converter = new wkhtmltox\Image\Converter(null, [
	"out" => "test.png"
]);

var_dump($converter["out"]);
?>
--EXPECTF--
string(%d) "test.png"




