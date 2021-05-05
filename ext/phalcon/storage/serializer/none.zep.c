
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_None)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Serializer, None, phalcon, storage_serializer_none, phalcon_storage_serializer_abstractserializer_ce, phalcon_storage_serializer_none_method_entry, 0);

	return SUCCESS;
}

/**
 * Serializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_None, serialize)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "data");
}

/**
 * Unserializes data
 */
PHP_METHOD(Phalcon_Storage_Serializer_None, unserialize)
{
	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &data);


	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), data);
}

