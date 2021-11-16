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

class UnderscoreGetSetCest
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: __get() / __set()
     */
    public function mvcViewUnderscoreGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - __get() / __set()');

        $view = new View();

        $view->foo = 'bar';

        $I->assertEquals(
            'bar',
            $view->foo
        );

        $I->assertEquals(
            'bar',
            $view->getVar('foo')
        );


        $view->setVar('bar', 'foo');

        $I->assertEquals(
            'foo',
            $view->bar
        );
    }
}
