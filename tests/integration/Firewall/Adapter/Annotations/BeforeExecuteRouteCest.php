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

use Codeception\Example;
use IntegrationTester;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Annotations;
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
     * Tests Phalcon\Firewall\Adapter\Annotations :: beforeExecuteRoute()
     *
     * @dataProvider getBeforeExecute
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-05-12
     */
    public function firewallAdapterAnnotationsBeforeExecuteRoute(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - beforeExecuteRoute()');

        $dispatcher = $this->dispatcher;
        $di         = $this->container;

        $di->set('dispatcher', $this->dispatcher);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            $example[0],
            $example[1],
            $example[2]
        );
        $I->assertEquals($returnedValue, $example[3]);
    }

    private function getBeforeExecute(): array
    {
        return [
            ['one', 'firstRole', 'ROLE1', 'allowed'],
            ['one', 'firstRole', 'ROLE2', null],
            ['one', 'firstRole', 'ROLE3', null],
            ['one', 'firstRole', new RoleObject('ROLE1'), 'allowed'],
            ['one', 'firstRole', new RoleObject('ROLE2'), null],
            ['one', 'firstRole', new RoleObject('ROLE3'), null],
            ['one', 'firstRole', ['ROLE1', 'ROLE2'], 'allowed'],
            ['one', 'firstRole', ['ROLE2', 'ROLE3'], null],
            ['one', 'firstRole', ['ROLE3', 'ROLE4'], null],
            ['one', 'secondRole', 'ROLE1', null],
            ['one', 'secondRole', 'ROLE2', 'allowed'],
            ['one', 'secondRole', 'ROLE3', 'allowed'],
            ['one', 'secondRole', new RoleObject('ROLE1'), null],
            ['one', 'secondRole', new RoleObject('ROLE2'), 'allowed'],
            ['one', 'secondRole', new RoleObject('ROLE3'), 'allowed'],
            ['one', 'secondRole', ['ROLE1', 'ROLE2'], null],
            ['one', 'secondRole', ['ROLE2', 'ROLE3'], 'allowed'],
            ['one', 'secondRole', ['ROLE3', 'ROLE4'], 'allowed'],
            ['one', 'firstArray', 'ROLE1', 'allowed'],
            ['one', 'firstArray', 'ROLE2', 'allowed'],
            ['one', 'firstArray', 'ROLE3', null],
            ['one', 'firstArray', new RoleObject('ROLE1'), 'allowed'],
            ['one', 'firstArray', new RoleObjecT('ROLE2'), 'allowed'],
            ['one', 'firstArray', new RoleObject('ROLE3'), null],
            ['one', 'firstArray', ['ROLE1', 'ROLE2'], 'allowed'],
            ['one', 'firstArray', ['ROLE2', 'ROLE3'], 'allowed'],
            ['one', 'firstArray', ['ROLE3', 'ROLE4'], null],
            ['one', 'secondArray', 'ROLE1', null],
            ['one', 'secondArray', 'ROLE2', null],
            ['one', 'secondArray', 'ROLE3', 'allowed'],
            ['one', 'secondArray', new RoleObject('ROLE1'), null],
            ['one', 'secondArray', new RoleObject('ROLE2'), null],
            ['one', 'secondArray', new RoleObject('ROLE3'), 'allowed'],
            ['one', 'secondArray', ['ROLE1', 'ROLE2'], null],
            ['one', 'secondArray', ['ROLE2', 'ROLE3'], null],
            ['one', 'allowEveryone', 'ROLE1', 'allowed'],
            ['one', 'allowEveryone', 'ROLE2', 'allowed'],
            ['one', 'allowEveryone', 'ROLE3', 'allowed'],
            ['one', 'allowEveryone', new RoleObject('ROLE1'), 'allowed'],
            ['one', 'allowEveryone', new RoleObject('ROLE2'), 'allowed'],
            ['one', 'allowEveryone', new RoleObject('ROLE3'), 'allowed'],
            ['one', 'allowEveryone', ['ROLE1', 'ROLE2'], 'allowed'],
            ['one', 'allowEveryone', ['ROLE2', 'ROLE3'], 'allowed'],
            ['one', 'allowEveryone', ['ROLE3', 'ROLE4'], 'allowed'],
            ['one', 'denyEveryone', 'ROLE1', null],
            ['one', 'denyEveryone', 'ROLE2', null],
            ['one', 'denyEveryone', 'ROLE3', null],
            ['one', 'denyEveryone', new RoleObject('ROLE1'), null],
            ['one', 'denyEveryone', new RoleObject('ROLE2'), null],
            ['one', 'denyEveryone', new RoleObject('ROLE3'), null],
            ['one', 'denyEveryone', ['ROLE1', 'ROLE2'], null],
            ['one', 'denyEveryone', ['ROLE2', 'ROLE3'], null],
            ['one', 'denyEveryone', ['ROLE3', 'ROLE4'], null],
            ['three', 'deny', 'ROLE1', null],
            ['three', 'deny', 'ROLE2', null],
            ['three', 'deny', 'ROLE3', null],
            ['three', 'deny', new RoleObject('ROLE1'), null],
            ['three', 'deny', new RoleObject('ROLE2'), null],
            ['three', 'deny', new RoleObject('ROLE3'), null],
            ['three', 'deny', ['ROLE1', 'ROLE2'], null],
            ['three', 'deny', ['ROLE2', 'ROLE3'], null],
            ['three', 'deny', ['ROLE3', 'ROLE4'], null],
        ];
    }
}
