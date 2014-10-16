
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

namespace Phalcon\Mvc\Entity\Behavior;

/**
 * Phalcon\Mvc\Entity\Behavior\SoftDelete
 *
 * Instead of permanently delete a entity it marks the entity as
 * deleted changing the value of a flag field
 */
class SoftDelete extends \Phalcon\Mvc\Entity\Behavior
{

	/**
	 * Listens for notifications from the entities manager
	 *
	 * @param string type
	 * @param Phalcon\Mvc\EntityInterface entity
	 */
	public function notify(string! type, <\Phalcon\Mvc\EntityInterface> entity)
	{
		var options, value, field, updateEntity, message;

		if type == "beforeDelete" {

			let options = this->getOptions();

			/**
			 * 'value' is the value to be updated instead of delete the entity
			 */
			if !fetch value, options["value"] {
				throw new \Phalcon\Mvc\Entity\Exception("The option 'value' is required");
			}

			/**
			 * 'field' is the attribute to be updated instead of delete the entity
			 */
			if !fetch field, options["field"] {
				throw new \Phalcon\Mvc\Entity\Exception("The option 'field' is required");
			}

			/**
			 * Skip the current operation
			 */
			entity->skipOperation(true);

			/**
			 * If the entity is already flagged as 'deleted' we don't delete it again
			 */
			if entity->readAttribute(field) != value {

				/**
				 * Clone the current entity to make a clean new operation
				 */
				let updateEntity = clone entity;

				updateEntity->writeAttribute(field, value);

				/**
				 * Update the cloned entity
				 */
				if !updateEntity->save() {

					/**
					 * Transfer the messages from the cloned entity to the original entity
					 */
					for message in updateEntity->getMessages() {
						entity->appendMessage(message);
					}

					return false;
				}

				/**
				 * Update the original entity too
				 */
				entity->writeAttribute(field, value);

			}
		}

	}
}
