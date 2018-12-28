
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
 * Phalcon\Acl\SubjectAware
 *
 * Interface for classes which could be used in allow method as RESOURCE
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_SubjectAware) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Acl, SubjectAware, phalcon, acl_subjectaware, phalcon_acl_subjectaware_method_entry);

	return SUCCESS;

}

/**
 * Returns subject name
 */
ZEPHIR_DOC_METHOD(Phalcon_Acl_SubjectAware, getSubjectName);

