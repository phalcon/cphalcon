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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Simple;

use IntegrationTester;

/**
 * Class SetIsFreshCest
 */
class SetIsFreshCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: setIsFresh()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSimpleSetIsFresh(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - setIsFresh()');
        $I->skipTest('Need implementation');
    }
}
