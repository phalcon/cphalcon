
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
 * Phalcon\Mvc\Collection\Behavior\Timestampable
 *
 * Allows to automatically update a model’s attribute saving the
 * datetime when a record is created or updated
 */
class Timestampable extends Behavior implements BehaviorInterface
{

	/**
	 * Listens for notifications from the models manager
	 */
	public function notify(string! type, <CollectionInterface> model)
	{
		var options, timestamp, singleField, field, generator, format;

		/**
		 * Check if the developer decided to take action here
		 */
		if this->mustTakeAction(type) !== true {
			return null;
		}

		let options = this->getOptions(type);
		if typeof options == "array" {

			/**
			 * The field name is required in this behavior
			 */
			if !fetch field, options["field"] {
				throw new Exception("The option 'field' is required");
			}

			let timestamp = null;

			if fetch format, options["format"] {
				/**
				 * Format is a format for date()
				 */
				let timestamp = date(format);
			} else {
				if fetch generator, options["generator"] {

					/**
					 * A generator is a closure that produce the correct timestamp value
					 */
					if typeof generator == "object" {
						if generator instanceof \Closure {
							let timestamp = call_user_func(generator);
						}
					}
				}
			}

			/**
			 * Last resort call time()
			 */
			if timestamp === null {
				let timestamp = time();
			}

			/**
			 * Assign the value to the field, use writeattribute if the property is protected
			 */
			if typeof field == "array" {
				for singleField in field {
					model->writeAttribute(singleField, timestamp);
				}
			} else {
				model->writeAttribute(field, timestamp);
			}
		}
	}
}
