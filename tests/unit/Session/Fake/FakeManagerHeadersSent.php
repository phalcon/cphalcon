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

namespace Phalcon\Tests\Unit\Session\Fake;

use Phalcon\Session\Manager;

final class FakeManagerHeadersSent extends Manager
{
    protected static function phpHeadersSent(): bool
    {
        return true;
    }
}
