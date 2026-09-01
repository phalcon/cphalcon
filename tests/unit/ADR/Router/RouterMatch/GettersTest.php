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

namespace Phalcon\Tests\Unit\ADR\Router\RouterMatch;

use Phalcon\ADR\Router\RouterMatch;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GettersTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Router\RouterMatch :: getAction()/getAttributes()/getMiddleware()/getName()
     */
    public function testAdrRouterRouterMatchGetters(): void
    {
        $match = new RouterMatch('ShowAction', ['id' => '42'], ['AuthMiddleware'], 'posts.show');

        $this->assertSame('ShowAction', $match->getAction());
        $this->assertSame(['id' => '42'], $match->getAttributes());
        $this->assertSame(['AuthMiddleware'], $match->getMiddleware());
        $this->assertSame('posts.show', $match->getName());
    }
}
