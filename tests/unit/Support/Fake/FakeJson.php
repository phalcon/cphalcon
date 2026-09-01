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

use JsonSerializable;

final class FakeJson implements JsonSerializable
{
    private array $data = [];

    public function __construct()
    {
        $this->data["one"] = "two";
    }

    public function jsonSerialize(): mixed
    {
        return $this->data;
    }
}
