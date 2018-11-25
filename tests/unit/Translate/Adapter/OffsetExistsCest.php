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

class OffsetExistsCest
{
    /**
     * Tests Phalcon\Translate\Adapter :: offsetExists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterOffsetExists(UnitTester $I)
    {
        $I->wantToTest("Translate\Adapter - offsetExists()");
        $I->skipTest("Need implementation");
    }
}
