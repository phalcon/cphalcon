
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Acl\Adapter;

use Phalcon\Acl\Enum;
use Phalcon\Events\AbstractEventsAware;
use Phalcon\Events\EventsAwareInterface;

/**
 * Functionality common to all adapters
 */
abstract class AbstractAdapter extends AbstractEventsAware implements AdapterInterface, EventsAwareInterface
{
    /**
     * Access Granted
     *
     * @var int
     */
    protected accessGranted = Enum::DENY;

    /**
     * Active access which the list is checking if some role can access it
     */
    protected ?string activeAccess = null;

    /**
     * Component which the list is checking if some role can access it
     */
    protected ?string activeComponent = null;

    /**
     * Role which the list is checking if it's allowed to certain
     * component/access
     */
    protected ?string activeRole = null;

    /**
     * Default access
     *
     * @var int
     */
    protected defaultAccess = Enum::DENY;


    /**
     * Returns the access which the list is checking if a role can access it
     */
    public function getActiveAccess() -> string | null
    {
        return this->activeAccess;
    }

    /**
     * Returns the component which the list is checking if some role can access
     * it
     */
    public function getActiveComponent() -> string | null
    {
        return this->activeComponent;
    }

    /**
     * Returns the role which the list is checking if it's allowed to certain
     * component/access
     */
    public function getActiveRole() -> string | null
    {
        return this->activeRole;
    }

    /**
     * Returns the default action
     */
    public function getDefaultAction() -> int
    {
        return this->defaultAccess;
    }

    /**
     * Sets the default access level
     * (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
     */
    public function setDefaultAction(int defaultAccess) -> void
    {
        let this->defaultAccess = defaultAccess;
    }
}
