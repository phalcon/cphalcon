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

namespace Phalcon\Test\Integration\Mvc\Micro\Collection;

use IntegrationTester;

/**
 * Class PatchCest
 */
class PatchCest
{
    /**
     * Tests Phalcon\Mvc\Micro\Collection :: patch()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcMicroCollectionPatch(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\Collection - patch()');
        $I->skipTest('Need implementation');
    }
}
