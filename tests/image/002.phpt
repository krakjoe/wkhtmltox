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
object(WKHTMLTOX\Image\Converter)#%d (%d) {
  ["crop.left"]=>
  string(1) "0"
  ["crop.top"]=>
  string(1) "0"
  ["crop.width"]=>
  string(1) "0"
  ["crop.height"]=>
  string(1) "0"
  ["load.cookieJar"]=>
  string(0) ""
  ["load.username"]=>
  string(0) ""
  ["load.password"]=>
  string(0) ""
  ["load.jsdelay"]=>
  string(1) "0"
  ["load.zoomFactor"]=>
  string(1) "0"
  ["load.customHeaders"]=>
  string(5) "false"
  ["load.repertCustomHeaders"]=>
  string(5) "false"
  ["load.cookies"]=>
  string(5) "false"
  ["load.post"]=>
  string(5) "false"
  ["load.blockLocalFileAccess"]=>
  string(5) "false"
  ["load.stopSlowScript"]=>
  string(5) "false"
  ["load.debugJavascript"]=>
  string(5) "false"
  ["load.loadErrorHandling"]=>
  string(5) "false"
  ["load.proxy"]=>
  string(5) "false"
  ["web.background"]=>
  string(0) ""
  ["web.loadImages"]=>
  string(4) "true"
  ["web.enableJavascript"]=>
  string(4) "true"
  ["web.enableIntelligentShrinking"]=>
  string(5) "false"
  ["web.minimumFontSize"]=>
  string(0) ""
  ["web.printMediaType"]=>
  string(0) ""
  ["web.defaultEncoding"]=>
  string(0) ""
  ["web.userStyleSheet"]=>
  string(0) ""
  ["web.enablePlugins"]=>
  string(5) "false"
  ["transparent"]=>
  string(4) "true"
  ["in"]=>
  string(0) ""
  ["out"]=>
  string(0) ""
  ["fmt"]=>
  string(0) ""
  ["screenWidth"]=>
  string(0) ""
  ["smartWidth"]=>
  string(0) ""
  ["quality"]=>
  string(0) ""
}


