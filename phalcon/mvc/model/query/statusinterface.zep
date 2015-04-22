
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

namespace Phalcon\Mvc\Model\Query;

use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Query\StatusInterface
 *
 * Interface for Phalcon\Mvc\Model\Query\Status
 */
interface StatusInterface
{

	/**
	 * Phalcon\Mvc\Model\Query\Status
	 */
	public function __construct(boolean success, <ModelInterface> model);

	/**
	 * Returns the model which executed the action
	 */
	public function getModel() -> <ModelInterface>;

	/**
	 * Returns the messages produced by a operation failed
	 */
	public function getMessages() -> <\Phalcon\Mvc\Model\MessageInterface[]>;

	/**
	 * Allows to check if the executed operation was successful
	 */
	public function success() -> boolean;

}