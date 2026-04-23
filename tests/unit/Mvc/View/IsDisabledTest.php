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

class IsDisabledTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-22
     */
    public function testMvcViewIsDisabled(): void
    {
        $view = new View();

        $this->assertFalse(
            $view->isDisabled()
        );

        $view->disable();

        $this->assertTrue(
            $view->isDisabled()
        );

        $view->enable();

        $this->assertFalse(
            $view->isDisabled()
        );
    }
}
