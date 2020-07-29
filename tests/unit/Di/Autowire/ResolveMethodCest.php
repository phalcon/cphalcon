<?php

declare(strict_types=1);

namespace Phalcon\Test\Unit\Di\Autowire;

use Codeception\Util\Stub;
use Phalcon\Di\Autowire;
use Phalcon\Di\DiInterface;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredInterface;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredSecond;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedFirstClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedFourthClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedSeventhClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedSixthClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolveFifthClass;
use UnitTester;

class ResolveMethodCest
{
    /**
     * Tests Phalcon\Di\Autowire :: resolveMethod()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolve(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolveMethod()');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function($name) use ($I) {
            $I->assertEquals(AutowiredFirst::class, $name);

            return new AutowiredFirst();
        }]);

        $object = new ResolveFifthClass();

        $I->assertNull($object->autowired);

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        /** @var ResolvedFirstClass $object */
        $autowire->resolveMethod($diStub, $object, 'resolveMethod');

        $I->assertInstanceOf(ResolveFifthClass::class, $object);
        $I->assertInstanceOf(AutowiredFirst::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolveMethod()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveMultipleDefinitions(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolveMethod() with multiple definitions');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function($name) use ($I) {
            $I->assertEquals(AutowiredSecond::class, $name);

            return new AutowiredSecond();
        }]);

        $object = new ResolvedSixthClass();

        $I->assertNull($object->autowired);

        $autowire = new Autowire([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);
        /** @var ResolvedFirstClass $object */
        $autowire->resolveMethod($diStub, $object, 'resolveMethod');

        $I->assertInstanceOf(ResolvedSixthClass::class, $object);
        $I->assertInstanceOf(AutowiredSecond::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolveMethod()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveMultipleDefinitionsStatic(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolveMethod() with multiple definitions static');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function($name) use ($I) {
            $I->assertEquals(AutowiredSecond::class, $name);

            return new AutowiredSecond();
        }]);

        $object = new ResolvedSeventhClass();

        $I->assertNull($object->autowired);

        $autowire = new Autowire([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);
        /** @var ResolvedFirstClass $object */
        $autowire->resolveMethod($diStub, $object, 'resolveMethod');

        $I->assertInstanceOf(ResolvedSeventhClass::class, $object);
        $I->assertInstanceOf(AutowiredSecond::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
    }
}
