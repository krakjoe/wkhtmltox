--TEST--
wkhtmltopdf object construct options
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(new wkhtmltox\PDF\Object("Hello World", [
	"foo.bar" => "qux"
]));
?>
--EXPECTF--
Fatal error: Uncaught RuntimeException: foo.bar is not a valid object setting in %s:3
Stack trace:
#0 %s(3): WKHTMLTOX\PDF\Object->__construct('Hello World', Array)
#1 {main}
  thrown in %s on line 3




