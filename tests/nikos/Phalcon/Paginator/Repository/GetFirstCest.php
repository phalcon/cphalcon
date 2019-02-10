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
 * Class GetFirstCest
 */
class GetFirstCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getFirst()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function paginatorRepositoryGetFirst(UnitTester $I)
    {
        $I->wantToTest('Paginator\Repository - getFirst()');
        $I->skipTest('Need implementation');
    }
}
