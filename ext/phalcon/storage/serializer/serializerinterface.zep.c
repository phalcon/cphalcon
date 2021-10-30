
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
 * Interface SerializerInterface
 *
 * @package Phalcon\Storage\Serializer
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_SerializerInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Storage\\Serializer, SerializerInterface, phalcon, storage_serializer_serializerinterface, phalcon_storage_serializer_serializerinterface_method_entry);

	zend_class_implements(phalcon_storage_serializer_serializerinterface_ce, 1, zend_ce_serializable);
	return SUCCESS;
}

/**
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Serializer_SerializerInterface, getData);
/**
 * @param mixed $data
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Serializer_SerializerInterface, setData);
