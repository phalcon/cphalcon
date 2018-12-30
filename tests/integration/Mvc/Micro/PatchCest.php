<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;

/**
 * Class PatchCest
 */
class PatchCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: patch()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroPatch(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - patch()');
        $I->skipTest('Need implementation');
    }
}
