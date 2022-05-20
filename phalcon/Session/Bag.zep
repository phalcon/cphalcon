/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

use Phalcon\Di\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Session\ManagerInterface;
use Phalcon\Support\Collection;

/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by
 * this way you can easily create groups of session variables into the
 * application
 *
 * ```php
 * $user = new \Phalcon\Session\Bag("user");
 *
 * $user->name = "Kimbra Johnson";
 * $user->age  = 22;
 * ```
 *
 * @property DiInterface|null $container
 * @property string           $name
 * @property ManagerInterface $session;
 */
class Bag extends Collection implements BagInterface, InjectionAwareInterface
{
    /**
     * @var DiInterface|null
     */
    private container;

    /**
     * Session Bag name
     *
     * @var string
     */
    private name;

    /**
     * @var ManagerInterface
     */
    private session;

    /**
     * @param ManagerInterface $session
     * @param string           $name
     */
    public function __construct(<ManagerInterface> session, string name)
    {
        var data;

        let this->session   = session,
            this->name      = name,
            this->container = session->getDI();

        let data = session->get(this->name);

        if typeof data !== "array" {
            let data = [];
        }

        this->init(data);
    }

    /**
     * Destroys the session bag
     */
    public function clear() -> void
    {
        parent::clear();

        this->session->remove(this->name);
    }

    /**
     * Returns the DependencyInjector container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Initialize internal array
     */
    public function init(array! data = []) -> void
    {
        parent::init(data);

        this->session->set(this->name, data);
    }

    /**
     * Removes a property from the internal bag
     */
    public function remove(string! element) -> void
    {
        parent::remove(element);

        this->session->set(this->name, this->data);
    }

    /**
     * Sets a value in the session bag
     */
    public function set(string! element, var value) -> void
    {
        parent::set(element, value);

        this->session->set(this->name, this->data);
    }

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }
}
