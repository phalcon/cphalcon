
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Events;

/**
 * Phalcon's local mirror of PSR-14 StoppableEventInterface. Identical shape;
 * not extended from the PSR interface because the Zephir extension cannot
 * reference Composer-loaded interfaces at build time. A separate bridge
 * package exposes a PSR-14 adapter.
 */
interface Stoppable
{
    /**
     * Returns true when the event must stop propagating to subsequent
     * listeners.
     */
    public function isPropagationStopped() -> bool;
}
