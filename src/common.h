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

static inline void php_wkhtmltox_disallowed(zval *object, zval *member, zval *value) {
	zend_throw_exception_ex(spl_ce_RuntimeException, 4, 
		"properties are read only, manipulation after construction is not possible");
}
#endif

