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

class PartialTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewPartial(): void
    {
        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(supportDir('assets/views'))
        );
        $view->setPartialsDir('partials/');
        $view->setDI($container);

        ob_start();
        $view->partial('partial', ['cool_var' => 'abcde']);
        $actual = ob_get_clean();

        $this->assertSame('Hey, this is a partial, also abcde', $actual);
    }
}
