--TEST--
wkhtmltopdf object construct
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(new wkhtmltox\PDF\Object("Hello World", [

]));
?>
--EXPECTF--
object(WKHTMLTOX\PDF\Object)#%d (0) {
}



