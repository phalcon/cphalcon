<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Exception;

use IntegrationTester;

class GetTraceAsStringCest
{
    /**
     * Tests Phalcon\Db\Exception :: getTraceAsString()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbExceptionGetTraceAsString(IntegrationTester $I)
    {
        $I->wantToTest("Db\Exception - getTraceAsString()");
        $I->skipTest("Need implementation");
    }
}
