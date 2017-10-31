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
#ifndef HAVE_PHP_WKHTMLTOX_PDF_H
#define HAVE_PHP_WKHTMLTOX_PDF_H

#include "php_wkhtmltox.h"

#include <wkhtmltox/pdf.h>

PHP_MINIT_FUNCTION(wkhtmltox_pdf);

PHP_WKHTMLTOX_API zend_class_entry* wkhtmltox_pdf_ce;
PHP_WKHTMLTOX_API zend_class_entry* wkhtmltox_pdf_object_ce;

typedef struct _php_wkhtmltopdf_t {
	wkhtmltopdf_global_settings *settings;
	wkhtmltopdf_converter *converter;
	zend_object std;
} php_wkhtmltopdf_t;

#define php_wkhtmltopdf_from(object) ((php_wkhtmltopdf_t*) ((char*)object - XtOffsetOf(php_wkhtmltopdf_t, std)))
#define php_wkhtmltopdf_fetch(zend) php_wkhtmltopdf_from(Z_OBJ_P(zend))

typedef struct _php_wkhtmltopdf_object_t {
	wkhtmltopdf_object_settings *settings;
	zend_string *data;
	zend_object std;
} php_wkhtmltopdf_object_t;

#define php_wkhtmltopdf_object_from(object) ((php_wkhtmltopdf_object_t*) ((char*)object - XtOffsetOf(php_wkhtmltopdf_object_t, std)))
#define php_wkhtmltopdf_object_fetch(zend) php_wkhtmltopdf_object_from(Z_OBJ_P(zend))

#endif

