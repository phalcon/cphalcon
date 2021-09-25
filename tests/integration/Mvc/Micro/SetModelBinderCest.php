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

namespace Phalcon\Tests\Integration\Mvc\Micro;

use IntegrationTester;

/**
 * Class SetModelBinderCest
 */
class SetModelBinderCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: setModelBinder()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroSetModelBinder(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - setModelBinder()');
        $I->skipTest('Need implementation');
    }
}
