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

namespace Phalcon\Tests\Unit\Mvc\View\Simple;

use Phalcon\Mvc\View\Simple;
use Phalcon\Tests\AbstractUnitTestCase;

class GetSetContentTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSimpleGetSetContent(): void
    {
        $view = new Simple();

        $this->assertEquals(
            $view,
            $view->setContent('<h1>hello</h1>')
        );

        $this->assertEquals(
            '<h1>hello</h1>',
            $view->getContent()
        );
    }
}
