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
#ifndef HAVE_PHP_WKHTMLTOX_PDF_TYPE
#define HAVE_PHP_WKHTMLTOX_PDF_TYPE

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>
#include <ext/spl/spl_exceptions.h>

#include "src/pdf.h"
#include "src/common.h"

zend_object_handlers php_wkhtmltopdf_handlers;
zend_object_handlers php_wkhtmltopdf_object_handlers;

void php_wkhtmltopdf_warn(php_wkhtmltopdf_t *w, const char *warn) {
	zend_error(E_WARNING, "%s", warn);
}

void php_wkhtmltopdf_error(php_wkhtmltopdf_t *w, const char *error) {
	zend_throw_exception_ex(spl_ce_RuntimeException, 2, "%s", error);
}

static php_wkhtmltox_setting_t php_wkhtmltopdf_global_settings[] = {
	PHP_WKHTMLTOX_SETTING_CTOR("size.pageSize")
	PHP_WKHTMLTOX_SETTING_CTOR("size.width")
	PHP_WKHTMLTOX_SETTING_CTOR("size.height")
	PHP_WKHTMLTOX_SETTING_CTOR("orientation")
	PHP_WKHTMLTOX_SETTING_CTOR("colorMode")
	PHP_WKHTMLTOX_SETTING_CTOR("resolution")
	PHP_WKHTMLTOX_SETTING_CTOR("dpi")
	PHP_WKHTMLTOX_SETTING_CTOR("pageOffset")
	PHP_WKHTMLTOX_SETTING_CTOR("copies")
	PHP_WKHTMLTOX_SETTING_CTOR("collate")
	PHP_WKHTMLTOX_SETTING_CTOR("outline")
	PHP_WKHTMLTOX_SETTING_CTOR("outlineDepth")
	PHP_WKHTMLTOX_SETTING_CTOR("dumpOutline")
	PHP_WKHTMLTOX_SETTING_CTOR("out")
	PHP_WKHTMLTOX_SETTING_CTOR("documentTitle")
	PHP_WKHTMLTOX_SETTING_CTOR("useCompression")
	PHP_WKHTMLTOX_SETTING_CTOR("margin.top")
	PHP_WKHTMLTOX_SETTING_CTOR("margin.bottom")
	PHP_WKHTMLTOX_SETTING_CTOR("margin.left")
	PHP_WKHTMLTOX_SETTING_CTOR("margin.right")
	PHP_WKHTMLTOX_SETTING_CTOR("imageDPI")
	PHP_WKHTMLTOX_SETTING_CTOR("imageQuality")
	PHP_WKHTMLTOX_SETTING_CTOR("load.cookiejar")
	PHP_WKHTMLTOX_SETTING_END
};

static php_wkhtmltox_setting_t php_wkhtmltopdf_object_settings[] = {
	PHP_WKHTMLTOX_SETTING_CTOR("toc.useDottedLines")
	PHP_WKHTMLTOX_SETTING_CTOR("toc.captionText")
	PHP_WKHTMLTOX_SETTING_CTOR("toc.forwardLinks")
	PHP_WKHTMLTOX_SETTING_CTOR("toc.backLinks")
	PHP_WKHTMLTOX_SETTING_CTOR("toc.indentation")
	PHP_WKHTMLTOX_SETTING_CTOR("toc.fontScale")
	PHP_WKHTMLTOX_SETTING_CTOR("page")
	PHP_WKHTMLTOX_SETTING_CTOR("useExternalLinks")
	PHP_WKHTMLTOX_SETTING_CTOR("useLocalLinks")
	PHP_WKHTMLTOX_SETTING_CTOR("replacements")
	PHP_WKHTMLTOX_SETTING_CTOR("produceForms")
	PHP_WKHTMLTOX_SETTING_CTOR("includeInOutLine")
	PHP_WKHTMLTOX_SETTING_CTOR("pagesCount")
	PHP_WKHTMLTOX_SETTING_CTOR("tocXsl")
	PHP_WKHTMLTOX_SETTING_CTOR("header.fontSize")
	PHP_WKHTMLTOX_SETTING_CTOR("header.fontName")
	PHP_WKHTMLTOX_SETTING_CTOR("header.left")
	PHP_WKHTMLTOX_SETTING_CTOR("header.center")
	PHP_WKHTMLTOX_SETTING_CTOR("header.right")
	PHP_WKHTMLTOX_SETTING_CTOR("header.line")
	PHP_WKHTMLTOX_SETTING_CTOR("header.spacing")
	PHP_WKHTMLTOX_SETTING_CTOR("header.htmlUrl")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.fontSize")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.fontName")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.left")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.center")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.right")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.line")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.spacing")
	PHP_WKHTMLTOX_SETTING_CTOR("footer.htmlUrl")
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
	PHP_WKHTMLTOX_SETTING_END
};

zend_object* php_wkhtmltopdf_create(zend_class_entry *ce) {
	php_wkhtmltopdf_t *w = (php_wkhtmltopdf_t*) ecalloc(1,
		sizeof(php_wkhtmltopdf_t) + zend_object_properties_size(ce));

	zend_object_std_init(&w->std, ce);
	object_properties_init(&w->std, ce);

	w->std.handlers = &php_wkhtmltopdf_handlers;

	w->settings = wkhtmltopdf_create_global_settings();	

	return &w->std;
}

void php_wkhtmltopdf_destroy(zend_object *o) {
	php_wkhtmltopdf_t *w = php_wkhtmltopdf_from(o);

	wkhtmltopdf_destroy_global_settings(w->settings);

	if (w->converter) {
		wkhtmltopdf_destroy_converter(w->converter);
	}

	zend_object_std_dtor(&w->std);
}

zend_object* php_wkhtmltopdf_object_create(zend_class_entry *ce) {
	php_wkhtmltopdf_object_t *w = (php_wkhtmltopdf_object_t*) ecalloc(1,
		sizeof(php_wkhtmltopdf_object_t) + zend_object_properties_size(ce));

	zend_object_std_init(&w->std, ce);
	object_properties_init(&w->std, ce);

	w->std.handlers = &php_wkhtmltopdf_object_handlers;	

	w->settings = wkhtmltopdf_create_object_settings();	

	return &w->std;
}

void php_wkhtmltopdf_object_destroy(zend_object *o) {
	php_wkhtmltopdf_object_t *w = php_wkhtmltopdf_object_from(o);

	wkhtmltopdf_destroy_object_settings(w->settings);

	if (w->data) {
		zend_string_release(w->data);
	}

	zend_object_std_dtor(&w->std);
}

/* {{{ */
PHP_METHOD(PDF, __construct) 
{
	php_wkhtmltopdf_t *w = php_wkhtmltopdf_fetch(getThis());
	HashTable *settings = NULL;
	zend_string *key = NULL;
	zval *value = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "|H", &settings) != SUCCESS) {
		return;
	}

	if (settings) {
		ZEND_HASH_FOREACH_STR_KEY_VAL(settings, key, value) {
			if (php_wkhtmltox_setting_applicator(php_wkhtmltopdf_global_settings, key, value) == PHP_WKHTMLTOX_SETTING_OK) {
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

				wkhtmltopdf_set_global_setting(w->settings, ZSTR_VAL(key), Z_STRVAL_P(value));

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

	w->converter = wkhtmltopdf_create_converter(w->settings);

	wkhtmltopdf_set_warning_callback(w->converter, (wkhtmltopdf_str_callback) php_wkhtmltopdf_warn);
	wkhtmltopdf_set_error_callback(w->converter, (wkhtmltopdf_str_callback) php_wkhtmltopdf_error);
} /* }}} */

/* {{{ */
PHP_METHOD(PDF, add)
{
	php_wkhtmltopdf_t *w = php_wkhtmltopdf_fetch(getThis());
	php_wkhtmltopdf_object_t *o = NULL;
	zval *zv = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "O", &zv, wkhtmltox_pdf_object_ce) != SUCCESS) {
		return;
	}

	o = php_wkhtmltopdf_object_fetch(zv);

	wkhtmltopdf_add_object(w->converter, o->settings, o->data ? ZSTR_VAL(o->data) : NULL);
} /* }}} */

/* {{{ */
PHP_METHOD(PDF, convert)
{
	php_wkhtmltopdf_t *w = php_wkhtmltopdf_fetch(getThis());

	if (zend_parse_parameters_none() != SUCCESS) {
		return;
	}

	wkhtmltopdf_convert(w->converter);

	if (RETURN_VALUE_USED(EX(prev_execute_data)->opline)) {
		const unsigned char *buff = NULL;
		size_t len = wkhtmltopdf_get_output(w->converter, &buff);

		if (len) {
			RETURN_STRINGL(buff, len);
		}
	}
} /* }}} */

ZEND_BEGIN_ARG_INFO_EX(php_wkhtmltopdf_converter_construct_arginfo, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, settings, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(php_wkhtmltopdf_converter_add_arginfo, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, object, wkhtmltox\\PDF\\Object, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(php_wkhtmltopdf_converter_convert_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

zend_function_entry php_wkhtmltopdf_methods[] = {
	PHP_ME(PDF, __construct, php_wkhtmltopdf_converter_construct_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(PDF, add, php_wkhtmltopdf_converter_add_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(PDF, convert, php_wkhtmltopdf_converter_convert_arginfo, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

/* {{{ */
PHP_METHOD(Object, __construct)
{
	php_wkhtmltopdf_object_t *w = php_wkhtmltopdf_object_fetch(getThis());
	zend_string *data = NULL;
	HashTable *settings = NULL;
	zend_string *key = NULL;
	zval *value = NULL;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "S|H", &data, &settings) != SUCCESS) {
		return;
	}

	if (settings) {
		ZEND_HASH_FOREACH_STR_KEY_VAL(settings, key, value) {
			if (php_wkhtmltox_setting_applicator(php_wkhtmltopdf_object_settings, key, value) == PHP_WKHTMLTOX_SETTING_OK) {
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

				wkhtmltopdf_set_object_setting(w->settings, ZSTR_VAL(key), Z_STRVAL_P(value));

				if (!Z_ISUNDEF(tmp)) {
					zval_ptr_dtor(&tmp);
				}
			} else {
				zend_throw_exception_ex(spl_ce_RuntimeException, 
					PHP_WKHTMLTOX_SETTING_EX, "%s is not a valid object setting", ZSTR_VAL(key));
				return;
			}
		} ZEND_HASH_FOREACH_END();
	}

	w->data = zend_string_copy(data);
} /* }}} */

ZEND_BEGIN_ARG_INFO_EX(php_wkhtmltopdf_object_construct_arginfo, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, settings, 1)
ZEND_END_ARG_INFO()

zend_function_entry php_wkhtmltopdf_object_methods[] = {
	PHP_ME(Object, __construct, php_wkhtmltopdf_object_construct_arginfo, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_MINIT_FUNCTION(wkhtmltox_pdf)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, "WKHTMLTOX\\PDF", "Converter", php_wkhtmltopdf_methods);

    wkhtmltox_pdf_ce = zend_register_internal_class(&ce);
	wkhtmltox_pdf_ce->create_object = php_wkhtmltopdf_create;

	memcpy(&php_wkhtmltopdf_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));

	php_wkhtmltopdf_handlers.offset = XtOffsetOf(php_wkhtmltopdf_t, std);
	php_wkhtmltopdf_handlers.free_obj = php_wkhtmltopdf_destroy;

	INIT_NS_CLASS_ENTRY(ce, "WKHTMLTOX\\PDF", "Object", php_wkhtmltopdf_object_methods);
	
	wkhtmltox_pdf_object_ce = zend_register_internal_class(&ce);
	wkhtmltox_pdf_object_ce->create_object = php_wkhtmltopdf_object_create;

	memcpy(&php_wkhtmltopdf_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));	

	php_wkhtmltopdf_object_handlers.offset = XtOffsetOf(php_wkhtmltopdf_object_t, std);
	php_wkhtmltopdf_object_handlers.free_obj = php_wkhtmltopdf_object_destroy;

	wkhtmltopdf_init(0);
}

PHP_MSHUTDOWN_FUNCTION(wkhtmltox_pdf)
{
	wkhtmltopdf_deinit();
}
#endif
