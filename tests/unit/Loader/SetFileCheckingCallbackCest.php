<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Loader;

use UnitTester;

class SetFileCheckingCallbackCest
{
    /**
     * Tests Phalcon\Loader :: setFileCheckingCallback()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loaderSetFileCheckingCallback(UnitTester $I)
    {
        $I->wantToTest("Loader - setFileCheckingCallback()");
        $I->skipTest("Need implementation");
    }
}
