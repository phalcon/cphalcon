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
 * Class GetTotalItemsCest
 */
class GetTotalItemsCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getTotalItems()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorRepositoryGetTotalItems(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - getTotalItems()');
        $I->skipTest('Need implementation');
    }
}
