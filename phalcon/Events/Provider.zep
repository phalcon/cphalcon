
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

use Closure;

/**
 * Phalcon\Events\Provider
 *
 * Phalcon Events Provider, offers an easy way to declare event listeners
 * for Phalcon Events Manager.
 */
class Provider implements ProviderInterface
{
    /**
     * @var array
     *
     * Available formats of listener declarations:
     *
     * ```php
     * $listeners = [
     *    'router:notMatchedRoute' => NotMatchedRoute::class,
     *    'router:notMatchedRoute' => function($event, $router) { return true; }
     *    'router:notMatchedRoute' => [
     *        'class' => NotMatchedRoute::class,
     *        'method' => 'handle',
     *    ],
     *    'router:notMatchedRoute' => [
     *        NotMatchedRoute::class,
     *        function($event, $router) { return true; },
     *    ],
     *    'router:notMatchedRoute' => [
     *        [
     *            'class' => NotMatchedRoute::class,
     *            'method' => 'handle',
     *        ],
     *        function($event, $router) { return true; },
     *    ],
     * ]
     * ```
     */
     protected listeners = [];

    /**
     * @var array
     *
     * Available options for events:
     *
     * ```php
     * $options = [
     *    'dispatcher:beforeExecuteRoute' => [
     *        'cancelable' => true,
     *        'strict'     => true,
     *    ],
     * ]
     * ```
     */
     protected options = [];

    /**
     * Returns array of event listeners grouped by event type
     *
     * @return array
     */
    final public function getListeners() -> array
    {
        var listeners, eventType, values, value;

        let listeners = [];

        for eventType, values in this->listeners {
            let eventType = (string) eventType;

            if likely typeof values == "array" {
                if is_callable(values) {
                    let listeners[eventType][] = values;
                } else {
                    for value in values {
                        let listeners[eventType][] = this->getListener(value);
                    }
                }
            } else {
                let listeners[eventType][] = this->getListener(values);
            }
        }

        return listeners;
    }

    /**
     * @param mixed $value
     *
     * @return array|object|null
     */
    final protected function getListener(var value) -> null | array | object
    {
        var className;

        if likely typeof value == "string" {
            return new {value}();
        } elseif typeof value == "object" || value instanceof Closure {
            return value;
        } elseif typeof value == "array" {
            if is_callable(value) {
                return value;
            }
            if !isset(value["class"]) {
                return null;
            }
            if isset(value["method"]) {
                return [
                    0 : value["class"],
                    1 : value["method"]
                ];
            }

            let className = value["class"];

            return new {className}();
        }

        return null;
    }

    /**
     * Returns array of events options by event name
     *
     * @return array
     */
    final public function getOptions() -> array
    {
        return this->options;
    }
}
