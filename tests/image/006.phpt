--TEST--
wkhtmltoimage converter no writing properties
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
$converter = new wkhtmltox\Image\Converter();

$converter->out = "fail";
?>
--EXPECTF--
Fatal error: Uncaught RuntimeException: properties are read only, manipulation after construction is not possible in %s:4
Stack trace:
#0 {main}
  thrown in %s on line 4





