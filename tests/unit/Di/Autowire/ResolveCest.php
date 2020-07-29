<?php

declare(strict_types=1);

namespace Phalcon\Test\Unit\Di\Autowire;

use Codeception\Util\Stub;
use Phalcon\Di\Autowire;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Exception\AutowireException;
use Phalcon\Di\Exception\BindException;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredInterface;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredSecond;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedFirstClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedFourthClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedSecondClass;
use Phalcon\Test\Fixtures\Di\Autowire\ResolvedThirdClass;
use UnitTester;

class ResolveCest
{
    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolve(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve()');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function ($name) use ($I) {
            $I->assertEquals(AutowiredFirst::class, $name);

            return new AutowiredFirst();
        }]);

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        /** @var ResolvedFirstClass $object */
        $object = $autowire->resolve($diStub, ResolvedFirstClass::class);

        $I->assertInstanceOf(ResolvedFirstClass::class, $object);
        $I->assertInstanceOf(AutowiredFirst::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveWrongClass(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve() with wrong class');

        $diStub = Stub::makeEmpty(DiInterface::class);

        $autowire = new Autowire();
        $exception = new AutowireException("Class 'xyz' wasn't found by autowire compomenent");
        $I->expectThrowable($exception, function () use ($diStub, $autowire) {
            $autowire->resolve($diStub, 'xyz');
        });
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveOptionalDefaultParameter(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve() with optional default parameter');

        $I->wantToTest('Autowire - resolve()');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function ($name) use ($I) {
            $I->assertEquals(AutowiredFirst::class, $name);

            return new AutowiredFirst();
        }]);

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        /** @var ResolvedSecondClass $object */
        $object = $autowire->resolve($diStub, ResolvedSecondClass::class);

        $I->assertInstanceOf(ResolvedSecondClass::class, $object);
        $I->assertInstanceOf(AutowiredFirst::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
        $I->assertEquals('testParameter', $object->test);
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveOptionalValueParameter(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve() with value of optional parameter');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function ($name) use ($I) {
            $I->assertEquals(AutowiredFirst::class, $name);

            return new AutowiredFirst();
        }]);

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        /** @var ResolvedSecondClass $object */
        $newValue = 'newValue';
        $object = $autowire->resolve($diStub, ResolvedSecondClass::class, ['test' => $newValue]);

        $I->assertInstanceOf(ResolvedSecondClass::class, $object);
        $I->assertInstanceOf(AutowiredFirst::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
        $I->assertEquals($newValue, $object->test);
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveMissingParameter(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve() with missing parameter throws exception');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function ($name) use ($I) {
            $I->assertEquals(AutowiredFirst::class, $name);

            return new AutowiredFirst();
        }]);

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        /** @var ResolvedSecondClass $object */
        $exception = new AutowireException("Missing value for parameter 'test'");
        $I->expectThrowable($exception, function () use ($diStub, $autowire) {
            $autowire->resolve($diStub, ResolvedThirdClass::class);
        });
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveRequiredParameter(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve() with required parameter');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function ($name) use ($I) {
            $I->assertEquals(AutowiredFirst::class, $name);

            return new AutowiredFirst();
        }]);

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        /** @var ResolvedSecondClass $object */
        $newValue = 'newValue';
        $object = $autowire->resolve($diStub, ResolvedThirdClass::class, ['test' => $newValue]);

        $I->assertInstanceOf(ResolvedThirdClass::class, $object);
        $I->assertInstanceOf(AutowiredFirst::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
        $I->assertEquals($newValue, $object->test);
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveMultipleDefinitions(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve() with multiple definitions');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function ($name) use ($I) {
            $I->assertEquals(AutowiredSecond::class, $name);

            return new AutowiredSecond();
        }]);

        $autowire = new Autowire([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);
        /** @var ResolvedSecondClass $object */
        $newValue = 'newValue';
        $object = $autowire->resolve($diStub, ResolvedFourthClass::class, ['test' => $newValue]);

        $I->assertInstanceOf(ResolvedFourthClass::class, $object);
        $I->assertInstanceOf(AutowiredSecond::class, $object->autowired);
        $I->assertInstanceOf(AutowiredInterface::class, $object->autowired);
        $I->assertEquals($newValue, $object->test);
    }

    /**
     * Tests Phalcon\Di\Autowire :: resolve()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireResolveMultipleDefinitionsException(UnitTester $I)
    {
        $I->wantToTest('Autowire - resolve() with multiple definitions throws exceptiong');

        $diStub = Stub::makeEmpty(DiInterface::class, ['get' => function ($name) use ($I) {
            $I->assertEquals(AutowiredSecond::class, $name);

            return new AutowiredSecond();
        }]);

        $autowire = new Autowire([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);
        $exception = new BindException("More than one possible definitions for class '" . AutowiredInterface::class . "', please provide
                     which implementation should be used for this class using setAutowireTypes on service or implement
                     one of the inerfaces - Phalcon\Di\AutowireTypesProviderInterface or Phalcon\Di\AutowireTypesStaticProviderInterface
                     depending if this is __construct or method autowiring");
        $I->expectThrowable($exception, function () use ($diStub, $autowire) {
            $autowire->resolve($diStub, ResolvedThirdClass::class);
        });
    }
}
