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

namespace Phalcon\Tests\Unit\Translate\Fake;

use Phalcon\Tests\Support\Fake\FopenReturnsFalseTrait;
use Phalcon\Translate\Adapter\Csv;

final class FakeCsvFopen extends Csv
{
    use FopenReturnsFalseTrait;
}
