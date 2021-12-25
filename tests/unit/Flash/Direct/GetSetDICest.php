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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Di\Di;
use Phalcon\Flash\Direct;
use UnitTester;

/**
 * Class GetSetDICest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class GetSetDICest
{
    /**
     * Tests Phalcon\Flash\Direct :: getDI()/setDI()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getDI()/setDI()');

        $container = new Di();
        $flash     = new Direct();
        $flash->setDI($container);

        $actual = $flash->getDI();
        $I->assertSame($container, $actual);
        $I->assertInstanceOf(Di::class, $actual);
    }
}
