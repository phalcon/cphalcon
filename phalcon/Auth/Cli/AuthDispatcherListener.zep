
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

namespace Phalcon\Auth\Cli;

use Phalcon\Auth\AbstractAuthDispatcherListener;
use Phalcon\Auth\Exception;
use Phalcon\Cli\Dispatcher;
use Phalcon\Events\Event;

class AuthDispatcherListener extends AbstractAuthDispatcherListener
{
    /**
     * @throws Exception
     */
    public function beforeExecuteRoute(<Event> event, <Dispatcher> dispatcher) -> bool
    {
        return this->enforce((string) dispatcher->getActionName());
    }

    protected function getActionType() -> string
    {
        return "task";
    }
}
