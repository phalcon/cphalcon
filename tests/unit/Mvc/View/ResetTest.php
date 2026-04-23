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
use Phalcon\Tests\AbstractUnitTestCase;

class ResetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewReset(): void
    {
        $view = new View();
        $view->disable();
        $result = $view->reset();
        $this->assertInstanceOf(View::class, $result);
        $this->assertFalse($view->isDisabled());
        $this->assertSame(View::LEVEL_MAIN_LAYOUT, $view->getRenderLevel());
    }
}
