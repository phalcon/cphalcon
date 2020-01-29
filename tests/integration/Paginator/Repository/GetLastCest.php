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
 * Class GetLastCest
 */
class GetLastCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getLast()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorRepositoryGetLast(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - getLast()');
        $I->skipTest('Need implementation');
    }
}
