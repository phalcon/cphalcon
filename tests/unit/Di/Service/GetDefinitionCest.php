<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\Service;

use UnitTester;

class GetDefinitionCest
{
    /**
     * Tests Phalcon\Di\Service :: getDefinition()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diServiceGetDefinition(UnitTester $I)
    {
        $I->wantToTest("Di\Service - getDefinition()");
        $I->skipTest("Need implementation");
    }
}
