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

namespace Phalcon\Tests\Support\Forms;

/**
 * Entity with typed properties and a typed setter. Used to test the weak type
 * checks of Form::bind().
 */
class ContactFormTypedProperties
{
    public ?int $age = null;
    public ?string $code = null;
    private ?float $total = null;

    public function getTotal(): ?float
    {
        return $this->total;
    }

    public function setTotal(?float $total): void
    {
        $this->total = $total;
    }
}
