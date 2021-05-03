
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
 * This class helps to work with HTML Attributes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Attributes)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html, Attributes, phalcon, html_attributes, phalcon_collection_ce, phalcon_html_attributes_method_entry, 0);

	zend_class_implements(phalcon_html_attributes_ce, 1, phalcon_html_attributes_renderinterface_ce);
	return SUCCESS;
}

/**
 * Render attributes as HTML attributes
 */
PHP_METHOD(Phalcon_Html_Attributes, render)
{
	zval _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_1, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_ce, "renderattributes", &_0, 0, &_2, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias of the render method
 */
PHP_METHOD(Phalcon_Html_Attributes, __toString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "render", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

