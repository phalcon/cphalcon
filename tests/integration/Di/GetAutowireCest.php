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

namespace Phalcon\Test\Integration\Di;

use Phalcon\Di;
use Phalcon\Di\Autowire;
use Phalcon\Di\Exception\BindException;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredInterface;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredThird;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedEighthClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedFirstClass;

class GetAutowireCest
{
    /**
     * Tests Phalcon\Di :: get() with autowire component
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-29
     */
    public function testGetNoService(\UnitTester $I)
    {
        $I->wantToTest('Tests Di::get() with autowire without services');

        $autowire = new Autowire([
            AutowiredInterface::class => AutowiredFirst::class
        ]);

        $di = new Di($autowire);
        $object = $di->get(ResolvedFirstClass::class);
        $I->assertInstanceOf(ResolvedFirstClass::class, $object);
        $I->assertInstanceOf(AutowiredFirst::class, $object->autowired);
    }

    /**
     * Tests Phalcon\Di :: get() with autowire component
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-29
     */
    public function testGetWithServices(\UnitTester $I)
    {
        $I->wantToTest('Tests Di::get() with autowire with services');

        $di = new Di(new Autowire());
        $di->set('autowired', AutowiredThird::class);

        $object = $di->get(ResolvedEighthClass::class);
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $test = $object->autowired->test;

        $object = $di->get(ResolvedEighthClass::class);
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $test2 = $object->autowired->test;

        $I->assertNotSame($test, $test2);
    }

    /**
     * Tests Phalcon\Di :: get() with autowire component
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-29
     */
    public function testWithEmptyBindAndNoService(\UnitTester $I)
    {
        $I->wantToTest('Tests Di::get() with autowire without services and binds');

        $di = new Di(new Autowire());

        $object = $di->get(ResolvedEighthClass::class);
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
    }

    /**
     * Tests Phalcon\Di :: get() with autowire component
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-29
     */
    public function testGetWithSharedService(\UnitTester $I)
    {
        $I->wantToTest('Tests Di::get() with autowire with shared service');

        $di = new Di(new Autowire());
        $di->setShared('autowired', AutowiredThird::class);

        $object = $di->get(ResolvedEighthClass::class);
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $test = $object->autowired->test;

        $object = $di->get(ResolvedEighthClass::class);
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $test2 = $object->autowired->test;

        $I->assertSame($test, $test2);
    }

    /**
     * Tests Phalcon\Di :: get() with autowire component
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-29
     */
    public function testGetWithAutowireTypesInterfaces(\UnitTester $I)
    {
        $I->wantToTest('Tests Di::get() with autowire types as interfaces');

        $di = new Di(new Autowire([
            AutowiredInterface::class => [AutowiredThird::class, AutowiredFirst::class],
        ]));

        $exception = new BindException("More than one possible definitions for class '" . AutowiredInterface::class . "', please provide
                     which implementation should be used for this class using setAutowireTypes on service or implement
                     one of the inerfaces - Phalcon\Di\AutowireTypesProviderInterface or Phalcon\Di\AutowireTypesStaticProviderInterface
                     depending if this is __construct or method autowiring");
        $I->expectThrowable($exception, function () use ($di) {
            $di->get(ResolvedFirstClass::class);
        });

        $object = $di->get(ResolvedFirstClass::class, [], [AutowiredInterface::class => AutowiredThird::class]);
        $I->assertInstanceOf(ResolvedFirstClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);

        $object = $di->get(ResolvedFirstClass::class, [], [AutowiredInterface::class => AutowiredFirst::class]);
        $I->assertInstanceOf(ResolvedFirstClass::class, $object);
        $I->assertInstanceOf(AutowiredFirst::class, $object->autowired);
    }

    /**
     * Tests Phalcon\Di :: get() with autowire component
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-29
     */
    public function testGetWithAutowireTypesServices(\UnitTester $I)
    {
        $I->wantToTest('Tests Di::get() with autowire types as service');

        $di = new Di(new Autowire([
            AutowiredThird::class => ['autowiredOne', 'autowiredTwo']
        ]));

        $authowiredOne = new AutowiredThird(123);
        $authowiredTwo = new AutowiredThird('asd');
        $di->set('autowiredOne', $authowiredOne);
        $di->set('autowiredTwo', $authowiredTwo);

        $exception = new BindException("More than one possible definitions for class '" . AutowiredThird::class . "', please provide
                     which implementation should be used for this class using setAutowireTypes on service or implement
                     one of the inerfaces - Phalcon\Di\AutowireTypesProviderInterface or Phalcon\Di\AutowireTypesStaticProviderInterface
                     depending if this is __construct or method autowiring");
        $I->expectThrowable($exception, function () use ($di) {
            $di->get(ResolvedEighthClass::class);
        });

        $object = $di->get(ResolvedEighthClass::class, [], [AutowiredThird::class => 'autowiredOne']);
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $I->assertSame($authowiredOne, $object->autowired);

        $object = $di->get(ResolvedEighthClass::class, [], [AutowiredThird::class => 'autowiredTwo']);
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $I->assertSame($authowiredTwo, $object->autowired);
    }

    /**
     * Tests Phalcon\Di :: get() with autowire component
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-29
     */
    public function testGetAutowireTypesDefinedOnService(\UnitTester $I)
    {
        $I->wantToTest('Tests Di::get() with autowire types defined on service');

        $di = new Di(new Autowire([
            AutowiredThird::class => ['autowiredOne', 'autowiredTwo']
        ]));

        $authowiredOne = new AutowiredThird(123);
        $authowiredTwo = new AutowiredThird('asd');

        $di->set('autowiredOne', $authowiredOne);
        $di->set('autowiredTwo', $authowiredTwo);

        $di->set('resolvedOne', ResolvedEighthClass::class)
            ->setAutowireTypes([AutowiredThird::class => 'autowiredOne']);
        $di->set('resolvedTwo', ResolvedEighthClass::class)
            ->setAutowireTypes([AutowiredThird::class => 'autowiredTwo']);

        $object = $di->get('resolvedOne');
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $I->assertSame($authowiredOne, $object->autowired);

        $object = $di->get('resolvedTwo');
        $I->assertInstanceOf(ResolvedEighthClass::class, $object);
        $I->assertInstanceOf(AutowiredThird::class, $object->autowired);
        $I->assertSame($authowiredTwo, $object->autowired);
    }
}
