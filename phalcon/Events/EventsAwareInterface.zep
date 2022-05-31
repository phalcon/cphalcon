
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
 * This interface must for those classes that accept an EventsManager and
 * dispatch events
 */
interface EventsAwareInterface
{
    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null;

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void;
}
