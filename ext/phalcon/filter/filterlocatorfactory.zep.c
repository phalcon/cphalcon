
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterLocatorFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter, FilterLocatorFactory, phalcon, filter_filterlocatorfactory, phalcon_filter_filterlocatorfactory_method_entry, 0);

	zend_class_implements(phalcon_filter_filterlocatorfactory_ce TSRMLS_CC, 1, phalcon_service_locatorfactoryinterface_ce);
	return SUCCESS;

}

/**
 * Returns a Locator object with all the helpers defined in anonynous
 * functions
 */
PHP_METHOD(Phalcon_Filter_FilterLocatorFactory, newInstance) {

	zval helpers;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&helpers);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&helpers);
	zephir_create_array(&helpers, 21, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&helpers, SL("absint"), SL("Phalcon\\Filter\\Sanitize\\AbsInt"));
	add_assoc_stringl_ex(&helpers, SL("alnum"), SL("Phalcon\\Filter\\Sanitize\\Alnum"));
	add_assoc_stringl_ex(&helpers, SL("alpha"), SL("Phalcon\\Filter\\Sanitize\\Alpha"));
	add_assoc_stringl_ex(&helpers, SL("bool"), SL("Phalcon\\Filter\\Sanitize\\BoolVal"));
	add_assoc_stringl_ex(&helpers, SL("email"), SL("Phalcon\\Filter\\Sanitize\\Email"));
	add_assoc_stringl_ex(&helpers, SL("float"), SL("Phalcon\\Filter\\Sanitize\\FloatVal"));
	add_assoc_stringl_ex(&helpers, SL("int"), SL("Phalcon\\Filter\\Sanitize\\IntVal"));
	add_assoc_stringl_ex(&helpers, SL("lower"), SL("Phalcon\\Filter\\Sanitize\\Lower"));
	add_assoc_stringl_ex(&helpers, SL("lowerFirst"), SL("Phalcon\\Filter\\Sanitize\\LowerFirst"));
	add_assoc_stringl_ex(&helpers, SL("regex"), SL("Phalcon\\Filter\\Sanitize\\Regex"));
	add_assoc_stringl_ex(&helpers, SL("remove"), SL("Phalcon\\Filter\\Sanitize\\Remove"));
	add_assoc_stringl_ex(&helpers, SL("replace"), SL("Phalcon\\Filter\\Sanitize\\Replace"));
	add_assoc_stringl_ex(&helpers, SL("special"), SL("Phalcon\\Filter\\Sanitize\\Special"));
	add_assoc_stringl_ex(&helpers, SL("specialFull"), SL("Phalcon\\Filter\\Sanitize\\SpecialFull"));
	add_assoc_stringl_ex(&helpers, SL("string"), SL("Phalcon\\Filter\\Sanitize\\StringVal"));
	add_assoc_stringl_ex(&helpers, SL("striptags"), SL("Phalcon\\Filter\\Sanitize\\Striptags"));
	add_assoc_stringl_ex(&helpers, SL("trim"), SL("Phalcon\\Filter\\Sanitize\\Trim"));
	add_assoc_stringl_ex(&helpers, SL("upper"), SL("Phalcon\\Filter\\Sanitize\\Upper"));
	add_assoc_stringl_ex(&helpers, SL("upperFirst"), SL("Phalcon\\Filter\\Sanitize\\UpperFirst"));
	add_assoc_stringl_ex(&helpers, SL("upperWords"), SL("Phalcon\\Filter\\Sanitize\\UpperWords"));
	add_assoc_stringl_ex(&helpers, SL("url"), SL("Phalcon\\Filter\\Sanitize\\Url"));
	object_init_ex(return_value, phalcon_filter_filterlocator_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 187, &helpers);
	zephir_check_call_status();
	RETURN_MM();

}

