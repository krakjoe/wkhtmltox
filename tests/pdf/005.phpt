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
object(WKHTMLTOX\PDF\Object)#%d (0) {
}



