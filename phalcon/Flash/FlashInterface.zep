
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Flash;

/**
 * Phalcon\Flash\FlashInterface
 *
 * Interface for Phalcon\Flash classes
 */
interface FlashInterface
{
    /**
     * Shows a HTML error message
     *
     * @return null|string|void
     */
    public function error(string message) -> string | null;

    /**
     * Outputs a message
     *
     * @return null|string|void
     */
    public function message(string type, string message) -> string | null;

    /**
     * Shows a HTML notice/information message
     *
     * @return null|string|void
     */
    public function notice(string message) -> string | null;

    /**
     * Shows a HTML success message
     *
     * @return null|string|void
     */
    public function success(string message) -> string | null;

    /**
     * Shows a HTML warning message
     *
     * @return null|string|void
     */
    public function warning(string message) -> string | null;
}
