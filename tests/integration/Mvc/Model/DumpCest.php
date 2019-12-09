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
 * Class DumpCest
 */
class DumpCest
{
    /**
     * Tests Phalcon\Mvc\Model :: dump()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelDump(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - dump()');
        $I->skipTest('Need implementation');
    }
}
