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

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Mvc\Fake\RouterTrait;

final class NotFoundTest extends AbstractUnitTestCase
{
    use RouterTrait;

    /**
     * @author Andy Gutierrez <andres.gutierrez@phalcon.io>
     * @since  2013-03-01
     */
    public function testSettingNotFoundPaths(): void
    {
        $router = $this->getRouter(false);

        $router->notFound(
            [
                'module'     => 'module',
                'namespace'  => 'namespace',
                'controller' => 'controller',
                'action'     => 'action',
            ]
        );

        $router->handle('/');


        $this->assertSame(
            'controller',
            $router->getControllerName()
        );

        $this->assertSame(
            'action',
            $router->getActionName()
        );

        $this->assertSame(
            'module',
            $router->getModuleName()
        );

        $this->assertSame(
            'namespace',
            $router->getNamespaceName()
        );
    }
}
