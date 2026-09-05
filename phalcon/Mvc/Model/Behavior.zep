
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\Model\Behavior
 *
 * This is an optional base class for ORM behaviors
 */
abstract class Behavior implements BehaviorInterface
{
    /**
     * @var array
     */
    protected options;

    /**
     * Phalcon\Mvc\Model\Behavior
     *
     * @phpstan-param array<string, mixed> $options
     */
    public function __construct(array options = [])
    {
        let this->options = options;
    }

    /**
     * Acts as fallbacks when a missing method is called on the model
     *
     * @phpstan-param array<array-key, mixed> $arguments
     */
    public function missingMethod(<ModelInterface> model, string method, array arguments = [])
    {
        return null;
    }

    /**
     * This method receives the notifications from the EventsManager
     *
     * @phpstan-return mixed
     */
    public function notify(string type, <ModelInterface> model)
    {
        return null;
    }

    /**
     * Returns the behavior options related to an event
     *
     * @return array
     *
     * @phpstan-return array<string, mixed>|mixed
     */
    protected function getOptions(string eventName = null)
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
     * Checks whether the behavior must take action on certain event
     */
    protected function mustTakeAction(string eventName) -> bool
    {
        return isset this->options[eventName];
    }
}
