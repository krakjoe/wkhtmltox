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
#ifndef HAVE_PHP_WKHTMLTOX_COMMON_H
#define HAVE_PHP_WKHTMLTOX_COMMON_H

#if PHP_VERSION_ID < 70100
#	define RETURN_VALUE_USED(opline) (!((opline)->result_type & EXT_TYPE_UNUSED))
#else
#	define RETURN_VALUE_USED(opline) ((opline)->result_type != IS_UNUSED)
#endif

typedef struct _php_wkhtmltox_setting_t {
	char *name;
	zend_long length;
} php_wkhtmltox_setting_t;

#define PHP_WKHTMLTOX_SETTING_CTOR(s)    {(s),  sizeof(s)-1},
#define PHP_WKHTMLTOX_SETTING_END 	   {NULL, 0}

#define PHP_WKHTMLTOX_SETTING_OK 0
#define PHP_WKHTMLTOX_SETTING_EX 1

static inline int php_wkhtmltox_setting_applicator(const php_wkhtmltox_setting_t *settings, zend_string *key, zval *value) {

	for (; settings && settings->name; settings++) {
		if (ZSTR_LEN(key) == settings->length) {
			if (memcmp(ZSTR_VAL(key), settings->name, settings->length) == SUCCESS) {
				return PHP_WKHTMLTOX_SETTING_OK;
			}
		}
	}

	return PHP_WKHTMLTOX_SETTING_EX;
}

#endif

