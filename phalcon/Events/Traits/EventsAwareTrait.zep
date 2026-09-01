
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */


namespace Phalcon\Events\Traits;

use Phalcon\Events\Exception as EventsException;
use Phalcon\Events\ManagerInterface;

trait EventsAwareTrait
{
    protected ?<ManagerInterface> eventsManager = null;

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        if (
            true === property_exists(this, "container") &&
            null !== this->{"container"}
        ) {
            this->{"container"}->set("eventsManager", eventsManager, true);
        }

        let this->eventsManager = eventsManager;
    }

    /**
     * Helper method to fire an event
     * 
     * @throws EventsException
     */
    protected function fireManagerEvent(
        string eventName,
        var data = null,
        bool cancellable = true,
        bool stopOnFalse = false
    ) -> mixed {
        if (null !== this->eventsManager) {
            /**
             * A security boundary asks for stop-on-false so a listener's
             * denial cannot be overwritten by a later listener. Only the
             * concrete Manager knows the per-call override; a custom
             * ManagerInterface keeps its own semantics.
             */
            if (stopOnFalse && this->eventsManager instanceof \Phalcon\Events\Manager) {
                return this
                    ->eventsManager
                    ->fire(eventName, this, data, cancellable, true)
                ;
            }

            return this
                ->eventsManager
                ->fire(eventName, this, data, cancellable)
            ;
        }

        return true;
    }
}
