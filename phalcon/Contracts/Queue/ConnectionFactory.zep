
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Queue;

/**
 * Builds a Context: the entry point of every adapter.
 */
interface ConnectionFactory
{
    /**
     * Creates a context (a session/connection to the transport).
     */
    public function createContext() -> <Context>;
}
