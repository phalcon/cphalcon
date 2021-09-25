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
 * Class SetAliasesCest
 */
class SetAliasesCest
{
    /**
     * Tests Phalcon\Paginator\Repository :: setAliases()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorRepositorySetAliases(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Repository - setAliases()');
        $I->skipTest('Need implementation');
    }
}
