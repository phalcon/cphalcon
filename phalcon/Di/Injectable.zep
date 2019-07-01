
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Di\Exception;
use Phalcon\Session\BagInterface;

/**
 * This class allows to access services in the services container by just only
 * accessing a public property with the same name of a registered service
 *
 * @property \Phalcon\Annotations\Adapter\Memory|\Phalcon\Annotations\Adapter $annotations
 * @property \Phalcon\Assets\Manager $assets
 * @property \Phalcon\Http\Response\Cookies|\Phalcon\Http\Response\CookiesInterface $cookies
 * @property \Phalcon\Crypt\Crypt|\Phalcon\Crypt\CryptInterface $crypt
 * @property \Phalcon\Db\Adapter\AdapterInterface $db
 * @property \Phalcon\Di|\Phalcon\DiInterface $di
 * @property \Phalcon\Mvc\Dispatcher|\Phalcon\Mvc\DispatcherInterface $dispatcher
 * @property \Phalcon\Escaper|\Phalcon\Escaper\EscaperInterface $escaper
 * @property \Phalcon\Events\Manager|\Phalcon\Events\ManagerInterface $eventsManager
 * @property \Phalcon\Mvc\Model\Manager|\Phalcon\Mvc\Model\ManagerInterface $modelsManager
 * @property \Phalcon\Mvc\Model\MetaData\Memory|\Phalcon\Mvc\Model\MetadataInterface $modelsMetadata
 * @property \Phalcon\Flash\Direct $flash
 * @property \Phalcon\Flash\Session $flashSession
 * @property \Phalcon\Filter\FilterLocator $filter
 * @property \Phalcon\Session\Bag|\Phalcon\Session\BagInterface $persistent
 * @property \Phalcon\Http\Request|\Phalcon\Http\RequestInterface $request
 * @property \Phalcon\Http\Response|\Phalcon\Http\ResponseInterface $response
 * @property \Phalcon\Mvc\Router|\Phalcon\Mvc\RouterInterface $router
 * @property \Phalcon\Session\ManagerInterface $session
 * @property \Phalcon\Security\Security $security
 * @property \Phalcon\Tag $tag
 * @property \Phalcon\Mvc\Model\Transaction\Manager|\Phalcon\Mvc\Model\Transaction\ManagerInterface $transactionManager
 * @property \Phalcon\Url|\Phalcon\UrlInterface $url
 * @property \Phalcon\Mvc\View|\Phalcon\Mvc\ViewInterface $view
 */
abstract class Injectable implements InjectionAwareInterface, EventsAwareInterface
{
    /**
     * Dependency Injector
     *
     * @var DiInterface
     */
    protected container;

    /**
     * Events Manager
     *
     * @var \Phalcon\Events\ManagerInterface
     */
    protected eventsManager;

    /**
     * Magic method __get
     */
    public function __get(string! propertyName) -> var | null
    {
        var container, service;

        let container = <DiInterface> this->container;

        if typeof container != "object" {
            let container = Di::getDefault();

            if unlikely typeof container != "object" {
                throw new Exception(
                    Exception::containerServiceNotFound("internal services")
                );
            }
        }

        /**
         * Fallback to the PHP userland if the cache is not available
         */
        if container->has(propertyName) {
            let service = container->getShared(propertyName);
            let this->{propertyName} = service;

            return service;
        }

        if propertyName == "di" {
            let this->{"di"} = container;

            return container;
        }

        /**
         * Accessing the persistent property will create a session bag on any class
         */
        if propertyName == "persistent" {
            let this->{"persistent"} = <BagInterface> container->get(
                "sessionBag",
                [
                    get_class(this)
                ]
            );

            return this->{"persistent"};
        }

        /**
         * A notice is shown if the property is not defined and isn't a valid service
         */
        trigger_error("Access to undefined property " . propertyName);

        return null;
    }

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface>
    {
        var container;

        let container = this->container;

        if typeof container != "object" {
            let container = Di::getDefault();
        }

        return container;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface>
    {
        return this->eventsManager;
    }

    /**
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Sets the event manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }
}
