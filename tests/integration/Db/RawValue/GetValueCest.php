<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\RawValue;

use IntegrationTester;

class GetValueCest
{
    /**
     * Tests Phalcon\Db\RawValue :: getValue()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbRawvalueGetValue(IntegrationTester $I)
    {
        $I->wantToTest("Db\RawValue - getValue()");
        $I->skipTest("Need implementation");
    }
}
