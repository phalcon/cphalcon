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

namespace Phalcon\Tests\Unit\Support\Version\Fake;

use Phalcon\Support\Version;

/**
 * Fake for beta version
 */
final class FakeVersionBeta extends Version
{
    protected function getVersion(): array
    {
        return [5, 0, 0, 2, 2];
    }
}
