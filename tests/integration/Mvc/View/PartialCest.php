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

namespace Phalcon\Tests\Integration\Mvc\View;

use IntegrationTester;

/**
 * Class PartialCest
 */
class PartialCest
{
    /**
     * Tests Phalcon\Mvc\View :: partial()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewPartial(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - partial()');
        $I->skipTest('Need implementation');
    }
}
