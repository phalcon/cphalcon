
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\Model\MetaDataInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, MetaDataInterface, mvc_model_metadatainterface, phalcon_mvc_model_metadatainterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, isEmpty){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, reset){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, read){ }

PHP_METHOD(Phalcon_Mvc_Model_MetaDataInterface, write){ }

