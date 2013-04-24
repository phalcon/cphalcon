
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Mvc\CollectionInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_CollectionInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, CollectionInterface, mvc_collectioninterface, phalcon_mvc_collectioninterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Collection
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, __construct);

/**
 * Sets a value for the _id propery, creates a MongoId object if needed
 *
 * @param mixed $id
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, setId);

/**
 * Returns the value of the _id property
 *
 * @return MongoId
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getId);

/**
 * Returns an array with reserved properties that cannot be part of the insert/update
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getReservedAttributes);

/**
 * Returns collection name mapped in the model
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getSource);

/**
 * Sets a service in the services container that returns the Mongo database
 *
 * @param string $connectionService
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, setConnectionService);

/**
 * Retrieves a database connection
 *
 * @return MongoDb
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getConnection);

/**
 * Reads an attribute value by its name
 *
 * <code>
 *	echo $robot->readAttribute('name');
 * </code>
 *
 * @param string $attribute
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, readAttribute);

/**
 * Writes an attribute value by its name
 *
 * <code>
 *	$robot->writeAttribute('name', 'Rosey');
 * </code>
 *
 * @param string $attribute
 * @param mixed $value
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, writeAttribute);

/**
 * Returns a cloned collection
 *
 * @param Phalcon\Mvc\Collection $collection
 * @param array $document
 * @return Phalcon\Mvc\Collection
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, cloneResult);

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string $eventName
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEvent);

/**
 * Fires an event, implicitly listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string $eventName
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, fireEventCancel);

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *	{
 *		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, validationHasFailed);

/**
 * Returns all the validation messages
 *
 * <code>
 *$robot = new Robots();
 *$robot->type = 'mechanical';
 *$robot->name = 'Astro Boy';
 *$robot->year = 1952;
 *if ($robot->save() == false) {
 *	echo "Umh, We can't store robots right now ";
 *	foreach ($robot->getMessages() as $message) {
 *		echo $message;
 *	}
 *} else {
 *	echo "Great, a new robot was saved successfully!";
 *}
 * </code>
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, getMessages);

/**
 * Appends a customized message on the validation process
 *
 *<code>
 *	use \Phalcon\Mvc\Model\Message as Message;
 *
 *	class Robots extends Phalcon\Mvc\Model
 *	{
 *
 *		public function beforeSave()
 *		{
 *			if ($this->name == 'Peter') {
 *				$message = new Message("Sorry, but a robot cannot be named Peter");
 *				$this->appendMessage($message);
 *			}
 *		}
 *	}
 *</code>
 *
 * @param Phalcon\Mvc\Model\MessageInterface $message
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, appendMessage);

/**
 * Creates/Updates a collection based on the values in the atributes
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, save);

/**
 * Find a document by its id
 *
 * @param string $id
 * @return Phalcon\Mvc\Collection
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, findById);

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 *
 * //What's the first robot in robots table?
 * $robot = Robots::findFirst();
 * echo "The robot name is ", $robot->name;
 *
 * //What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst(array(
 *     array("type" => "mechanical")
 * ));
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * //Get first virtual robot ordered by name
  * $robot = Robots::findFirst(array(
 *     array("type" => "mechanical"),
 *     "order" => array("name" => 1)
 * ));
 * echo "The first virtual robot name is ", $robot->name;
 *
 * </code>
 *
 * @param array $parameters
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, findFirst);

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $robots = Robots::find();
 * echo "There are ", count($robots);
 *
 * //How many mechanical robots are there?
 * $robots = Robots::find(array(
 *     array("type" => "mechanical")
 * ));
 * echo "There are ", count($robots);
 *
 * //Get and print virtual robots ordered by name
 * $robots = Robots::findFirst(array(
 *     array("type" => "virtual"),
 *     "order" => array("name" => 1)
 * ));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
  * //Get first 100 virtual robots ordered by name
  * $robots = Robots::find(array(
 *     array("type" => "virtual"),
 *     "order" => array("name" => 1),
 *     "limit" => 100
 * ));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 *
 * @param 	array $parameters
 * @return  array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, find);

/**
 * Perform a count over a collection
 *
 * @param array $parameters
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, count);

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 *$robot = Robots::findFirst();
 *$robot->delete();
 *
 *foreach(Robots::find() as $robot){
 *   $robot->delete();
 *}
 * </code>
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_CollectionInterface, delete);

