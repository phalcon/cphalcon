<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Column;

use IntegrationTester;

class IsNotNullCest
{
    /**
     * Tests Phalcon\Db\Column :: isNotNull()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbColumnIsNotNull(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - isNotNull()");
        $I->skipTest("Need implementation");
    }
}
