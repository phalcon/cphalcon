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

use Phalcon\Mvc\View\Engine\Php;
use Phalcon\Mvc\View\Simple;
use Phalcon\Tests\AbstractUnitTestCase;

class RegisterEnginesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSimpleRegisterEngines(): void
    {
        $view    = new Simple();
        $engines = ['.phtml' => Php::class];

        $view->registerEngines($engines);

        $this->assertSame($engines, $view->getRegisteredEngines());
    }
}
