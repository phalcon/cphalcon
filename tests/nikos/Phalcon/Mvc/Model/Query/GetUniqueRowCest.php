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

namespace Phalcon\Test\Unit\Mvc\Model\Query;

use UnitTester;

/**
 * Class GetUniqueRowCest
 */
class GetUniqueRowCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query :: getUniqueRow()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelQueryGetUniqueRow(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Query - getUniqueRow()');
        $I->skipTest('Need implementation');
    }
}
