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

namespace Phalcon\Tests\Support\ADR\Action\Hello;

use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;

final class GetHello implements Action
{
    public function __invoke(AttributeRequest $request): ResponseInterface
    {
        return (new Response())->setContent('hello ' . $request->getAttributes()->get(0));
    }
}
