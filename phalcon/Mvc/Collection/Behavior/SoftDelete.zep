
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Collection\Behavior;

use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\Collection\Behavior;
use Phalcon\Mvc\Collection\Exception;

/**
 * Phalcon\Mvc\Collection\Behavior\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as
 * deleted changing the value of a flag column
 */
class SoftDelete extends Behavior
{
    /**
     * Listens for notifications from the models manager
     */
    public function notify(string! type, <CollectionInterface> model)
    {
        var options, value, field, updateModel, message;

        if type !== "beforeDelete" {
            return;
        }

        let options = this->getOptions();

        /**
         * 'value' is the value to be updated instead of delete the record
         */
        if unlikely !fetch value, options["value"] {
            throw new Exception("The option 'value' is required");
        }

        /**
         * 'field' is the attribute to be updated instead of delete the record
         */
        if unlikely !fetch field, options["field"] {
            throw new Exception("The option 'field' is required");
        }

        /**
         * Skip the current operation
         */
        model->skipOperation(true);

        /**
         * If the record is already flagged as 'deleted' we don't delete it again
         */
        if model->readAttribute(field) == value {
            return;
        }

        /**
         * Clone the current model to make a clean new operation
         */
        let updateModel = clone model;

        updateModel->writeAttribute(field, value);

        /**
         * Update the cloned model
         */
        if !updateModel->save() {
            /**
             * Transfer the messages from the cloned model to the original model
             */
            for message in updateModel->getMessages() {
                model->appendMessage(message);
            }

            return false;
        }

        /**
         * Update the original model too
         */
        model->writeAttribute(field, value);
    }
}
