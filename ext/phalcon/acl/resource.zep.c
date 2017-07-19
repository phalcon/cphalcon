
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"


/**
 * Phalcon\Acl\Resource
 *
 * This class defines resource entity and its description
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Resource) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Resource, phalcon, acl_resource, phalcon_acl_resource_method_entry, 0);

	/**
	 * Resource name
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Resource description
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_description"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_resource_ce TSRMLS_CC, 1, phalcon_acl_resourceinterface_ce);
	return SUCCESS;

}

/**
 * Resource name
 */
PHP_METHOD(Phalcon_Acl_Resource, getName) {

	

	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Resource name
 */
PHP_METHOD(Phalcon_Acl_Resource, __toString) {

	

	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Resource description
 */
PHP_METHOD(Phalcon_Acl_Resource, getDescription) {

	

	RETURN_MEMBER(getThis(), "_description");

}

/**
 * Phalcon\Acl\Resource constructor
 */
PHP_METHOD(Phalcon_Acl_Resource, __construct) {

	zval *name_param = NULL, *description_param = NULL;
	zval *name = NULL, *description = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &description_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!description_param) {
		ZEPHIR_INIT_VAR(description);
		ZVAL_EMPTY_STRING(description);
	} else {
		zephir_get_strval(description, description_param);
	}


	if (ZEPHIR_IS_STRING(name, "*")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Resource name cannot be '*'", "phalcon/acl/resource.zep", 50);
		return;
	}
	zephir_update_property_this(getThis(), SL("_name"), name TSRMLS_CC);
	if (!(!description) && Z_STRLEN_P(description)) {
		zephir_update_property_this(getThis(), SL("_description"), description TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

