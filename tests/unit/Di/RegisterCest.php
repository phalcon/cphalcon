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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di;
use Phalcon\Tests\Fixtures\Di\SomeComponent;
use Phalcon\Tests\Fixtures\Di\SomeServiceProvider;
use UnitTester;

/**
 * Class RegisterCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class RegisterCest
{
    /**
     * Unit Tests Phalcon\Di :: register()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diRegister(UnitTester $I)
    {
        $I->wantToTest('Di - register()');

        $container = new Di();
        $container->register(new SomeServiceProvider());

        $expected = 'bar';
        $actual   = $container->get('foo');
        $I->assertEquals($expected, $actual);

        $expected = SomeComponent::class;
        $actual   = $container->get('fooAction');
        $I->assertInstanceOf($expected, $actual);
    }
}
