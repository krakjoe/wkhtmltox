--TEST--
wkhtmltopdf converter version
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(wkhtmltox\PDF\Converter::getVersion());
?>
--EXPECTF--
string(%d) "%d.%d.%d"
