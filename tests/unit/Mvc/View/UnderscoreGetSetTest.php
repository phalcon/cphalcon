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

namespace Phalcon\Tests\Unit\Mvc\View;

use Phalcon\Mvc\View;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\ViewTrait;

class UnderscoreGetSetTest extends AbstractUnitTestCase
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: __get() / __set()
     */
    public function testMvcViewUnderscoreGetSet(): void
    {
        $view = new View();

        $view->foo = 'bar';

        $this->assertEquals(
            'bar',
            $view->foo
        );

        $this->assertEquals(
            'bar',
            $view->getVar('foo')
        );


        $view->setVar('bar', 'foo');

        $this->assertEquals(
            'foo',
            $view->bar
        );
    }
}
