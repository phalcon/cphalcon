
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Marks a property as the identity column. It is the attribute form of `@Identity`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Models_MetaData_Identity)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Models\\MetaData, Identity, phalcon, annotations_models_metadata_identity, NULL, 0);

	{
		zend_attribute *_za = zephir_add_class_attribute(phalcon_annotations_models_metadata_identity_ce, SL("Attribute"), 1);
		zval _zc0;
		ZVAL_LONG(&_zc0, 8);
		zephir_attribute_set_arg(_za, 0, NULL, 0, &_zc0);
	}

	return SUCCESS;
}

