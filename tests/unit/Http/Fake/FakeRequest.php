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

namespace Phalcon\Tests\Unit\Http\Fake;

use Phalcon\Http\Request;

final class FakeRequest extends Request
{
    public function getTrustedProxies(): array
    {
        return $this->trustedProxies;
    }
}
