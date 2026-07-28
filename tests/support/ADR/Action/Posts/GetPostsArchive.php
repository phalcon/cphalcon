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

namespace Phalcon\Tests\Support\ADR\Action\Posts;

use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;

/**
 * Deliberately unreachable. The class name fuses an operation onto the
 * resource, but there is no `Posts/Archive` directory, so `/posts/archive`
 * resolves to GetPosts with `archive` as a positional attribute. Kept as the
 * negative fixture for the "nothing can be shadowed" guarantee.
 */
final class GetPostsArchive implements Action
{
    public function __invoke(AttributeRequest $request): ResponseInterface
    {
        return (new Response())->setContent('archive');
    }
}
