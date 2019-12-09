<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Firewall\Adapter\Annotations;

use IntegrationTester;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Annotations;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;

use function ob_end_clean;
use function ob_start;

class SetCacheCest
{
    use DiTrait;
    use FirewallTrait;

    /**
     * @var Dispatcher
     */
    protected $dispatcher;

    /**
     * @var Annotations
     */
    protected $firewall;

    public function _before()
    {
        ob_start();

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $di         = $this->container;
        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace(
            'Phalcon\Test\Controllers\Firewall'
        );
        $dispatcher->setDI($di);

        $eventsManager = new Manager();
        $eventsManager->attach(
            'firewall:beforeException',
            function () {
                return false;
            }
        );
        $firewall = new Annotations(new Memory());
        $firewall->setEventsManager($eventsManager);
        $firewall->setRoleCallback(
            function () use ($di) {
                return $di->get('myrole');
            }
        );
        $eventsManager->attach('dispatch:beforeExecuteRoute', $firewall);
        $dispatcher->setEventsManager($eventsManager);
        $this->dispatcher = $dispatcher;
        $this->firewall   = $firewall;
    }

    public function _after()
    {
        ob_end_clean();

        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Firewall\Adapter\Annotations :: setCache()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsSetCache(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - setCache()');

        $serializer = new SerializerFactory();
        $factory    = new AdapterFactory($serializer);
        $cache      = $factory->newInstance('memory');

        $di            = $this->container;
        $eventsManager = new Manager();
        $eventsManager->attach(
            'firewall:beforeException',
            function () {
                return false;
            }
        );
        $firewall = new Annotations(new Memory());
        $firewall->setEventsManager($eventsManager);
        $firewall->setRoleCallback(
            function () use ($di) {
                return $di->get('myrole');
            }
        );
        $firewall->setAlwaysResolvingRole(true);
        $firewall->setCache($cache);
        $eventsManager->attach('dispatch:beforeExecuteRoute', $firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $di->set('dispatcher', $dispatcher);

        $examples = [
            ['one', 'firstRole', 'ROLE1', 'allowed', 'ROLE1!one!firstRole', true],
            ['one', 'allowEveryone', 'ROLE1', 'allowed', '*!one!allowEveryone', true],
            ['one', 'firstRole', 'ROLE2', null, 'ROLE2!one!firstRole', false],
        ];

        foreach ($examples as $example) {
            $returnedValue = $this->getReturnedValueFor(
                $di,
                $dispatcher,
                $example[0],
                $example[1],
                $example[2]
            );
            $I->assertEquals($returnedValue, $example[3]);
            $I->assertEquals($cache->get('_PHF_')[$example[4]], $example[5]);
        }
    }
}
