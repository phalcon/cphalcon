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

namespace Phalcon\Tests\Unit\Support\Fake;

use Phalcon\Support\Version;

/**
 * A Version with a fixed release array, so version tests do not depend on the
 * library's live version. Fixture: 6.0.0 alpha 5 (format ABBCCDE).
 */
class FakeVersion extends Version
{
    /**
     * @return int[]
     */
    protected function getVersion(): array
    {
        return [6, 0, 0, 1, 5];
    }
}
