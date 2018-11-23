<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Manager;

use UnitTester;

class MissingMethodCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: missingMethod()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testMissingMethod(UnitTester $I)
    {
        $I->skipTest("Need implementation");
    }
}
