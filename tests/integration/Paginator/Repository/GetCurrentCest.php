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

namespace Phalcon\Tests\Integration\Paginator\Repository;

use IntegrationTester;

/**
 * Class GetCurrentCest
 */
class GetCurrentCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getCurrent()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorRepositoryGetCurrent(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - getCurrent()');
        $I->skipTest('Need implementation');
    }
}
