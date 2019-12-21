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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;

class GetContentCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: getContent()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewEngineVoltGetContent(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - getContent()');

        $view = new View();

        $engine = new Volt($view);

        $view->setContent('hello world');

        $I->assertEquals(
            'hello world',
            $engine->getContent()
        );
    }
}
