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

namespace Phalcon\Test\Unit\Mvc\Collection;

use UnitTester;

/**
 * Class CountCest
 */
class CountCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: count()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionCount(UnitTester $I)
    {
        $I->wantToTest('Mvc\Collection - count()');
        $I->skipTest('Need implementation');
    }
}
