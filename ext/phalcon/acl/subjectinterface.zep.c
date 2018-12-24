
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 *
 * Phalcon\Acl\SubjectInterface
 *
 * Interface for Phalcon\Acl\Subject
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_SubjectInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, SubjectInterface, phalcon, acl_subjectinterface, phalcon_acl_subjectinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns subject description
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_SubjectInterface, getDescription);

/**
 * Returns the subject name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_SubjectInterface, getName);

/**
 * Magic method __toString
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_SubjectInterface, __toString);

