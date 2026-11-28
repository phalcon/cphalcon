<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\ADR\Hidden;

/**
 * An Action with a params() method that the router cannot call. It is not
 * in the Action directory, thus the routing tests do not find it.
 */
class GetHidden
{
    /**
     * @return array<string, array<string, string>>
     */
    private static function params(): array
    {
        return ['id' => ['type' => 'int']];
    }
}
