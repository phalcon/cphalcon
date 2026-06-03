
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

namespace Phalcon\Auth\Access;

use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Contracts\Auth\Manager;

/**
 * @phpstan-import-type ForwardTarget from Access
 */
abstract class AbstractAccess implements Access
{
    /**
     * @var array
     */
    protected exceptActions = [];

    /**
     * @var Manager
     */
    protected manager;
    /**
     * @var array
     */
    protected onlyActions = [];

    public function __construct(<Manager> manager)
    {
        let this->manager = manager;
    }

    /**
     * @phpstan-return list<string>
     */
    public function getExceptActions() -> array
    {
        return this->exceptActions;
    }

    /**
     * @phpstan-return list<string>
     */
    public function getOnlyActions() -> array
    {
        return this->onlyActions;
    }

    public function isAllowed(string actionName) -> bool
    {
        var allowed;

        let allowed = this->allowedIf();

        if (!empty(this->exceptActions)) {
            return allowed || in_array(actionName, this->exceptActions, true);
        }

        if (!empty(this->onlyActions)) {
            return allowed && in_array(actionName, this->onlyActions, true);
        }

        return allowed;
    }

    /**
     * @phpstan-return ForwardTarget|null
     */
    public function redirectTo() -> array | null
    {
        return null;
    }

    /**
     * @param list<string> $exceptActions
     */
    public function setExceptActions(array exceptActions = []) -> void
    {
        let this->exceptActions = exceptActions;
    }

    /**
     * @param list<string> $onlyActions
     */
    public function setOnlyActions(array onlyActions = []) -> void
    {
        let this->onlyActions = onlyActions;
    }
}
