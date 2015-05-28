/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Vladimir Metelitsa <green.cat@me.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model\Behavior;

use Phalcon\Mvc\Model\Behavior;
use Phalcon\Mvc\Model\BehaviorInterface;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Behavior\Blameable
 */
class Blameable extends Behavior implements BehaviorInterface
{

    /**
     * Listens for notifications from the models manager
     */
    public function notify(string! type, <ModelInterface> model)
    {
        //Fires logAfterCreate if the event is afterCreate
        if (eventType == "afterCreate") {
            return this->auditAfterCreate(model);
        }

        //Fires logAfterUpdate if the event is afterUpdate
        if (eventType == "afterUpdate") {
            return this->auditAfterUpdate(model);
        }
    }

    /**
     * Creates an Audit instance based on the current enviroment
     */
    internal function createAudit(string! type, <ModelInterface> model) -> <Audit>
    {
        var session, request, audit;

        //Get the session service
        session = model->getDI()->getSession();

        //Get the request service
        request = model->getDI()->getRequest();

        audit = new Audit();

        //Get the username from session
        audit->user_name = session->get("userName");

        //The model who performed the action
        audit->model_name = get_class(model);

        //The client IP address
        audit->ipaddress = request->getClientAddress();

        //Action is an update
        audit->type = type;

        //Current time
        audit->created_at = date("Y-m-d H:i:s");

        return audit;
    }

    /**
     * Audits a DELETE operation
     */
    internal function auditAfterCreate(<ModelInterface> model) -> bool
    {
        var audit, metaData, fields, field, auditDetail;
        array details;

        //Create a new audit
        audit    = this->createAudit("C", model);
        metaData = model->getModelsMetaData();
        fields   = $metaData->getAttributes($model);

        foreach (fields as field) {
            auditDetail = new AuditDetail();
            auditDetail->field_name = field;
            auditDetail->old_value = null;
            auditDetail->new_value = model->readAttribute(field);

            details[] = auditDetail;
        }

        audit->details = details;

        return audit->save();
    }

    /**
     * Audits an UPDATE operation
     */
    internal function auditAfterUpdate(<ModelInterface> model) -> bool
    {
        var changedFields, field, audit, originalData, auditDetail;
        array details;

        changedFields = model->getChangedFields();

        if (count(changedFields) == 0) {
            return null;
        }

        //Create a new audit
        audit = this->createAudit("U", model);

        //Data the model had before modifications
        originalData = model->getSnapshotData();

        foreach (changedFields as field) {
            auditDetail = new AuditDetail();
            auditDetail->field_name = field;
            auditDetail->old_value = originalData[field];
            auditDetail->new_value = model->readAttribute(field);

            details[] = auditDetail;
        }

        audit->details = details;

        return audit->save();
    }
}