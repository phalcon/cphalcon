
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

#include "mvc/model/validatorinterface.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/resultsetinterface.h"
#include "mvc/model/behaviorinterface.h"
#include "mvc/model/resultinterface.h"
#include "mvc/model/queryinterface.h"
#include "mvc/model/query/statusinterface.h"
#include "mvc/model/query/builderinterface.h"
#include "mvc/model/transactioninterface.h"
#include "mvc/model/relationinterface.h"
#include "mvc/model/managerinterface.h"
#include "mvc/model/transaction/managerinterface.h"
#include "mvc/model/criteriainterface.h"
#include "mvc/model/messageinterface.h"
#include "mvc/model/exception.h"
#include "mvc/model/validator.h"
#include "mvc/model/metadata.h"
#include "mvc/model/resultset.h"
#include "mvc/model/behavior.h"
#include "mvc/model/transaction/exception.h"
#include "mvc/model/row.h"
#include "mvc/model/query.h"
#include "mvc/model/criteria.h"
#include "mvc/model/manager.h"
#include "mvc/model/message.h"
#include "mvc/model/relation.h"
#include "mvc/model/transaction.h"
#include "mvc/model/query/lang.h"
#include "mvc/model/validator/url.h"
#include "mvc/model/query/status.h"
#include "mvc/model/metadata/apc.h"
#include "mvc/model/metadata/files.h"
#include "mvc/model/query/builder.h"
#include "mvc/model/validator/regex.h"
#include "mvc/model/validationfailed.h"
#include "mvc/model/resultset/simple.h"
#include "mvc/model/resultset/complex.h"
#include "mvc/model/metadata/memory.h"
#include "mvc/model/metadata/xcache.h"
#include "mvc/model/validator/email.h"
#include "mvc/model/metadata/session.h"
#include "mvc/model/validator/uniqueness.h"
#include "mvc/model/validator/presenceof.h"
#include "mvc/model/transaction/failed.h"
#include "mvc/model/behavior/softdelete.h"
#include "mvc/model/transaction/manager.h"
#include "mvc/model/behavior/timestampable.h"
#include "mvc/model/metadata/strategy/annotations.h"
#include "mvc/model/metadata/strategy/introspection.h"
#include "mvc/model/validator/inclusionin.h"
#include "mvc/model/validator/numericality.h"
#include "mvc/model/validator/exclusionin.h"
#include "mvc/model/validator/stringlength.h"

extern int nusphere_dbg_present;
