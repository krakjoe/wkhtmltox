--TEST--
wkhtmltopdf object construct options
--SKIPIF--
<?php if (!extension_loaded("wkhtmltox")) print "skip"; ?>
--FILE--
<?php
var_dump(new wkhtmltox\PDF\Object("Hello World", [
	"toc.useDottedLines"        => true,
	"toc.captionText"           => "caption text",
	"toc.forwardLinks"          => true,
	"toc.backLinks"             => true,
	"toc.indentation"           => 0,
	"toc.fontScale"             => 1,
	"page"                      => 1,
	"useExternalLinks"          => true,
	"useLocalLinks"             => false,
	"replacements"              => "",
	"produceForms"              => true,
	"includeInOutLine"          => true,
	"pagesCount"                => 1,
	"tocXsl"                    => "",
	"header.fontSize"           => "",
	"header.fontName"           => "",
	"header.left"               => false,
	"header.center"             => false,
	"header.right"              => false,
	"header.line"               => false,
	"header.spacing"            => 0,
	"header.htmlUrl"            => "",
	"footer.fontSize"           => "",
	"footer.fontName"           => "",
	"footer.left"               => false,
	"footer.center"             => false,
	"footer.right"              => false,
	"footer.line"               => false,
	"footer.spacing"            => 0,
	"footer.htmlUrl"            => "",
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
]));
?>
--EXPECTF--
object(WKHTMLTOX\PDF\Object)#%d (%d) {
  ["toc.useDottedLines"]=>
  string(4) "true"
  ["toc.captionText"]=>
  string(12) "caption text"
  ["toc.forwardLinks"]=>
  string(4) "true"
  ["toc.backLinks"]=>
  string(4) "true"
  ["toc.indentation"]=>
  string(1) "0"
  ["toc.fontScale"]=>
  string(1) "1"
  ["page"]=>
  string(1) "1"
  ["useExternalLinks"]=>
  string(4) "true"
  ["useLocalLinks"]=>
  string(5) "false"
  ["replacements"]=>
  string(0) ""
  ["produceForms"]=>
  string(4) "true"
  ["includeInOutLine"]=>
  string(4) "true"
  ["pagesCount"]=>
  string(1) "1"
  ["tocXsl"]=>
  string(0) ""
  ["header.fontSize"]=>
  string(0) ""
  ["header.fontName"]=>
  string(0) ""
  ["header.left"]=>
  string(5) "false"
  ["header.center"]=>
  string(5) "false"
  ["header.right"]=>
  string(5) "false"
  ["header.line"]=>
  string(5) "false"
  ["header.spacing"]=>
  string(1) "0"
  ["header.htmlUrl"]=>
  string(0) ""
  ["footer.fontSize"]=>
  string(0) ""
  ["footer.fontName"]=>
  string(0) ""
  ["footer.left"]=>
  string(5) "false"
  ["footer.center"]=>
  string(5) "false"
  ["footer.right"]=>
  string(5) "false"
  ["footer.line"]=>
  string(5) "false"
  ["footer.spacing"]=>
  string(1) "0"
  ["footer.htmlUrl"]=>
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
  ["load.runScript"]=>
  string(0) ""
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
}
