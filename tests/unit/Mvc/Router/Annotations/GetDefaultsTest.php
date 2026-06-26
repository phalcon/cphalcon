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

namespace Phalcon\Tests\Unit\Mvc\Router\Annotations;

use Phalcon\Mvc\Router\Annotations;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetDefaultsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsGetDefaults(): void
    {
        $router = new Annotations(false);

        $expected = [
            'namespace'  => '',
            'module'     => '',
            'controller' => '',
            'action'     => '',
            'params'     => [],
        ];
        $this->assertSame($expected, $router->getDefaults());

        $defaults = [
            'namespace'  => 'Phalcon',
            'module'     => 'front',
            'controller' => 'Login',
            'action'     => 'default',
            'params'     => [1, 2, 3],
        ];

        $router->setDefaults($defaults);

        $this->assertSame($defaults, $router->getDefaults());
    }
}
