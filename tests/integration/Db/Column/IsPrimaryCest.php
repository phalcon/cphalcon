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

class IsPrimaryCest
{
    /**
     * Tests Phalcon\Db\Column :: isPrimary()
     *
     * @param IntegrationTester $I
     * 
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbColumnIsPrimary(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - isPrimary()");
        $I->skipTest("Need implementation");
    }
}
