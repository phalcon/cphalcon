
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Cli;

use Phalcon\Cli\TaskInterface;
use Phalcon\Contracts\Dispatcher\Dispatcher as DispatcherContract;

/**
 * Canonical contract for Phalcon\Cli\Dispatcher.
 *
 * @phpstan-import-type cli_options from CliTypes
 */
interface Dispatcher extends DispatcherContract
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
     *
     * @phpstan-return cli_options
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
     *
     * @phpstan-param cli_options $options
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
