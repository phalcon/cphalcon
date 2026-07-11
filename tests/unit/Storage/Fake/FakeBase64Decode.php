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

namespace Phalcon\Tests\Unit\Storage\Fake;

use Phalcon\Storage\Serializer\Base64;

final class FakeBase64Decode extends Base64
{
    protected static function phpBase64Decode(
        string $input,
        bool $strict = false
    ): string | false {
        return false;
    }
}
