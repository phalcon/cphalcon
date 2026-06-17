
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Flash;

/**
 * Canonical contract for Phalcon\Flash messengers.
 *
 * Note: `output()` and `clear()` are part of the concrete `Direct` / `Session`
 * API and are not declared on this contract; they are scheduled to be added in
 * the next major version.
 */
interface Flash
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
     * Note: the shipped implementations (`Direct`, `Session`) accept
     * `string|array` for `$message`; this contract declares `string` and is
     * scheduled to be widened to `mixed` in the next major version. Delivery
     * semantics differ per implementation: `Direct::message()` renders and
     * emits the message immediately, while `Session::message()` stores the raw
     * message for output on a later request.
     *
     * @param string $type
     * @param string $message
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
