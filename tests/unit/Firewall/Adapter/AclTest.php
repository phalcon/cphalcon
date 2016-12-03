<?php

namespace Phalcon\Test\Unit\Firewall\Adapter;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Unit\Firewall\Helper\BindingRole;
use Phalcon\Test\Unit\Firewall\Helper\FirewallTrait;
use Phalcon\Firewall\Adapter\Acl;
use Phalcon\Test\Unit\Firewall\Helper\RoleObject;
use Phalcon\Mvc\Model\Binder;
use PHPUnit_Framework_Exception;

/**
 * \Phalcon\Test\Unit\Firewall\Adapter\AclTest
 * Tests the Phalcon\Firewall\Adapter\Acl component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Flash
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class AclTest extends UnitTest
{
    use FirewallTrait;

    /**
     * @var Dispatcher
     */
    protected $dispatcher;

    /**
     * @var Acl
     */
    protected $firewall;

    /**
     * @var Di
     */
    protected $di;

    public function _before()
    {
        $di = $this->tester->getApplication()->getDI();
        $dispatcher = new Dispatcher();
        $dispatcher->setDefaultNamespace('Phalcon\Test\Unit\Firewall\Helper\Controllers');
        $dispatcher->setDI($di);
        $eventsManager = new Manager();
        $eventsManager->attach(
            'firewall:beforeException',
            function () {
                return false;
            }
        );
        $firewall = new Acl('acl');
        $firewall->setEventsManager($eventsManager)
            ->setRoleCallback(
                function ($di) {
                    return $di->get('myrole');
                }
            )
            ->setAlwaysResolvingRole(true);
        $dispatcher->setEventsManager($eventsManager);
        $this->dispatcher = $dispatcher;
        $this->firewall = $firewall;
        $this->di = $di;
    }

    /**
     * Tests Acl firewall before execute
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testBeforeExecute()
    {
        $this->specify(
            "Acl firewall doesn't work correctly for beforeExecute event",
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addResource("Test11", ['firstRole', 'secondRole']);
                $acl->addRole('ROLE1');
                $acl->addRole('ROLE2');
                $acl->addRole('ROLE3');
                $acl->addRole('ROLE4');
                $acl->allow('ROLE1', 'Test11', 'firstRole');
                $acl->deny('ROLE1', 'Test11', 'secondRole');
                $acl->deny('ROLE2', 'Test11', ['firstRole', 'secondRole']);
                $acl->allow('ROLE3', 'Test11', ['firstRole', 'secondRole']);
                $acl->deny('ROLE4', 'Test11', 'firstRole');
                $acl->allow('ROLE4', 'Test11', 'secondRole');

                $this->di->set('acl', $acl);
                $eventsManager = new Manager();
                $eventsManager->attach('dispatch:beforeExecuteRoute', $this->firewall);
                $this->dispatcher->setEventsManager($eventsManager);
                $dispatcher = $this->dispatcher;
                $this->di->set('dispatcher', $dispatcher);
                $di = $this->di;

                expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE1");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE2");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE3");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE4");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    new RoleObject("ROLE2")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    new RoleObject("ROLE3")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    new RoleObject("ROLE4")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE1");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE2");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE3");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE4");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    new RoleObject("ROLE2")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    new RoleObject("ROLE3")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    new RoleObject("ROLE4")
                );
                expect($returnedValue)->equals("allowed");
            }
        );
    }

    /**
     * Tests Acl firewall after binding
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testAfterBinding()
    {
        $this->specify(
            "Acl firewall doesn't work correctly with afterBinding event.",
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addResource("Test14", ['first', 'second']);
                $acl->addRole('ROLE1');
                $acl->addRole('ROLE2');
                $acl->allow('ROLE1', 'Test14', 'first');
                $acl->allow('ROLE1', 'Test14', 'second');
                $acl->allow(
                    'ROLE2',
                    'Test14',
                    'first',
                    function (BindingRole $user, Albums $album) {
                        return $user->getId() == $album->artists_id;
                    }
                );
                $acl->allow('ROLE2', 'Test14', 'second');

                $this->di->set('acl', $acl);
                $binder = new Binder();
                $this->dispatcher->setModelBinder($binder);
                $eventsManager = new Manager();
                $eventsManager->attach('dispatch:afterBinding', $this->firewall);
                $this->dispatcher->setEventsManager($eventsManager);
                $dispatcher = $this->dispatcher;
                $this->di->set('dispatcher', $dispatcher);

                expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
                $di = $this->di;
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE1", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE1", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE2", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE2", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE1", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE1", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE2", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE2", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
            }
        );
    }

    /**
     * Tests Acl firewall after binding key map
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testAfterBindingKeyMap()
    {
        $this->specify(
            "Acl firewall key map doesn't work correctly with afterBinding event.",
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addResource("Test14", ['first', 'second']);
                $acl->addRole('ROLE2');
                $acl->allow(
                    'ROLE2',
                    'Test14',
                    'first',
                    function (BindingRole $user, Albums $model) {
                        return $user->getId() == $model->artists_id;
                    }
                );
                $acl->allow('ROLE2', 'Test14', 'second');

                $this->di->set('acl', $acl);
                $binder = new Binder();
                $this->dispatcher->setModelBinder($binder);
                $eventsManager = new Manager();
                $this->firewall->setBoundModelsKeyMap(['album' => 'model']);
                $eventsManager->attach('dispatch:afterBinding', $this->firewall);
                $this->dispatcher->setEventsManager($eventsManager);
                $dispatcher = $this->dispatcher;
                $this->di->set('dispatcher', $dispatcher);

                expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
                $di = $this->di;
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE2", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
            }
        );
    }

    /**
     * Tests Acl firewall multi module
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-18
     */
    public function testMultiModule()
    {
        $this->specify(
            "Acl firewall doesn't work correctly with multi module configuration",
            function () {
                $acl = new Memory();
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addResource("Module1:Test11", ['firstRole', 'secondRole']);
                $acl->addResource("Module2:Test11", ['firstRole', 'secondRole']);
                $acl->addRole('ROLE1');
                $acl->addRole('ROLE2');
                $acl->allow('ROLE1', 'Module1:Test11', 'firstRole');
                $acl->deny('ROLE1', 'Module1:Test11', 'secondRole');
                $acl->deny('ROLE1', 'Module2:Test11', 'firstRole');
                $acl->allow('ROLE1', 'Module2:Test11', 'secondRole');
                $acl->deny('ROLE2', 'Module1:Test11', 'firstRole');
                $acl->allow('ROLE2', 'Module1:Test11', 'secondRole');
                $acl->allow('ROLE2', 'Module2:Test11', 'firstRole');
                $acl->deny('ROLE2', 'Module2:Test11', 'secondRole');

                $this->di->set('acl', $acl);
                $eventsManager = new Manager();
                $this->firewall->useMultiModuleConfiguration(true);
                $eventsManager->attach('dispatch:beforeExecuteRoute', $this->firewall);
                $this->dispatcher->setEventsManager($eventsManager);
                $dispatcher = $this->dispatcher;
                $this->di->set('dispatcher', $dispatcher);
                $di = $this->di;

                expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    "ROLE1",
                    null,
                    "Module1"
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    "ROLE2",
                    null,
                    "Module1"
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    "ROLE1",
                    null,
                    "Module1"
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    "ROLE2",
                    null,
                    "Module1"
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    "ROLE1",
                    null,
                    "Module2"
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    "ROLE2",
                    null,
                    "Module2"
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    "ROLE1",
                    null,
                    "Module2"
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    "ROLE2",
                    null,
                    "Module2"
                );
                expect($returnedValue)->null();
            }
        );

    }

    /**
     * Tests Acl firewall cache
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-19
     */
    public function testCache()
    {
        $this->specify(
            "Acl firewall for dispatcher doesn't work properly with cache.",
            function () {

                $acl = new Memory();
                $acl->setDefaultAction(\Phalcon\Acl::DENY);
                $acl->addResource("Test14", ['first', 'second']);
                $acl->addResource("Test13", ['deny',]);
                $acl->addRole('ROLE1');
                $acl->addRole('ROLE2');
                $acl->addRole('ROLE3');
                $acl->addRole('ROLE4');
                $acl->addRole('ROLE5');
                $acl->allow('ROLE1', 'Test14', 'first');
                $acl->allow('ROLE1', 'Test14', 'second');
                $acl->allow('ROLE1', 'Test13', '*');
                $acl->allow('ROLE2', 'Test14', 'second');
                $acl->allow(
                    'ROLE2',
                    'Test14',
                    'first',
                    function (BindingRole $user, Albums $album) {
                        return $user->getId() == $album->artists_id;
                    }
                );
                $acl->allow('ROLE3', '*', '*');
                $acl->allow(
                    'ROLE4',
                    'Test14',
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

                $this->di->set('acl', $acl);
                $binder = new Binder();
                $this->dispatcher->setModelBinder($binder);
                $eventsManager = new Manager();
                $cache = new Apc(new Data(['lifetime' => 20]));
                $this->firewall->setCache($cache);
                $this->firewall->setRoleCacheCallback(
                    function (BindingRole $user) {
                        return $user->getId();
                    }
                );
                $eventsManager->attach('dispatch:afterBinding', $this->firewall);
                $this->dispatcher->setEventsManager($eventsManager);
                $dispatcher = $this->dispatcher;
                $this->di->set('dispatcher', $dispatcher);

                expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
                $di = $this->di;
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE1", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->exists("_PHF_"));
                expect($cache->get("_PHF_")['ROLE1!Test14!first'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE1", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE1!Test14!first'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE2", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE2!Test14!first!1!1'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE2", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->null();
                expect($cache->get("_PHF_")['ROLE2!Test14!first!1!2'])->false();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE1", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE1!Test14!second'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE1", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE1!Test14!second'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE2", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE2!Test14!second'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "second",
                    new BindingRole("ROLE2", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE2!Test14!second'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test13",
                    "deny",
                    new BindingRole("ROLE1", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE1!Test13!*'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE4", 1),
                    ['album' => 1]
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE4!Test14!*!1!1'])->true();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test14",
                    "first",
                    new BindingRole("ROLE4", 2),
                    ['album' => 1]
                );
                expect($returnedValue)->null();
                expect($cache->get("_PHF_")['ROLE4!Test14!*!1!2'])->false();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test13",
                    "deny",
                    new BindingRole("ROLE5", 2)
                );
                expect($returnedValue)->null();
                expect($cache->get("_PHF_")['ROLE5!*!*!2'])->false();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test13",
                    "deny",
                    new BindingRole("ROLE5", 3)
                );
                expect($returnedValue)->equals("allowed");
                expect($cache->get("_PHF_")['ROLE5!*!*!3'])->true();
            }
        );
    }
}
