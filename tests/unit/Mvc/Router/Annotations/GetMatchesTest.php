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
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetMatchesTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        parent::setUp();

        $this->newDi();
        $this->setDiService('request');
        $this->setDiService('annotations');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcRouterAnnotationsGetMatches(): void
    {
        $router = new Annotations(true);
        $router->setDI($this->container);

        $router->handle('/users/edit/100/');

        $this->assertTrue($router->wasMatched());

        $expected = [
            0 => '/users/edit/100/',
            1 => 'users',
            2 => 'edit',
            3 => '/100/',
        ];
        $this->assertSame($expected, $router->getMatches());
    }
}
