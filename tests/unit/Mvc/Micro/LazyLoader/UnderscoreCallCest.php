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

class UnderscoreCallCest
{
    /**
     * Tests Phalcon\Mvc\Micro\LazyLoader :: __call()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroLazyloaderCall(UnitTester $I)
    {
        $I->wantToTest("Mvc\Micro\LazyLoader - __call()");
        $I->skipTest("Need implementation");
    }
}
