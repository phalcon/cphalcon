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

namespace Phalcon\Test\Integration\Paginator\Repository;

use IntegrationTester;

/**
 * Class GetNextCest
 */
class GetNextCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getNext()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorRepositoryGetNext(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - getNext()');
        $I->skipTest('Need implementation');
    }
}
