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
 * Class GetLimitCest
 */
class GetLimitCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getLimit()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorRepositoryGetLimit(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - getLimit()');
        $I->skipTest('Need implementation');
    }
}
