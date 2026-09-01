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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\File\Size\Fake;

use Phalcon\Filter\Validation\Validator\File\Size\Min;

final class FakeMin extends Min
{
    protected function checkIsUploadedFile(string $name): bool
    {
        return true;
    }
}
