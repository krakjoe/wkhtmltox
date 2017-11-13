/*
 * Copyright (c) 2017 Joe Watkins
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *	notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *	notice, this list of conditions and the following disclaimer in the
 *	documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef HAVE_PHP_WKHTMLTOX_PDF_H
#define HAVE_PHP_WKHTMLTOX_PDF_H

#include "php_wkhtmltox.h"

#include <wkhtmltox/pdf.h>

PHP_MINIT_FUNCTION(wkhtmltox_pdf);
PHP_MSHUTDOWN_FUNCTION(wkhtmltox_pdf);

PHP_WKHTMLTOX_API zend_class_entry* wkhtmltox_pdf_ce;
PHP_WKHTMLTOX_API zend_class_entry* wkhtmltox_pdf_object_ce;

typedef struct _php_wkhtmltopdf_t {
	wkhtmltopdf_converter *converter;
	wkhtmltopdf_global_settings *settings;
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

