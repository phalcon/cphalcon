
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is a variant of the Phalcon\Flash that immediately outputs any message
 * passed to it
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_Direct) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, Direct, phalcon, flash_direct, phalcon_flash_abstractflash_ce, phalcon_flash_direct_method_entry, 0);

	return SUCCESS;

}

/**
 * Outputs a message
 */
PHP_METHOD(Phalcon_Flash_Direct, message) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message, message_sub;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(&type, type_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "outputmessage", NULL, 0, &type, message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the messages accumulated in the flasher
 */
PHP_METHOD(Phalcon_Flash_Direct, output) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, message, _0, *_1, _2;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	zephir_read_property(&_0, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "/home/nikos/Work/niden/cphalcon/phalcon/Flash/Direct.zep", 38);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _1);
			zend_print_zval(&message, 0);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, &_0, "current", NULL, 0);
			zephir_check_call_status();
				zend_print_zval(&message, 0);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&message);
	if (remove) {
		ZEPHIR_CALL_PARENT(NULL, phalcon_flash_direct_ce, getThis(), "clear", &_3, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

