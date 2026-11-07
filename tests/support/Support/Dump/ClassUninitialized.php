<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Support\Dump;

class ClassUninitialized
{
    public int $count;

    public int $total = 5;

    protected string $name;

    private ?array $data;
}
