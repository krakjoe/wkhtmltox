--TEST--
wkhtmltoimage converter constructor options
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(new wkhtmltox\Image\Converter(null, [
	"crop.left"                 => 0,
	"crop.top"                  => 0,
	"crop.width"                => 0,
	"crop.height"               => 0,
	"load.cookieJar"            => "",
	"load.username"             => "",
	"load.password"             => "",
	"load.jsdelay"              => 0,
	"load.zoomFactor"           => 0,
	"load.customHeaders"        => false,
	"load.repertCustomHeaders"  => false,
	"load.cookies"              => false,
	"load.post"                 => false,
	"load.blockLocalFileAccess" => false,
	"load.stopSlowScript"       => false,
	"load.debugJavascript"      => false,
	"load.loadErrorHandling"    => false,
	"load.proxy"                => false,
	"load.runScript"            => "",
	"web.background"            => "",
	"web.loadImages"            => true,
	"web.enableJavascript"      => true,
	"web.enableIntelligentShrinking" => false,
	"web.minimumFontSize"       => "",
	"web.printMediaType"        => "",
	"web.defaultEncoding"       => "",
	"web.userStyleSheet"        => "",
	"web.enablePlugins"         => false,
	"transparent"               => true,
	"in"                        => "",
	"out"                       => "",
	"fmt"                       => "",
	"screenWidth"               => "",
	"smartWidth"                => "",
	"quality"                   => "",
]));
?>
--EXPECTF--
object(WKHTMLTOX\Image\Converter)#%d (0) {
}

