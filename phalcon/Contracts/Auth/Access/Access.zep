
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Contracts\Auth\Access;

/**
 * @phpstan-type ForwardTarget array{
 *     controller?: string,
 *     action?: string,
 *     params?: array<int|string, mixed>,
 *     namespace?: string,
 *     task?: string,
 * }&array<string, mixed>
 */
interface Access
{
    public function allowedIf() -> bool;

    /**
     * @return list<string>
     */
    public function getExceptActions() -> array;

    /**
     * @return list<string>
     */
    public function getOnlyActions() -> array;

    public function isAllowed(string actionName) -> bool;

    /**
     * @phpstan-return ForwardTarget|null
     */
    public function redirectTo() -> array | null;

    /**
     * @param list<string> $exceptActions
     */
    public function setExceptActions(array exceptActions = []) -> void;

    /**
     * @param list<string> $onlyActions
     */
    public function setOnlyActions(array onlyActions = []) -> void;
}
