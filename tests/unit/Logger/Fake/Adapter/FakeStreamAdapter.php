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

namespace Phalcon\Tests\Unit\Logger\Fake\Adapter;

use Phalcon\Logger\Adapter\Stream;
use Phalcon\Tests\Support\Fake\FopenReturnsFalseTrait;

final class FakeStreamAdapter extends Stream
{
    use FopenReturnsFalseTrait;
}
