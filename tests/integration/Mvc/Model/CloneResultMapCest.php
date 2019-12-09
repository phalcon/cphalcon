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

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

/**
 * Class CloneResultMapCest
 */
class CloneResultMapCest
{
    /**
     * Tests Phalcon\Mvc\Model :: cloneResultMap()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelCloneResultMap(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - cloneResultMap()');
        $I->skipTest('Need implementation');
    }
}
