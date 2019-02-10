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

namespace Phalcon\Test\Unit\Mvc\Model\Manager;

use UnitTester;

/**
 * Class CreateQueryCest
 */
class CreateQueryCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: createQuery()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelManagerCreateQuery(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - createQuery()');
        $I->skipTest('Need implementation');
    }
}
