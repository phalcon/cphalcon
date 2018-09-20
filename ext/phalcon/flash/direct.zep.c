
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
 * Phalcon\Flash\Direct
 *
 * This is a variant of the Phalcon\Flash that immediately outputs any message passed to it
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_Direct) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, Direct, phalcon, flash_direct, phalcon_flash_ce, phalcon_flash_direct_method_entry, 0);

	return SUCCESS;

}

/**
 * Outputs a message
 */
PHP_METHOD(Phalcon_Flash_Direct, message) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(type, type_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "outputmessage", NULL, 0, type, message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the messages accumulated in the flasher
 */
PHP_METHOD(Phalcon_Flash_Direct, output) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *remove_param = NULL, *message = NULL, *messages = NULL, **_2$$3;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_is_iterable(messages, &_1$$3, &_0$$3, 0, 0, "phalcon/flash/direct.zep", 52);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(message, _2$$3);
			zend_print_zval(message, 0);
		}
	}
	if (remove) {
		ZEPHIR_CALL_PARENT(NULL, phalcon_flash_direct_ce, getThis(), "clear", &_3, 217);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

