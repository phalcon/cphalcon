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
use Phalcon\Mvc\ViewInterface;
use Phalcon\Tests\AbstractUnitTestCase;

class DisableLevelTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewDisableLevel(): void
    {
        $view   = new View();
        $result = $view->disableLevel(View::LEVEL_LAYOUT);
        $this->assertInstanceOf(ViewInterface::class, $result);
    }
}
