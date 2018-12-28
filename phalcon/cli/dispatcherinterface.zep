
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli;

use Phalcon\DispatcherInterface as DispatcherInterfaceBase;

/**
 * Phalcon\Cli\DispatcherInterface
 *
 * Interface for Phalcon\Cli\Dispatcher
 */
interface DispatcherInterface extends DispatcherInterfaceBase
{

	/**
	 * Sets the default task suffix
	 */
	public function setTaskSuffix(string taskSuffix);

	/**
	 * Sets the default task name
	 */
	public function setDefaultTask(string taskName);

	/**
	 * Sets the task name to be dispatched
	 */
	public function setTaskName(string taskName);

	/**
	 * Gets last dispatched task name
	 */
	public function getTaskName() -> string;

	/**
	 * Gets default task suffix
	 */
	public function getTaskSuffix() -> string;

	/**
	 * Returns the latest dispatched controller
	 */
	public function getLastTask() -> <TaskInterface>;

	/**
	 * Returns the active task in the dispatcher
	 */
	public function getActiveTask() -> <TaskInterface>;

	/**
	 * Set the options to be dispatched
	 */
	public function setOptions(array options);

	/**
	 * Get dispatched options
	 */
	public function getOptions() -> array;
}
