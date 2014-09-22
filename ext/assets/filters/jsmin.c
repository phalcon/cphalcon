
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "assets/filters/jsmin.h"
#ifdef PHALCON_NON_FREE
#include "assets/filters/jsminifier.h"
#else
#include "assets/filters/nojsminifier.h"
#endif
#include "assets/filterinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Assets\Filters\Jsmin
 *
 * Deletes the characters which are insignificant to JavaScript. Comments will be removed. Tabs will be
 * replaced with spaces. Carriage returns will be replaced with linefeeds.
 * Most spaces and linefeeds will be removed.
 */
zend_class_entry *phalcon_assets_filters_jsmin_ce;

PHP_METHOD(Phalcon_Assets_Filters_Jsmin, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filters_jsmin_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_assets_filters_jsmin_method_entry[] = {
	PHP_ME(Phalcon_Assets_Filters_Jsmin, filter, arginfo_phalcon_assets_filters_jsmin_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Assets\Filters\Jsmin initializer
 */
PHALCON_INIT_CLASS(Phalcon_Assets_Filters_Jsmin){

	PHALCON_REGISTER_CLASS(Phalcon\\Assets\\Filters, Jsmin, assets_filters_jsmin, phalcon_assets_filters_jsmin_method_entry, 0);

	zend_class_implements(phalcon_assets_filters_jsmin_ce TSRMLS_CC, 1, phalcon_assets_filterinterface_ce);
	return SUCCESS;
}

/**
 * Filters the content using JSMIN
 *
 * @param string $content
 * @return $content
 */
PHP_METHOD(Phalcon_Assets_Filters_Jsmin, filter){

	zval *content;

	phalcon_fetch_params(0, 1, 0, &content);
	
	if (phalcon_jsmin(return_value, content TSRMLS_CC) == FAILURE) {
		return;
	}
}

