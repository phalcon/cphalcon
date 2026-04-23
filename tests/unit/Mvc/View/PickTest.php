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

use Phalcon\Di\Di;
use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

class PickTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-01-07
     */
    public function testMvcViewPick(): void
    {
        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(supportDir('assets/views'))
        );

        $view->setDI($container);

        $view->start();
        $view->setLayout('pick');
        $view->pick('currentrender/other');
        $view->render('currentrender', 'another');
        $view->finish();

        $expected = 'Well, this is the view content: here.';
        $actual   = $view->getContent();
        $this->assertEquals($expected, $actual);

        $view->start();
        $view->setLayout('pick');
        $view->pick(['currentrender/other']);
        $view->render('currentrender', 'another');
        $view->finish();

        $expected = 'Well, this is the view content: here.';
        $actual   = $view->getContent();
        $this->assertEquals($expected, $actual);
    }
}
