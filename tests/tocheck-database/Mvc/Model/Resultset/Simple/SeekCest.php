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
 * Class SeekCest
 */
class SeekCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: seek()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSimpleSeek(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - seek()');
        $I->skipTest('Need implementation');
    }
}
