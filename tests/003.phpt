--TEST--
wkhtmltopdf converter constructor invalid option
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(new wkhtmltox\PDF\Converter([
	"foo.bar"  => "qux",
]));
?>
--EXPECTF--
Fatal error: Uncaught RuntimeException: foo.bar is not a valid global setting in %s:3
Stack trace:
#0 %s(3): WKHTMLTOX\PDF\Converter->__construct(Array)
#1 {main}
  thrown in %s on line 3


