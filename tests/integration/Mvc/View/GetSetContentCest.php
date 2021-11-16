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

namespace Phalcon\Tests\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Tests\Fixtures\Traits\ViewTrait;

class GetSetContentCest
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: getContent() / setContent()
     */
    public function mvcViewGetSetContent(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getContent() / setContent()');

        $view = new View();

        $view->setContent('<h1>hello</h1>');

        $I->assertEquals(
            '<h1>hello</h1>',
            $view->getContent()
        );
    }
}
