--TEST--
wkhtmltoimage converter
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
$converter = new wkhtmltox\Image\Converter("Hello World", [
	"fmt" => "png"
]);

$result = $converter->convert();

var_dump(
	$result ? strlen($result) : false);
?>
--EXPECTF--
int(%d)




