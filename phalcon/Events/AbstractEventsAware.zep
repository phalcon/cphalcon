
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

use Phalcon\Events\ManagerInterface;

/**
 * This abstract class offers access to the events manager
 * @property ?ManagerInterface $eventsManager
 */
abstract class AbstractEventsAware
{
    /**
     * @var ManagerInterface|null
     */
    protected eventsManager = null;

    /**
     * Returns the internal event manager
     *
     * @return ManagerInterface|null
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Sets the events manager
     *
     * @param ManagerInterface $eventsManager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Helper method to fire an event
     *
     * @param string     $eventName
     * @param mixed|null $data
     * @param bool       $cancellable
     *
     * @return mixed|bool
     */
    protected function fireManagerEvent(
        string eventName,
        data = null,
        bool cancellable = true
    ) -> var | bool {
        if (null !== this->eventsManager) {
            return this
                ->eventsManager
                ->fire(eventName, this, data, cancellable)
            ;
        }

        return true;
    }
}

