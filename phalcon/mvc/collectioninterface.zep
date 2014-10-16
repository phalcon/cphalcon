
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

namespace Phalcon\Mvc;

use Phalcon\Mvc\Entity\StaticFinderInterface;

/**
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Collection
 */
interface CollectionInterface extends EntityInterface, StaticFinderInterface
{

	/**
	 * Phalcon\Mvc\Collection
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function __construct(<\Phalcon\DiInterface> dependencyInjector=null);

	/**
	 * Sets a value for the _id propery, creates a MongoId object if needed
	 *
	 * @param mixed id
	 */
	public function setId(id);

	/**
	 * Returns the value of the _id property
	 *
	 * @return MongoId
	 */
	public function getId();

	/**
	 * Returns an array with reserved properties that cannot be part of the insert/update
	 *
	 * @return array
	 */
	public function getReservedAttributes();

	/**
	 * Returns collection name mapped in the model
	 *
	 * @return string
	 */
	public function getSource();

	/**
	 * Sets a service in the services container that returns the Mongo database
	 *
	 * @param string connectionService
	 */
	public function setConnectionService(connectionService);

	/**
	 * Retrieves a database connection
	 *
	 * @return MongoDb
	 */
	public function getConnection();

	/**
	 * Returns a cloned collection
	 *
	 * @param Phalcon\Mvc\Collection collection
	 * @param array document
	 * @return Phalcon\Mvc\Collection
	 */
	public static function cloneResult(<CollectionInterface> collection, array! document);

	/**
	 * Find a document by its id
	 *
	 * @param string id
	 * @return Phalcon\Mvc\Collection
	 */
	public static function findById(id);

	/**
	 * Perform a count over a collection
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function count(parameters = null);

}
