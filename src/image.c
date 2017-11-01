/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: krakjoe                                                      |
  +----------------------------------------------------------------------+
*/
#ifndef HAVE_PHP_WKHTMLTOX_IMAGE_TYPE
#define HAVE_PHP_WKHTMLTOX_IMAGE_TYPE

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>
#include <ext/spl/spl_exceptions.h>

#include "src/image.h"
#include "src/common.h"

zend_object_handlers php_wkhtmltoimage_handlers;

void php_wkhtmltoimage_warn(php_wkhtmltoimage_t *w, const char *warn) {
	zend_error(E_WARNING, "%s", warn);
}

void php_wkhtmltoimage_error(php_wkhtmltoimage_t *w, const char *error) {
	zend_throw_exception_ex(spl_ce_RuntimeException, 2, "%s", error);
}

static php_wkhtmltox_setting_t php_wkhtmltoimage_global_settings[] = {
	PHP_WKHTMLTOX_SETTING_CTOR("crop.left")
	PHP_WKHTMLTOX_SETTING_CTOR("crop.top")
	PHP_WKHTMLTOX_SETTING_CTOR("crop.width")
	PHP_WKHTMLTOX_SETTING_CTOR("crop.height")
	PHP_WKHTMLTOX_SETTING_CTOR("load.cookieJar")
	PHP_WKHTMLTOX_SETTING_CTOR("load.username")
	PHP_WKHTMLTOX_SETTING_CTOR("load.password")
	PHP_WKHTMLTOX_SETTING_CTOR("load.jsdelay")
	PHP_WKHTMLTOX_SETTING_CTOR("load.zoomFactor")
	PHP_WKHTMLTOX_SETTING_CTOR("load.customHeaders")
	PHP_WKHTMLTOX_SETTING_CTOR("load.repertCustomHeaders")
	PHP_WKHTMLTOX_SETTING_CTOR("load.cookies")
	PHP_WKHTMLTOX_SETTING_CTOR("load.post")
	PHP_WKHTMLTOX_SETTING_CTOR("load.blockLocalFileAccess")
	PHP_WKHTMLTOX_SETTING_CTOR("load.stopSlowScript")
	PHP_WKHTMLTOX_SETTING_CTOR("load.debugJavascript")
	PHP_WKHTMLTOX_SETTING_CTOR("load.loadErrorHandling")
	PHP_WKHTMLTOX_SETTING_CTOR("load.proxy")
	PHP_WKHTMLTOX_SETTING_CTOR("load.runScript")
	PHP_WKHTMLTOX_SETTING_CTOR("web.background")
	PHP_WKHTMLTOX_SETTING_CTOR("web.loadImages")
	PHP_WKHTMLTOX_SETTING_CTOR("web.enableJavascript")
	PHP_WKHTMLTOX_SETTING_CTOR("web.enableIntelligentShrinking")
	PHP_WKHTMLTOX_SETTING_CTOR("web.minimumFontSize")
	PHP_WKHTMLTOX_SETTING_CTOR("web.printMediaType")
	PHP_WKHTMLTOX_SETTING_CTOR("web.defaultEncoding")
	PHP_WKHTMLTOX_SETTING_CTOR("web.userStyleSheet")
	PHP_WKHTMLTOX_SETTING_CTOR("web.enablePlugins")
	PHP_WKHTMLTOX_SETTING_CTOR("transparent")
	PHP_WKHTMLTOX_SETTING_CTOR("in")
	PHP_WKHTMLTOX_SETTING_CTOR("out")
	PHP_WKHTMLTOX_SETTING_CTOR("fmt")
	PHP_WKHTMLTOX_SETTING_CTOR("screenWidth")
	PHP_WKHTMLTOX_SETTING_CTOR("smartWidth")
	PHP_WKHTMLTOX_SETTING_CTOR("quality")
	PHP_WKHTMLTOX_SETTING_END
};

zend_object* php_wkhtmltoimage_create(zend_class_entry *ce) {
	php_wkhtmltoimage_t *w = (php_wkhtmltoimage_t*) ecalloc(1,
		sizeof(php_wkhtmltoimage_t) + zend_object_properties_size(ce));

	zend_object_std_init(&w->std, ce);
	object_properties_init(&w->std, ce);

	w->std.handlers = &php_wkhtmltoimage_handlers;

	w->settings = wkhtmltoimage_create_global_settings();	

	return &w->std;
}

void php_wkhtmltoimage_destroy(zend_object *o) {
	php_wkhtmltoimage_t *w = php_wkhtmltoimage_from(o);

	if (w->converter) {
		wkhtmltoimage_destroy_converter(w->converter);
	}

	zend_object_std_dtor(&w->std);
}

/* {{{ */
PHP_METHOD(Image, __construct) 
{
	php_wkhtmltoimage_t *w = php_wkhtmltoimage_fetch(getThis());
	zend_string *buffer = NULL;
	HashTable *settings = NULL;
	zend_string *key = NULL;
	zval *value = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|SH", &buffer, &settings) != SUCCESS) {
		return;
	}

	if (settings) {
		ZEND_HASH_FOREACH_STR_KEY_VAL(settings, key, value) {
			if (php_wkhtmltox_setting_applicator(php_wkhtmltoimage_global_settings, key, value) == PHP_WKHTMLTOX_SETTING_OK) {
				zval tmp;

				ZVAL_UNDEF(&tmp);

				if (Z_TYPE_P(value) != IS_STRING) {
					ZVAL_COPY(&tmp, value);

					if (Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE) {
						if (Z_TYPE_P(value) == IS_TRUE) {
							ZVAL_STRING(&tmp, "true");
						} else ZVAL_STRING(&tmp, "false");
					} else {
						convert_to_string(&tmp);
					}

					value = &tmp;
				}

				wkhtmltoimage_set_global_setting(w->settings, ZSTR_VAL(key), Z_STRVAL_P(value));

				if (!Z_ISUNDEF(tmp)) {
					zval_ptr_dtor(&tmp);
				}
			} else {
				zend_throw_exception_ex(spl_ce_RuntimeException, 
					PHP_WKHTMLTOX_SETTING_EX, "%s is not a valid global setting", ZSTR_VAL(key));
				return;
			}
		} ZEND_HASH_FOREACH_END();
	}

	w->converter = wkhtmltoimage_create_converter(w->settings, buffer ? ZSTR_VAL(buffer) : NULL);

	wkhtmltoimage_set_warning_callback(w->converter, (wkhtmltoimage_str_callback) php_wkhtmltoimage_warn);
	wkhtmltoimage_set_error_callback(w->converter, (wkhtmltoimage_str_callback) php_wkhtmltoimage_error);
} /* }}} */

/* {{{ */
PHP_METHOD(Image, convert)
{
	php_wkhtmltoimage_t *w = php_wkhtmltoimage_fetch(getThis());

	if (zend_parse_parameters_none() != SUCCESS) {
		return;
	}

	wkhtmltoimage_convert(w->converter);

	if (RETURN_VALUE_USED(EX(prev_execute_data)->opline)) {
		const unsigned char *buff = NULL;
		size_t len = wkhtmltoimage_get_output(w->converter, &buff);

		if (len) {
			RETURN_STRINGL(buff, len);
		}
	}
} /* }}} */

ZEND_BEGIN_ARG_INFO_EX(php_wkhtmltoimage_converter_construct_arginfo, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_STRING, 1)
	ZEND_ARG_ARRAY_INFO(0, settings, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(php_wkhtmltoimage_converter_convert_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

zend_function_entry php_wkhtmltoimage_methods[] = {
	PHP_ME(Image, __construct, php_wkhtmltoimage_converter_construct_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(Image, convert, php_wkhtmltoimage_converter_convert_arginfo, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(wkhtmltox_image)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "WKHTMLTOX\\Image", "Converter", php_wkhtmltoimage_methods);

    wkhtmltox_image_ce = zend_register_internal_class(&ce);
	wkhtmltox_image_ce->create_object = php_wkhtmltoimage_create;

	memcpy(&php_wkhtmltoimage_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

	php_wkhtmltoimage_handlers.offset = XtOffsetOf(php_wkhtmltoimage_t, std);
	php_wkhtmltoimage_handlers.free_obj = php_wkhtmltoimage_destroy;

	wkhtmltoimage_init(0);
}

PHP_MSHUTDOWN_FUNCTION(wkhtmltox_image)
{
	wkhtmltoimage_deinit();
}
#endif

