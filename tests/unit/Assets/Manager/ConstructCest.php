<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Assets\Manager;

use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Manager :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsManagerConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Manager - __construct()');

        $I->skipTest('Need implementation');
    }
}
