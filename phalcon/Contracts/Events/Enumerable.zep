
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
 * Optional capability contract for an events manager that can report every
 * attached listener in one call. Callers detect support with `instanceof`.
 *
 * Deliberately separate from Manager rather than a member of it: adding a
 * member to a published interface breaks every implementor, so a second,
 * narrow interface states the capability without touching the first.
 *
 * Tooling that reports on an events manager type-hints this instead of the
 * concrete Manager, so it depends on a published contract rather than on an
 * implementation detail that is free to change.
 */
interface Enumerable
{
    /**
     * Returns every event type that currently has at least one listener,
     * mapped to that type's listeners. Types contributed by subscribers are
     * included, because addSubscriber() attaches through the regular listener
     * pipeline.
     */
    public function getListenerMap() -> array;
}
