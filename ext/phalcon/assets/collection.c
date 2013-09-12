
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Collection, phalcon, assets_collection, NULL, 0);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_local"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_join"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetUri"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_assets_collection_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

