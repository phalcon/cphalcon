<?php

declare(strict_types=1);

namespace Phalcon\Test\Unit\Di\Autowire;

use Phalcon\Di\Autowire;
use Phalcon\Di\BindDefinition;
use Phalcon\Di\BindDefinitionInterface;
use Phalcon\Di\Exception\BindException;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Di\Autowire\AutowiredInterface;
use UnitTester;

class HasBindCest
{
    /**
     * Tests Phalcon\Di\Autowire :: hasBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireHasBind(UnitTester $I)
    {
        $I->wantToTest('Autowire - hasBind()');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        $I->assertTrue($autowire->hasBind(AutowiredInterface::class));
    }

    /**
     * Tests Phalcon\Di\Autowire :: hasBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireHasBindWithDefinition(UnitTester $I)
    {
        $I->wantToTest('Autowire - hasBind() with definition');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        $I->assertTrue($autowire->hasBind(AutowiredInterface::class, AutowiredFirst::class));
    }

    /**
     * Tests Phalcon\Di\Autowire :: hasBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireHasBindFalse(UnitTester $I)
    {
        $I->wantToTest('Autowire - hasBind() returns false');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        $I->assertFalse($autowire->hasBind(AutowiredFirst::class));
    }

    /**
     * Tests Phalcon\Di\Autowire :: hasBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireHasBindWrongDefinition(UnitTester $I)
    {
        $I->wantToTest('Autowire - hasBind() with wrong definition');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        $exception = new BindException("Implementation 'xyz' does not exists for class '" . AutowiredInterface::class . "'");
        $I->expectThrowable($exception, function () use ($autowire) {
            $autowire->hasBind(AutowiredInterface::class, 'xyz');
        });
    }
}
