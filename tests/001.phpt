--TEST--
wkhtmltopdf converter constructor (no options)
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php 
var_dump(new wkhtmltox\PDF\Converter());
?>
--EXPECTF--
object(WKHTMLTOX\PDF\Converter)#%d (0) {
}

