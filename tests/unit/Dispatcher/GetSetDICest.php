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

namespace Phalcon\Tests\Unit\Dispatcher;

use Phalcon\Di;
use Phalcon\Mvc\Dispatcher;
use UnitTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Dispatcher :: getDI() / setDI()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-17
     */
    public function dispatcherGetSetDI(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getDI() / setDI()');

        $oContainer = new Di();

        $oDispatcher = new Dispatcher();

        $oDispatcher->setDI($oContainer);

        $I->assertSame(
            $oContainer,
            $oDispatcher->getDI()
        );

        $oClass  = Di::class;
        $oActual = $oDispatcher->getDI();
        $I->assertInstanceOf($oClass, $oActual);
    }
}
