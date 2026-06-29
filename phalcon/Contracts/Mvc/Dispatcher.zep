
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Mvc;

use Phalcon\Contracts\Dispatcher\Dispatcher as DispatcherContract;
use Phalcon\Mvc\ControllerInterface;

/**
 * Canonical contract for Phalcon\Mvc\Dispatcher.
 */
interface Dispatcher extends DispatcherContract
{
    /**
     * Returns the active controller in the dispatcher
     */
    public function getActiveController() -> <ControllerInterface> | null;

    /**
     * Gets last dispatched controller name
     */
    public function getControllerName() -> string;

    /**
     * Returns the latest dispatched controller
     */
    public function getLastController() -> <ControllerInterface> | null;

    /**
     * Sets the controller name to be dispatched
     */
    public function setControllerName( string controllerName) -> <DispatcherContract>;

    /**
     * Sets the default controller suffix
     */
    public function setControllerSuffix( string controllerSuffix) -> <DispatcherContract>;

    /**
     * Sets the default controller name
     */
    public function setDefaultController( string controllerName) -> <DispatcherContract>;
}
