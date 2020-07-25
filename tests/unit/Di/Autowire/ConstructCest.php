<?php
declare(strict_types=1);

namespace Phalcon\Test\Unit\Di\Autowire;

use Phalcon\Di\Autowire;
use Phalcon\Di\AutowireInterface;
use Phalcon\Di\BindDefinition;
use Phalcon\Test\Fixtures\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Autowire\AutowiredInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Di\Autowire :: __construct()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireConstruct(UnitTester $I)
    {
        $I->wantToTest('Autowire - __construct()');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());
        $I->assertInstanceOf(Autowire::class, $autowire);
        $I->assertInstanceOf(AutowireInterface::class, $autowire);
    }

    /**
     * Tests Phalcon\Di\Autowire :: __construct()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireConstructBinds(UnitTester $I)
    {
        $I->wantToTest('Autowire - __construct() with binds');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        $I->assertEquals(
            [
                AutowiredInterface::class => [
                    AutowiredFirst::class => new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, false)
                ]
            ],
            $autowire->getBinds()
        );
        $I->assertInstanceOf(Autowire::class, $autowire);
        $I->assertInstanceOf(AutowireInterface::class, $autowire);
    }
}
