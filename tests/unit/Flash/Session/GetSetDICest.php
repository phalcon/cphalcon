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

namespace Phalcon\Tests\Unit\Flash\Session;

use Phalcon\Di\Di;
use Phalcon\Flash\Session;
use UnitTester;

/**
 * Class GetSetDICest
 *
 * @package Phalcon\Tests\Unit\Flash\Session
 */
class GetSetDICest
{
    /**
     * Tests Phalcon\Flash\Session :: getDI()/setDI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashSessionGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getDI()/setDI()');

        $container = new Di();
        $flash     = new Session();
        $flash->setDI($container);

        $actual = $flash->getDI();
        $I->assertSame($container, $actual);
        $I->assertInstanceOf(Di::class, $actual);
    }
}
