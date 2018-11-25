<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger\Adapter;

use UnitTester;

class CommitCest
{
    /**
     * Tests Phalcon\Logger\Adapter :: commit()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function loggerAdapterCommit(UnitTester $I)
    {
        $I->wantToTest("Logger\Adapter - commit()");
        $I->skipTest("Need implementation");
    }
}
