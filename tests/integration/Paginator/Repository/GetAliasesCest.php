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
 * Class GetAliasesCest
 */
class GetAliasesCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: getAliases()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorRepositoryGetAliases(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - getAliases()');
        $I->skipTest('Need implementation');
    }
}
