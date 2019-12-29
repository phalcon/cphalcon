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
 * Class GetDefinitionCest
 */
class GetDefinitionCest
{
    /**
     * Tests Phalcon\Mvc\Micro\LazyLoader :: getDefinition()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroLazyloaderGetDefinition(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro\LazyLoader - getDefinition()');
        $I->skipTest('Need implementation');
    }
}
