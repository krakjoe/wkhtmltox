--TEST--
wkhtmltopdf converter
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
<?php if (false !== getenv("APPVEYOR")) print "skip"; ?>
--FILE--
<?php
$converter = new wkhtmltox\PDF\Converter();

$converter->add(new wkhtmltox\PDF\Object("Hello World"));

$result = $converter->convert();

var_dump(
	$result ? strlen($result) : false);
?>
--EXPECTF--
int(%d)




