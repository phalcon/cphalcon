<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Http\Server;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\ServerRequestInterface;
use Phalcon\Http\Server\AbstractRequestHandler;

/**
 * Class MiddlewareFixture
 */
class RequestHandlerFixture extends AbstractRequestHandler
{
    public function handle(ServerRequestInterface $request): ResponseInterface
    {
    }
}
