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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Php;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Php;

class GetContentCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Php :: getContent()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewEnginePhpGetContent(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Php - getContent()');

        $view = new View();

        $engine = new Php($view);

        $view->setContent('hello world');

        $I->assertEquals(
            'hello world',
            $engine->getContent()
        );
    }
}
