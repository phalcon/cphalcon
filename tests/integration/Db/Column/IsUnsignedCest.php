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

class IsUnsignedCest
{
    /**
     * Tests Phalcon\Db\Column :: isUnsigned()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbColumnIsUnsigned(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - isUnsigned()");
        $I->skipTest("Need implementation");
    }
}
