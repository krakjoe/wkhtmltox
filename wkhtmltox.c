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

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_wkhtmltox.h"

#include "src/pdf.h"
#include "src/image.h"

ZEND_DECLARE_MODULE_GLOBALS(wkhtmltox);

/* {{{ */
PHP_INI_BEGIN()
	STD_PHP_INI_ENTRY("wkhtmltox.graphics", "0", PHP_INI_SYSTEM | PHP_INI_PERDIR, OnUpdateBool, graphics, zend_wkhtmltox_globals, wkhtmltox_globals)
PHP_INI_END() 
/* }}} */

/* {{{ */
static void php_wkhtmltox_globals_ctor(zend_wkhtmltox_globals *wg) {
	memset(wg, 0, sizeof(zend_wkhtmltox_globals));
} /* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(wkhtmltox)
{
	ZEND_INIT_MODULE_GLOBALS(wkhtmltox, php_wkhtmltox_globals_ctor, NULL)

	if (!wkhtmltopdf_extended_qt()) {
		zend_error(
			E_WARNING,
			"wkhtmltox extension has been compiled against a version of QT without the wkhtmltopdf patches. Therefore a X11 server is required."
		);
	}

	REGISTER_INI_ENTRIES();

	PHP_MINIT(wkhtmltox_pdf)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(wkhtmltox_image)(INIT_FUNC_ARGS_PASSTHRU);

	return SUCCESS;
}
/* }}} */

/* {{{ */
PHP_MSHUTDOWN_FUNCTION(wkhtmltox)
{
	PHP_MSHUTDOWN(wkhtmltox_pdf)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MSHUTDOWN(wkhtmltox_image)(INIT_FUNC_ARGS_PASSTHRU);

	UNREGISTER_INI_ENTRIES();

	return SUCCESS;
} /* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(wkhtmltox)
{
#if defined(COMPILE_DL_WKHTMLTOX) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(wkhtmltox)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "wkhtmltox support", "enabled");
	php_info_print_table_row(2, "wkhtmltox version", PHP_WKHTMLTOX_VERSION);
	php_info_print_table_row(2, "libwkhtmltox version", wkhtmltopdf_version());
	php_info_print_table_row(2, "X11 server required", wkhtmltopdf_extended_qt() ? "No" : "Yes");
	php_info_print_table_end();
}
/* }}} */

/* {{{ wkhtmltox_functions[]
 */
const zend_function_entry wkhtmltox_functions[] = {
	PHP_FE_END
};
/* }}} */

/* {{{ wkhtmltox_module_entry
 */
zend_module_entry wkhtmltox_module_entry = {
	STANDARD_MODULE_HEADER,
	"wkhtmltox",
	wkhtmltox_functions,
	PHP_MINIT(wkhtmltox),
	PHP_MSHUTDOWN(wkhtmltox),
	PHP_RINIT(wkhtmltox),
	NULL,
	PHP_MINFO(wkhtmltox),
	PHP_WKHTMLTOX_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_WKHTMLTOX
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(wkhtmltox)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
