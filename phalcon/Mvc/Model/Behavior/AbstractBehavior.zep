
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Behavior;

use Phalcon\Mvc\Model\ModelInterface;
use Phalcon\Mvc\Model\Behavior\BehaviorInterface;

/**
 * This is an optional base class for ORM behaviors
 */
abstract class AbstractBehavior implements BehaviorInterface
{
    /**
     * @var array
     */
    protected options;

    /**
     * Phalcon\Mvc\Model\Behavior
     */
    public function __construct(array options = []) -> void
    {
        let this->options = options;
    }

    /**
     * Returns the behavior options related to an event
     *
     * @return array
     */
    protected function getOptions(string! eventName = null)
    {
        var options, eventOptions;

        let options = this->options;

        if eventName !== null {
            if !fetch eventOptions, options[eventName] {
                return null;
            }

            return eventOptions;
        }

        return options;
    }

    /**
     * Acts as fallbacks when a missing method is called on the model
     */
    public function missingMethod(<ModelInterface> model, string method, array arguments = [])
    {
        return null;
    }

    /**
     * Checks whether the behavior must take action on certain event
     */
    protected function mustTakeAction(string! eventName) -> bool
    {
        return isset this->options[eventName];
    }

    /**
     * This method receives the notifications from the EventsManager
     */
    public function notify(string type, <ModelInterface> model)
    {
        return null;
    }
}
