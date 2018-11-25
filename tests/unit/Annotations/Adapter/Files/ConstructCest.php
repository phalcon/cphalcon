<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\Adapter\Files;

use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Files :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsAdapterFilesConstruct(UnitTester $I)
    {
        $I->wantToTest("Annotations\Adapter\Files - __construct()");
        $I->skipTest("Need implementation");
    }
}
