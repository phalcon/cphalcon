
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

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
     *    'router:beforeCheckRoute' => [
     *        BeforeCheckRoutes::class,
     *    ],
     *    'router:matchedRoute' => [
     *        [
     *            'class' => MatchedRoute::class,
     *            'method' => 'handle',
     *        ],
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
        var listeners, eventType, items, item;

        let listeners = [];

        for eventType, items in this->listeners {
            let eventType = (string) eventType;

            if likely typeof items == "array" {
                for item in items {
                    let listeners[eventType][] = this->getListener(items);
                }
            } elseif typeof items == "string" {
                let listeners[eventType][] = this->getListener(items);
            }
        }

        return listeners;
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

    /**
     * @param mixed $item
     *
     * @return array|object|null
     */
    final protected function getListener(var item) -> null | array | object
    {
        var className;

        if likely typeof item == "array" {
            if unlikely !isset(item["class"]) {
                return null;
            }
            if isset(item["method"]) {
                return [
                    0 : item["class"],
                    1 : item["method"]
                ];
            }

            let className = item["class"];

            return new {className}();
        } elseif typeof item == "string" {
            return new {item}();
        }

        return null;
    }
}
