<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter;

use UnitTester;

class ExistsCest
{
    /**
     * Tests Phalcon\Translate\Adapter :: exists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterExists(UnitTester $I)
    {
        $I->wantToTest("Translate\Adapter - exists()");
        $I->skipTest("Need implementation");
    }
}
