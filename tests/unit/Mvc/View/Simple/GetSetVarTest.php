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

class GetSetVarTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSimpleGeSettVar(): void
    {
        $view = new Simple();

        $this->assertEquals(
            $view,
            $view->setVar('foo1', 'bar1')
        );

        $this->assertEquals(
            'bar1',
            $view->getVar('foo1')
        );
    }
}
