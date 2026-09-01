
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Mvc;

use Phalcon\Auth\AbstractAuthDispatcherListener;
use Phalcon\Auth\Exception;
use Phalcon\Events\Event;
use Phalcon\Mvc\Dispatcher;

/**
 * Listener that enforces the active Phalcon\Auth access gate on each MVC
 * dispatch. Attach to the events manager:
 *
 *   $eventsManager->attach('dispatch', new AuthDispatcherListener($manager));
 *
 * No-op when no active access has been set on the manager.
 */
class AuthDispatcherListener extends AbstractAuthDispatcherListener
{
    /**
     * @throws Exception
     */
    public function beforeExecuteRoute(<Event> event, <Dispatcher> dispatcher) -> bool
    {
        return this->enforce(
            (string) dispatcher->getActionName(),
            [
                "handler": dispatcher->getControllerName(),
                "module":  dispatcher->getModuleName(),
                "params":  dispatcher->getParams()
            ],
            function (target) use (dispatcher) {
                dispatcher->forward(target);
            }
        );
    }

    protected function getActionType() -> string
    {
        return "action";
    }
}
