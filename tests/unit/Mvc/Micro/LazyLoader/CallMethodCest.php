<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Micro\LazyLoader;

use UnitTester;

class CallMethodCest
{
    /**
     * Tests Phalcon\Mvc\Micro\LazyLoader :: callMethod()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroLazyloaderCallMethod(UnitTester $I)
    {
        $I->wantToTest("Mvc\Micro\LazyLoader - callMethod()");
        $I->skipTest("Need implementation");
    }
}
