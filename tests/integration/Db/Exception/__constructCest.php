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

class __constructCest
{
    /**
     * Tests Phalcon\Db\Exception :: __construct()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbException__construct(IntegrationTester $I)
    {
        $I->wantToTest("Db\Exception - __construct()");
        $I->skipTest("Need implementation");
    }
}
