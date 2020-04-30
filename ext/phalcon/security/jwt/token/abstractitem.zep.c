
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AbstractItem
 *
 * @property array $data
 */
ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Token_AbstractItem) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Security\\JWT\\Token, AbstractItem, phalcon, security_jwt_token_abstractitem, phalcon_security_jwt_token_abstractitem_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_security_jwt_token_abstractitem_ce, SL("data"), ZEND_ACC_PROTECTED);

	phalcon_security_jwt_token_abstractitem_ce->create_object = zephir_init_properties_Phalcon_Security_JWT_Token_AbstractItem;
	return SUCCESS;

}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Security_JWT_Token_AbstractItem, getEncoded) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("encoded"), PH_NOISY | PH_READONLY, "phalcon/Security/JWT/Token/AbstractItem.zep", 30);
	RETURN_CTORW(&_1);

}

zend_object *zephir_init_properties_Phalcon_Security_JWT_Token_AbstractItem(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("data"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

