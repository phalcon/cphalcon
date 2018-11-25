<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Dialect;

use UnitTester;

class AddIndexCest
{
    /**
     * Tests Phalcon\Db\Dialect :: addIndex()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectAddIndex(UnitTester $I)
    {
        $I->wantToTest("Db\Dialect - addIndex()");
        $I->skipTest("Need implementation");
    }
}
