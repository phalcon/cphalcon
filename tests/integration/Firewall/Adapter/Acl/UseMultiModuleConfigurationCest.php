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

namespace Phalcon\Test\Integration\Firewall\Adapter\Acl;

use IntegrationTester;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Enum;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Acl;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;

use function ob_end_clean;
use function ob_start;

class UseMultiModuleConfigurationCest
{
    use DiTrait;
    use FirewallTrait;

    /**
     * @var Dispatcher
     */
    protected $dispatcher;

    /**
     * @var Acl
     */
    protected $firewall;

    public function _before()
    {
        ob_start();

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace(
            'Phalcon\Test\Controllers\Firewall'
        );
        $dispatcher->setDI($this->container);
        $eventsManager = new Manager();
        $eventsManager->attach(
            'firewall:beforeException',
            function () {
                return false;
            }
        );
        $firewall = new Acl('acl');
        $firewall->setEventsManager($eventsManager);
        $firewall->setRoleCallback(
            function ($di) {
                return $di->get('myrole');
            }
        );
        $firewall->setAlwaysResolvingRole(true);
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
     * Tests Phalcon\Firewall\Adapter\Acl :: useMultiModuleConfiguration()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function firewallAdapterAclUseMultiModuleConfiguration(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - useMultiModuleConfiguration()');

        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addComponent('Module1:One', ['firstRole', 'secondRole']);
        $acl->addComponent('Module2:One', ['firstRole', 'secondRole']);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->allow('ROLE1', 'Module1:One', 'firstRole');
        $acl->deny('ROLE1', 'Module1:One', 'secondRole');
        $acl->deny('ROLE1', 'Module2:One', 'firstRole');
        $acl->allow('ROLE1', 'Module2:One', 'secondRole');
        $acl->deny('ROLE2', 'Module1:One', 'firstRole');
        $acl->allow('ROLE2', 'Module1:One', 'secondRole');
        $acl->allow('ROLE2', 'Module2:One', 'firstRole');
        $acl->deny('ROLE2', 'Module2:One', 'secondRole');

        $this->container->set('acl', $acl);
        $eventsManager = new Manager();
        $this->firewall->useMultiModuleConfiguration(true);
        $eventsManager->attach('dispatch:beforeExecuteRoute', $this->firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $this->container->set('dispatcher', $dispatcher);

        $examples = [
            ['one', 'firstRole', 'ROLE1', null, 'Module1', 'allowed'],
            ['one', 'firstRole', 'ROLE2', null, 'Module1', null],
            ['one', 'secondRole', 'ROLE1', null, 'Module1', null],
            ['one', 'secondRole', 'ROLE2', null, 'Module1', 'allowed'],
            ['one', 'firstRole', 'ROLE1', null, 'Module2', null],
            ['one', 'firstRole', 'ROLE2', null, 'Module2', 'allowed'],
            ['one', 'secondRole', 'ROLE1', null, 'Module2', 'allowed'],
            ['one', 'secondRole', 'ROLE2', null, 'Module2', null],
        ];

        foreach ($examples as $example) {
            $returnedValue = $this->getReturnedValueFor(
                $this->container,
                $dispatcher,
                $example[0],
                $example[1],
                $example[2],
                $example[3],
                $example[4]
            );
            $I->assertEquals($returnedValue, $example[5]);
        }
    }
}
