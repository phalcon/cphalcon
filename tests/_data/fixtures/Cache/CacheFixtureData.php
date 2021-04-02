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

namespace Phalcon\Test\Fixtures\Cache;

use stdClass;

/**
 * Phalcon\Test\Fixtures\Cache
 *
 */
class CacheFixtureData
{

    public static function getExamples(): array
    {

        return [
            [
                'string',
                'random string',
            ],
            [
                'integer',
                123456,
            ],
            [
                'float',
                123.456,
            ],
            [
                'boolean',
                true,
            ],
            [
                'object',
                new stdClass(),
            ],
            [
                'empty array',
                [],
            ],
            [
                'boolean false',
                false,
            ],
            [
                'integer 0',
                0,
            ],
            [
                'string 0',
                "0",
            ],
            [
                'null',
                null,
            ],
        ];
    }
}
