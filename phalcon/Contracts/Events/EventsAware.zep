
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Events;

use Phalcon\Events\ManagerInterface;

/**
 * Canonical contract for Phalcon\Events\EventsAwareInterface. Implemented by
 * components that accept an events manager and dispatch through it.
 *
 * Cross-references the legacy ManagerInterface (not the canonical Manager
 * contract) to preserve LSP for the many AbstractEventsAware subclasses that
 * already type-hint ManagerInterface. ManagerInterface extends Manager, so
 * this remains type-compatible with any code that needs the canonical surface.
 */
interface EventsAware
{
    /**
     * Returns the internal events manager
     */
    public function getEventsManager() -> <ManagerInterface> | null;

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void;
}
