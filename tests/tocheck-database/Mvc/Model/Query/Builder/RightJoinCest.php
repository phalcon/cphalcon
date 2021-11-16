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

namespace Phalcon\Tests\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;

/**
 * Class RightJoinCest
 */
class RightJoinCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: rightJoin()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryBuilderRightJoin(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - rightJoin()');
        $I->skipTest('Need implementation');
    }
}
