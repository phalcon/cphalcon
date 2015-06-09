
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Collection\Behavior;

use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\Collection\Behavior;
use Phalcon\Mvc\Collection\BehaviorInterface;
use Phalcon\Mvc\Collection\Exception;

/**
 * Phalcon\Mvc\Collection\Behavior\SoftDelete
 *
 * Instead of permanently delete a record it marks the record as
 * deleted changing the value of a flag column
 */
class SoftDelete extends Behavior implements BehaviorInterface
{

	/**
	 * Listens for notifications from the models manager
	 */
	public function notify(string! type, <CollectionInterface> model)
	{
		var options, value, field, updateModel, message;

		if type == "beforeDelete" {

			let options = this->getOptions();

			/**
			 * 'value' is the value to be updated instead of delete the record
			 */
			if !fetch value, options["value"] {
				throw new Exception("The option 'value' is required");
			}

			/**
			 * 'field' is the attribute to be updated instead of delete the record
			 */
			if !fetch field, options["field"] {
				throw new Exception("The option 'field' is required");
			}

			/**
			 * Skip the current operation
			 */
			model->skipOperation(true);

			/**
			 * If the record is already flagged as 'deleted' we don't delete it again
			 */
			if model->readAttribute(field) != value {

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
	}
}