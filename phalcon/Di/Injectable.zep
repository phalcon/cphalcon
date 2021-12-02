
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Di;
use Phalcon\Session\BagInterface;

/**
 * This class allows to access services in the services container by just only
 * accessing a public property with the same name of a registered service
 *
 * @property \Phalcon\Mvc\Dispatcher|\Phalcon\Mvc\DispatcherInterface $dispatcher
 * @property \Phalcon\Mvc\Router|\Phalcon\Mvc\RouterInterface $router
 * @property \Phalcon\Mvc\Url|\Phalcon\Mvc\Url\UrlInterface $url
 * @property \Phalcon\Http\Request|\Phalcon\Http\RequestInterface $request
 * @property \Phalcon\Http\Response|\Phalcon\Http\ResponseInterface $response
 * @property \Phalcon\Http\Response\Cookies|\Phalcon\Http\Response\CookiesInterface $cookies
 * @property \Phalcon\Filter $filter
 * @property \Phalcon\Flash\Direct $flash
 * @property \Phalcon\Flash\Session $flashSession
 * @property \Phalcon\Session\ManagerInterface $session
 * @property \Phalcon\Events\Manager|\Phalcon\Events\ManagerInterface $eventsManager
 * @property \Phalcon\Db\Adapter\AdapterInterface $db
 * @property \Phalcon\Security $security
 * @property \Phalcon\Crypt\Crypt|\Phalcon\Crypt\CryptInterface $crypt
 * @property \Phalcon\Tag $tag
 * @property \Phalcon\Html\Escaper|\Phalcon\Html\Escaper\EscaperInterface $escaper
 * @property \Phalcon\Annotations\Adapter\Memory|\Phalcon\Annotations\Adapter $annotations
 * @property \Phalcon\Mvc\Model\Manager|\Phalcon\Mvc\Model\ManagerInterface $modelsManager
 * @property \Phalcon\Mvc\Model\MetaData\Memory|\Phalcon\Mvc\Model\MetadataInterface $modelsMetadata
 * @property \Phalcon\Mvc\Model\Transaction\Manager|\Phalcon\Mvc\Model\Transaction\ManagerInterface $transactionManager
 * @property \Phalcon\Assets\Manager $assets
 * @property \Phalcon\Di|\Phalcon\Di\DiInterface $di
 * @property \Phalcon\Session\Bag|\Phalcon\Session\BagInterface $persistent
 * @property \Phalcon\Mvc\View|\Phalcon\Mvc\ViewInterface $view
 */
abstract class Injectable implements InjectionAwareInterface
{
    /**
     * Dependency Injector
     *
     * @var DiInterface|null
     */
    protected container = null;

    /**
     * Magic method __get
     */
    public function __get(string! propertyName) -> var | null
    {
        var container, service;

        let container = <DiInterface> this->getDI();

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
                    get_class(this),
                    container
                ]
            );

            return this->{"persistent"};
        }

        /**
         * Fallback to the PHP userland if the cache is not available
         */
        if container->has(propertyName) {
            let service = container->getShared(propertyName);
            let this->{propertyName} = service;

            return service;
        }

        /**
         * A notice is shown if the property is not defined and isn't a valid service
         */
        trigger_error("Access to undefined property " . propertyName);

        return null;
    }

    /**
     * Magic method __isset
     */
    public function __isset(string! name) -> bool
    {
        return this->getDI()->has(name);
    }

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface>
    {
        var container;

        let container = <DiInterface> this->container;

        if typeof container != "object" {
            let container = Di::getDefault();

            if unlikely typeof container != "object" {
                throw new Exception(
                    "A dependency injection container is required to access internal services"
                );
            }

            /**
             * Set container for future reuse on next `getDI()` calls.
             */
            this->setDI(container);
        }

        return container;
    }

    /**
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }
}
