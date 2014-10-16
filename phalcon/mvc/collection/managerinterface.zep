
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

namespace Phalcon\Mvc\Collection;

use Phalcon\Mvc\Entity\ManagerInterface as EntityManagerInterface;
use Phalcon\Mvc\CollectionInterface;

/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of collections, keeping record of relations
 * between the different collections of the application.
 *
 * A CollectionManager is injected to a collection via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new \Phalcon\Di();
 *
 * $di->set('collectionManager', function(){
 *      return new \Phalcon\Mvc\Collection\Manager();
 * });
 *
 * robot = new Robots(di);
 * </code>
 */
interface ManagerInterface extends EntityManagerInterface
{
	/**
	 * Sets a connection service for a specific collection
	 *
	 * @param Phalcon\Mvc\CollectionInterface collection
	 * @param string connectionService
	 */
	public function setConnectionService(<CollectionInterface> collection, string! connectionService);

	/**
	 * Sets if a collection must use implicit objects ids
	 *
	 * @param Phalcon\Mvc\CollectionInterface collection
	 * @param boolean useImplicitObjectIds
	 */
	public function useImplicitObjectIds(<CollectionInterface> collection, boolean useImplicitObjectIds);

	/**
	 * Checks if a collection is using implicit object ids
	 *
	 * @param Phalcon\Mvc\CollectionInterface collection
	 * @return boolean
	 */
	public function isUsingImplicitObjectIds(<CollectionInterface> collection);

	/**
	 * Returns the connection related to a collection
	 *
	 * @param Phalcon\Mvc\CollectionInterface collection
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getConnection(<CollectionInterface> collection);
}