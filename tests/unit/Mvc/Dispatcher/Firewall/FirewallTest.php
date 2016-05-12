<?php

namespace Phalcon\Test\Unit\Mvc\Dispatcher\Firewall;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Http\Response;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Dispatcher\Firewall\Adapter\Acl;
use Phalcon\Mvc\Dispatcher\Firewall\Adapter\Annotations;
use Phalcon\Test\Models\AlbumORama\Albums;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\BindingRole;
use Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\RoleObject;

/**
 * \Phalcon\Test\Unit\Mvc\Dispatcher\FirewallTest
 * Tests the \Phalcon\Test\Unit\Mvc\Dispatcher\Firewall component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Mvc\Dispatcher\Firewall
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FirewallTest extends UnitTest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher\Firewall\Adapter\Annotations
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-24
     */
    public function testAnnotations()
    {
        $this->specify("Testing firewall with annotations configuration.", function () {
            $di = new Di();
            $response = new Response();
            $di->set('response', $response);
            $dispatcher = new Dispatcher;
            $dispatcher->setDefaultNamespace('Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\Controllers');
            $dispatcher->setDI($di);
            $eventsManager = new Manager();
            $eventsManager->attach('firewall:beforeException', function () {
                return false;
            });
            $firewall = new Annotations(new \Phalcon\Annotations\Adapter\Memory());
            $firewall->setEventsManager($eventsManager);
            $firewall->setRoleCallback(function () use ($di) {
                return $di->get('myrole');
            });
            $eventsManager = new Manager();
            $eventsManager->attach('dispatch:beforeExecuteRoute', $firewall);
            $dispatcher->setEventsManager($eventsManager);
            expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
            $di->set('dispatcher', $dispatcher);
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE2");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE3");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", new RoleObject("ROLE1"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", new RoleObject("ROLE2"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", new RoleObject("ROLE3"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE1");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE2");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE3");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", new RoleObject("ROLE1"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", new RoleObject("ROLE2"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", new RoleObject("ROLE3"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", "ROLE1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", "ROLE2");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", "ROLE3");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", new RoleObject("ROLE1"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", new RoleObjecT("ROLE2"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", new RoleObject("ROLE3"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", "ROLE1");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", "ROLE2");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", "ROLE3");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", new RoleObject("ROLE1"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", new RoleObject("ROLE2"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", new RoleObject("ROLE3"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", "ROLE1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", "ROLE2");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", "ROLE3");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", new RoleObject("ROLE1"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", new RoleObject("ROLE2"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", new RoleObject("ROLE3"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", "ROLE1");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", "ROLE2");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", "ROLE3");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", new RoleObject("ROLE1"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", new RoleObject("ROLE2"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", new RoleObject("ROLE3"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE2");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE3");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", new RoleObject("ROLE1"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", new RoleObject("ROLE2"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", new RoleObject("ROLE3"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE2");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE3");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", "ROLE1");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", "ROLE2");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", "ROLE3");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", new RoleObject("ROLE1"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", new RoleObject("ROLE2"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", new RoleObject("ROLE3"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", ["ROLE1", "ROLE2"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", ["ROLE2", "ROLE3"]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", ["ROLE3", "ROLE4"]);
            expect($returnedValue)->null();
        });
    }

    /**
     * @param $di
     * @param Dispatcher $dispatcher
     * @param $controllerName
     * @param $actionName
     * @param $roleName
     * @param array $params
     * @param string $moduleName
     *
     * @return mixed
     */
    private function getReturnedValueFor($di, $dispatcher, $controllerName, $actionName, $roleName, $params = null, $moduleName = null)
    {
        $dispatcher->setReturnedValue(null);
        $this->changeRole($di, $roleName);
        $dispatcher->setControllerName($controllerName);
        $dispatcher->setActionName($actionName);
        if (!empty($moduleName)) {
            $dispatcher->setModuleName($moduleName);
        }
        if (!empty($params)) {
            $dispatcher->setParams($params);
        }
        $dispatcher->dispatch();
        return $dispatcher->getReturnedValue();
    }

    /**
     * @param Di $di
     * @param $role
     */
    private function changeRole($di, $role)
    {
        $di->set('myrole', function () use ($role) {
            return $role;
        });
    }

    /**
     * Tests Phalcon\Mvc\Dispatcher\Firewall\Adapter\Acl when using it as beforeExecute in Dispatcher
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-24
     */
    public function testAclBeforeExecute()
    {
        $this->specify("Testing firewall with acl configuration and beforeExecute.", function () {
            $di = new Di();
            $response = new Response();
            $di->set('response', $response);
            $acl = new Memory();
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
            $di->set('acl', $acl);
            $dispatcher = new Dispatcher();
            $dispatcher->setDefaultNamespace('Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\Controllers');
            $dispatcher->setDI($di);
            $eventsManager = new Manager();
            $eventsManager->attach('firewall:beforeException', function () {
                return false;
            });
            $firewall = new Acl("acl");
            $firewall->setEventsManager($eventsManager);
            $firewall->setRoleCallback(function () use ($di) {
                return $di->get('myrole');
            });
            $eventsManager = new Manager();
            $eventsManager->attach('dispatch:beforeExecuteRoute', $firewall);
            $dispatcher->setEventsManager($eventsManager);
            expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
            $di->set('dispatcher', $dispatcher);
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE2");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE3");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE4");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", new RoleObject("ROLE1"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", new RoleObject("ROLE2"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", new RoleObject("ROLE3"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", new RoleObject("ROLE4"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE1");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE2");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE3");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE4");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", new RoleObject("ROLE1"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", new RoleObject("ROLE2"));
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", new RoleObject("ROLE3"));
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", new RoleObject("ROLE4"));
            expect($returnedValue)->equals("allowed");
        });
    }

    /**
     * Tests Phalcon\Mvc\Dispatcher\Firewall\Adapter\Acl when using it as afterBinding in Dispatcher
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-24
     */
    public function testAclAfterBinding()
    {
        $this->specify("Testing firewall with acl configuration and afterBinding.", function () {
            $di = new FactoryDefault();
            $response = new Response();
            $di->set('response', $response);
            $acl = new Memory();
            $acl->addResource("Test14", ['first', 'second']);
            $acl->addRole('ROLE1');
            $acl->addRole('ROLE2');
            $acl->allow('ROLE1', 'Test14', 'first');
            $acl->allow('ROLE1', 'Test14', 'second');
            $acl->allow('ROLE2', 'Test14', 'first', function (BindingRole $user, Albums $model) {
                return $user->getId() == $model->artists_id;
            });
            $acl->allow('ROLE2', 'Test14', 'second');
            $di->set('acl', $acl);
            $dispatcher = new Dispatcher();
            $dispatcher->setModelBinding(true);
            $dispatcher->setDefaultNamespace('Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\Controllers');
            $dispatcher->setDI($di);
            $eventsManager = new Manager();
            $eventsManager->attach('firewall:beforeException', function () {
                return false;
            });
            $firewall = new Acl("acl", "model");
            $firewall->setEventsManager($eventsManager);
            $firewall->setRoleCallback(function () use ($di) {
                return $di->get('myrole');
            });
            $eventsManager = new Manager();
            $eventsManager->attach('dispatch:afterBinding', $firewall);
            $dispatcher->setEventsManager($eventsManager);
            expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
            $di->set('dispatcher', $dispatcher);
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "first", new BindingRole("ROLE1",1), [0=>1]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "first", new BindingRole("ROLE1",2), [0=>1]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "first", new BindingRole("ROLE2",1), [0=>1]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "first", new BindingRole("ROLE2",2), [0=>1]);
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "second", new BindingRole("ROLE1",1), [0=>1]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "second", new BindingRole("ROLE1",2), [0=>1]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "second", new BindingRole("ROLE2",1), [0=>1]);
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test14", "second", new BindingRole("ROLE2",2), [0=>1]);
            expect($returnedValue)->equals("allowed");
        });
    }

    /**
     * Tests Phalcon\Mvc\Dispatcher\Firewall\Adapter\Acl when using it as beforeExecute and multi-module application
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-03-24
     */
    public function testMultiModule()
    {
        $this->specify("Testing firewall with acl configuration and beforeExecute with multi-module application.", function () {
            $di = new Di();
            $response = new Response();
            $di->set('response', $response);
            $acl = new Memory();
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
            $di->set('acl', $acl);
            $dispatcher = new Dispatcher();
            $dispatcher->setDefaultNamespace('Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\Controllers');
            $dispatcher->setDI($di);
            $eventsManager = new Manager();
            $eventsManager->attach('firewall:beforeException', function () {
                return false;
            });
            $firewall = new Acl("acl");
            $firewall->setEventsManager($eventsManager);
            $firewall->setRoleCallback(function () use ($di) {
                return $di->get('myrole');
            });
            $firewall->useMultiModuleConfiguration(true);
            $eventsManager = new Manager();
            $eventsManager->attach('dispatch:beforeExecuteRoute', $firewall);
            $dispatcher->setEventsManager($eventsManager);
            expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
            $di->set('dispatcher', $dispatcher);
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE1", null, "Module1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE2", null, "Module1");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE1", null, "Module1");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE2", null, "Module1");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE1", null, "Module2");
            expect($returnedValue)->null();
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE2", null, "Module2");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE1", null, "Module2");
            expect($returnedValue)->equals("allowed");
            $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE2", null, "Module2");
            expect($returnedValue)->null();
        });
    }
}
