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

use Phalcon\Storage\Serializer\Igbinary;

use function trigger_error;

use const E_USER_WARNING;

final class FakeIgbinaryUnserializeWarning extends Igbinary
{
    protected function doUnserialize($value)
    {
        trigger_error('Unserialize Error', E_USER_WARNING);
        return false;
    }
}
