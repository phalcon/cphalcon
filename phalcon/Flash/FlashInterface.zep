
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
 * Interface FlashInterface
 *
 * @package Phalcon\Flash
 */
interface FlashInterface
{
    /**
     * Shows a HTML error message
     *
     * @param string $message
     *
     * @return string|null
     */
    public function error(string message) -> string | null;

    /**
     * Outputs a message
     *
     * @param string $type
     * @param mixed  $message
     *
     * @return string|null
     */
    public function message(string type, string message) -> string | null;

    /**
     * Shows a HTML notice/information message
     *
     * @param string $message
     *
     * @return string|null
     */
    public function notice(string message) -> string | null;

    /**
     * Shows a HTML success message
     *
     * @param string $message
     *
     * @return string|null
     */
    public function success(string message) -> string | null;

    /**
     * Shows a HTML warning message
     *
     * @param string $message
     *
     * @return string|null
     */
    public function warning(string message) -> string | null;
}
