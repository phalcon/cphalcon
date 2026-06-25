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

namespace Phalcon\Tests\Unit\Filter\Validation\Fake;

final class FakeValueAttribute
{
    private string $name;

    public function __construct(string $name)
    {
        $this->name = $name;
    }

    public function readAttribute(string $field = 'name'): mixed
    {
        return $this->{$field};
    }

    public function writeAttribute(string $field, mixed $value): void
    {
        $this->{$field} = $value;
    }
}
