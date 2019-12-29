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

namespace Phalcon\Test\Integration\Mvc\Micro\LazyLoader;

use IntegrationTester;

/**
 * Class CallMethodCest
 */
class CallMethodCest
{
    /**
     * Tests Phalcon\Mvc\Micro\LazyLoader :: callMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroLazyloaderCallMethod(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\LazyLoader - callMethod()');
        $I->skipTest('Need implementation');
    }
}
