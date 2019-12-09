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

namespace Phalcon\Test\Unit\Flash\Direct;

use Phalcon\Di;
use Phalcon\Flash\Direct;
use UnitTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Flash\Direct :: getDI() / setDI()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function flashDirectGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getDI() / setDI()');

        $container = new Di();

        $oFlashDirect = new Direct();

        $oFlashDirect->setDI($container);

        $I->assertSame(
            $container,
            $oFlashDirect->getDI()
        );

        $class  = Di::class;
        $actual = $oFlashDirect->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}
