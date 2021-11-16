
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

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
 * Phalcon\Support\Collection\CollectionInterface
 *
 * Interface for Phalcon\Support\Collection class
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Collection_CollectionInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Support\\Collection, CollectionInterface, phalcon, support_collection_collectioninterface, phalcon_support_collection_collectioninterface_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, __get);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, __isset);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, __set);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, __unset);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, clear);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, get);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, getKeys);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, getValues);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, has);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, init);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, remove);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, set);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, toArray);
ZEPHIR_DOC_METHOD(Phalcon_Support_Collection_CollectionInterface, toJson);
