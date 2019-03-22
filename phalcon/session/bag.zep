/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

use Phalcon\Collection;
use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Di\InjectionAwareInterface;

/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by this way
 * you can easily create groups of session variables into the application
 *
 * <code>
 * $user = new \Phalcon\Session\Bag("user");
 *
 * $user->name = "Kimbra Johnson";
 * $user->age  = 22;
 * </code>
 */
class Bag extends Collection implements InjectionAwareInterface
{
    private container;

    private name = null;

    private session;

    /**
     * Phalcon\Session\Bag constructor
     */
    public function __construct(string! name)
    {
        var container, data, session;

        let this->name = name,
            session    = this->session;

        if typeof session != "object" {
            let container = this->container;
            if typeof container != "object" {
                let container = Di::getDefault();
                if typeof container != "object" {
                    throw new Exception("A dependency injection object is required to access the 'session' service");
                }
            }

            let session       = container->getShared("session"),
                this->session = session;
        }

        let data = session->get(this->name);
        if typeof data != "array" {
            let data = [];
        }

        parent::__construct(data);
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
     * Removes a property from the internal bag
     */
    public function init(array! data = []) -> void
    {
        parent::init(data);
    }

    /**
     * Removes a property from the internal bag
     */
    public function remove(string! element, bool insensitive = true) -> void
    {
        parent::remove(element, insensitive);
        this->session->set(this->name, this->data);
    }

    /**
     * Sets a value in the session bag
     */
    public function set(string! element, var value)
    {
        parent::set(element, value);
        this->session->set(this->name, this->data);
    }

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container)
    {
        let this->container = container;
    }
}
