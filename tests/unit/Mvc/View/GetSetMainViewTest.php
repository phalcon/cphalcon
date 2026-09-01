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

class GetSetMainViewTest extends AbstractUnitTestCase
{
    /**
     * Tests Phalcon\Mvc\View :: getMainView() / setMainView()
     */
    public function testMvcViewGetSetMainView(): void
    {
        $view = new View();

        $view->setMainView('html5');

        $this->assertEquals(
            'html5',
            $view->getMainView()
        );
    }
}
