
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cli;

use Phalcon\Dispatcher\DispatcherInterface as DispatcherInterfaceBase;

/**
 * Interface for Phalcon\Cli\Dispatcher
 */
interface DispatcherInterface extends DispatcherInterfaceBase
{
    /**
     * Returns the active task in the dispatcher
     */
    public function getActiveTask() -> <TaskInterface>;

    /**
     * Returns the latest dispatched controller
     */
    public function getLastTask() -> <TaskInterface>;

    /**
     * Get dispatched options
     */
    public function getOptions() -> array;

    /**
     * Gets last dispatched task name
     */
    public function getTaskName() -> string;

    /**
     * Gets default task suffix
     */
    public function getTaskSuffix() -> string;

    /**
     * Sets the default task name
     */
    public function setDefaultTask(string taskName) -> void;

    /**
     * Set the options to be dispatched
     */
    public function setOptions(array options) -> void;

    /**
     * Sets the task name to be dispatched
     */
    public function setTaskName(string taskName) -> void;

    /**
     * Sets the default task suffix
     */
    public function setTaskSuffix(string taskSuffix) -> void;
}
