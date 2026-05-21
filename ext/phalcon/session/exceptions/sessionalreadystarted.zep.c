
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Phalcon_Session_Exceptions_SessionAlreadyStarted)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Exceptions, SessionAlreadyStarted, phalcon, session_exceptions_sessionalreadystarted, phalcon_session_exception_ce, phalcon_session_exceptions_sessionalreadystarted_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Session_Exceptions_SessionAlreadyStarted, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "The session has already been started. To change the id, use regenerateId()");
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_exceptions_sessionalreadystarted_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

