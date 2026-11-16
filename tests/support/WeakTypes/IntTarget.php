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

namespace Phalcon\Tests\Support\WeakTypes;

/**
 * User code that declares int parameters and an int property. Used to test
 * that phalcon calls user code with the PHP weak type rules.
 */
class IntTarget
{
    public int $value = 0;

    public function __construct(int $value = 0)
    {
        $this->value = $value;
    }

    public function __invoke(int $value): int
    {
        return $value * 2;
    }

    public static function double(int $value): int
    {
        return $value * 2;
    }

    public function mainAction(int $value): int
    {
        return $value;
    }

    /**
     * The parameter rules of an ADR action
     *
     * @return array<string, array<string, mixed>>
     */
    public static function params(): array
    {
        return [
            'id' => [
                'type'    => 'string',
                'convert' => [self::class, 'double'],
            ],
        ];
    }

    public function setValue(int $value): void
    {
        $this->value = $value;
    }

    public function showAction(int $value): int
    {
        return $value;
    }
}
