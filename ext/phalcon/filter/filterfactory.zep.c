
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
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class FilterFactory
 *
 * @package Phalcon\Filter
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter, FilterFactory, phalcon, filter_filterfactory, phalcon_filter_filterfactory_method_entry, 0);

	return SUCCESS;
}

/**
 * Returns a Locator object with all the helpers defined in anonymous
 * functions
 *
 * @return FilterInterface
 */
PHP_METHOD(Phalcon_Filter_FilterFactory, newInstance)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_filter_filter_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 297, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Filter_FilterFactory, getServices)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 21, 0);
	add_assoc_stringl_ex(return_value, SL("absint"), SL("Phalcon\\Filter\\Sanitize\\AbsInt"));
	add_assoc_stringl_ex(return_value, SL("alnum"), SL("Phalcon\\Filter\\Sanitize\\Alnum"));
	add_assoc_stringl_ex(return_value, SL("alpha"), SL("Phalcon\\Filter\\Sanitize\\Alpha"));
	add_assoc_stringl_ex(return_value, SL("bool"), SL("Phalcon\\Filter\\Sanitize\\BoolVal"));
	add_assoc_stringl_ex(return_value, SL("email"), SL("Phalcon\\Filter\\Sanitize\\Email"));
	add_assoc_stringl_ex(return_value, SL("float"), SL("Phalcon\\Filter\\Sanitize\\FloatVal"));
	add_assoc_stringl_ex(return_value, SL("int"), SL("Phalcon\\Filter\\Sanitize\\IntVal"));
	add_assoc_stringl_ex(return_value, SL("lower"), SL("Phalcon\\Filter\\Sanitize\\Lower"));
	add_assoc_stringl_ex(return_value, SL("lowerfirst"), SL("Phalcon\\Filter\\Sanitize\\LowerFirst"));
	add_assoc_stringl_ex(return_value, SL("regex"), SL("Phalcon\\Filter\\Sanitize\\Regex"));
	add_assoc_stringl_ex(return_value, SL("remove"), SL("Phalcon\\Filter\\Sanitize\\Remove"));
	add_assoc_stringl_ex(return_value, SL("replace"), SL("Phalcon\\Filter\\Sanitize\\Replace"));
	add_assoc_stringl_ex(return_value, SL("special"), SL("Phalcon\\Filter\\Sanitize\\Special"));
	add_assoc_stringl_ex(return_value, SL("specialfull"), SL("Phalcon\\Filter\\Sanitize\\SpecialFull"));
	add_assoc_stringl_ex(return_value, SL("string"), SL("Phalcon\\Filter\\Sanitize\\StringVal"));
	add_assoc_stringl_ex(return_value, SL("striptags"), SL("Phalcon\\Filter\\Sanitize\\Striptags"));
	add_assoc_stringl_ex(return_value, SL("trim"), SL("Phalcon\\Filter\\Sanitize\\Trim"));
	add_assoc_stringl_ex(return_value, SL("upper"), SL("Phalcon\\Filter\\Sanitize\\Upper"));
	add_assoc_stringl_ex(return_value, SL("upperfirst"), SL("Phalcon\\Filter\\Sanitize\\UpperFirst"));
	add_assoc_stringl_ex(return_value, SL("upperwords"), SL("Phalcon\\Filter\\Sanitize\\UpperWords"));
	add_assoc_stringl_ex(return_value, SL("url"), SL("Phalcon\\Filter\\Sanitize\\Url"));
	return;
}

