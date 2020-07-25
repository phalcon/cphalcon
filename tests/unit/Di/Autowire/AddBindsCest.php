<?php
declare(strict_types=1);

namespace Phalcon\Test\Unit\Di\Autowire;

use Phalcon\Di;
use Phalcon\Di\Autowire;
use Phalcon\Di\BindDefinition;
use Phalcon\Test\Fixtures\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Autowire\AutowiredInterface;
use Phalcon\Test\Fixtures\Autowire\AutowiredSecond;
use UnitTester;

class AddBindsCest
{
    /**
     * Tests Phalcon\Di\Autowire :: addBinds()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireAddBinds(UnitTester $I)
    {
        $I->wantToTest('Autowire - addBinds()');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());

        $autowire->addBinds([AutowiredInterface::class => AutowiredFirst::class]);

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
     * Tests Phalcon\Di\Autowire :: addBinds()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireAddBindsArray(UnitTester $I)
    {
        $I->wantToTest('Autowire - addBinds() with array');

        $autowire = new Autowire();
        $I->assertEmpty($autowire->getBinds());

        $autowire->addBinds([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);

        $I->assertEquals(
            [
                AutowiredInterface::class => [
                    AutowiredFirst::class => new BindDefinition(
                        AutowiredInterface::class,
                        AutowiredFirst::class,
                        false
                    ),
                    AutowiredSecond::class => new BindDefinition(
                        AutowiredInterface::class,
                        AutowiredSecond::class,
                        false
                    ),
                ],
            ],
            $autowire->getBinds()
        );
    }

    /**
     * Tests Phalcon\Di\Autowire :: addBinds()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireAddBindsReplace(UnitTester $I)
    {
        $I->wantToTest('Autowire - addBinds()');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);

        $autowire->addBinds([AutowiredInterface::class => AutowiredSecond::class], true);

        $I->assertEquals(
            [
                AutowiredInterface::class => [
                    AutowiredSecond::class => new BindDefinition(AutowiredInterface::class, AutowiredSecond::class, false)
                ]
            ],
            $autowire->getBinds()
        );
    }
}
