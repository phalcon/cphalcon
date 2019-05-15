<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Firewall\Adapter\Annotations;

use function getOptionsModelCacheStream;
use Phalcon\Cache\Adapter\Memory;
use Phalcon\Cache\Adapter\Stream as StorageStream;
use Phalcon\Events\Manager;
use Phalcon\Firewall\Adapter\Annotations;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Firewall\RoleObject;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\FirewallTrait;
use UnitTester;

class AnnotationsCest
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
        $this->setNewFactoryDefault();
        $this->setDiMysql();

        $serializer = new SerializerFactory();
        $cache      = new Memory($serializer);

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
        $firewall = new Annotations($cache);
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
    }

    /**
     * Tests Annotations firewall before execute
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-18
     */
    public function testBeforeExecute(UnitTester $I)
    {
        $dispatcher = $this->dispatcher;
        $di = $this->container;
        
        $di->set('dispatcher', $this->dispatcher);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstRole", "ROLE1");
        
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstRole", "ROLE2");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstRole", "ROLE3");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstRole",
            new RoleObject("ROLE1")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstRole",
            new RoleObject("ROLE2")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstRole",
            new RoleObject("ROLE3")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstRole",
            ["ROLE1", "ROLE2"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstRole",
            ["ROLE2", "ROLE3"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstRole",
            ["ROLE3", "ROLE4"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "secondRole", "ROLE1");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "secondRole", "ROLE2");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "secondRole", "ROLE3");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondRole",
            new RoleObject("ROLE1")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondRole",
            new RoleObject("ROLE2")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondRole",
            new RoleObject("ROLE3")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondRole",
            ["ROLE1", "ROLE2"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondRole",
            ["ROLE2", "ROLE3"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondRole",
            ["ROLE3", "ROLE4"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstArray", "ROLE1");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstArray", "ROLE2");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstArray", "ROLE3");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstArray",
            new RoleObject("ROLE1")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstArray",
            new RoleObjecT("ROLE2")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstArray",
            new RoleObject("ROLE3")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstArray",
            ["ROLE1", "ROLE2"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstArray",
            ["ROLE2", "ROLE3"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "firstArray",
            ["ROLE3", "ROLE4"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "secondArray", "ROLE1");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "secondArray", "ROLE2");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "secondArray", "ROLE3");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondArray",
            new RoleObject("ROLE1")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondArray",
            new RoleObject("ROLE2")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondArray",
            new RoleObject("ROLE3")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondArray",
            ["ROLE1", "ROLE2"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondArray",
            ["ROLE2", "ROLE3"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "secondArray",
            ["ROLE3", "ROLE4"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "allowEveryone", "ROLE1");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "allowEveryone", "ROLE2");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "allowEveryone", "ROLE3");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "allowEveryone",
            new RoleObject("ROLE1")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "allowEveryone",
            new RoleObject("ROLE2")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "allowEveryone",
            new RoleObject("ROLE3")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "allowEveryone",
            ["ROLE1", "ROLE2"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "allowEveryone",
            ["ROLE2", "ROLE3"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "allowEveryone",
            ["ROLE3", "ROLE4"]
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "denyEveryone", "ROLE1");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "denyEveryone", "ROLE2");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "denyEveryone", "ROLE3");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "denyEveryone",
            new RoleObject("ROLE1")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "denyEveryone",
            new RoleObject("ROLE2")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "denyEveryone",
            new RoleObject("ROLE3")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "denyEveryone",
            ["ROLE1", "ROLE2"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "denyEveryone",
            ["ROLE2", "ROLE3"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "one",
            "denyEveryone",
            ["ROLE3", "ROLE4"]
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", "ROLE1");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", "ROLE2");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", "ROLE3");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "two",
            "allow",
            new RoleObject("ROLE1")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "two",
            "allow",
            new RoleObject("ROLE2")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "two",
            "allow",
            new RoleObject("ROLE3")
        );
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", ["ROLE1", "ROLE2"]);
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", ["ROLE2", "ROLE3"]);
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", ["ROLE3", "ROLE4"]);
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", "ROLE1");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", "ROLE2");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", "ROLE3");
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", ["ROLE1", "ROLE2"]);
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", ["ROLE2", "ROLE3"]);
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", ["ROLE3", "ROLE4"]);
        $I->assertEquals($returnedValue, "allowed");
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "three", "deny", "ROLE1");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "three", "deny", "ROLE2");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "three", "deny", "ROLE3");
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "three",
            "deny",
            new RoleObject("ROLE1")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "three",
            "deny",
            new RoleObject("ROLE2")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor(
            $di,
            $dispatcher,
            "three",
            "deny",
            new RoleObject("ROLE3")
        );
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "three", "deny", ["ROLE1", "ROLE2"]);
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "three", "deny", ["ROLE2", "ROLE3"]);
        $I->assertNull($returnedValue);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "three", "deny", ["ROLE3", "ROLE4"]);
        $I->assertNull($returnedValue);
    }

    /**
     * Tests Annotations firewall with cache
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-01-18
     */
    public function testCache(UnitTester $I)
    {
        $serializer = new SerializerFactory();
        $cache      = new Memory($serializer);

        $di = $this->container;
        $eventsManager = new Manager();
        $eventsManager->attach(
            'firewall:beforeException',
            function () {
                return false;
            }
        );
        $firewall = new Annotations($cache);
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

        $di->set('dispatcher', $dispatcher);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstRole", "ROLE1");
        $I->assertEquals($returnedValue, "allowed");
        $I->assertTrue($cache->has('_PHF_'));
        $I->assertTrue($cache->get('_PHF_')['ROLE1!one!firstRole']);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "allowEveryone", "ROLE1");
        $I->assertEquals($returnedValue, "allowed");
        $I->assertTrue($cache->get('_PHF_')['*!one!allowEveryone']);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "one", "firstRole", "ROLE2");
        $I->assertNull($returnedValue);
        $I->assertFalse($cache->get('_PHF_')['ROLE2!one!firstRole']);
        $returnedValue = $this->getReturnedValueFor($di, $dispatcher, "two", "allow", "ROLE1");
        $I->assertEquals($returnedValue, "allowed");
        $I->assertTrue($cache->get('_PHF_')['*!two!*']);
    }
}
