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

namespace Phalcon\Tests\Support\ADR\Action\User;

use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;

use function gettype;

final class GetUser implements Action
{
    public function __invoke(AttributeRequest $request): ResponseInterface
    {
        $id = $request->getAttributes()->get('id');

        return (new Response())->setContent(gettype($id) . ':' . $id);
    }

    public static function params(): array
    {
        return [
            'id' => ['match' => '\d+', 'type' => 'int'],
        ];
    }
}
