<?php
declare(strict_types=1);

namespace Phalcon\Test\Unit\Di\Autowire;

use Phalcon\Di\Autowire;
use Phalcon\Di\AutowireInterface;
use Phalcon\Di\BindDefinition;
use Phalcon\Di\BindDefinitionInterface;
use Phalcon\Di\Exception\BindException;
use Phalcon\Test\Fixtures\Autowire\AutowiredFirst;
use Phalcon\Test\Fixtures\Autowire\AutowiredInterface;
use Phalcon\Test\Fixtures\Autowire\AutowiredSecond;
use UnitTester;

class GetBindCest
{
    /**
     * Tests Phalcon\Di\Autowire :: getBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireGetBind(UnitTester $I)
    {
        $I->wantToTest('Autowire - getBind()');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        $bind = $autowire->getBind(AutowiredInterface::class);
        $I->assertInstanceOf(BindDefinitionInterface::class, $bind);

        $I->assertEquals(
             new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, false),
            $bind
        );
    }

    /**
     * Tests Phalcon\Di\Autowire :: getBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireGetBindOneDefinition(UnitTester $I)
    {
        $I->wantToTest('Autowire - getBind() with one definition');

        $autowire = new Autowire([AutowiredInterface::class => AutowiredFirst::class]);
        $bind = $autowire->getBind(AutowiredInterface::class, AutowiredFirst::class);
        $I->assertInstanceOf(BindDefinitionInterface::class, $bind);

        $I->assertEquals(
            new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, false),
            $bind
        );
    }

    /**
     * Tests Phalcon\Di\Autowire :: getBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireGetBindTwoDefinitions(UnitTester $I)
    {
        $I->wantToTest('Autowire - getBind() with two definitions');

        $autowire = new Autowire([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);
        $bind = $autowire->getBind(AutowiredInterface::class, AutowiredFirst::class);
        $I->assertInstanceOf(BindDefinitionInterface::class, $bind);

        $I->assertEquals(
            new BindDefinition(AutowiredInterface::class, AutowiredFirst::class, false),
            $bind
        );

        $bind = $autowire->getBind(AutowiredInterface::class, AutowiredSecond::class);
        $I->assertInstanceOf(BindDefinitionInterface::class, $bind);

        $I->assertEquals(
            new BindDefinition(AutowiredInterface::class, AutowiredSecond::class, false),
            $bind
        );
    }

    /**
     * Tests Phalcon\Di\Autowire :: getBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireGetBindTwoDefinitionsException(UnitTester $I)
    {
        $I->wantToTest('Autowire - getBind() with two definitions');

        $autowire = new Autowire([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);
        $exception = new BindException(
            "More than one possible definitions for class '" . AutowiredInterface::class . "', please provide
                     which implementation should be used for this class using setAutowireTypes on service"
        );
        $I->expectThrowable($exception, function() use ($autowire) {
            $autowire->getBind(AutowiredInterface::class);
        });
    }

    /**
     * Tests Phalcon\Di\Autowire :: getBind()
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2020-07-25
     */
    public function autowireGetBindWrongDefinitionException(UnitTester $I)
    {
        $I->wantToTest('Autowire - getBind() with wrong definition');

        $autowire = new Autowire([AutowiredInterface::class => [AutowiredFirst::class, AutowiredSecond::class]]);
        $exception = new BindException("Implementation 'xyz' does not exists for class '" . AutowiredInterface::class . "'");
        $I->expectThrowable($exception, function() use ($autowire) {
            $autowire->getBind(AutowiredInterface::class, 'xyz');
        });
    }
}
