--TEST--
wkhtmltoimage converter version
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(wkhtmltox\Image\Converter::getVersion());
?>
--EXPECT--
string(15) "NOT IMPLEMENTED"

