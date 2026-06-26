
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared base for ACL Role and Component entities: a name and an optional
 * description.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_AbstractElement)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, AbstractElement, phalcon, acl_abstractelement, phalcon_acl_abstractelement_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Element description
	 *
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_acl_abstractelement_ce, SL("description"), ZEND_ACC_PROTECTED);
	/**
	 * Element name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_abstractelement_ce, SL("name"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Acl_AbstractElement, __toString)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

PHP_METHOD(Phalcon_Acl_AbstractElement, getDescription)
{

	RETURN_MEMBER(getThis(), "description");
}

PHP_METHOD(Phalcon_Acl_AbstractElement, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

