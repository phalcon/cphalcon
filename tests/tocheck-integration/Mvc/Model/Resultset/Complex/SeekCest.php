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

namespace Phalcon\Test\Integration\Mvc\Model\Resultset\Complex;

use IntegrationTester;

/**
 * Class SeekCest
 */
class SeekCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Complex :: seek()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetComplexSeek(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Complex - seek()');
        $I->skipTest('Need implementation');
    }
}
