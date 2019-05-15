<?php

namespace Phalcon\Test\Unit\Firewall\Adapter\Acl;

use Codeception\Example;
use Phalcon\Acl as PhAcl;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Cache\Adapter\Stream as StorageStream;
use Phalcon\Cache\AdapterFactory;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Acl;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Firewall\BindingRole;
use Phalcon\Test\Fixtures\Firewall\RoleObject;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;
use Phalcon\Test\Models\AlbumORama\Albums;
use UnitTester;
use function getOptionsModelCacheStream;

class AclCest
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
        $firewall
            ->setEventsManager($eventsManager)
            ->setRoleCallback(
                function ($di) {
                    return $di->get('myrole');
                }
            )
            ->setAlwaysResolvingRole(true)
        ;
        $dispatcher->setEventsManager($eventsManager);
        $this->dispatcher = $dispatcher;
        $this->firewall   = $firewall;
    }

    /**
     * Tests Acl firewall before execute
     *
     * @dataProvider getBeforeExecute
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testBeforeExecute(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addComponent("One", ['firstRole', 'secondRole']);
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
        $eventsManager->attach('dispatch:beforeExecuteRoute', $this->firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $this->container->set('dispatcher', $dispatcher);

        $returnedValue = $this->getReturnedValueFor(
            $this->container,
            $dispatcher,
            $example[0],
            $example[1],
            $example[2]
        );
        $I->assertEquals($returnedValue, $example[3]);
    }

    /**
     * Tests Acl firewall after binding
     *
     * @dataProvider getAfterBinding
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testAfterBinding(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addComponent("Four", ['first', 'second']);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->allow('ROLE1', 'Four', 'first');
        $acl->allow('ROLE1', 'Four', 'second');
        $acl->allow(
            'ROLE2',
            'Four',
            'first',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow('ROLE2', 'Four', 'second');

        $this->container->set('acl', $acl);
        $binder = new Binder();
        $this->dispatcher->setModelBinder($binder);
        $eventsManager = new Manager();
        $eventsManager->attach('dispatch:afterBinding', $this->firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $this->container->set('dispatcher', $dispatcher);

        $returnedValue = $this->getReturnedValueFor(
            $this->container,
            $dispatcher,
            $example[0],
            $example[1],
            $example[2],
            $example[3]
        );
        $I->assertEquals($returnedValue, $example[4]);
    }

    /**
     * Tests Acl firewall after binding key map
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testAfterBindingKeyMap(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addComponent("Four", ['first', 'second']);
        $acl->addRole('ROLE2');
        $acl->allow(
            'ROLE2',
            'Four',
            'first',
            function (BindingRole $user, Albums $model) {
                return $user->getId() == $model->artists_id;
            }
        );
        $acl->allow('ROLE2', 'Four', 'second');

        $this->container->set('acl', $acl);
        $binder = new Binder();
        $this->dispatcher->setModelBinder($binder);
        $eventsManager = new Manager();
        $this->firewall->setBoundModelsKeyMap(['album' => 'model']);
        $eventsManager->attach('dispatch:afterBinding', $this->firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $this->container->set('dispatcher', $dispatcher);

        $returnedValue = $this->getReturnedValueFor(
            $this->container,
            $dispatcher,
            "four",
            "first",
            new BindingRole("ROLE2", 1),
            ['album' => 1]
        );
        $I->assertEquals($returnedValue, "allowed");
    }

    /**
     * Tests Acl firewall multi module
     *
     * @dataProvider getMultiModule
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-18
     */
    public function testMultiModule(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addComponent("Module1:One", ['firstRole', 'secondRole']);
        $acl->addComponent("Module2:One", ['firstRole', 'secondRole']);
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

    /**
     * Tests Acl firewall cache
     *
     * @dataProvider getCache
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testCache(UnitTester $I, Example $example)
    {
        $acl = new Memory();
        $acl->setDefaultAction(PhAcl::DENY);
        $acl->addComponent("Four", ['first', 'second']);
        $acl->addComponent("Three", ['deny',]);
        $acl->addRole('ROLE1');
        $acl->addRole('ROLE2');
        $acl->addRole('ROLE3');
        $acl->addRole('ROLE4');
        $acl->addRole('ROLE5');
        $acl->allow('ROLE1', 'Four', 'first');
        $acl->allow('ROLE1', 'Four', 'second');
        $acl->allow('ROLE1', 'Three', '*');
        $acl->allow('ROLE2', 'Four', 'second');
        $acl->allow(
            'ROLE2',
            'Four',
            'first',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow('ROLE3', '*', '*');
        $acl->allow(
            'ROLE4',
            'Four',
            '*',
            function (BindingRole $user, Albums $album) {
                return $user->getId() == $album->artists_id;
            }
        );
        $acl->allow(
            'ROLE5',
            '*',
            '*',
            function (BindingRole $user) {
                return $user->getId() == 3;
            }
        );

        $binder = new Binder();
        $this->dispatcher->setModelBinder($binder);
        $this->container->set('acl', $acl);
        $eventsManager = new Manager();

        $serializer   = new SerializerFactory();
        $factory      = new AdapterFactory($serializer);
        $cache        = $factory->newInstance('memory');

        $this->firewall->setCache($cache);
        $this->firewall->setRoleCacheCallback(
            function (BindingRole $user) {
                return $user->getId();
            }
        );
        $eventsManager->attach('dispatch:afterBinding', $this->firewall);
        $this->dispatcher->setEventsManager($eventsManager);
        $dispatcher = $this->dispatcher;
        $this->container->set('dispatcher', $dispatcher);

        $returnedValue = $this->getReturnedValueFor(
            $this->container,
            $dispatcher,
            $example[0],
            $example[1],
            $example[2],
            $example[3]
        );
        $I->assertEquals($returnedValue, $example[4]);
        $I->assertEquals($cache->get("_PHF_")[$example[5]], $example[6]);
    }

    private function getAfterBinding(): array
    {
        return [
            ["four", "first", new BindingRole("ROLE1", 1), ['album' => 1], "allowed"],
            ["four", "first", new BindingRole("ROLE1", 2), ['album' => 1], "allowed"],
            ["four", "first", new BindingRole("ROLE2", 1), ['album' => 1], "allowed"],
            ["four", "first", new BindingRole("ROLE2", 2), ['album' => 1], null],
            ["four", "second", new BindingRole("ROLE1", 1), ['album' => 1], "allowed"],
            ["four", "second", new BindingRole("ROLE1", 2), ['album' => 1], "allowed"],
            ["four", "second", new BindingRole("ROLE2", 1), ['album' => 1], "allowed"],
            ["four", "second", new BindingRole("ROLE2", 2), ['album' => 1], "allowed"],
        ];
    }

    private function getBeforeExecute(): array
    {
        return [
            ["one", "firstRole", "ROLE1", "allowed"],
            ["one", "firstRole", "ROLE2", null],
            ["one", "firstRole", "ROLE3", "allowed"],
            ["one", "firstRole", "ROLE4", null],
            ["one", "firstRole", new RoleObject("ROLE1"), "allowed"],
            ["one", "firstRole", new RoleObject("ROLE2"), null],
            ["one", "firstRole", new RoleObject("ROLE3"), "allowed"],
            ["one", "firstRole", new RoleObject("ROLE4"), null],
            ["one", "secondRole", "ROLE1", null],
            ["one", "secondRole", "ROLE2", null],
            ["one", "secondRole", "ROLE3", "allowed"],
            ["one", "secondRole", "ROLE4", "allowed"],
            ["one", "secondRole", new RoleObject("ROLE1"), null],
            ["one", "secondRole", new RoleObject("ROLE2"), null],
            ["one", "secondRole", new RoleObject("ROLE3"), "allowed"],
            ["one", "secondRole", new RoleObject("ROLE4"), "allowed"],
        ];
    }

    private function getMultiModule(): array
    {
        return [
            ["one", "firstRole", "ROLE1", null, "Module1", "allowed"],
            ["one", "firstRole", "ROLE2", null, "Module1", null],
            ["one", "secondRole", "ROLE1", null, "Module1", null],
            ["one", "secondRole", "ROLE2", null, "Module1", "allowed"],
            ["one", "firstRole", "ROLE1", null, "Module2", null],
            ["one", "firstRole", "ROLE2", null, "Module2", "allowed"],
            ["one", "secondRole", "ROLE1", null, "Module2", "allowed"],
            ["one", "secondRole", "ROLE2", null, "Module2", null],
        ];
    }

    private function getCache(): array
    {
        return [
            ["four", "first", new BindingRole("ROLE1", 1), ['album' => 1], "allowed", 'ROLE1!Four!first', true],
            ["four", "first", new BindingRole("ROLE1", 2), ['album' => 1], "allowed", 'ROLE1!Four!first', true],
            ["four", "first", new BindingRole("ROLE2", 1), ['album' => 1], "allowed", 'ROLE2!Four!first!1!1', true],
            ["four", "first", new BindingRole("ROLE2", 2), ['album' => 1], null, 'ROLE2!Four!first!1!2', false],
            ["four", "second", new BindingRole("ROLE1", 1), ['album' => 1], "allowed", 'ROLE1!Four!second', true],
            ["four", "second", new BindingRole("ROLE1", 2), ['album' => 1], "allowed", 'ROLE1!Four!second', true],
            ["four", "second", new BindingRole("ROLE2", 1), ['album' => 1], "allowed", 'ROLE2!Four!second', true],
            ["four", "second", new BindingRole("ROLE2", 2), ['album' => 1], "allowed", 'ROLE2!Four!second', true],
            ["three", "deny", new BindingRole("ROLE1", 2), ['album' => 1], "allowed", 'ROLE1!Three!*', true],
            ["four", "first", new BindingRole("ROLE4", 1), ['album' => 1], "allowed", 'ROLE4!Four!*!1!1', true],
            ["four", "first", new BindingRole("ROLE4", 2), ['album' => 1], null, 'ROLE4!Four!*!1!2', false],
            ["three", "deny", new BindingRole("ROLE5", 2), ['album' => 1], null, 'ROLE5!*!*!2', false],
            ["three", "deny", new BindingRole("ROLE5", 3), ['album' => 1], "allowed", 'ROLE5!*!*!3', true],
        ];
    }
}
