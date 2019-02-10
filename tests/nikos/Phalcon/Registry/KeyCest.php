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

use UnitTester;

/**
 * Class KeyCest
 */
class KeyCest
{
    /**
     * Tests Phalcon\Registry :: key()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function registryKey(UnitTester $I)
    {
        $I->wantToTest('Registry - key()');
        $I->skipTest('Need implementation');
    }
}
