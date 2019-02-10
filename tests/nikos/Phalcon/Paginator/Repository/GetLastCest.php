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

namespace Phalcon\Test\Unit\Paginator\Repository;

use UnitTester;

/**
 * Class GetLastCest
 */
class GetLastCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getLast()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function paginatorRepositoryGetLast(UnitTester $I)
    {
        $I->wantToTest('Paginator\Repository - getLast()');
        $I->skipTest('Need implementation');
    }
}
