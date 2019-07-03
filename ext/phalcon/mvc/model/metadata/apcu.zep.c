
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaData\Apcu
 *
 * Stores model meta-data in the APCu cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apcu_fetch('$PMM$') or apcu_fetch('$PMM$my-app-id')
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Apcu(
 *     [
 *         "prefix"   => "my-app-id",
 *         "lifetime" => 86400,
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apcu) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Apcu, phalcon, mvc_model_metadata_apcu, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_apcu_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Apcu constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apcu, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ph-mm-apcu-");
	zephir_array_update_string(&options, SL("prefix"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 172800);
	zephir_array_update_string(&options, SL("lifetime"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "apcu");
	ZEPHIR_CALL_METHOD(&_2, factory, "newinstance", NULL, 0, &_3, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("adapter"), &_2);
	ZEPHIR_MM_RESTORE();

}

