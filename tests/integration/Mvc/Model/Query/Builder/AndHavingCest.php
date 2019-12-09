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

namespace Phalcon\Test\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;

/**
 * Class AndHavingCest
 */
class AndHavingCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: andHaving()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryBuilderAndHaving(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - andHaving()');
        $I->skipTest('Need implementation');
    }
}
