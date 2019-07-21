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

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Test\Fixtures\Traits\ViewTrait;

class UnderscoreIssetCest
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: __isset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewUnderscoreIsset(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View - __isset()");

        $view = new View();

        $view->paramA = '1';

        $view->setVar('paramB', '2');

        $I->assertTrue(
            isset($view->paramA)
        );

        $I->assertTrue(
            isset($view->paramA)
        );

        $I->assertFalse(
            isset($view->paramC)
        );
    }
}
