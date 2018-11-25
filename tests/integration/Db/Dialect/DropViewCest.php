<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Dialect;

use IntegrationTester;

class DropViewCest
{
    /**
     * Tests Phalcon\Db\Dialect :: dropView()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectDropView(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect - dropView()");
        $I->skipTest("Need implementation");
    }
}
