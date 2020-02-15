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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;

/**
 * Class GetHasOneThroughCest
 */
class GetHasOneThroughCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: getHasOneThrough()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-11-02
     */
    public function mvcModelManagerGetHasOneThrough(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - getHasOneThrough()');
        $I->skipTest('Need implementation');
    }
}
