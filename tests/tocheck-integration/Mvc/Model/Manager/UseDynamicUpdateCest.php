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
 * Class UseDynamicUpdateCest
 */
class UseDynamicUpdateCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: useDynamicUpdate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelManagerUseDynamicUpdate(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - useDynamicUpdate()');
        $I->skipTest('Need implementation');
    }
}
