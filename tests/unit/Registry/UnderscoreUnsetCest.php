<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

/**
 * Class UnderscoreUnsetCest
 */
class UnderscoreUnsetCest
{
    /**
     * Tests Phalcon\Registry :: __unset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryUnderscoreUnset(UnitTester $I)
    {
        $I->wantToTest('Registry - __unset()');
        $registry        = new Registry();
        $registry->one   = 1;
        $registry->two   = 2;
        $registry->three = 3;

        $I->assertCount(3, $registry);

        unset($registry->two);

        $I->assertCount(2, $registry);

        unset($registry['one']);

        $I->assertCount(1, $registry);
    }
}
