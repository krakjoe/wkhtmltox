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
object(WKHTMLTOX\PDF\Converter)#%d (0) {
}

