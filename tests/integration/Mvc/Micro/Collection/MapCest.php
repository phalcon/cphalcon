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

namespace Phalcon\Test\Integration\Mvc\Micro\Collection;

use IntegrationTester;

/**
 * Class MapCest
 */
class MapCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: map()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroCollectionMap(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - map()');
        $I->skipTest('Need implementation');
    }
}
