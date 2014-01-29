
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#ifndef PHALCON_MVC_MODEL_METADATA_H
#define PHALCON_MVC_MODEL_METADATA_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_mvc_model_metadata_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData);

#define PHALCON_MVC_MODEL_METADATA_MODELS_ATTRIBUTES                   0
#define PHALCON_MVC_MODEL_METADATA_MODELS_PRIMARY_KEY                  1
#define PHALCON_MVC_MODEL_METADATA_MODELS_NON_PRIMARY_KEY              2
#define PHALCON_MVC_MODEL_METADATA_MODELS_NOT_NULL                     3
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATA_TYPES                   4
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATA_TYPES_NUMERIC           5
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATE_AT                      6
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATE_IN                      7
#define PHALCON_MVC_MODEL_METADATA_MODELS_IDENTITY_COLUMN              8
#define PHALCON_MVC_MODEL_METADATA_MODELS_DATA_TYPES_BIND              9
#define PHALCON_MVC_MODEL_METADATA_MODELS_AUTOMATIC_DEFAULT_INSERT    10
#define PHALCON_MVC_MODEL_METADATA_MODELS_AUTOMATIC_DEFAULT_UPDATE    11

#define PHALCON_MVC_MODEL_METADATA_MODELS_COLUMN_MAP                   0
#define PHALCON_MVC_MODEL_METADATA_MODELS_REVERSE_COLUMN_MAP           1

#endif /* PHALCON_MVC_MODEL_METADATA_H */
