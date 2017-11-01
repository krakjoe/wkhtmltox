--TEST--
wkhtmltoimage converter constructor (no options)
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php 
var_dump(new wkhtmltox\Image\Converter());
?>
--EXPECTF--
object(WKHTMLTOX\Image\Converter)#%d (0) {
}

