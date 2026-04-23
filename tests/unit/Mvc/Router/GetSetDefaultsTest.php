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

final class GetSetDefaultsTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcRouterGetSetDefaults(): void
    {
        $router = new Router();

        $expected = [
            'namespace'  => '',
            'module'     => '',
            'controller' => '',
            'action'     => '',
            'params'     => [],
        ];
        $actual   = $router->getDefaults();
        $this->assertSame($expected, $actual);

        $defaults = [
            'namespace'  => 'Phalcon',
            'module'     => 'front',
            'controller' => 'Login',
            'action'     => 'default',
            'params'     => [1, 2, 3],
        ];

        $router->setDefaults($defaults);

        $expected = $defaults;
        $actual   = $router->getDefaults();
        $this->assertSame($expected, $actual);
    }
}
