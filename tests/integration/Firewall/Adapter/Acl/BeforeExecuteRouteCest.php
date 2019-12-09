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
use Phalcon\Test\Fixtures\Firewall\RoleObject;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;

use function ob_end_clean;
use function ob_start;

class BeforeExecuteRouteCest
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
     * Tests Phalcon\Firewall\Adapter\Acl :: beforeExecuteRoute()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function firewallAdapterAclBeforeExecuteRoute(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - beforeExecuteRoute()');

        $acl = new Memory();

        $acl->setDefaultAction(Enum::DENY);

        $acl->addComponent('One', ['firstRole', 'secondRole']);

        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->addRole('ROLE3');
        $acl->addRole('ROLE4');

        $acl->allow('ROLE1', 'One', 'firstRole');
        $acl->deny('ROLE1', 'One', 'secondRole');
        $acl->deny('ROLE2', 'One', ['firstRole', 'secondRole']);
        $acl->allow('ROLE3', 'One', ['firstRole', 'secondRole']);
        $acl->deny('ROLE4', 'One', 'firstRole');
        $acl->allow('ROLE4', 'One', 'secondRole');

        $this->container->set('acl', $acl);

        $eventsManager = new Manager();

        $eventsManager->attach(
            'dispatch:beforeExecuteRoute',
            $this->firewall
        );

        $this->dispatcher->setEventsManager($eventsManager);

        $dispatcher = $this->dispatcher;

        $this->container->set('dispatcher', $dispatcher);

        $examples = [
            ['one', 'firstRole', 'ROLE1', 'allowed'],
            ['one', 'firstRole', 'ROLE2', null],
            ['one', 'firstRole', 'ROLE3', 'allowed'],
            ['one', 'firstRole', 'ROLE4', null],
            ['one', 'firstRole', new RoleObject('ROLE1'), 'allowed'],
            ['one', 'firstRole', new RoleObject('ROLE2'), null],
            ['one', 'firstRole', new RoleObject('ROLE3'), 'allowed'],
            ['one', 'firstRole', new RoleObject('ROLE4'), null],
            ['one', 'secondRole', 'ROLE1', null],
            ['one', 'secondRole', 'ROLE2', null],
            ['one', 'secondRole', 'ROLE3', 'allowed'],
            ['one', 'secondRole', 'ROLE4', 'allowed'],
            ['one', 'secondRole', new RoleObject('ROLE1'), null],
            ['one', 'secondRole', new RoleObject('ROLE2'), null],
            ['one', 'secondRole', new RoleObject('ROLE3'), 'allowed'],
            ['one', 'secondRole', new RoleObject('ROLE4'), 'allowed'],
        ];

        foreach ($examples as $example) {
            $returnedValue = $this->getReturnedValueFor(
                $this->container,
                $dispatcher,
                $example[0],
                $example[1],
                $example[2]
            );

            $I->assertEquals(
                $example[3],
                $returnedValue
            );
        }
    }
}
