<?php

declare(strict_types=1);

namespace Phalcon\Test\Unit\Di\Autowire;

use Phalcon\Di\Autowire;
use Phalcon\Di\BindDefinition;
use Phalcon\Di\Exception\BindException;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredInterface;
use UnitTester;

class BindCest
{
    /**
     * Tests Phalcon\Di\Autowire :: bind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireBind(UnitTester $I)
    {
        $I->wantToTest('Autowire - bind()');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());

        $autowire->bind(AutowiredInterface::class, AutowiredFirst::class, false);

        $I->assertEquals(
            [
                AutowiredInterface::class => [
                    AutowiredFirst::class => new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, false)
                ]
            ],
            $autowire->getBinds()
        );
    }

    /**
     * Tests Phalcon\Di\Autowire :: bind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireBindObject(UnitTester $I)
    {
        $I->wantToTest('Autowire - bind() with object');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());

        $autowire->bind(AutowiredInterface::class, new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, false));

        $I->assertEquals(
            [
                AutowiredInterface::class => [
                    AutowiredFirst::class => new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, false)
                ]
            ],
            $autowire->getBinds()
        );
    }

    /**
     * Tests Phalcon\Di\Autowire :: bind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireBindShared(UnitTester $I)
    {
        $I->wantToTest('Autowire - bind() with shared');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());

        $autowire->bind(AutowiredInterface::class, AutowiredFirst::class, true);

        $I->assertEquals(
            [
                AutowiredInterface::class => [
                    AutowiredFirst::class => new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, true)
                ]
            ],
            $autowire->getBinds()
        );
    }

    /**
     * Tests Phalcon\Di\Autowire :: bind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireBindWrongDefinition(UnitTester $I)
    {
        $I->wantToTest('Autowire - bind() with wrong definition');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());
        $exception = new BindException("Definition should be a string or object implementing BindDefinitionInterface");
        $I->expectThrowable($exception, function() use ($autowire) {
            $autowire->bind(AutowiredInterface::class, []);
        });
    }

    /**
     * Tests Phalcon\Di\Autowire :: bind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireBindWrongClassName(UnitTester $I)
    {
        $I->wantToTest('Autowire - bind() with wrong class name');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());
        $exception = new BindException("Bind class or interface 'xyz' does not exist");
        $I->expectThrowable($exception, function() use ($autowire) {
            $autowire->bind('xyz', AutowiredFirst::class);
        });
    }
}
