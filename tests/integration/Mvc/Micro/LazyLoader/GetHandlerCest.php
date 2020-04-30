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

use Phalcon\Assets\Manager;
use UnitTester;

/**
 * Class GetHandlerCest
 */
class GetHandlerCest
{
    /**
     * Tests Phalcon\Mvc\Micro\LazyLoader :: getHandler()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function mvcMicroLazyloaderGetHandler(IntegrationTester $I)
    {
        $I->wantToTest('Assets\Manager - getJs()');

        $assets = new Manager();

        $assets->addJs('/js/script1.js');
        $assets->addJs('/js/script2.js');

        $collection = $assets->getJs();

        $I->assertCount(2, $collection);
    }
}
