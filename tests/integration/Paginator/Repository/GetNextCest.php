<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorRepositoryGetNext(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - getNext()');
        $I->skipTest('Need implementation');
    }
}
