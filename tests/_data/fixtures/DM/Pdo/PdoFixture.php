<?php

/**
* This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\DM\Pdo;

class PdoFixture
{
    public function callMe(string $name): string
    {
        return $name;
    }
}
