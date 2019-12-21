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

namespace Phalcon\Test\Unit\Flash\Session;

use Phalcon\Di;
use Phalcon\Flash\Session as FlashSession;
use UnitTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Flash\Session :: getDI() / setDI()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-07
     */
    public function flashSessionSetDI(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getDI() / setDI()');

        $container = new Di();

        $oFlashSession = new FlashSession();

        $oFlashSession->setDI($container);

        $I->assertSame(
            $container,
            $oFlashSession->getDI()
        );

        $class  = Di::class;
        $actual = $oFlashSession->getDI();
        $I->assertInstanceOf($class, $actual);
    }
}
