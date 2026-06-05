<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Auth\Access\AbstractAccess;

final class FakeAccess extends AbstractAccess
{
    private bool $allowed = false;

    public function allowedIf(): bool
    {
        return $this->allowed;
    }

    public function setAllowed(bool $value): void
    {
        $this->allowed = $value;
    }
}
