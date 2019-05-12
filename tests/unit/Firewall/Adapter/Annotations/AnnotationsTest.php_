<?php

namespace Phalcon\Test\Unit\Firewall\Adapter;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Cache\Backend\Apc;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Firewall\Adapter\Annotations;
use Phalcon\Test\Unit\Firewall\Helper\FirewallTrait;
use Phalcon\Test\Unit\Firewall\Helper\RoleObject;

/**
 * \Phalcon\Test\Unit\Firewall\Adapter\AnnotationsTest
 * Tests the Phalcon\Firewall\Adapter\Annotations component
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
class AnnotationsTest extends UnitTest
{
    use FirewallTrait;

    /**
     * @var Dispatcher
     */
    protected $dispatcher;

    /**
     * @var Annotations
     */
    protected $firewall;

    /**
     * @var Di
     */
    protected $di;

    public function _before()
    {
        $di = new FactoryDefault();
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
        $firewall = new Annotations(new Memory());
        $firewall->setEventsManager($eventsManager)
            ->setRoleCallback(
                function ($di) {
                    return $di->get('myrole');
                }
            )
            ->setAlwaysResolvingRole(true);
        $eventsManager->attach('dispatch:beforeExecuteRoute', $firewall);
        $dispatcher->setEventsManager($eventsManager);
        $this->dispatcher = $dispatcher;
        $this->firewall = $firewall;
        $this->di = $di;
    }

    /**
     * Tests Annotations firewall before execute
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-18
     */
    public function testBeforeExecute()
    {
        $this->specify(
            "Annotations firewall doesn't work correctly.",
            function () {
                $di = $this->di;
                $dispatcher = $this->dispatcher;

                expect($this->dispatcher->getDI())->isInstanceOf('Phalcon\Di');
                $di->set('dispatcher', $this->dispatcher);
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE1");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE2");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE3");
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
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    ["ROLE1", "ROLE2"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    ["ROLE2", "ROLE3"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstRole",
                    ["ROLE3", "ROLE4"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE1");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE2");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondRole", "ROLE3");
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
                expect($returnedValue)->equals("allowed");
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
                    ["ROLE1", "ROLE2"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    ["ROLE2", "ROLE3"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondRole",
                    ["ROLE3", "ROLE4"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", "ROLE1");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", "ROLE2");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstArray", "ROLE3");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstArray",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstArray",
                    new RoleObjecT("ROLE2")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstArray",
                    new RoleObject("ROLE3")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstArray",
                    ["ROLE1", "ROLE2"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstArray",
                    ["ROLE2", "ROLE3"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "firstArray",
                    ["ROLE3", "ROLE4"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", "ROLE1");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", "ROLE2");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "secondArray", "ROLE3");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondArray",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondArray",
                    new RoleObject("ROLE2")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondArray",
                    new RoleObject("ROLE3")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondArray",
                    ["ROLE1", "ROLE2"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondArray",
                    ["ROLE2", "ROLE3"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "secondArray",
                    ["ROLE3", "ROLE4"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", "ROLE1");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", "ROLE2");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", "ROLE3");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "allowEveryone",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "allowEveryone",
                    new RoleObject("ROLE2")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "allowEveryone",
                    new RoleObject("ROLE3")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "allowEveryone",
                    ["ROLE1", "ROLE2"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "allowEveryone",
                    ["ROLE2", "ROLE3"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "allowEveryone",
                    ["ROLE3", "ROLE4"]
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", "ROLE1");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", "ROLE2");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "denyEveryone", "ROLE3");
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "denyEveryone",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "denyEveryone",
                    new RoleObject("ROLE2")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "denyEveryone",
                    new RoleObject("ROLE3")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "denyEveryone",
                    ["ROLE1", "ROLE2"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "denyEveryone",
                    ["ROLE2", "ROLE3"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test11",
                    "denyEveryone",
                    ["ROLE3", "ROLE4"]
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE1");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE2");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE3");
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test12",
                    "allow",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test12",
                    "allow",
                    new RoleObject("ROLE2")
                );
                expect($returnedValue)->equals("allowed");
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test12",
                    "allow",
                    new RoleObject("ROLE3")
                );
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
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test13",
                    "deny",
                    new RoleObject("ROLE1")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test13",
                    "deny",
                    new RoleObject("ROLE2")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor(
                    $di,
                    $dispatcher,
                    "test13",
                    "deny",
                    new RoleObject("ROLE3")
                );
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", ["ROLE1", "ROLE2"]);
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", ["ROLE2", "ROLE3"]);
                expect($returnedValue)->null();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test13", "deny", ["ROLE3", "ROLE4"]);
                expect($returnedValue)->null();
            }
        );
    }

    /**
     * Tests Annotations firewall with cache
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-18
     */
    public function testCache()
    {
        $this->specify(
            "Testing firewall with annotations configuration and cache.",
            function () {
                $cache = new Apc(new Data(['lifetime' => 20]));
                $this->firewall->setCache($cache);
                $di = $this->di;
                $eventsManager = new Manager();
                $eventsManager->attach(
                    'firewall:beforeException',
                    function () {
                        return false;
                    }
                );
                $firewall = new Annotations(new Memory());
                $firewall->setEventsManager($eventsManager)
                    ->setRoleCallback(
                        function ($di) {
                            return $di->get('myrole');
                        }
                    )
                    ->setAlwaysResolvingRole(true);
                $firewall->setCache($cache);
                $eventsManager->attach('dispatch:beforeExecuteRoute', $firewall);
                $this->dispatcher->setEventsManager($eventsManager);
                $dispatcher = $this->dispatcher;

                expect($dispatcher->getDI())->isInstanceOf('Phalcon\Di');
                $di->set('dispatcher', $dispatcher);
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE1");
                expect($returnedValue)->equals("allowed");
                expect($cache->exists('_PHF_'))->true();
                expect($cache->get('_PHF_')['ROLE1!test11!firstRole'])->true();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "allowEveryone", "ROLE1");
                expect($returnedValue)->equals("allowed");
                expect($cache->get('_PHF_')['*!test11!allowEveryone'])->true();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test11", "firstRole", "ROLE2");
                expect($returnedValue)->null();
                expect($cache->get('_PHF_')['ROLE2!test11!firstRole'])->false();
                $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "test12", "allow", "ROLE1");
                expect($returnedValue)->equals("allowed");
                expect($cache->get('_PHF_')['*!test12!*'])->true();
            }
        );
    }
}
