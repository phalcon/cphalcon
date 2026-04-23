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

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Mvc\Router;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetDefaultActionTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcRouterSetDefaultAction(): void
    {
        $router = new Router();

        $router->setDefaultAction('default');

        $this->assertSame(
            'default',
            $router->getDefaults()['action']
        );
    }
}
