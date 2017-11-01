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
#ifndef HAVE_PHP_WKHTMLTOX_IMAGE_H
#define HAVE_PHP_WKHTMLTOX_IMAGE_H

#include "php_wkhtmltox.h"

#include <wkhtmltox/image.h>

PHP_MINIT_FUNCTION(wkhtmltox_image);
PHP_MSHUTDOWN_FUNCTION(wkhtmltox_image);

PHP_WKHTMLTOX_API zend_class_entry* wkhtmltox_image_ce;

typedef struct _php_wkhtmltoimage_t {
	wkhtmltoimage_converter *converter;
	wkhtmltoimage_global_settings *settings;
	HashTable *hash;
	zend_object std;
} php_wkhtmltoimage_t;

#define php_wkhtmltoimage_from(object) ((php_wkhtmltoimage_t*) ((char*)object - XtOffsetOf(php_wkhtmltoimage_t, std)))
#define php_wkhtmltoimage_fetch(zend) php_wkhtmltoimage_from(Z_OBJ_P(zend))

#endif

