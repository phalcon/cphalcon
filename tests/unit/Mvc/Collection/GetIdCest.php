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

class GetIdCest
{
    /**
     * Tests Phalcon\Mvc\Collection :: getId()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionGetId(UnitTester $I)
    {
        $I->wantToTest('Mvc\Collection - getId()');

        $I->skipTest('Need implementation');
    }
}
