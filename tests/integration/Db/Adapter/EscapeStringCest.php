<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter;

use IntegrationTester;

class EscapeStringCest
{
    /**
     * Tests Phalcon\Db\Adapter :: escapeString()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterEscapeString(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter - escapeString()");
        $I->skipTest("Need implementation");
    }
}
