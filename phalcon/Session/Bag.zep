/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

use Phalcon\Support\Collection;
use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;

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
 */
class Bag extends Collection implements InjectionAwareInterface
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
     * @var \Phalcon\Session\ManagerInterface
     */
    private session;

    /**
     * Phalcon\Session\Bag constructor
     */
    public function __construct(string! name, <DiInterface> container = null)
    {
        var data, session;

        let this->name = name;

        if unlikely null === container {
            throw new Exception(
                "A dependency injection container is required to access the 'session' service"
            );
        }

        if unlikely true !== container->has("session") {
            throw new Exception(
                "A dependency injection container is required to access the 'session' service"
            );
        }

        let session         = container->getShared("session"),
            this->container = container,
            this->session   = session;

        let data = session->get(this->name);

        if typeof data != "array" {
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

        this->session->set(this->name, this->data);
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
