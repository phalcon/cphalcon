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
 * Class ToArrayCest
 */
class ToArrayCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: toArray()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionToArray(UnitTester $I)
    {
        $I->wantToTest('Mvc\Collection - toArray()');
        $I->skipTest('Need implementation');
    }
}
