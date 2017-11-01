--TEST--
wkhtmltopdf converter constructor options
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(new wkhtmltox\PDF\Converter([
	"size.pageSize"  => "A4",
	"size.width"     => "210mm",
	"size.height"    => "297mm",
	"orientation"    => "Portrait", /* Landscape */
	"colorMode"      => "Color",    /* Grayscale */
	"resolution"     => "",
	"dpi"            => 80,
	"pageOffset"     => 0,
	"copies"         => 1,
	"collate"        => false,    /* true */
	"outline"        => false,    /* true */
	"outlineDepth"   => 0,
	"dumpOutline"    => false,    /* true */
	"out"            => "-",
	"documentTitle"  => "",
	"useCompression" => false,    /* true */
	"margin.top"     => 0,
	"margin.bottom"  => 0,
	"margin.left"    => 0,
	"margin.right"   => 0,
	"imageDPI"       => 80,
	"imageQuality"   => 80,
	"load.cookiejar" => ""
]));
?>
--EXPECTF--
object(WKHTMLTOX\PDF\Converter)#%d (%d) {
  ["size.pageSize"]=>
  string(2) "A4"
  ["size.width"]=>
  string(5) "210mm"
  ["size.height"]=>
  string(5) "297mm"
  ["orientation"]=>
  string(8) "Portrait"
  ["colorMode"]=>
  string(5) "Color"
  ["resolution"]=>
  string(0) ""
  ["dpi"]=>
  string(2) "80"
  ["pageOffset"]=>
  string(1) "0"
  ["copies"]=>
  string(1) "1"
  ["collate"]=>
  string(5) "false"
  ["outline"]=>
  string(5) "false"
  ["outlineDepth"]=>
  string(1) "0"
  ["dumpOutline"]=>
  string(5) "false"
  ["out"]=>
  string(1) "-"
  ["documentTitle"]=>
  string(0) ""
  ["useCompression"]=>
  string(5) "false"
  ["margin.top"]=>
  string(1) "0"
  ["margin.bottom"]=>
  string(1) "0"
  ["margin.left"]=>
  string(1) "0"
  ["margin.right"]=>
  string(1) "0"
  ["imageDPI"]=>
  string(2) "80"
  ["imageQuality"]=>
  string(2) "80"
  ["load.cookiejar"]=>
  string(0) ""
}

