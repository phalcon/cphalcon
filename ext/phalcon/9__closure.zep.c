
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalcon_9__closure)
{
	ZEPHIR_REGISTER_CLASS(phalcon, 9__closure, phalcon, 9__closure, phalcon_9__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalcon_9__closure, __invoke)
{
	zval *number, number_sub, *message, message_sub, *file, file_sub, *line, line_sub, *context, context_sub, __$true;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_BOOL(&__$true, 1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_ZVAL(number)
		Z_PARAM_ZVAL(message)
		Z_PARAM_ZVAL(file)
		Z_PARAM_ZVAL(line)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(5, 0, &number, &message, &file, &line, &context);


	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$true);
}

