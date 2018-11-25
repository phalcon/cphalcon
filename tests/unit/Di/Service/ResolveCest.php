<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\Service;

use UnitTester;

class ResolveCest
{
    /**
     * Tests Phalcon\Di\Service :: resolve()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diServiceResolve(UnitTester $I)
    {
        $I->wantToTest("Di\Service - resolve()");
        $I->skipTest("Need implementation");
    }
}
