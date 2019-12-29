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

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Mvc\View\Simple;
use Phalcon\Mvc\ViewBaseInterface;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Mvc\View\Simple :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - __construct()');

        $view = new Simple();
        $I->assertInstanceOf(ViewBaseInterface::class, $view);
    }
}
