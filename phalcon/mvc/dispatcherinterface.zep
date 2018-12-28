
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Mvc\ControllerInterface;
use Phalcon\DispatcherInterface as DispatcherInterfaceBase;

/**
 * Phalcon\Mvc\DispatcherInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher
 */
interface DispatcherInterface extends DispatcherInterfaceBase
{

	/**
	 * Sets the default controller suffix
	 */
	public function setControllerSuffix(string! controllerSuffix);

	/**
	 * Sets the default controller name
	 */
	public function setDefaultController(string! controllerName);

	/**
	 * Sets the controller name to be dispatched
	 */
	public function setControllerName(string! controllerName);

	/**
	 * Gets last dispatched controller name
	 */
	public function getControllerName() -> string;

	/**
	 * Returns the latest dispatched controller
	 */
	public function getLastController() -> <ControllerInterface>;

	/**
	 * Returns the active controller in the dispatcher
	 */
	public function getActiveController() -> <ControllerInterface>;
}
