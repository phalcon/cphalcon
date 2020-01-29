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

namespace Phalcon\Test\Integration\Paginator\Adapter\Model;

use IntegrationTester;

/**
 * Class SetCurrentPageCest
 */
class SetCurrentPageCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\Model :: setCurrentPage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterModelSetCurrentPage(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\Model - setCurrentPage()');
        $I->skipTest('Need implementation');
    }
}
