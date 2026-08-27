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

/**
 * The declared name differs in letter case from the file path on purpose.
 * The router derives `Casing\GetCasing` from `/casing`; PHP loads this class
 * for that name because class names are case-insensitive, but the router
 * must not accept it.
 */

namespace Phalcon\Tests\Support\ADR\Action\CASING;

use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;

final class GetCASING implements Action
{
    public function __invoke(AttributeRequest $request): ResponseInterface
    {
        return (new Response())->setContent('casing');
    }
}
